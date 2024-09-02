/* string_to_int 
 * Program name: string_to_int
 * Author: Scott Fullenbaum
 * Purpsoe: Convert an int into a string
 */

#include <iostream>
using namespace std;

//function declaration
int string_to_int(string s);
int digit_check(char n);
int exp(int a, int b);
int num_digit(string s);
void testing(string s, int k);

int main(){    
        //all test cases, formatted as testing(input, expected output)
        testing("can#n0L15", 15); 
        testing("123abc56", 12356);
        testing(" 2times3", 23);
        testing("help me!", 0);
        testing(" ", 0);
        testing("12wnrg-21", 1221);
        testing("p1ck3", 13);
        return 0;
}

/*string_to_int
* Parameters: A string
* Purpose: Removes any characters and converts it into a number
* Returns: The number
*/
int string_to_int(string s){
    int num_zero = num_digit(s); //means number of digits
    int final = 0; //final integer

    // Loops through the string, and adds each integer to final string in order
    for (unsigned int i = 0; i < s.length(); i++){
        if (digit_check(s[i]) <= 9 and digit_check(s[i]) >= 0){
            /*1st digit minus rest = digit * 10^(location -1)
            i.e, 123 = 100 + 20 + 3, 100 = 1* 10^2 + 2*10+3*1, which is how I
            get the new number. Don't need a check if num_zero >= 0, as that's 
            never true, as already found number of digits.*/
            final = final + digit_check(s[i])*exp(10, num_zero - 1);
            num_zero--; 
        }
    }
    return final;
}

/*num_digit
* Parameters: A string
* Purpose: Finds the number of digits in a string
* Returns: The number of nonzero digits
*/
int num_digit(string s){
    int num_zero = 0;
    for (unsigned int i = 0; i < s.length(); i++){
        if (digit_check(s[i]) <= 9 and digit_check(s[i]) >= 0){
            num_zero++;
        }
    }
    return num_zero;
}

/*digit_check
* Parameters: character n
* Purpose: Converts a character into a number
* Returns: The number the character is equivalent to 
*/
int digit_check(char n){
    return (n - '0');
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
* Parameters: String and expected integer output
* Purpose: Runs the testing process for me, converts the string to int
* Returns: Nothing
*/
void testing(string s, int k){
    cout << "TESTING: " << s << endl;
    int z = string_to_int(s);
    if (z == k){
        cout << "SUCCESS: " << z << endl;
    } else {
        cout << "FAILURE: " << z << endl;
    }
}