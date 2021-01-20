#ifndef USER
#define USER

#include <iostream>
#include <string.h>

using namespace std;

class User {
    friend ostream& operator<<(ostream&, const User&);

    private:
        int score;
        string name;
    
    public:
        bool operator<(User);
        void setUser(string);
        void setNewScore(int);
        string getName();
        int getScore();
};

#endif