#include "Book.h"

void Book::setData() {
    cout << "Set title: "; cin >> title;
    cout << "Set author: "; cin >> author;
}

void Book::displayData() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
}