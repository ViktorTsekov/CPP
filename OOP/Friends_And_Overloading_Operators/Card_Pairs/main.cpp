#include "PlayingDeck.h"
#include "Hand.h"

int main() {
    PlayingDeck deck;
    Hand playerHand("Player");
    Hand computerHand("Computer");
    Hand winnerHand;
    
    deck.generateDeck();
    
    cout << "Player Hand:";
    playerHand.generateHand(deck);
    playerHand.showHand();

    cout << "Computer Hand:";
    computerHand.generateHand(deck);
    computerHand.showHand();

    winnerHand = playerHand + computerHand;
    cout << "Winner: " << winnerHand.getName() << endl;
}