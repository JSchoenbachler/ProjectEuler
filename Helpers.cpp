#include <math.h>
#include <string>

using namespace std;

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

bool IsPalindrome(int &num) {
    string numStr = to_string(num);
    int len = numStr.length();
    int maxIdx = floor(len / 2);
    for (int i = 0; i < maxIdx; i++) {
        if (numStr.at(i) != numStr.at(len - (1 + i))) return false;
    }
    return true;
}

int GetNumOfDivisors(int &num) {
    int sqrt = floor(pow(num, 0.5));

    int numDivisors = 0;
    for(int i = 1; i <= sqrt; i++) {
        if (num % i == 0) {
            numDivisors += (i != sqrt ? 2 : 1);
        }
    }

    return numDivisors;
}