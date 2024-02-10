#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <iostream>
#include <fstream>
#include <mutex>

#include "network.h"
#include "Account.h"
#include "Game.h"

#define PORT 8080

class Server : public network
{
public:
    /**
     * @brief Runs the server
    */
    void run();

    
private:

    /**
     * @brief Sends a message to the client
     * 
     * @param client The client to send the message to
     * @param message The message to send
     * @param status The status of the connection
    */
    void sendMessage(sf::TcpSocket& client, std::string message, sf::Socket::Status& status);

    /**
     * @brief Handles a client
    */
    void handleClient(sf::TcpSocket& client);

    /**
     * @brief Receives a message from the client
     * 
     * @param client The client to receive the message from
     * @param status The status of the connection
     * 
     * @return The message received
    */
    std::string receiveMessage(sf::TcpSocket& client, sf::Socket::Status& status);

    /**
     * @brief Registers an account
     * 
     * @param data The data to use to register the account
     * @param response The response to send to the client
     * @param status The status of the connection
     * 
     * @return 0 if the registration was successful, -1 if the registration failed
    */
    int registerAccount(Account* account ,std::string data, std::string& response);

    /**
     * @brief Logs a user in
     * 
     * @param data The data to use to log the user in
     * @param response The response to send to the client
     * @param status The status of the connection
     * 
     * @return 0 if the login was successful, -1 if the login failed
    */
    int login(Account* account , std::string data, std::string& response);

    /**
     * @brief Handles a bet
     * 
     * @param data The data to use to handle the bet
     * @param response The response to send to the client
     * @param account The account to use to handle the bet
     * 
     * @return 0 if the bet was successful, -1 if the bet failed
    */
    int bet(std::string data, std::string& response, Account* account);

    /**
     * @brief Handles a game
    */
    Game game;

    /**
     * @brief The mutex to use to lock the accounts
    */
    std::mutex accountsMutex;

    /**
     * @brief The mutex to use to lock the games
     * 
     * @param username The username to use to update the balance
     * @param balance The balance to update the balance with
     * 
     * @return 0 if the game was successful, -1 if the game failed
    */
    int updateBalanceInFile(const std::string& username, double balance);

    std::string BuildGameMessage(Hand dealerHand, Hand gamblerHand);

    struct Config{
    std::string serverIP;
    int serverPort;
    };

    /**
     * @brief Reads the config file
     * 
     * @param filename The name of the config file
     * 
     * @return The config
    */
    Config readConfig(const std::string& filename);

};

