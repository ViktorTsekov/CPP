#include "Hand.h"

void Hand::initialize() {
    playingCardInstance.generateRandomSeed();
}

void Hand::generateRandomHand() {
    PlayingCard card;

    for(int i = 0; i < 5; i++) {
        card = playingCardInstance.withdrawRandomCard();

        while(cardIsAlreadyInHand(card)) {
            card = playingCardInstance.withdrawRandomCard();
        }

        pokerHand[i] = card;
    }

}

void Hand::showHand() {
    cout << "Hand:" << endl;

    for(int i = 0; i < 5; i++) {

        if(pokerHand[i].getValue() > 10) {
            cout << pokerHand[i].getValueSymbol() << " of " << pokerHand[i].getDye() << endl; 
        } else {
            cout << pokerHand[i].getValue() << " of " << pokerHand[i].getDye() << endl; 
        }

    }

}

bool Hand::cardIsAlreadyInHand(PlayingCard card) {
    for(int i = 0; i < 5; i++) {
        if(pokerHand[i].getValue() == card.getValue() && pokerHand[i].getDye().compare(card.getDye()) == 0) {
            return true;
        }
    }

    return false;
}