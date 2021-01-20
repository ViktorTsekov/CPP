#include "PlayingDeck.h" 

PlayingDeck::PlayingDeck() {
    playingCardInstance.generateRandomSeed();
}

void PlayingDeck::generateDeck() {
    PlayingCard card;

    for(int i = 0; i < 52; i++) {
        card = playingCardInstance.withdrawRandomCard();

        while(cardIsAlreadyInDeck(card)) {
            card = playingCardInstance.withdrawRandomCard();
        }

        deck[i] = card;
    }
}

bool PlayingDeck::cardIsAlreadyInDeck(PlayingCard card) {
    for(int i = 0; i < 52; i++) {
        if(deck[i].getValue() == card.getValue() && deck[i].getDye().compare(card.getDye()) == 0) {
            return true;
        }
    }

    return false;
}

PlayingCard PlayingDeck::withdrawCardFromDeck() {
    static int index = 0;
    PlayingCard card = deck[index];
    index++;
    return card;
}