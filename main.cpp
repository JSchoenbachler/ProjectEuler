#include <iostream>
#include "Problems.h"

int main() {
    printf("Please enter which Project Euler problem number you wish to solve: ");
    int problemNum;
    std::cin >> problemNum;
    
    switch (problemNum) {
        case 1 :
            Problem1();
            break;
        case 2 :
            Problem2();
            break;
        case 3 :
            Problem3();
            break;
        default :
            printf("That problem isn't solved here yet!");
    }
}