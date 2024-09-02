//
//Program name: add8.cpp
//Author: Scott Fullenbaum
//Purpose: Add 8 integers of the user's choice and then give the user the sum
//Notes: I was able to get it down to two variables, using my code. My thought  //process was that we need a variable for each input, as we just need to make 
//sure it is added to the sum. 


#include <iostream> //does stuff
using namespace std;

int main(){
    //sum tracks sum of the 8 numbers, input is number user enters
    int sum = 0;
    int input = 0;
    
    //takes input adds to it to the sum. Could be written as for loop. 
    cout << "enter a floating point number: ";
    cin >> input;
    sum = sum + input;
    
    //repeats process, since previous number already accounted for
    cout << "enter a floating point number: ";
    cin >> input;
    sum = sum + input;
    
    cout << "enter a floating point number: ";
    cin >> input;
    sum = sum + input;
    
    cout << "enter a floating point number: ";
    cin >> input;
    sum = sum + input;
    
    cout << "enter a floating point number: ";
    cin >> input;
    sum = sum + input;
    
    cout << "enter a floating point number: ";
    cin >> input;
    sum = sum + input;
    
    cout << "enter a floating point number: ";
    cin >> input;
    sum = sum + input;
    
    cout << "enter a floating point number: ";
    cin >> input;
    sum = sum + input;

    cout << "The sum is: " << sum << endl;
}