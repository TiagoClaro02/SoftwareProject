#include "Card.h"

int Card::getValue() {
    return value;
}

void Card::setCard(std::string suit, std::string rank, int value) {
    this->suit = suit;
    this->rank = rank;
    this->value = value;
}

std::string Card::getSuit() {
    return this->suit;
}

std::string Card::getRank() {
    return this->rank;
}