// recursion.cpp
// CS 11 Fall 2021
// Lab 03
//
// Purpose: Make recursive functions.
// Modified by: Scott Fullenbaum
// Date: 9/22/21
//

#include <iostream>
using namespace std;
#include <cstdlib>

int multiply(int x, int y);
int power(int x, int k);
int sum_from(int a, int b);

int main(){
    
    cout << multiply(3, 1) << endl;
    cout << power(2, 10) << endl;
    cout << sum_from(1, 10) << endl;
}

int multiply(int x, int y){
    if (y <= 1){
        return x;
    } else { 
        return multiply(x, (y - 1)) + x; 
    }
}

int power(int x, int k){
    if (k <= 1){
        return x; 
    } else {
        return power(x, (k-1))*x;
    }
}

int sum_from(int a, int b){
    if ( a == b){
        return b; 
    } else { 
        return sum_from(a + 1, b) + a;
    }
}