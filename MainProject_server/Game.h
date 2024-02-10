#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Shoe.h"
#include "Dealer.h"
#include "Gambler.h"

class Game
{
public:

    /**
     * @brief Init a game
     * 
     * @param betAmmount The bet ammount
    */
    void init(double betAmmount);

    Gambler gambler;
    Dealer dealer;
    Shoe shoe;

    /**
     * @brief The game state
    */
    std::string gameState;

    std::string input;

    /**
     * @brief Runs the game
     * 
     * @param input The input to use
    */
    void run(std::string input);

    bool isDouble;

    /**
     * @brief The bet ammount
    */
    double betAmmount;

private:

    void reset();

};
