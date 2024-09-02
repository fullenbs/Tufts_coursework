/*
* Program name: dictionary.cpp
* Author: Scott Fullenbaum
* Purpose: Make a limited dictionary
*/
#include <iostream> //does stuff
#include <cctype> 
using namespace std;

//function declaration
void dictionary(string s);
string input();
string lower(string s, unsigned int n);

int main(){
    string word = input();  //gets input
    dictionary(word); //finds the word
    
    return 0;
}

/* input 
* Parameters: None
* Purpose: Gets word and makes it lowercase (JFFE)
* Returns: The word in lowercase form
*/
string input(){
    string s = "";
    cin >> s;
    s = lower(s, 0); //makes word lowercase 
    return s; 
}

/* dictionary
* Parameters: word entered
* Purpose: Find the definition of the entered word if it's in the dictionary
* Returns: Nothing, leads to output
*/
void dictionary(string s){
    if (s == "variable"){
        cout << "A location in the computer's memory that can store a value";
        cout << endl;
    } else if (s == "function"){
        cout << "A named block of code that can be invoked as a statement or";
        cout << " within an expression" << endl;
    } else if (s == "recursion"){
        cout << "A situation in which a definition refers to the term it"; 
        cout << " is defining" << endl;
    } else if (s == "pseudocode"){
        cout << "Notation similar to programming used to help write code";
        cout << endl;
    } else if (s == "conditional"){
        cout << "A method to execute a block of code depending on the outcome";
        cout << " of an expression" << endl;
    } else if (s == "cs11"){
        cout << "An intro level computer science course offered at Tufts";
        cout << endl;
    } else if (s == "parameter"){
        cout << "A variable that stores information passed into a function"; 
        cout << endl;
    } else { 
        cout << "Definition Not Found" << endl;
    }
}


/* lower 
* Parameters: word entered and character word is currently at 
* Purpose: JFFE, converts a string to lowercase (could be done with for loop)
* Returns: The lowercase string 
*/
string lower(string s, unsigned int n){ //didn't compile with signed int
    if (n < s.length()){
        s[n] = tolower(s[n]); //only works for characters 
        return lower(s, n + 1);
    } else {
        return s;
    }
}