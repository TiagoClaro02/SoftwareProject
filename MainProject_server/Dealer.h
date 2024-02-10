#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Hand.h"

class Dealer
{
public:
    /**
     * @brief The dealer hits
     * 
    */
    void hit();

    /**
     * @brief The dealer stands
     * 
    */
    void stand();

    /**
     * @brief Resets the dealer's hand
     * 
    */
    void reset();

    /**
     * @brief The dealer's hand
     * 
    */
    Hand hand;

};
