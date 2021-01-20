#ifndef ARCADE
#define ARCADE

#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h> 

#include "RandomNumbers.h"
#include "User.h"

using namespace std;

class Arcade {
    private:
        vector<User> users;

    protected:
        void updateLeaderBoard(User);

    public:
        bool theNameIsTaken(string);
        void guessNumber(User);
        void displayLeaderBoard();
};

#endif