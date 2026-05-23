#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>

using namespace std;
class SuperUltraLong;

bool IsPrime(long &num);
bool IsPrime(int &num);
bool IsPalindrome(int &num);
int GetNumOfDivisors(int &num);
unsigned long long GetCollatzSequenceLength(unsigned long long num, std::unordered_map<unsigned long long, unsigned long long>& CachedSequenceCountMap);
unsigned long long GetTotalRoutesForGrid(unsigned int Width, unsigned int x, unsigned int y);
unsigned long long Factorial(unsigned int num);
void ToCharArr(const SuperUltraLong & SUL, char* CopyToArr);

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

    void operator= (const unsigned long long & first)
    {
        Lower = first;
        Mid = 0;
        Upper = 0;
        if (Lower >= kOverflow)
        {
            ++Mid;
            Lower -= kOverflow;
        }
    }

    UnsignedSuperUltraLong operator+ (const UnsignedSuperUltraLong first) const
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

    UnsignedSuperUltraLong operator- (const UnsignedSuperUltraLong first) const
    {
        UnsignedSuperUltraLong RetVal = UnsignedSuperUltraLong(this);
        if (*this > first)
        {
            RetVal.Upper = Upper - first.Upper;
            if (Mid < first.Mid)
            {
                --RetVal.Upper;
                RetVal.Mid = kOverflow - (Mid - first.Mid);
            }
            else
            {
                RetVal.Mid = Mid - first.Mid;
            }
            if (Lower < first.Lower)
            {
                --RetVal.Mid;
                RetVal.Lower = kOverflow - (Lower - first.Lower);
            }
            else
            {
                RetVal.Lower = Lower - first.Lower;
            }
        }
        return RetVal;
    }

    UnsignedSuperUltraLong operator* (const unsigned int & first) const
    {
        UnsignedSuperUltraLong RetVal = UnsignedSuperUltraLong(this);
        cout << "Multiplying an UnsignedSuperUltraLong by " << first << endl;
        for (int i = 1; i <= first; ++i){
            //cout << "i=" << i << endl;
            RetVal = RetVal + RetVal;
        }
        return RetVal;
    }

    bool operator> (const UnsignedSuperUltraLong & first) const
    {
        if (Upper != first.Upper)
        {
            return Upper > first.Upper;
        }
        else if (Mid != first.Mid)
        {
            return Mid > first.Mid;
        }
        else
        {
            return Lower > first.Lower;
        }
    }

    bool operator< (const UnsignedSuperUltraLong & first) const
    {
        return !(*this > first);
    }

    bool operator== (const UnsignedSuperUltraLong & first) const
    {
        return (Upper == first.Upper && Mid == first.Mid && Lower == first.Lower);
    }

    bool operator== (const unsigned long long & first) const
    {
        return (Upper == 0 && Mid == 0 && Lower == first);
    }

    void operator+= (const UnsignedSuperUltraLong first)
    {
        UnsignedSuperUltraLong Tmp = *this + first;
        *this = Tmp;
    }

    void ToCharArr(char* CopyToArr);
    void MultiplyBy(unsigned int Multiplier);
    void DivideByTen();
};

class SuperUltraLong {
public:
    static const size_t kMaxTotalInts = 256;
    bool isNegative = false;
    signed short IntArray[kMaxTotalInts] = { 0 };

    SuperUltraLong () {};

    SuperUltraLong(const signed short* IntArrayIn, const size_t IntArrayLen = kMaxTotalInts, bool isNegativeIn = false)
    {
        IntArray[kMaxTotalInts] = { 0 };
        isNegative = isNegativeIn;
        for (int i = 0; i < IntArrayLen; ++i)
        {
            IntArray[i] = IntArrayIn[i];
        }
    }

    SuperUltraLong (const SuperUltraLong *ToCopy)
    {
        isNegative = ToCopy->isNegative;
        for (int i = 0; i < kMaxTotalInts; ++i)
        {
            IntArray[i] = ToCopy->IntArray[i];
        }
    }

    SuperUltraLong(const char* FromString, size_t StrLen);

    SuperUltraLong(const long long & first)
    {
        isNegative = (first < 0);
        long long AbsVal = (first < 0) ? -first : first;
        for (int i = 0; i < kMaxTotalInts; ++i)
        {
            IntArray[i] = AbsVal % 10;
            AbsVal /= 10;
        }
    }

    void operator= (const SuperUltraLong & first)
    {
        isNegative = first.isNegative;
        for (int i = 0; i < kMaxTotalInts; ++i)
        {
            IntArray[i] = first.IntArray[i];
        }
    }

    SuperUltraLong operator+ (const SuperUltraLong &first) const
    {
        SuperUltraLong RetVal = SuperUltraLong();
        if (isNegative == first.isNegative)
        {
            RetVal.isNegative = isNegative;
            bool carry = false;
            for (int i = 0; i < kMaxTotalInts; ++i)
            {
                RetVal.IntArray[i] = IntArray[i] + first.IntArray[i] + carry;
                if (RetVal.IntArray[i] >= 10)
                {
                    RetVal.IntArray[i] -= 10;
                    carry = true;
                }
                else
                {
                    carry = false;
                }
            }
        }
        else
        {
            SuperUltraLong RealFirst = SuperUltraLong(this);
            const SuperUltraLong* RealSecond = &first;
            if (first > *this)
            {
                RealFirst = first;
                RealSecond = this;
            }
            RetVal.isNegative = RealFirst.isNegative;
            for (int i = 0; i < kMaxTotalInts; ++i)
            {
                if (RealFirst.IntArray[i] >= RealSecond->IntArray[i])
                {
                    RetVal.IntArray[i] = RealFirst.IntArray[i] - RealSecond->IntArray[i];
                }
                else
                {
                    RetVal.IntArray[i] = (RealFirst.IntArray[i] + 10) - RealSecond->IntArray[i];
                    int j = i + 1;
                    while (j < kMaxTotalInts)
                    {
                        if (RealFirst.IntArray[j] > 0)
                        {
                            --RealFirst.IntArray[j];
                            break;
                        }
                        else
                        {
                            RealFirst.IntArray[j] = 9;
                        }
                        ++j;
                    }
                }
            }
        }
        return RetVal;
    }

    SuperUltraLong operator- (const SuperUltraLong &first) const
    {
        SuperUltraLong RetVal = SuperUltraLong(first);
        RetVal.isNegative = !isNegative;
        return *this + RetVal;
    }

    SuperUltraLong operator* (const SuperUltraLong & first) const
    {
        SuperUltraLong RetVal = SuperUltraLong();
        if (first.IntArray[0] > 0)
        {
            RetVal = SuperUltraLong(this) * first.IntArray[0];
        }
        for (int i = 1; i < kMaxTotalInts-1; ++i)
        {
            if (first.IntArray[i] > 0)
            {
                SuperUltraLong Tmp = SuperUltraLong(this);
                Tmp.ShiftLeft(i);
                Tmp = Tmp * first.IntArray[i];
                RetVal += Tmp;
            }
        }
        if (isNegative != first.isNegative)
        {
            RetVal.isNegative = true;
        }
        return RetVal;
    }

    SuperUltraLong operator* (const unsigned int & first) const
    {
        unsigned short CarryAmt = 0;
        SuperUltraLong RetVal = SuperUltraLong();
        for (int i = 0; i < kMaxTotalInts; ++i) 
        {
            RetVal.IntArray[i] = (IntArray[i] * first) + CarryAmt;
            if (RetVal.IntArray[i] >= 10)
            {
                CarryAmt = RetVal.IntArray[i] / 10;
                RetVal.IntArray[i] %= 10;
            }
            else
            {
                CarryAmt = 0;
            }
        }
        return RetVal;
    }

    SuperUltraLong operator/ (const SuperUltraLong & first) const
    {
        unsigned int FirstLen = 0;
        SuperUltraLong RetVal = SuperUltraLong();
        for (int i = kMaxTotalInts-1; i >= 0; --i)
        {
            if (first.IntArray[i] > 0)
            {
                FirstLen = i + 1;
                break;
            }
        }
        bool FoundFirstOne = false;
        int CurMostSignificantBitNum = kMaxTotalInts - 1;
        SuperUltraLong TmpNum = SuperUltraLong();
        while (CurMostSignificantBitNum >= 0)
        {
            if (!FoundFirstOne)
            {
                if (IntArray[CurMostSignificantBitNum])
                {
                    FoundFirstOne = true;
                }
                else
                {
                    --CurMostSignificantBitNum;
                    continue;
                }
            }
            TmpNum.ShiftLeft();
            TmpNum.IntArray[0] = IntArray[CurMostSignificantBitNum];
            if (TmpNum >= first)
            {
                TmpNum = TmpNum - first;
                RetVal.IntArray[CurMostSignificantBitNum] = 1;
                while (TmpNum >= first)
                {
                    TmpNum = TmpNum - first;
                    ++RetVal.IntArray[CurMostSignificantBitNum];
                }
            }
            --CurMostSignificantBitNum;
        }
        if (isNegative != first.isNegative)
        {
            RetVal.isNegative = true;
        }
        return RetVal;
    }

    bool operator>= (const SuperUltraLong & first) const
    {
        return (*this > first || *this == first);
    }

    bool operator> (const SuperUltraLong & first) const
    {
        for (int i = kMaxTotalInts - 1; i >= 0; --i)
        {
            if (IntArray[i] != first.IntArray[i])
            {
                return IntArray[i] > first.IntArray[i];
            }
        }
        return false;
    }

    bool operator< (const SuperUltraLong & first) const
    {
        return !(*this > first);
    }

    bool operator== (const SuperUltraLong & first) const
    {
        if (isNegative != first.isNegative) return false;
        for (int i = 0; i < kMaxTotalInts; ++i)
        {
            if (IntArray[i] != first.IntArray[i])
            {
                return false;
            }
        }
        return true;
    }

    void operator+= (const SuperUltraLong first)
    {
        SuperUltraLong Tmp = *this + first;
        *this = Tmp;
    }

    void ShiftRight(unsigned short NumShifts = 1)
    {
        for (int i = 0; i < kMaxTotalInts - 1; ++i)
        {
            IntArray[i] = IntArray[i + NumShifts];
        }
        for (int i = kMaxTotalInts - NumShifts; i < kMaxTotalInts; ++i)
        {
            IntArray[i] = 0;
        }
    }

    void ShiftLeft(unsigned short NumShifts = 1)
    {
        for (int i = kMaxTotalInts - NumShifts - 1; i >= 0; --i)
        {
            IntArray[i + NumShifts] = IntArray[i];
        }
        for (int i = 0; i < NumShifts; ++i)
        {
            IntArray[i] = 0;
        }
    }



};




#endif