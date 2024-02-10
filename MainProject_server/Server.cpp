#include "Server.h"

Server::Config Server::readConfig(const std::string &filename)
{
    Config config;
    std::ifstream configFile(filename);

    if (configFile.is_open())
    {
        std::string line;
        while (std::getline(configFile, line))
        {
            std::istringstream iss(line);
            std::string key, separator, value;

            iss >> key >> separator;

            if (key == "ServerIP=")
            {
                config.serverIP = separator;
            }
            else if (key == "ServerPort=")
            {
                config.serverPort = std::stoi(separator);
            }
        }
        configFile.close();
    }
    else
    {
        std::cerr << "Unable to open config file: " << filename << std::endl;
    }

    return config;
}

void Server::run()
{
    Config config = readConfig("../config.txt");

    sf::TcpListener listener;
    std::vector<std::thread> clientThreads;

    if (listener.listen(config.serverPort) != sf::Socket::Done)
    {
        std::cerr << "Error listening to port " << config.serverPort << std::endl;
    }

    std::cout << "Server is listening to port " << config.serverPort << ", waiting for connections... " << std::endl;

    while (true)
    {

        sf::TcpSocket *client = new sf::TcpSocket;

        if (listener.accept(*client) == sf::Socket::Done)
        {
            // Connection accepted
            // Start a new thread to handle this client.

            std::cout << "[" << client->getRemoteAddress() << "] Client connected" << std::endl;

            clientThreads.emplace_back([this, client]()
                                       { this->handleClient(*client); });
        }
    }

    for (auto &thread : clientThreads)
    {
        thread.join();
    }
}

void Server::handleClient(sf::TcpSocket &client)
{

    std::cout << "[" << client.getRemoteAddress() << "] handeling thread started" << std::endl;

    bool *loggedIn = new bool(false);
    sf::Socket::Status *status = new sf::Socket::Status;
    std::string *token = new std::string;
    Account *account = new Account;

    std::fstream file("accounts.txt");

    while (*status != sf::Socket::Disconnected)
    {

        std::string *message = new std::string;
        *message = receiveMessage(client, *status);

        if (*message == "")
        {
            continue;
        }

        // std::cout << "message: " << *message << std::endl;

        std::istringstream data(*message);
        data >> *token;

        if (*token == "register")
        {

            if (registerAccount(account, data.str(), *message) == 0)
            {
                std::cout << "[" << client.getRemoteAddress() << "] client regited, username: " << account->getUsername() << " balance: " << account->getBalance() << std::endl;
            }
            else
            {
                std::cout << "[" << client.getRemoteAddress() << "] client failed to regiter" << std::endl;
            }
            sendMessage(client, *message, *status);
        }
        if (*token == "login")
        {

            if (login(account, data.str(), *message) == 0)
            {
                std::cout << "[" << client.getRemoteAddress() << "] client logged in, username: " << account->getUsername() << " balance: " << account->getBalance() << std::endl;
                *loggedIn = true;
            }
            else
            {
                std::cout << "[" << client.getRemoteAddress() << "] client failed to log in" << std::endl;
            }
            sendMessage(client, *message, *status);
        }
        else if (*token == "map")
        {
            sendMessage(client, "map", *status);
        }
        else if (*token == "bet")
        {

            if (bet(data.str(), *message, account) == 0)
            {
                std::cout << "[" << client.getRemoteAddress() << "] client placed a bet ammout of: " << account->getBetAmmount() << std::endl;
            }
            else
            {
                std::cout << "[" << client.getRemoteAddress() << "] client failed to place a bet" << std::endl;
            }
            sendMessage(client, *message, *status);
        }
        else if (*token == "game")
        {

            this->game.init(account->getBetAmmount());

            std::cout << "[" << client.getRemoteAddress() << "] client is playing a game" << std::endl;

            *message = BuildGameMessage(game.dealer.hand, game.gambler.hand);

            sendMessage(client, *message, *status);


            while (true)
            {

                *message = receiveMessage(client, *status);
                if (*status == sf::Socket::Disconnected)
                {
                    break;
                }

                game.run(*message);
                message->clear();

                if (game.gameState != "init")
                {
                    break;
                }

                *message = "game ";

                for (int i = 0; i < game.dealer.hand.getNumCards(); i++)
                {
                    *message += game.dealer.hand.getCards()[i].getSuit() + game.dealer.hand.getCards()[i].getRank() + ",";
                }
                *message += std::to_string(game.dealer.hand.getValue()) + " ";

                for (int i = 0; i < game.gambler.hand.getNumCards(); i++)
                {
                    *message += game.gambler.hand.getCards()[i].getSuit() + game.gambler.hand.getCards()[i].getRank() + ",";
                }
                *message += std::to_string(game.gambler.hand.getValue()) + " ";
                *message += "game";

                sendMessage(client, *message, *status);

            }

            message->clear();

            if (game.gameState == "gamblerWin")
            {
                if (game.isDouble)
                    account->setBalance(account->getBalance() + game.betAmmount * 3);
                else
                    account->setBalance(account->getBalance() + game.betAmmount * 2);

                *message = "win ";

                for (int i = 0; i < game.dealer.hand.getNumCards(); i++)
                {
                    *message += game.dealer.hand.getCards()[i].getSuit() + game.dealer.hand.getCards()[i].getRank() + ",";
                }
                *message += std::to_string(game.dealer.hand.getValue()) + " ";

                for (int i = 0; i < game.gambler.hand.getNumCards(); i++)
                {
                    *message += game.gambler.hand.getCards()[i].getSuit() + game.gambler.hand.getCards()[i].getRank() + ",";
                }
                *message += std::to_string(game.gambler.hand.getValue()) + " ";

                *message += std::to_string(account->getBalance()) + " bet";
            }
            else if (game.gameState == "dealerWin")
            {
                if (game.isDouble)
                    account->setBalance(account->getBalance() - game.betAmmount);
                else
                    account->setBalance(account->getBalance());

                if (account->getBalance() <= 0)
                    account->setBalance(1000);

                *message = "lose ";

                for (int i = 0; i < game.dealer.hand.getNumCards(); i++)
                {
                    *message += game.dealer.hand.getCards()[i].getSuit() + game.dealer.hand.getCards()[i].getRank() + ",";
                }
                *message += std::to_string(game.dealer.hand.getValue()) + " ";

                for (int i = 0; i < game.gambler.hand.getNumCards(); i++)
                {
                    *message += game.gambler.hand.getCards()[i].getSuit() + game.gambler.hand.getCards()[i].getRank() + ",";
                }
                *message += std::to_string(game.gambler.hand.getValue()) + " ";

                *message += std::to_string(account->getBalance()) + " bet";
            }
            else if (game.gameState == "draw")
            {
                account->setBalance(account->getBalance() + game.betAmmount);

                *message = "draw ";

                for (int i = 0; i < game.dealer.hand.getNumCards(); i++)
                {
                    *message += game.dealer.hand.getCards()[i].getSuit() + game.dealer.hand.getCards()[i].getRank() + ",";
                }
                *message += std::to_string(game.dealer.hand.getValue()) + " ";

                for (int i = 0; i < game.gambler.hand.getNumCards(); i++)
                {
                    *message += game.gambler.hand.getCards()[i].getSuit() + game.gambler.hand.getCards()[i].getRank() + ",";
                }
                *message += std::to_string(game.gambler.hand.getValue()) + " ";

                *message += std::to_string(account->getBalance()) + " bet";
            }
            else
            {
                *message = "failed";
            }

            updateBalanceInFile(account->getUsername(), account->getBalance());

            sendMessage(client, *message, *status);
        }

        delete message;
    }

    std::cout << "[" << client.getRemoteAddress() << "] client disconnected" << std::endl;
    client.disconnect();

    delete loggedIn;
    delete token;
    delete status;
}

void Server::sendMessage(sf::TcpSocket &client, std::string message, sf::Socket::Status &status)
{

    status = client.send(message.c_str(), message.size());

    if (status != sf::Socket::Done)
    {
        // Error sending message
        std::cerr << "[" << client.getRemoteAddress() << "] Error sending message to client" << std::endl;
    }
}

std::string Server::receiveMessage(sf::TcpSocket &client, sf::Socket::Status &status)
{

    char buffer[1024];
    std::size_t received;

    status = client.receive(buffer, sizeof(buffer), received);

    if (status != sf::Socket::Done)
    {
        // Error receiving message
        std::cerr << "[" << client.getRemoteAddress() << "] Error receiving message to client" << std::endl;
    }
    return std::string(buffer, received);
}

int Server::registerAccount(Account *account, std::string data, std::string &response)
{

    std::string *username = new std::string;
    std::string *password = new std::string;
    std::string *token = new std::string;

    std::istringstream NewData(data);
    NewData >> *token >> *username >> *password;

    account->setUsername(*username);

    std::ofstream outputFile("accounts.txt", std::ios::app);

    accountsMutex.lock();

    std::ifstream inputFile("accounts.txt");
    if (!inputFile)
    {
        std::cerr << "Error opening file" << std::endl;
        accountsMutex.unlock();
        return -1;
    }
    else
    {
        std::string *fileUsername = new std::string;
        std::string *filePassword = new std::string;
        std::string *fileBalance = new std::string;

        while (inputFile >> *fileUsername >> *filePassword >> *fileBalance)
        {
            if (*username == *fileUsername)
            {
                response = "failed";
                inputFile.close();
                accountsMutex.unlock();
                return -1;
            }
        }

        delete fileUsername;
        delete filePassword;
        delete fileBalance;
    }

    if (*username == "" || *password == "")
    {
        response = "failed";
        accountsMutex.unlock();
        return -1;
    }

    for (int i = 0; i < username->size(); i++)
    {
        if (username->at(i) == ' ')
        {
            response = "failed";
            accountsMutex.unlock();
            return -1;
        }
    }

    if (!outputFile)
    {
        std::cerr << "Error opening file" << std::endl;
        accountsMutex.unlock();
        return -1;
    }
    else
    {
        outputFile << *username << " " << *password << " " << std::to_string(5000) << std::endl;
        outputFile.close();
    }

    accountsMutex.unlock();

    delete token;

    if (*username == "admin" && *password == "admin")
    {
        response = "failed";
        return -1;
    }
    else if (*username == "user" && *password == "user")
    {
        response = "failed";
        return -1;
    }
    else
    {
        response = "success " + std::to_string(5000) + " map";
        account->setBalance(5000);
        return 0;
    }
}

int Server::login(Account *account, std::string data, std::string &response)
{

    std::string *username = new std::string;
    std::string *password = new std::string;
    std::string *token = new std::string;

    std::istringstream NewData(data);
    NewData >> *token >> *username >> *password;

    account->setUsername(*username);

    std::ifstream inputFile("accounts.txt");

    accountsMutex.lock();

    if (!inputFile)
    {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }
    else
    {
        std::string *fileUsername = new std::string;
        std::string *filePassword = new std::string;
        std::string *fileBalance = new std::string;

        while (inputFile >> *fileUsername >> *filePassword >> *fileBalance)
        {
            if (*username == *fileUsername && *password == *filePassword)
            {
                response = "success " + *fileBalance + " map";
                // std::cout << "balance: " << *fileBalance << std::endl;
                account->setBalance(std::stod(*fileBalance));
                inputFile.close();
                accountsMutex.unlock();
                return 0;
            }
        }

        delete fileUsername;
        delete filePassword;
        delete fileBalance;
    }

    delete token;

    response = "failed";
    inputFile.close();
    accountsMutex.unlock();

    return -1;
}

int Server::bet(std::string data, std::string &response, Account *account)
{

    std::string *token = new std::string;
    std::string *betStr = new std::string;
    double *balance = new double;
    double *bet = new double;

    // std::cout << "username: " << account->getUsername() << std::endl;
    // std::cout << "balance: " << account->getBalance() << std::endl;

    std::istringstream NewData(data);
    NewData >> *token >> *betStr;
    delete token;

    *bet = std::stod(*betStr);
    *balance = account->getBalance();
    if (*bet > *balance)
    {
        response = "failed";
        delete balance;
        delete bet;
        return -1;
    }
    else
    {
        *balance -= *bet;
        account->setBalance(*balance);
        account->setBetAmmount(*bet);
        response = "success " + std::to_string(*balance) + " game";
        delete balance;
        delete bet;

        if (updateBalanceInFile(account->getUsername(), account->getBalance()) == -1)
        {
            std::cerr << "Error updating balance" << std::endl;
            return -1;
        }
        else
        {
            return 0;
        }

        return 0;
    }
}

int Server::updateBalanceInFile(const std::string &username, double balance)
{

    std::ifstream inputFile("accounts.txt");
    std::vector<std::string> fileData;
    bool updated = false;

    if (!inputFile)
    {
        std::cerr << "Error opening file for balance update" << std::endl;
        return -1;
    }
    else
    {
        std::string line;

        while (std::getline(inputFile, line))
        {
            std::istringstream iss(line);
            std::string fileUsername;
            std::string filePassword;
            double fileBalance;

            if (iss >> fileUsername >> filePassword >> fileBalance)
            {
                if (fileUsername == username)
                {
                    // Update the balance for the specified username
                    fileBalance = balance;
                    updated = true;
                }

                fileData.push_back(fileUsername + " " + filePassword + " " + std::to_string(fileBalance));
            }
        }

        inputFile.close();

        if (!updated)
        {
            // The username was not found in the file
            return -1;
        }

        // Write the updated data back to the file
        std::ofstream outputFile("accounts.txt");
        if (outputFile)
        {
            for (const std::string &userData : fileData)
            {
                outputFile << userData << std::endl;
            }
            outputFile.close();
        }
        else
        {
            std::cerr << "Error opening file for balance update" << std::endl;
            return -1;
        }
    }

    return 0;
}

std::string Server::BuildGameMessage(Hand dealerHand, Hand gamblerHand)
{
    std::string *message = new std::string;
    *message = "success ";
    *message = *message + dealerHand.getCards()[0].getSuit();
    *message = *message + dealerHand.getCards()[0].getRank();
    *message = *message + "," + dealerHand.getCards()[1].getSuit();
    *message = *message + dealerHand.getCards()[1].getRank();
    *message = *message + "," + std::to_string(dealerHand.getValue());
    *message = *message + " " + gamblerHand.getCards()[0].getSuit();
    *message = *message + gamblerHand.getCards()[0].getRank();
    *message = *message + "," + gamblerHand.getCards()[1].getSuit();
    *message = *message + gamblerHand.getCards()[1].getRank();
    *message = *message + "," + std::to_string(gamblerHand.getValue()) + " " + " game";

    return *message;
}