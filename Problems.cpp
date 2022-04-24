#include <iostream>
#include "Problems.h"
#include "Helpers.h"
#include <math.h>
#include <string>

void Problem1() {
    std::cout << "Find the sum of all the multiples of 3 or 5 below 1000." << std::endl;
    
    int sum = 0;

    for(int i = 3; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            std::cout << "Found one: " << i << std::endl;
            sum += i;
        }
    }

    std::cout << "Sum: " << sum << std::endl;
}

void Problem2() {
    std::cout << "By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms." << std::endl;
    
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

    std::cout << "Sum: " << sum << std::endl;
}

void Problem3() {
    std::cout << "What is the largest prime factor of the number 600851475143?" << std::endl;
    
    long long num = 600851475143;

    long maxFactor;
    
    for(maxFactor = floor(pow(num, 0.5)); maxFactor > 1; maxFactor--) {
        if (num % maxFactor == 0) {
            if (IsPrime(maxFactor)) break;
        }
    }

    std::cout << "Largest prime factor: " << maxFactor << std::endl;
}

void Problem4() {
    std::cout << "Find the largest palindrome made from the product of two 3-digit numbers." << std::endl;
    
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

    std::cout << "Largest palindrome: " << largest << std::endl;
}

void Problem5() {
    std::cout << "What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?" << std::endl;
    
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
    
    std::cout << "Smallest number: " << smallestNum << std::endl;
}

void Problem6() {
    std::cout << "Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum." << std::endl;
    
    int maxNum = 100;
    long long sumOfSq = 0;
    int sum = 0;
    for(int i = 1; i <= maxNum; i++) {
        sum += i;
        sumOfSq += (i * i);
    }

    long long sqOfSum = (sum * sum);
    long long difference = sqOfSum - sumOfSq;
    
    std::cout << "Difference: " << difference << std::endl;
}

void Problem7() {
    std::cout << "What is the 10,001st prime number?" << std::endl;
    
    int primeToFind = 10001;
    int primesFound = 0;
    int i = 1;
    while (primesFound < primeToFind) {
        i++;
        if(IsPrime(i)) primesFound++;
    }
    
    std::cout << "10,001st prime: " << i << std::endl;
}