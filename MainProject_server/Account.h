#pragma once

#include <iostream>

class Account
{
public:
    /**
     *  @brief Returns the balance of the account
     * 
    */
    double getBalance();

    /**
     * @brief Sets the balance of the account
     * 
     * @param balance The balance of the account
    */
    void setBalance(double balance);

    /**
     * @brief Returns the bet ammount
     * 
     * @return double The bet ammount
    */
    double getBetAmmount();

    /**
     * @brief Sets the bet ammount
     * 
     * @param betAmmount The bet ammount
    */
    void setBetAmmount(double betAmmount);

    /**
     * @brief The username of the account
     * 
     * @return std::string The username of the account
    */
    std::string getUsername();

    /**
     * @brief Sets the username of the account
     * 
     * @param username The username of the account
    */
    void setUsername(std::string username);

private:
    /**
     * @brief The balance of the account
     * 
    */
    double balance;

    /**
     * @brief The bet ammount
     * 
    */
    double betAmmount;

    /**
     * @brief The username of the account
     * 
    */
    std::string username;
};
