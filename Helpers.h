#ifndef HELPERS_H
#define HELPERS_H

#include <math.h>
#include <string>
#include <unordered_map>

bool IsPrime(long &num);
bool IsPrime(int &num);
bool IsPalindrome(int &num);
int GetNumOfDivisors(int &num);
unsigned long long GetCollatzSequenceLength(unsigned long long num, std::unordered_map<unsigned long long, unsigned long long>& CachedSequenceCountMap);

class UnsignedSuperUltraLong {
public:
    static const short kMaxDigitsPerPart = 19;
    static const size_t kMaxTotalDigits = kMaxDigitsPerPart * 3;
    const unsigned long long kOverflow = pow(10, kMaxDigitsPerPart);
    unsigned long long Upper = 0, Mid = 0 , Lower = 0;
    UnsignedSuperUltraLong(unsigned long long int u = 0, unsigned long long int m = 0, unsigned long long int l = 0)
    {
        if (l >= kOverflow)
        {
            l -= kOverflow;
            ++m;
        }
        if (m >= kOverflow)
        {
            m -= kOverflow;
            ++u;
        }
        Upper = u;
        Mid = m;
        Lower = l;
    }

    UnsignedSuperUltraLong (const UnsignedSuperUltraLong *ToCopy)
    {
        Upper = ToCopy->Upper;
        Mid = ToCopy->Mid;
        Lower = ToCopy->Lower;
    }

    UnsignedSuperUltraLong(const char* FromString, size_t StrLen);

    void operator= (const UnsignedSuperUltraLong & first)
    {
        Lower = first.Lower;
        Mid = first.Mid;
        Upper = first.Upper;
    }

    UnsignedSuperUltraLong operator+ (const UnsignedSuperUltraLong & first) const
    {
        UnsignedSuperUltraLong RetVal = UnsignedSuperUltraLong(this);
        const auto kHalfOverflow = kOverflow / 2;
        if (Lower >= kHalfOverflow && first.Lower >= kHalfOverflow)
        {
            ++RetVal.Mid;
            RetVal.Lower = (RetVal.Lower - kHalfOverflow) + (first.Lower - kHalfOverflow);
        }
        else
        {
            RetVal.Lower += first.Lower;
            if (RetVal.Lower >= kOverflow)
            {
                RetVal.Lower -= kOverflow;
                ++RetVal.Mid;
            }
        }
        if (Mid >= kHalfOverflow && first.Mid >= kHalfOverflow)
        {
            ++RetVal.Upper;
            RetVal.Mid = (RetVal.Mid - kHalfOverflow) + (first.Mid - kHalfOverflow);
        }
        else
        {
            RetVal.Mid += first.Mid;
            if (RetVal.Mid >= kOverflow)
            {
                RetVal.Mid -= kOverflow;
                ++RetVal.Upper;
            }
        }
        RetVal.Upper += first.Upper;
        return RetVal;
    }

    void operator+= (const UnsignedSuperUltraLong & first)
    {
        UnsignedSuperUltraLong Tmp = *this + first;
        *this = Tmp;
    }

    void ToCharArr(char* CopyToArr);
};


#endif