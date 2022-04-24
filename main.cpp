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
        case 4 :
            Problem4();
            break;
        case 5 :
            Problem5();
            break;
        case 6 :
            Problem6();
            break;
        case 7 :
            Problem7();
            break;
        case 8 :
            Problem8();
            break;
        case 9 :
            Problem9();
            break;
        case 10 :
            Problem10();
            break;
        case 11 :
            Problem11();
            break;
        case 12 :
            Problem12();
            break;
        default :
            printf("That problem isn't solved here yet!");
    }
}