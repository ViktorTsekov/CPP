#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

//Headers
class Die {
    private:
        int randomNumbers[1000];

    protected:
        const static int maxDieValue;

        int rollDice();

    public:
        void generateRandomSeed();
};

class TwentyOne : public Die {
    private:
        int playerCurrentScore;
        int computerCurrentScore;
        bool playerFinished;
        bool computerFinished;

    public:
        void rollPlayerDice();
        void rollComputerDice();
        void displayResult();
        bool theGameFinished();
        void determineWinner();
} twentyOne;

//Die implementation
const int Die::maxDieValue = 6;

void Die::generateRandomSeed() {
    srand((unsigned)time(NULL));

    for(int i = 0; i < 1000; i++) {
        randomNumbers[i] = rand() % maxDieValue + 1;
    }
}

int Die::rollDice() {
    int i = rand() % 1000 + 0;
    return randomNumbers[i];
}

//TwentyOne implementation
void TwentyOne::rollPlayerDice() {
    int val;
    char input;

    cout<<endl;

    if(!playerFinished) {
        cout<< "Do you wish to roll the dice?\n";
        cout<< "Press Q to quit and R to roll: "; cin>>input;

        if (input == 'Q' || input == 'q') {
            playerFinished = true;
        } else if(input == 'R' || input == 'r') {
            val = twentyOne.rollDice();
            cout<<"You rolled: " <<val <<endl;
            playerCurrentScore += val;
        } else {
            cout<<"Invalid input!\n";
            rollPlayerDice();
        }
    } else {
        cout<<"Player stopped rolling!\n";
    }
}

void TwentyOne::rollComputerDice() {
    int val;

    if(computerCurrentScore >= 19) {
        cout<<"Computer stopped rolling!\n";
        computerFinished = true;
    } else {
        val = twentyOne.rollDice();
        cout<<"The computer rolled: "<<val <<endl;
        computerCurrentScore += val;
    }
}

void TwentyOne::displayResult() {
    cout<<"Player score: " <<playerCurrentScore <<endl;
    cout<<"Computer score: " <<computerCurrentScore <<endl; 
}

bool TwentyOne::theGameFinished() { 
    if(playerFinished && computerFinished) {
        return true;
    } else if(playerCurrentScore > 21) {
        return true;
    } else if(computerCurrentScore > 21) {
        return true;
    }

    return false;
}

void TwentyOne::determineWinner() {
    cout<<endl;

    if(playerCurrentScore > 21) {
        cout<< "Computer won!\n";
    } else if(computerCurrentScore > 21) {
        cout<< "Player won!\n";
    } else if(playerCurrentScore == computerCurrentScore) {
        cout<< "Draw!\n";
    } else {
        if(computerCurrentScore > playerCurrentScore) {
            cout<< "Computer won!\n";
        } else if(computerCurrentScore < playerCurrentScore) {
            cout<< "Player won!\n";
        }
    }

}

int main() {
    twentyOne.generateRandomSeed();

    do {
        twentyOne.rollPlayerDice();
        twentyOne.rollComputerDice();
        twentyOne.displayResult();
    } while(!twentyOne.theGameFinished());

    twentyOne.determineWinner();
}