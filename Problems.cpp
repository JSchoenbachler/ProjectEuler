#include <iostream>
#include "Problems.h"
#include "Helpers.h"
#include <math.h>

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