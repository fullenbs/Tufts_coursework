// camp.cpp
// CS 11 Fall 2021
//
// Purpose: Practice using variables and conditionals to organize
//          your new campers at Summer Camp.
//
// Modified by: Scott Fullenbaum
// Date: 9/15/21
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    /*--------------------Exercise 1------------------------------------------*/
    string name = " ";
    string emotion = " ";
     
    cout << "What's your name?" << endl;
    cin  >> name;
    
    cout << "How are you feeling?" << endl;
    cin >> emotion; 

    cout << "Hello, " << name << "! Welcome to camp!" << endl;
    cout << "You are feeling " << emotion << " today." << endl; 
    
    /*--------------------Exercise 2------------------------------------------*/
    
    float num1 = 0;
    float num2 = 0; 
    float num3 = 0;
    
    cout << "Enter a number:" << endl;
    cin >> num1; 
    
    cout << "Enter another number:" << endl;
    cin >> num2;
    
    num3 = num1*num2; 
    
    cout << "Your new ID number is: " << num3 << endl;
    
    /*--------------------Exercise 3------------------------------------------*/
    int age = 0; 
    
    cout << "How old are you?" << endl;
    cin >> age; 
    
    if (age < 10){
        cout << "Your age is " << age << ". You should go to lower campus.";
        cout << endl; 
    } else {
        cout << "Your age is " << age << ". You should go to upper campus.";
        cout << endl;
    }
    
    return 0;
} 