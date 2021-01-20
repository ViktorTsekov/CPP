#include "Hand.h"

Hand::Hand(string name) {
    pair = 0;
    threeOfAKind = 0;
    fourOfAKind = 0;
    combinationPower = 0;
    nameOfHand = name;
}

Hand Hand::operator+(Hand hand) {
    Hand winner;

    if(combinationPower > hand.combinationPower) {
        winner = *this;
    } else if(combinationPower < hand.combinationPower) {
        winner = hand;
    } else {
        winner["Draw"];
    }

    return winner;
}

Hand Hand::operator[](string name) {
    this->nameOfHand = name;

    return *this;
}

string Hand::getName() {
    return nameOfHand;
}

void Hand::generateHand(PlayingDeck deck) {
    for(int i = 0; i < 5; i++) {
        pokerHand[i] = deck.withdrawCardFromDeck();
    }

    countNumberOfPairs();
}

void Hand::showHand() {
    cout << endl;

    for(int i = 0; i < 5; i++) {
        pokerHand[i].displayCard();
    }
    
    cout << endl;
}

void Hand::countNumberOfPairs() {
    int currentValue = 2;
    int occurences = 0;

    while(currentValue != 14) {
        for(int i = 0; i < 5; i++) {
            if(currentValue == pokerHand[i].getValue()) {
                occurences++;
            }
        }

        switch (occurences) {
            case 2: pair++; combinationPower = 1; break;
            case 3: threeOfAKind++; combinationPower = 2; break;
            case 4: fourOfAKind++; combinationPower = 3; break;
        }

        currentValue++;
        occurences = 0;
    }
}