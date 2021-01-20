#include "Arcade.h"

bool Arcade::theNameIsTaken(string theName) {
    for(int i = 0; i < users.size(); i++) {
        if(users.at(i).getName() == theName) {
            cout << "The name is taken!\n";
            return true;
        }
    }

    return false;
}

void Arcade::guessNumber(User user) {
    RandomNumbers randomGenerator(1, 10);
    int randomNumber = randomGenerator.generateRandomNumber();
    int input;
    int score;

    cout << "\nTry to guess my number from 1 to 10: "; cin >> input;

    if(input > 10 || input < 1) {
        cout << "Incorrect input!" << endl;
        guessNumber(user);
    } else {
        score = randomNumber - input;
        if(score < 0) score *= -1;
        cout << user.getName() << " your score is " << score << endl;
        cout << "*************************" << endl;
        user.setNewScore(score);
    }

    updateLeaderBoard(user);
}

void Arcade::updateLeaderBoard(User user) {
    users.push_back(user);
    sort(users.begin(), users.end());
}

void Arcade::displayLeaderBoard() {
    cout << "All time champions so far:\n\n";
    for(int i = 0; i < users.size(); i++) {
        cout << users.at(i) << endl;
    }
}