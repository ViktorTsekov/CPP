#include <iostream>

using namespace std;

class Test {
    public:
        void setVar(int n) {
            var = n;
        }
        
        int getVar() {
            return var;
        }

    private:
        int var;
};

int func1(Test t) {
    t.setVar(420);
    return t.getVar();
}

int func2(Test &t) {
    t.setVar(420);
    return t.getVar();
}

int func3(Test *t) {
    t->setVar(420);
    return t->getVar();
}

int main() {
    Test t1;
    Test t2;
    Test t3;

    t1.setVar(69);
    t2.setVar(69);
    t3.setVar(69);

    cout<< "From func1: "<< func1(t1)<<endl;
    cout<< "From main: "<< t1.getVar()<<endl;

    cout<< "From func2: "<< func2(t2)<<endl;
    cout<< "From main: "<< t2.getVar()<<endl;

    cout<< "From func3: "<< func3(&t3)<<endl;
    cout<< "From main: "<< t3.getVar()<<endl;
}