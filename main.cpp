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
        case 13 :
            Problem13();
            break;
        case 14 :
            Problem14();
            break;
        case 15 :
            Problem15();
            break;
        case 16 :
            Problem16();
            break;
        case 17 :
            Problem17();
            break;
        case 18 :
            Problem18();
            break;
        case 19 :
            Problem19();
            break;
        case 20 :
            //printf("That problem is under construction!");
            Problem20();
            break;
        case 67 :
            Problem67();
            break;
        default :
            printf("That problem isn't solved here yet!");
    }
}