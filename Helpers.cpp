#include <iostream>
#include <math.h>
#include <string>
#include "Helpers.h"

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

void UnsignedSuperUltraLong::ToCharArr(char* CopyToArr)
{
    sprintf(CopyToArr, "%llu%.*llu%.*llu", Upper, kMaxDigitsPerPart, Mid, kMaxDigitsPerPart, Lower);
}

UnsignedSuperUltraLong::UnsignedSuperUltraLong(const char* FromString, size_t StrLen)
{
    unsigned int CurDigitPlace = 1;
    const int kLastPlace = StrLen-1;
    unsigned long long DigitTens = 1;
    for (int i = kLastPlace; i >= 0; --i)
    {
        // Lower
        if (kLastPlace - i < kMaxDigitsPerPart)
        {
            Lower += DigitTens * (FromString[i] - '0');
        }
        // Mid
        else if (kLastPlace - i < kMaxDigitsPerPart * 2)
        {
            Mid += DigitTens * (FromString[i] - '0');
        }
        // Upper
        else if (kLastPlace - i < kMaxTotalDigits)
        {
            Upper += DigitTens * (FromString[i] - '0');
        }
        else
        {
            return;
        }
        DigitTens *= 10;
        ++CurDigitPlace;
        if (CurDigitPlace > kMaxDigitsPerPart)
        {
            CurDigitPlace = 1;
            DigitTens = 1;
        }

    }
}