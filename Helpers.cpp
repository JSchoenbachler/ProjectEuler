#include <math.h>

bool IsPrime(long &num) {
    long sqrt = floor(pow(num, 0.5));
    long i = 2;

    while (i <= sqrt) {
        if (num % i == 0) return false;
        i++;
    }

    return true;
}

bool IsPrime(int &num) {
    long numLong = (long) num;
    return IsPrime(numLong);
}