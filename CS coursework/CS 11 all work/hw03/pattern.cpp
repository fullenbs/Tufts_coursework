/*
* Program name: pattern.cpp
* Author: Scott Fullenbaum
* Purpose: Pattern generator 
*/

#include <iostream> //does stuff
using namespace std;

void output_pattern(string s1, string s2, int n);
string create_line(string s1, string s2, string super, int n);
void line_gen(string s, string j, int k, int n);

int testing_main();

int main(){
    string s1 = "";
    string s2 = "";
    int n = 0;
    
    cin >> s1 >> s2 >> n;
    
    output_pattern(s1, s2, n);
    
    return 0;
}

/* testing_main
* Parameters: none
* Purpose: Run test cases inputs
* Returns: nothing, runs output_pattern
*/
int testing_main(){
    string test1 = "";
    string test2 = ""; 
    int j = 0;
    
    //can comment out case you don't want to test
    cin >> j; //test for empty strings, as both set to be empty
    output_pattern(test1, test2, j);
    
    cin >> test1 >> test2; //test for n = 0
    j = 0;
    output_pattern(test1, test2, j);
    
    return 0;
}

/* output_pattern
* Parameters: both input strings, and number of lines
* Purpose: Generates the proper output and pattern
* Returns: Nothing, is a void function
*/
void output_pattern(string s1, string s2, int n){
    string super_odd = s1 + s2; //creates repeated string for odd lines
    string super_even = s2 + s1; //creates repeated string for even lines
    
    super_odd = create_line(s1, s2, super_odd, 5); //creates both lines
    super_even = create_line(s2, s1, super_even, 5);
    
    line_gen(super_odd, super_even, n, 0); 
}

/* create_line 
* Parameters: Both entered strings and them combined and number of repetitions 
* Purpose: create a single line of text with the 5 repetitions
* Returns: The final line 
*/
string create_line(string s1, string s2, string line, int n){
    if (n <= 1){
        return line;
    } else { 
        line = line + s1 + s2; //adds pattern to the line
        return create_line(s1, s2, line, n-1);
    }
    return line;
}

/* line_gen
* Parameters: The strings for both lines, the number of lines, and a tracker
* Purpose: Create the completed pattern 
* Returns: Nothing, gives output
*/
void line_gen(string s, string j, int k, int n){
    if (n < k){
        if ((n % 2) == 0){
            //cout << "Even: " << n << " " << k << endl; debug statement
            cout << s << endl;
        } else {
            //cout << "Odd: " << n << " " << k << endl; debug statement
            cout << j << endl;
        }
        line_gen(s, j, k, n + 1);
    } 
}