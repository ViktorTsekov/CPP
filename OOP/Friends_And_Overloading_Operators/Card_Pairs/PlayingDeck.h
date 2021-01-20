#ifndef PLAYINGDECK
#define PLAYINGDECK

#include <iostream>
#include <string.h>

#include "PlayingCard.h"

class PlayingDeck {
    private:
        PlayingCard deck[52];
        PlayingCard playingCardInstance;

    protected:
        bool cardIsAlreadyInDeck(PlayingCard);

    public:
        PlayingDeck();
        void generateDeck();
        PlayingCard withdrawCardFromDeck();
};

#endif