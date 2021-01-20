#include <iostream>
#include <string.h>

using namespace std;

class Movie {
    private:
        string title;
        string name;
        int year;
    
    public:
        void setTitle(string);
        void setDirector(string);
        void setYear(int);
        void display();
};

void Movie::setTitle(string aTitle) {
    title = aTitle;
}

void Movie::setDirector(string aDirector) {
    name = aDirector;
}

void Movie::setYear(int aYear) {
    year = aYear;
}

void Movie::display() {
    cout<<"Title: "<< title<< endl;
    cout<<"Name: "<< name<< endl;
    cout<<"Year: "<< year<< endl;
}

int main() {
    Movie myFavoriteMovie;

    myFavoriteMovie.setTitle("Harry Potter");
    myFavoriteMovie.setDirector("Steven");
    myFavoriteMovie.setYear(2002);
    myFavoriteMovie.display();
}