#include <iostream>
#include <string.h>

using namespace std;

enum Values {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
enum Suits {CLUBS, DIAMONDS, HEARTS, SPADES};

void generateDeck() {
    for(int i = TWO; i <= ACE; i++) {
        for(int j = CLUBS; j <= SPADES; j++) {
            switch (i + 1) {
                case 1: cout << "Two of "; break;
                case 2: cout << "Three of "; break;
                case 3: cout << "Four of "; break;
                case 4: cout << "Five of "; break;
                case 5: cout << "Six of "; break;
                case 6: cout << "Seven of "; break;
                case 7: cout << "Eight of "; break;
                case 8: cout << "Nine of "; break;
                case 9: cout << "Ten of "; break;
                case 10: cout << "Jack of "; break;
                case 11: cout << "Queen of "; break;
                case 12: cout << "King of "; break;
                case 13: cout << "Ace of "; break;
            }

            switch (j) {
                case 0: cout << "Clubs\n"; break;
                case 1: cout << "Diamonds\n"; break;
                case 2: cout << "Hearts\n"; break;
                case 3: cout << "Spades\n"; break;
            }
        }
    }
}

int main() {
    generateDeck();
}