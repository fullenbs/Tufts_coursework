// iftest.cpp
//      purpose: report number of digits in an integer
//        shows: use of output, input, conditional statements
//         note: has bugs, needs work
//
//  modified by: Scott Fullenbaum 
//         date: 9/16/21
//

#include <iostream>

using namespace std;

int main()
{
        int input = 0;

        cout << "Enter a number: ";
        cin  >> input;

        //take abs() of input b/c # of digits are independent from sign
        if ((input >= 100) || (input <= -100)) { 
                cout << "input has three or more digits" << endl;
        } else if ( (input >= 10) or (input <= -10)) {
                cout << "input has two digits" << endl;
        } else if ( (input < 10) || (input > -10) ) {
                cout << "input has one digit" << endl;
        } 

        //checks if input is negative
        if (input < 0){
                cout << "and input is negative" << endl;
        }

        return 0;
}
