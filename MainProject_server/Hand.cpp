#include "Hand.h"

Hand::Hand() {
    this->numCards = 0;
}

int Hand::getValue() {

    int value = 0;

    for(int i = 0; i < numCards; i++) {
        
        value += this->cards[i].getValue();
    }

    if(value > 21){
        while(this->coveredAces > 0 && value > 21) {
            value -= 10;
            this->coveredAces--;
        }
    }

    this->coveredAces = this->ace;

    return value;
}

void Hand::checkAce() {

    this->ace = 0;

    for(int i = 0; i < numCards; i++) {
        if(this->cards[i].getRank() == "A") {
            this->ace++;
        }
    }
    this->coveredAces = this->ace;
}

void Hand::addCard(Card card) {
    this->cards.push_back(card);
    this->numCards++;
    checkAce();
}

bool Hand::isBust() {

    if(this->getValue() > 21) {
        return true;
    }

    return false;
}

void Hand::reset() {
    this->cards.clear();
    this->numCards = 0;
    this->ace = 0;
}

std::vector<Card> Hand::getCards() {
    return this->cards;
}

int Hand::getNumCards() {
    return this->numCards;
}