#include "Dog.h"
#include "RandomNumbers.h"

ostream& operator<<(ostream& out, const Dog& dog) {
    out << "Breed: " << dog.breed << endl;
    out << "Eye color: " << dog.eyeColor << endl;
    out << endl;

    return out;
}

istream& operator>>(istream& in, Dog& dog) {
    cout << endl;
    cout << "Enter breed: "; in >> dog.breed;
    cout << "Enter eye color: "; in >> dog.eyeColor;

    return in;
}

Dog Dog::operator*(Dog& dog) {
    Dog temp;
    RandomNumbers randomSelector(0, 1);
    
    if(this->breed == dog.breed) {
        temp.breed = dog.breed;
    } else {
        temp.breed = "Mixed";
    }

    switch(randomSelector.generateRandomNumber()) {
        case 0: temp.eyeColor = this->eyeColor; break;
        case 1: temp.eyeColor = dog.eyeColor; break;
    }

    return temp;
}