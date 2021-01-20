#ifndef PLAYINGCARD
#define PLAYINGCARD

#include <iostream>
#include <string.h>

using namespace std;

class PlayingCard {
    private:
        int randomValueNumbers[1000];
        int randomDyeNumbers[1000];

        int value;
        string dye;
        char valueSymbol;

    protected:
        const static int maxValue;
        const static int maxDye;

        PlayingCard assignValueSymbol(PlayingCard card);
        PlayingCard assignSuit(PlayingCard card, int randomSuit);

    public:
        int getValue();
        char getValueSymbol();
        string getDye();
        void generateRandomSeed();
        PlayingCard withdrawRandomCard();
};

#endif
