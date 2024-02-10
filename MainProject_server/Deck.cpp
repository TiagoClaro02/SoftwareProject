#include "Deck.h"

Deck::Deck() {
    Card* card = new Card;

    for(int i=0; i < 4; i++){
        for(int j=0; j < 13; j++){
            card->setCard(blackJackSuits[i], blackjackValuePairs[j].rank, blackjackValuePairs[j].value);
            deck.push_back(*card);
        }
    }

    delete card;
}

std::vector<Card> Deck::getDeck() {
    return deck;
}

