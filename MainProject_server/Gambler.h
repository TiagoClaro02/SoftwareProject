#pragma once
#include "Hand.h"

class Gambler
{
public:
    /**
     * @brief The gambler hits
    */
    void hit();

    /**
     * @brief The gambler stands
    */
    void stand();

    /**
     * @brief The gambler doubles down
    */
    void doubl();

    /**
     * @brief The gambler insurances
    */
    void insurance();

    void reset();

    /**
     * @brief The gambler's hand
    */
    Hand hand;
};
