/*
 * Program name: int_to_string.cpp
 * Author: Scott Fullenbaum
 * Purpose: Convert an integer into a string
*/

#include <iostream>
using namespace std;

//function declaration
string int_to_string(int num);
char digit_convert(int n);
int num_digits(int k);
int exp(int a, int b);
void testing(int k, string s);

int main(){
        //all tests, formatted as testing(input, expected output)
        testing(-12, "-12");
        testing(50, "50");
        testing(0, "0");
        testing (15311, "15311");
        testing(-123456, "-123456");
        return 0;
}

/* int_to_string
* Parameter: An integer k
* Purpose: Converts an int to a string
* Returns: The number in string form
*/
string int_to_string(int k){
    string output = "";
    
    if (k < 0){ //easier to convert to string when k is positive
        k = k * -1;
        output = output + '-';
    }
    int digits = num_digits(k); 
    
    /* digit_temp has the numeric value of the ith digit, then that digit gets 
    converted into a char, it's int value removed from k, and then added to 
    output.
    i.e: k = 123, for step 1, (i = 3) 1 would be removed, then k = 123 - 100 = 
    23, output = "1" */
    for (int  i = digits; i > 0; i--){
        int digit_temp = (k - k % exp(10, i - 1))/exp(10, i - 1);
        char j = digit_convert(digit_temp);
        k = k % exp(10, i - 1);
        output = output + j;
    }
    return output;
}

/*digit_check
* Parameters: int n
* Purpose: Converts n into a character representing a digit
* Returns: The number the character is equivalent to 
*/
char digit_convert(int n){
    if (n == 1){
        return '1';
    } else if (n == 2){
        return '2';
    } else if (n == 3){
        return '3';
    } else if (n == 4){
        return '4';
    } else if (n == 5){
        return '5';
    } else if (n == 6){
        return '6';
    } else if (n == 7){
        return '7';
    } else if (n == 8){
        return '8';
    } else if (n == 9){
        return '9';
    } else if (n == 0){
        return '0';
    }
    return '-'; //added to avoid any compiler issues
}

/* num_digits
* Paramters: An integer
* Purpose: Figure out number of digits so can determine size of array of digits
* Returns: The number of digits
*/
int num_digits(int k){
    int digits = 0;
    int num = k;
    if (num == 0){ //edge case for k = 0
        return 1;
    }
    
    /* Doesn't matter if num becomes non integer, as c++ takes the floor of it, 
    and we still reach proper outcome, as goal is to reduce it's size by one 
    non-decimal digit each iteration, which this accomplishes still the goal */
    
    while (num != 0){
        num = num / 10; 
        digits++;
    }
    return digits; 
}

/* exp
* Parameters: Two integers, a base and an exponent
* Purpose: Calculates an exponent, used for finding final integer
* Returns: a^b
*/
int exp(int a, int b){
    int c = 1;
    for (int i = 0; i < b; i++){
        c = c*a;
    }
    return c; 
}

/* testing
* Parameters: Integer being tested, expected string output
* Purpose: Runs the test case to avoid repetition in main
* Returns: Nothing
*/
void testing(int k, string s){
    cout << "TESTING: " << k << endl;
    string z = int_to_string(k);
    if (z == s){
        cout << "SUCCESS: " << z << endl;
    } else {
        cout << "FAILURE: " << z << endl;
    }
}