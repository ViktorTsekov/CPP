#include "Book.h"
#include "Fiction.h"
#include "NonFiction.h"

int main() {
    Book book;
    Fiction fictionBook;
    NonFiction nonFictionBook;

    cout << "The book: " << endl;
    book.setData();
    book.displayData();
    cout << endl;

    cout << "The fiction book: " << endl;
    fictionBook.setFictionData();
    fictionBook.displayFictionData();
    cout << endl;

    cout << "The nonfiction book: " << endl;
    nonFictionBook.setNonFictionData();
    nonFictionBook.displayNonFictionData();
    cout << endl;
}