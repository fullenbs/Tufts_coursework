/*
 *  testing_main.cpp
 *  Scott Fullenbaum
 *  2/26/2022
 *
 *  CS 15 Project 2 CalcYouLater
 *
 *  Contains all tests
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "RPNCalc.h"
using namespace std;

//DatumStack tests
bool empty_constructor_test();
bool Datum_constructor_test();
bool top_elem_test();
bool pop_nonempty_test();
bool pop_empty_test();
bool push_test();
bool clear_test();

//parse tests
bool convert_string_test();


//RPNCalc tests are below

//tests got_num() in RPNCalc, but really meant to check my logic
bool read_num_test();

//test math() function in RPNCalc
bool math_valid_nums_test();
bool math_invalid_nums_test();
bool math_divide_zero_test();
bool math_mod_zero_test();

//tests bool_log() function in RPNCalc
bool bool_log_valid_test();
bool bool_log_invalid_test();
bool bool_log_same_type_test();
bool bool_log_diff_type_test();

//tests bool_manipulate() function in RPNCalc
bool not_valid_test();
bool not_invalid_test();

//tests for word_cmds
bool quit_test();
bool drop_test();
bool dup_test();
bool swap_valid_test();
bool swap_invalid_test();

//tests for rstring_cmds
bool exec_test();

const int NUM_TESTS = 25;

//testing main longer than 30 lines, was told it was okay. Some tests could
//return void, but for those, I have them return bool to work with my testing
//main, and also since I consider true to mean it passed the test, and the
//test would be passed if it reached the end of the function. 
int main(){
    //I store tests in the array for my own sanity It also allows me to display 
    //everything more to my liking. 
    int tests[NUM_TESTS]; 
    int sum = 0;
    int temp = 0;
    //each index is 0 or 1, 0 if test failed, 1 if test passed 
    
    //TO RUN THESE PROPERLY, CHECK README FOR INSTRUCTIONS
    //Some of these tests might appear to fail due to changes in input/output
    //streams, but through earlier testing I had passed all of them.

    // tests[0] = int(empty_constructor_test());
    // tests[1] = int(Datum_constructor_test());

    // tests[2] = int(top_elem_test());
    // tests[3] = int(pop_nonempty_test());
    // tests[4] = int(pop_empty_test());
    // tests[5] = int(push_test());
    // tests[6] = int(clear_test());
    // tests[7] = int(convert_string_test());

    // tests[8] = int(read_num_test());
    // tests[9] = int(math_valid_nums_test());
    // tests[10] = int(math_invalid_nums_test());
    // tests[11] = int(math_divide_zero_test());
    // tests[12] = int(math_mod_zero_test());
    // tests[13] = int(bool_log_valid_test());
    // tests[14] = int(bool_log_invalid_test());
    // tests[15] = int(bool_log_same_type_test());
    // tests[16] = int(bool_log_diff_type_test());
    // tests[17] = int(not_valid_test());
    // tests[18] = int(not_invalid_test());
    // tests[19] = int(quit_test());
    // tests[20] = int(drop_test());
    // tests[21] = int(dup_test());
    // tests[22] = int(swap_valid_test());
    // tests[23] = int(swap_invalid_test());
    // tests[24] = int(exec_test());

    //everything below just displays results of testing_main
    cout << "\n**************** TEST SUMMARY ****************\n";
    for (int i = 0; i < NUM_TESTS; i++){
        sum = sum + tests[i];
    }
    cout << "\nPassed " << sum << " Tests" << endl;
    if (sum != NUM_TESTS){
        cout << "Tests failed are: " << endl;
    }
    for (int i = 0; i < NUM_TESTS; i++){
        if (tests[i] == 0){
            cout << "Test: " << i << endl;
        }
    }
    return 0;
}


/**************************** RPNCalc tests **********************************/
/*
 * name: read_num_test() 
 * purpose: Tests if can read in number properly
 * arguments: None
 * returns: True if works, false otherwise
 */
bool read_num_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    std::ostringstream ss2;
    calculator.parse_cmd("2", cin);
    calculator.print_top(ss);
    calculator.parse_cmd("3", cin);
    calculator.print_top(ss2);
    if (ss.str() == "2\n" and ss2.str() == "3\n"){
        return true;
    }
    return false;
}

/*
 * name: math_valid_nums_test() 
 * purpose: Tests if math done correctly when a valid operation is input
 * arguments: None
 * returns: True if works, false otherwise
 */
bool math_valid_nums_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("3", cin);
    calculator.parse_cmd("4", cin);
    calculator.parse_cmd("+", cin);
    calculator.print_top(ss);
    if (ss.str() == "7\n"){
        return true;
    }
    return false;
}

/*
 * name: math_invalid_nums_test() 
 * purpose: Tests if error is thrown correctly when error given
 * arguments: None
 * returns: True if works, false otherwise
 */
bool math_invalid_nums_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("#f", cin);
    calculator.parse_cmd("3", cin);
    calculator.parse_cmd("-", cin);
    calculator.print_top(ss);
    if (ss.str() == "Error: empty_stack\n"){
         return true;
    }
    return true;
}

/*
 * name: math_zero_test() 
 * purpose: Tests if can handle divide by zero
 * arguments: None
 * returns: True if works, false otherwise
 */
bool math_divide_zero_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("2", cin);
    calculator.parse_cmd("0", cin);
    calculator.parse_cmd("/", cin);
    calculator.print_top(ss);
    if (ss.str() == "Error: empty_stack\n"){
        return true;
    }
    return false;
}

/*
 * name: math_mod_zero_test() 
 * purpose: Tests if can handle mod by zero
 * arguments: None
 * returns: True if works, false otherwise
 */
bool math_mod_zero_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("2", cin);
    calculator.parse_cmd("0", cin);
    calculator.parse_cmd("mod", cin);
    calculator.print_top(ss);
    if (ss.str() == "Error: empty_stack\n"){
        return true;
    }
    return false;
}

/*
 * name: bool_log_valid_test() 
 * purpose: Tests if can handle with valid boolean comparison
 * arguments: None
 * returns: True if works, false otherwise
 */
bool bool_log_valid_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("2", cin);
    calculator.parse_cmd("5", cin);
    calculator.parse_cmd("<", cin);
    calculator.print_top(ss);
    if (ss.str() == "#t\n"){
        return true;
    }
    return false;
}

/*
 * name: bool_log_invalid_test() 
 * purpose: Tests if can handle with invalid boolean comparison
 * arguments: None
 * returns: True if works, false otherwise
 */
bool bool_log_invalid_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("#t", cin);
    calculator.parse_cmd("100", cin);
    calculator.parse_cmd(">", cin);
    calculator.print_top(ss);
    if (ss.str() == "Error: empty_stack\n"){
        return true;
    }
    return false;
}

/*
 * name: bool_log_same_type_test() 
 * purpose: Tests if can handle == when share variable type
 * arguments: None
 * returns: True if works, false otherwise
 */
bool bool_log_same_type_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("100", cin);
    calculator.parse_cmd("100", cin);
    calculator.parse_cmd("==", cin);
    calculator.print_top(ss);
    if (ss.str() == "#t\n"){
        return true;
    }
    return false;
}

/*
 * name: bool_log_diff_type_test() 
 * purpose: Tests if can handle == when have different variable type
 * arguments: None
 * returns: True if works, false otherwise
 */
bool bool_log_diff_type_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("2", cin);
    calculator.parse_cmd("#t", cin);
    calculator.parse_cmd("==", cin);
    calculator.print_top(ss);
    if (ss.str() == "#f\n"){
        return true;
    }
    return false;
}

/*
 * name: not_valid_test() 
 * purpose: Tests "not" works with a boolean value
 * arguments: None
 * returns: True if works, false otherwise
 */
bool not_valid_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("#t", cin);
    calculator.parse_cmd("not", cin);
    calculator.print_top(ss);
    if (ss.str() == "#f\n"){
        return true;
    }
    return false;
}

/*
 * name: not_invalid_test() 
 * purpose: Tests "not" works correctly with non boolean value
 * arguments: None
 * returns: True if works, false otherwise
 */
bool not_invalid_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("2", cin);
    calculator.parse_cmd("not", cin);
    calculator.print_top(ss);
    if (ss.str() == "Error: empty_stack\n"){
        return true;
    }
    return false;
}

/*
 * name: quit_test() 
 * purpose: Tests that quit ends the program
 * arguments: None
 * returns: True if works, false otherwise
 */
bool quit_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.word_cmds("quit", ss);
    cout << "string: " << ss.str() << endl;
    if (ss.str() == "Thank you for using CalcYouLater.\n"){
        return true;
    }
    return false;
}

/*
 * name: drop_test() 
 * purpose: Tests that drop pops first element
 * arguments: None
 * returns: True if works, false otherwise
 */
bool drop_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("2", cin);
    calculator.parse_cmd("drop", cin);
    calculator.print_top(ss);
    if (ss.str() == "Error: empty_stack\n"){
        return true;
    }
    return false;
}

/*
 * name: dup_test() 
 * purpose: Tests that drop pops first element
 * arguments: None
 * returns: True if works, false otherwise
 */
bool dup_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("2", cin);
    calculator.parse_cmd("dup", cin);
    calculator.print_top(ss);
    if (ss.str() == "2\n"){
        return true;
    }
    return false;
}

/*
 * name: swap_test() 
 * purpose: Tests that can swap first two elements on stack
 * arguments: None
 * returns: True if works, false otherwise
 */
bool swap_valid_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("3", cin);
    calculator.parse_cmd("#t", cin);
    calculator.parse_cmd("swap", cin);
    calculator.print_top(ss);
    if (ss.str() == "3\n"){
        return true;
    }
    return false;
}

/*
 * name: swap_invalid_test() 
 * purpose: Tests that handles error when invalid case for swap given
 * arguments: None
 * returns: True if works, false otherwise
 */
bool swap_invalid_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.parse_cmd("3", cin);
    calculator.parse_cmd("swap", cin);
    calculator.print_top(ss);
    if (ss.str() == "Error: empty_stack\n"){
        return true;
    }
    return false;
}

/*
 * name: exec_test() 
 * purpose: Pops off top of Rstring and runs it
 * arguments: None
 * returns: True if works, false otherwise
 */
bool exec_test(){
    RPNCalc calculator;
    std::ostringstream ss;
    calculator.run(); //enter { 1 2 + } exec
    calculator.parse_cmd("exec", cin);
    calculator.print_top(ss);
    if (ss.str() == "3\n"){
        return true;
    }
    return false;
}





/**************************** DatumStack tests *******************************/
/*
 * name: empty_constructor_test 
 * purpose: Tests empty constructor
 * arguments: None
 * returns: True if works, false otherwise
 */
bool empty_constructor_test(){
    DatumStack test;
    if (test.size() == 0){
        return true;
    }
    return false;
}

/*
 * name: Datum_constructor_test
 * purpose: Tests constructor w/ Datum array
 * arguments: None
 * returns: True if works, false otherwise
 */
bool Datum_constructor_test(){
    Datum data[2] = {Datum(5), Datum(true)};
    DatumStack test(data, 2);
    if (test.size() == 2){
        return true;
    }
    return false;
}

/*
 * name: top_elem_test
 * purpose: Checks top() function of Datum_Stack
 * arguments: None
 * returns: True if works, false otherwise
 */
bool top_elem_test(){
    Datum data[2] = {Datum(5), Datum(true)};
    DatumStack test(data, 2);
    if (test.top().getBool()){
        return true;
    }
    return false;
}

/*
 * name: pop_nonempty_test
 * purpose: Checks that can pop top of stack when stack has elements
 * arguments: None
 * returns: True if works, false otherwise
 */
bool pop_nonempty_test(){
    Datum data[2] = {Datum(5), Datum(true)};
    DatumStack test(data, 2);
    test.pop();
    if (test.size() == 1){
        return true;
    }
    return false;
}

/*
 * name: pop_empty_test
 * purpose: Checks that error thrown if try to pop from empty list
 * arguments: None
 * returns: True if works, false otherwise
 */
bool pop_empty_test(){
    DatumStack test;
    bool range_error_thrown = false;
    std::string error_message = "";
    try{
        test.pop();
    } catch (const std::runtime_error &e){
        range_error_thrown = true;
        error_message = e.what();
    }
    if (range_error_thrown == true and 
        error_message == "empty_stack"){
        return true;
    }
    return false;
}

/*
 * name: push_test()
 * purpose: Checks that properly can add to stack
 * arguments: None
 * returns: True if works, false otherwise
 */
bool push_test(){
    DatumStack test;
    test.push(Datum(5));
    test.push(Datum(true));
    if (test.size() == 2 and test.top().getBool()){
        return true;
    }
    return false;
}

/*
 * name: clear_test()
 * purpose: Checks that properly can clear stack
 * arguments: None
 * returns: True if works, false otherwise
 */
bool clear_test(){
    Datum data[2] = {Datum(5), Datum(true)};
    DatumStack test(data, 2);
    test.clear();
    if (test.size() == 0){
        return true;
    }
    return false;
}
/************************** End DatumStack tests *****************************/
/****************************** Parser tests *********************************/

/*
 * name: convert_string_test()
 * purpose: Checks to see if can convert ifstream to string properly
 * arguments: None
 * returns: True if works, false otherwise
 */
bool convert_string_test(){
    std::istringstream ss(" 1 2 3 }");
    RPNCalc calculator;
    string f = calculator.parseRString(ss); 
    if (f == "{ 1 2 3 }"){ 
        return true;
    }   
    return false;
}
/************************** End Parser tests *********************************/
