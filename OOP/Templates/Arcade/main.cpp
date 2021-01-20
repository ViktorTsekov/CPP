#include "User.h"
#include "Arcade.h"

int main() {
    Arcade arcadeGame;
    string input = "";

    while(1) {
        User user;
        loop:
        cout << "Enter player name or type 'quit' to exit: "; cin >> input;
        if(input == "quit") exit(1);
        if(arcadeGame.theNameIsTaken(input)) goto loop;
        user.setUser(input);
        arcadeGame.guessNumber(user);
        arcadeGame.displayLeaderBoard();
    }

}