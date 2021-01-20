#ifndef CALCULATE
#define CALCULATE

using namespace std;

class CalculateDistance {
    public:
        template <class T>
            int calculateDistance(T, T);
};

template <class T>
int CalculateDistance::calculateDistance(T objA, T objB) {
    return objA + objB;
}

#endif