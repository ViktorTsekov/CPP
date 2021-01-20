#ifndef HAND
#define HAND

#include <iostream>
#include <string.h>

#include "PlayingCard.h"

using namespace std;

class Hand {
    private:
        PlayingCard playingCardInstance;
        PlayingCard pokerHand[5];

    public:
        void initialize();
        void generateRandomHand();
        void showHand();
        bool cardIsAlreadyInHand(PlayingCard card);
};

#endif