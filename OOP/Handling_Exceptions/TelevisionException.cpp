#include <iostream>
#include <string.h>

using namespace std;

//Headers
template <class T>
class TelevisionException {
    private:
        string errorMessage;
        T badValue;
        
    public:
        TelevisionException(T, string);
        void what();
};

class Television {
    friend ostream& operator<<(ostream&, const Television);
    friend istream& operator>>(istream&, Television&);

    private:
        string modelNumber;
        double screenSizeInInches;
        double price;
};

//Implementation
template <class T>
TelevisionException<T>::TelevisionException(T value, string message) {
    badValue = value;
    errorMessage = message;
}

template <class T>
void TelevisionException<T>::what() {
    cout << errorMessage << endl;
    cout << "Bad value: " << badValue << endl;
    cout << "*****************\n";
}

ostream& operator<<(ostream& out, const Television television) {
    out << "Model number: " << television.modelNumber << endl;
    out << "Screen size: " << television.screenSizeInInches << " inches" << endl;
    out << "Price: " << television.price << endl;

    return out;
}

istream& operator>>(istream& in, Television& television) {
    string stringInput;
    double doubleInput;

    //Model number input
    cout << "Model number: "; cin >> stringInput;
    if(stringInput.length() < 4) {
        TelevisionException<string> e(stringInput, "Out of range");
        throw(e);
    } else {
        television.modelNumber = stringInput;
    }

    //Screen size input
    cout << "Screen size: "; cin >> doubleInput;
    if(!(doubleInput)) {
        TelevisionException<double> e(doubleInput, "Type mismatch");
        throw(e);
    } else if(doubleInput < 12 || doubleInput > 70) {
        TelevisionException<double> e(doubleInput, "Out of range");
        throw(e);
    } else {
        television.screenSizeInInches = doubleInput;
    }

    //Price input
    cout << "Price: "; cin >> doubleInput;
    if(!(doubleInput)) {
        TelevisionException<double> e(doubleInput, "Type mismatch");
        throw(e);
    } else if(doubleInput < 0 || doubleInput > 5000) {
        TelevisionException<double> e(doubleInput, "Out of range");
        throw(e);
    } else {
        television.price = doubleInput;
    }

    return in;
}

//main
int main() {
    Television television;

    try {
        cin >> television;
    } catch(TelevisionException<int> e) {
        e.what();
        cout << "Try entering data again:\n";
        cin >> television;
    } catch(TelevisionException<string> e) {
        e.what();
        cout << "Try entering data again:\n";
        cin >> television;
    } catch(TelevisionException<double> e) {
        e.what();
        cout << "Try entering data again:\n";
        cin >> television;
    }

    cout << "\nOutput:\n" << television;
}