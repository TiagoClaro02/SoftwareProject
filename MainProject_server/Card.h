#pragma once
#include <iostream>
#include <string>
#include <vector>


class Card
{
private:
    /**
     * @brief The suit of the card
    */
    std::string suit;

    /**
     * @brief The rank of the card
    */
    std::string rank;

    /**
     * @brief The value of the card
    */
    int value;

public:

    /**
     * @brief Construct a new Card object
     * 
     * @param suit The suit of the card
     * @param rank The rank of the card
     * @param value The value of the card
    */
    int getValue();

    /**
     * @brief Returns the value of the card
     * 
     * @return string the suit of the card
    */
    std::string getSuit();

    /**
     * @brief Returns the rank of the card
     * 
     * @return string the rank of the card
    */
    std::string getRank();

    /**
     * @brief Returns the suit of the card
     * 
     * @param suit The suit of the card
     * @param rank The rank of the card
     * @param value The value of the card
     * 
    */
    void setCard(std::string suit, std::string rank, int value);
};
