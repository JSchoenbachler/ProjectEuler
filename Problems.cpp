#include <iostream>
#include "Problems.h"
#include "Helpers.h"
#include <math.h>
#include <string>

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