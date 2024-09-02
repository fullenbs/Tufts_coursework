//Program name: yoda.cpp
//Author: Scott Fullenbaum
//Purpose: Take a string of 4 words and reverse the order. 
//


#include <iostream> //does stuff
#include <string>
using namespace std;

int main(){
    //creates the four words
    string word1 = "";
    string word2 = "";
    string word3 = "";
    string word4 = "";
    
    cout << "Type in four words: "; 
    
    //c++ ends inputs when space is pressed, so each word is assigned input var
    cin >> word1 >> word2 >> word3 >> word4;
    
    //displays it in reverse order
    cout << word4 << " " << word3 << " " << word2 << " " << word1;
}