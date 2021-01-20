#include "PlayingCard.h"

const int PlayingCard::maxValue = 14;
const int PlayingCard::maxDye = 4;

int PlayingCard::getValue() {
    return value;
}

char PlayingCard::getValueSymbol() {
    return valueSymbol;
}

string PlayingCard::getDye() {
    return dye;
}

void PlayingCard::generateRandomSeed() {
    srand((unsigned)time(NULL));

    for(int i = 0; i < 1000; i++) {
        randomValueNumbers[i] = rand() % (maxValue - 1) + 2;
        randomDyeNumbers[i] = rand() % maxDye + 1;
    }
}

PlayingCard PlayingCard::assignValueSymbol(PlayingCard card) {
    switch (card.value)
    {
        case 11: card.valueSymbol = 'J'; break;
        case 12: card.valueSymbol = 'Q'; break;
        case 13: card.valueSymbol = 'K'; break;
        case 14: card.valueSymbol = 'A'; break;
    }

    return card;
}

PlayingCard PlayingCard::assignSuit(PlayingCard card, int randomSuit) {
    switch (randomSuit)
    {
        case 1: card.dye = "hearts"; break;
        case 2: card.dye = "clubs"; break;
        case 3: card.dye = "diamonds"; break;
        case 4: card.dye = "spades"; break;
    }

    return card;
}

PlayingCard PlayingCard::withdrawRandomCard() {
    PlayingCard card;
    int valueIndex = rand() % 1000 + 0;
    int dyeIndex = rand() % 1000 + 0;
    int randomSuit;

    card.value = randomValueNumbers[valueIndex];
    randomSuit = randomDyeNumbers[dyeIndex];
    
    card = assignValueSymbol(card);
    card = assignSuit(card, randomSuit);

    return card;
}