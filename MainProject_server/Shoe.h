#pragma once
#include "Deck.h"
#include "Card.h"

#include <vector>
#include <algorithm>
#include <random>

class Shoe
{
public:

    /**
     * @brief Resets the shoe
    */
    void reset();

    /**
     * @brief Draws a card from the shoe
     * 
     * @return Card The card drawn
    */
    Card drawcard();

    /**
     * @brief Shuffles the shoe
     * 
     * @param Pile The pile to shuffle
    */
    void shuffle();

    /**
     * @brief Get the Pile object
     * 
     * @return std::vector<Card> The pile
    */
    std::vector<Card> getPile();


private:
    /**
     * @brief Vector of decks in the shoe
    */
    std::vector<Card> Pile;

};
