// welcome.cpp
// CS 11 Fall 2021
//
// Purpose: Welcome the squad to their new favorite class.
// Author:  Megan Monroe (mmonroe)
//
// Updated for Fall 2021 by: Sam Berman (sberma04)
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
        string name;
        
        // Get the user's name
        cout << endl;
        cout << "Hello!";
        cout << endl;
        cout << "Please enter your name: ";
        cin >> name;

        // Print the welcome message
        cout << endl;
        cout << "Hi " << name << "!  ";
        cout << "Welcome to CS 11!" << endl;
        cout << endl;

        return 0;
} 
