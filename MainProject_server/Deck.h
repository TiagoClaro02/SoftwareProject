#pragma once
#include "Card.h"
#include <vector>
#include <iostream>
#include <map>
#include <string>



class Deck
{
public:
    /**
     * @brief Construct a new Deck object
    */
    Deck();

    /**
     * @brief Get the Deck object
     * 
     * @return std::vector<Card> The deck
    */
    std::vector<Card> getDeck();

private:

    /**
     * @brief The array of cards in the deck
    */
    std::vector<Card> deck;

    /**
     * @brief The array of suits in a deck of cards
    */
    std::string blackJackSuits[4] = { "S", "D", "C", "H"};

    /**
     * @brief The array of value pairs in a deck of cards
    */
    typedef struct{
        std::string rank;
        int value;
    } valuePairs;


    /**
     * @brief The array of value pairs in a deck of cards
    */
    valuePairs blackjackValuePairs[13] = {
        {"A", 11},
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"8", 8},
        {"9", 9},
        {"10", 10},
        {"J", 10},
        {"Q", 10},
        {"K", 10}
    };
};