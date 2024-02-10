#include "Shoe.h"

void Shoe::reset() {
    Deck* deck = new Deck;

    for(int j=0; j<4; j++){

        for(int i=0; i<52; i++){
            Pile.push_back(deck->getDeck()[i]);
        }
    }

    delete deck;

}

Card Shoe::drawcard() {

    Card card=this->Pile.back();
    this->Pile.pop_back();
    return card;
}

void Shoe::shuffle() {
    
    //shuffle the deck
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->Pile.begin(), this->Pile.end(), g);

}

std::vector<Card> Shoe::getPile() {
    return Pile;
}
