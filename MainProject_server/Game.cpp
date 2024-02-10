#include "Game.h"

void Game::init(double betAmmount)
{

    reset();

    this->betAmmount = betAmmount;
    this->gameState = "init";

    this->shoe.reset();
    this->shoe.shuffle();

    for (int i = 0; i < 2; i++)
    {
        this->gambler.hand.addCard(shoe.drawcard());
        this->dealer.hand.addCard(shoe.drawcard());
    }

    this->isDouble = false;
}

void Game::run(std::string input)
{
    this->input = input;

    std::cout << "gambler: " << this->gambler.hand.getValue() << std::endl;

    if (input == "h")
    {
        // Player hits
        this->gambler.hand.addCard(shoe.drawcard());
        if (this->gambler.hand.isBust())
        {
            this->gameState = "dealerWin";
        }
    }
    else if (input == "s")
    {
        if (gambler.hand.getValue() < dealer.hand.getValue())
        {
            // Player stands, dealer wins
            this->gameState = "dealerWin";
        }
        else if (gambler.hand.getValue() > dealer.hand.getValue())
        {
            // Player stands, dealer must hit
            while (dealer.hand.getValue() < 17)
            {
                this->dealer.hand.addCard(shoe.drawcard());
            }
            if (dealer.hand.isBust())
            {
                this->gameState = "gamblerWin";
            }
            else if (dealer.hand.getValue() > gambler.hand.getValue())
            {
                this->gameState = "dealerWin";
            }
            else if (dealer.hand.getValue() == gambler.hand.getValue())
            {
                this->gameState = "draw";
            }
            else
            {
                this->gameState = "gamblerWin";
            }
        }
        else
        {
            // Player stands, it's a draw
            this->gameState = "draw";
        }
    }
    else if (input == "d")
    {
        // Double down
        if (!this->isDouble)
        {
            this->isDouble = true;
            this->gambler.hand.addCard(shoe.drawcard());

            if (this->gambler.hand.isBust())
            {
                this->gameState = "dealerWin";
            }
            else if (gambler.hand.getValue() < dealer.hand.getValue())
            {
                // Player stands, dealer wins
                this->gameState = "dealerWin";
            }
            else if (gambler.hand.getValue() > dealer.hand.getValue())
            {
                // Player stands, dealer must hit
                while (dealer.hand.getValue() < 17)
                {
                    this->dealer.hand.addCard(shoe.drawcard());
                }
                if (dealer.hand.isBust())
                {
                    this->gameState = "gamblerWin";
                }
                else if (dealer.hand.getValue() > gambler.hand.getValue())
                {
                    this->gameState = "dealerWin";
                }
                else if (dealer.hand.getValue() == gambler.hand.getValue())
                {
                    this->gameState = "draw";
                }
                else
                {
                    this->gameState = "gamblerWin";
                }
            }
            else
            {
                this->gameState = "draw";
            }
        }
        else
        {
            // std::cout << "You cannot double down again in the same hand." << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
    }

    std::cout << "gambler: " << this->gambler.hand.getValue() << std::endl;
}

void Game::reset()
{

    this->gambler.reset();
    this->dealer.reset();
    this->shoe.reset();
    this->gameState = "init";
    this->isDouble = false;
    this->input = "";
    this->betAmmount = 0;
}