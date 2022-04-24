#include <iostream>
#include "Problems.h"
#include "Helpers.h"
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Problem1() {
    cout << "Find the sum of all the multiples of 3 or 5 below 1000." << endl;
    
    int sum = 0;

    for(int i = 3; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            cout << "Found one: " << i << endl;
            sum += i;
        }
    }

    cout << "Sum: " << sum << endl;
}

void Problem2() {
    cout << "By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms." << endl;
    
    int sum = 0;
    
    int h = 1;
    int i = 2;
    while(i <= 4000000) {
        if (i % 2 == 0) {
            sum += i;
        }
        int tmp = i + h;
        h = i;
        i = tmp;
    }

    cout << "Sum: " << sum << endl;
}

void Problem3() {
    cout << "What is the largest prime factor of the number 600851475143?" << endl;
    
    long long num = 600851475143;

    long maxFactor;
    
    for(maxFactor = floor(pow(num, 0.5)); maxFactor > 1; maxFactor--) {
        if (num % maxFactor == 0) {
            if (IsPrime(maxFactor)) break;
        }
    }

    cout << "Largest prime factor: " << maxFactor << endl;
}

void Problem4() {
    cout << "Find the largest palindrome made from the product of two 3-digit numbers." << endl;
    
    int largest = 0;
    for(int num1 = 999; num1 >= 100; num1--) {
        for(int num2 = num1; num2 >= 100; num2--) {
            int product = num1 * num2;
            if (largest >= product && num2 == num1) {
                num1 = 0;
                num2 = 0;
                break;
            }
            if (IsPalindrome(product) && product > largest) {
                largest = product;
                break;
            }
        }
    }

    cout << "Largest palindrome: " << largest << endl;
}

void Problem5() {
    cout << "What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?" << endl;
    
    int maxDivisor = 20;
    bool finding = true;
    long long smallestNum = maxDivisor * (maxDivisor - 1);
    while(finding && smallestNum < 500000000) {
        for(int i = 2; i < maxDivisor; i++) {
            if(smallestNum % i != 0) break;
            if (i == maxDivisor - 1) finding = false;
        }
        if(finding) smallestNum += maxDivisor;
    }
    
    cout << "Smallest number: " << smallestNum << endl;
}

void Problem6() {
    cout << "Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum." << endl;
    
    int maxNum = 100;
    long long sumOfSq = 0;
    int sum = 0;
    for(int i = 1; i <= maxNum; i++) {
        sum += i;
        sumOfSq += (i * i);
    }

    long long sqOfSum = (sum * sum);
    long long difference = sqOfSum - sumOfSq;
    
    cout << "Difference: " << difference << endl;
}

void Problem7() {
    cout << "What is the 10,001st prime number?" << endl;
    
    int primeToFind = 10001;
    int primesFound = 0;
    int i = 1;
    while (primesFound < primeToFind) {
        i++;
        if(IsPrime(i)) primesFound++;
    }
    
    cout << "10,001st prime: " << i << endl;
}

void Problem8() {
    cout << "Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?" << endl;
    
    string numStr = "";
    numStr += "73167176531330624919225119674426574742355349194934";
    numStr += "96983520312774506326239578318016984801869478851843";
    numStr += "85861560789112949495459501737958331952853208805511";
    numStr += "12540698747158523863050715693290963295227443043557";
    numStr += "66896648950445244523161731856403098711121722383113";
    numStr += "62229893423380308135336276614282806444486645238749";
    numStr += "30358907296290491560440772390713810515859307960866";
    numStr += "70172427121883998797908792274921901699720888093776";
    numStr += "65727333001053367881220235421809751254540594752243";
    numStr += "52584907711670556013604839586446706324415722155397";
    numStr += "53697817977846174064955149290862569321978468622482";
    numStr += "83972241375657056057490261407972968652414535100474";
    numStr += "82166370484403199890008895243450658541227588666881";
    numStr += "16427171479924442928230863465674813919123162824586";
    numStr += "17866458359124566529476545682848912883142607690042";
    numStr += "24219022671055626321111109370544217506941658960408";
    numStr += "07198403850962455444362981230987879927244284909188";
    numStr += "84580156166097919133875499200524063689912560717606";
    numStr += "05886116467109405077541002256983155200055935729725";
    numStr += "71636269561882670428252483600823257530420752963450";

    long long maxProduct = 0;
    int numIndexes = 13;
    for(int i = 0; i < numStr.length() - (numIndexes - 1); i++){
        long long product = stoi(numStr.substr(i, 1)); 
        for(int j = i + 1; j < i + numIndexes; j++) {
            product *= stoi(numStr.substr(j, 1));
        }
        if (product > maxProduct) maxProduct = product;
    }
    
    
    cout << "Max product: " << maxProduct << endl;
}

void Problem9() {
    cout << "There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc." << endl;
    
    int pySum = 1000;
    long pyProduct = 0;

    for(int a = 1; a < pySum; a++) {
        int aa = a * a;
        for(int b = a + 1; b < pySum; b++) {
            int bb = b * b;
            if (a + b >= pySum) break;
            for(int c = b + 1; c < pySum; c++) {
                int sum = a + b + c;
                if (sum > pySum) break;
                if (sum == pySum) {
                    if(aa + bb == c * c) {
                        pyProduct = a * b * c;
                        break;
                    }
                }
            }
            if(pyProduct != 0) break;
        }
        if(pyProduct != 0) break;
    }
    
    cout << "Product: " << pyProduct << endl;
}

void Problem10() {
    cout << "Find the sum of all the primes below two million." << endl;
    
    int max = 2000000;
    long long sum = 0;
    
    for(int i = 2; i < max; i++) {
        if(IsPrime(i)) sum += i;
    }
    
    cout << "Sum: " << sum << endl;
}

void Problem11() {
    cout << "What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20x20 grid?" << endl;
    
    long maxProduct = 0;
    int numOfNums = 4;
    vector<vector<int>> grid;
    grid.reserve(20);
    grid.push_back({8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8});
    grid.push_back({49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0});
    grid.push_back({81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65});
    grid.push_back({52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91});
    grid.push_back({22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80});
    grid.push_back({24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50});
    grid.push_back({32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70});
    grid.push_back({67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21});
    grid.push_back({24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72});
    grid.push_back({21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95});
    grid.push_back({78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92});
    grid.push_back({16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57});
    grid.push_back({86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58});
    grid.push_back({19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40});
    grid.push_back({4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66});
    grid.push_back({88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69});
    grid.push_back({4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36});
    grid.push_back({20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16});
    grid.push_back({20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54});
    grid.push_back({1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48});

    for(int y = 0; y < grid.capacity(); y++) {
        vector<int>& rowRef = grid.at(y);
        bool canNorth = (y >= numOfNums);
        bool canSouth = (y + (numOfNums - 1) < grid.capacity());
        for(int x = 0; x < rowRef.capacity(); x++) {
            bool canEast = (x + (numOfNums - 1) < rowRef.capacity());
            long nProd = rowRef.at(x);
            long neProd = nProd;
            long eProd = nProd;
            long seProd = nProd;
            for(int mod = 1; mod < numOfNums; mod++) {
                //Check N Adjacent
                if(canNorth) nProd *= grid.at(y - mod).at(x);
                //Check NE Adjacent
                if(canNorth && canEast) neProd *= grid.at(y - mod).at(x + mod);
                //Check E Adjacent
                if(canEast) eProd *= grid.at(y).at(x + mod);
                //Check SE Adjacent
                if(canSouth && canEast) seProd *= grid.at(y + mod).at(x + mod);

            }
            if (nProd > maxProduct) maxProduct = nProd;
            if (neProd > maxProduct) maxProduct = neProd;
            if (eProd > maxProduct) maxProduct = eProd;
            if (seProd > maxProduct) maxProduct = seProd;
        }
    }
    
    cout << "Max product: " << maxProduct << endl;
}

void Problem12() {
    cout << "What is the value of the first triangle number to have over five hundred divisors?" << endl;
    
    int triNum = 0;
    int i = 1;
    int maxDivisors = 500;
    bool searching = true;
    
    while(searching) {
        triNum += i;
        int numDivisors = GetNumOfDivisors(triNum);
        if(numDivisors > maxDivisors) {
            searching = false;
            break;
        }
        i++;
    }
    
    cout << "Triangle number: " << triNum << endl;
}