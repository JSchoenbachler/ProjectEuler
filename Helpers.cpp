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

unsigned long long GetCollatzSequenceLength(unsigned long long num, unordered_map<unsigned long long, unsigned long long>& CachedSequenceCountMap)
{
    auto it = CachedSequenceCountMap.find(num);
    if (it == CachedSequenceCountMap.end())
    {
        if (num % 2 == 0)
        {
            CachedSequenceCountMap[num] = 1 + GetCollatzSequenceLength(num / 2, CachedSequenceCountMap);
        }
        else
        {
            CachedSequenceCountMap[num] = 1 + GetCollatzSequenceLength((num * 3) + 1, CachedSequenceCountMap);
        }
    }
    return CachedSequenceCountMap[num];
}

unsigned long long GetTotalRoutesForGrid(unsigned int Width, unsigned int x, unsigned int y)
{
    if (x == Width && y == Width)
    {
        return 0;
    }
    else if (x == Width)
    {
        return 1;
    }
    else if (y == Width)
    {
        return 1;
    }
    else
    {
        return GetTotalRoutesForGrid(Width, x + 1, y) + GetTotalRoutesForGrid(Width, x, y + 1);
    }
}

unsigned long long Factorial(unsigned int num)
{
    unsigned long long RetVal = 1;
    for (int i = 1; i <= num; ++i)
    {
        RetVal *= i;
    }
    return RetVal;
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