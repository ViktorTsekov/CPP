#ifndef AVERAGE
#define AVERAGE

using namespace std;

class Average {
    public:
        template <class T>
            double calcAverage(T, T);
        template <class T>
            double calcAverage(T, T, T);
};

template <class T>
double Average::calcAverage(T argA, T argB) {
    return (argA + argB) / 2;
}

template <class T>
double Average::calcAverage(T argA, T argB, T argC) {
    return (argA + argB + argC) / 3;
}

#endif