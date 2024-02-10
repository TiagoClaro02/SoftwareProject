#pragma once
#include "Card.h"
#include <vector>

class Hand
{
public:

    /**
     * @brief Init a hand
    */
    Hand();

    /**
     * @brief Gets the value of the hand
    */
    int getValue();

    /**
     * @brief Checks if the hand has an ace
    */
    void checkAce();

    /**
     * @brief Adds a card to the hand
    */
    void addCard(Card card);

    /**
     * @brief Checks if the hand is bust
    */
    bool isBust();


    /**
     * @brief Resets the hand
    */
    void reset();

    /**
     * @brief Gets the cards in the hand
    */
    std::vector<Card> getCards();

    /**
     * @brief Gets the number of cards in the hand
    */
    int getNumCards();

private:

    /**
     * @brief True if the hand has an ace
    */
    int ace;

    int coveredAces;

    /**
     * @brief Array of cards in the hand
    */
    std::vector<Card> cards;

    /**
     * @brief Number of cards in the hand
    */
    int numCards;

};
