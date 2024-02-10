#include "Account.h"

double Account::getBalance() {
    return balance;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

double Account::getBetAmmount() {
    return betAmmount;
}

void Account::setBetAmmount(double betAmmount) {
    this->betAmmount = betAmmount;
}

std::string Account::getUsername() {
    return username;
}

void Account::setUsername(std::string username) {
    this->username = username;
}