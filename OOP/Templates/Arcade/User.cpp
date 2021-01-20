#include "User.h"

ostream& operator<<(ostream& out, const User& user) {
    out << user.score << " " << user.name << endl;

    return out;
}

bool User::operator<(User user) {
    return (this->score < user.score);
}

void User::setUser(string userName) {
    this->name = userName;
}

void User::setNewScore(int score) {
    this->score = score;
}

string User::getName() {
    return name;
}

int User::getScore() {
    return score;
}