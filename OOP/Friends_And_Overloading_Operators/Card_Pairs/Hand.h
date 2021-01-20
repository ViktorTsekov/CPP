#ifndef HAND
#define HAND

#include <iostream>
#include <string.h>

#include "PlayingCard.h"
#include "PlayingDeck.h"

using namespace std;

class Hand {
    private:
        PlayingCard pokerHand[5];
        
        int pair;
        int threeOfAKind;
        int fourOfAKind;
        int combinationPower;
        string nameOfHand;

    protected:
        void countNumberOfPairs();

    public:
        Hand(string = "");
        Hand operator+(Hand);
        Hand operator[](string);
        string getName();
        void generateHand(PlayingDeck);
        void showHand();
};

#endif