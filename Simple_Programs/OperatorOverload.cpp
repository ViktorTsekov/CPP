#include <iostream>

using namespace std;

class Number {
    public:
        void setNum(int n) {
            num = n;
        }

        int getNum(void) {
            return num;
        }

        //Overload the + operator to add two Number objects
        Number operator+(const Number& n) {
            Number num;
            num.num = this->num + n.num + 1;
            return num;
        }

    private:
        int num;
};

int main() {
    Number num1;
    Number num2;
    Number num3;

    num1.setNum(5);
    num2.setNum(4);

    num3 = num1 + num2;

    cout<< num3.getNum();
}