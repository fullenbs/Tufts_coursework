/*
 *  RPNCalc.cpp
 *  Scott Fullenbaum
 *  3/1/2022
 *
 *  CS 15 Proj2 CalcYouLater
 *
 *  Implementation for RPNCalc
 *
 */


#include "RPNCalc.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

/*
 * name: Default constructor
 * purpose: Makes empty RPNCalc
 * arguments: None
 * returns: None
 */
RPNCalc::RPNCalc(){
    commandline = "";
    in_prog = true;
}

/*
 * name: Deconstructor
 * purpose: Clears any heap allocated memory
 * arguments: None
 * returns: None
 */
RPNCalc::~RPNCalc(){
    //Not needed
}

/*
 * name: run()
 * purpose: Runs the calculator
 * arguments: None
 * returns: None
 */
void RPNCalc::run(){
    while (in_prog and cin >> commandline){ //command loop
        parse_cmd(commandline, cin);
    }
    if (in_prog == true){ //means if done with commandline but no quit called
        cerr << "Thank you for using CalcYouLater.\n";
    }
}

/*
 * name: parse_cmd()
 * purpose: Reads in a command and runs it
 * arguments: The command and it's input stream 
 * returns: None
 * Note: Main reason need input stream is for handling File I/O
 */
void RPNCalc::parse_cmd(string s, istream &input){
    int val;
    if (got_int(s, &val)){ //just add int here, short enough to not need helper
        stack.push(Datum(val));
        return;
    }
    if (s == "+" or s == "-" or s == "*" or s == "/" or s == "mod"){
        math(s);
    } else if (s == "<" or s == ">" or s == "<=" or s == ">=" or s == "=="){
        bool_log(s);
    } else if (s == "#t" or s == "#f" or s == "not"){
        bool_manipulate(s);
    } else if (s == "print" or s == "drop" or s == "dup" or s == "swap"
               or s == "clear" or s == "quit"){
        word_cmds(s, cerr); //cerr stays for testing purposes
    } else if (s == "file") {
        file();
    } else if (s == "{"){
        addRString(input); 
    } else if (s == "if"){
        if_cmd();
    } else  if (s == "exec"){
        exec(input);
    } else {
        cerr << s << ": unimplemented\n";
    }
}

/*
 * name: math()
 * purpose: Handles addition, subtraction, multiplication, division, and 
 * modulus operations.
 * arguments: Operation entered
 * returns: None
 */
void RPNCalc::math(string operation){
    if (small(2)){ //If stack < 2 ints, can't perform any operation
        return;
    }
    Datum temp1 = stack.top();
    stack.pop();
    Datum temp2 = stack.top();
    stack.pop();
    if (not temp1.isInt() or not temp2.isInt()){ //if either is not an int
        return;
    }
    if (operation == "+"){ //addition
        stack.push(Datum(temp1.getInt() + temp2.getInt()));
    } else if (operation == "-"){ //subtraction
        stack.push(Datum(temp2.getInt() - temp1.getInt()));
    } else if (operation == "*"){ //multiplication
        stack.push(Datum(temp1.getInt() * temp2.getInt()));
    } else if (operation == "/"){ //division
        if (temp1.getInt() != 0){ //edge case of divide by 0
            stack.push(Datum(temp2.getInt() / temp1.getInt()));
        } else {
            cerr << "Error: division by 0.\n";
        }
    } else if (operation == "mod"){ //modulus
        if (temp1.getInt() != 0){ //edge case of mod by 0
            stack.push(Datum(temp2.getInt() % temp1.getInt()));
        } else {
            cerr << "Error: division by 0.\n";
        }
    }
}

/*
 * name: bool_log()
 * purpose: Handles any boolean comparison
 * arguments: Operation being performed and output stream
 * returns: None
 */
void RPNCalc::bool_log(string operation){
    if (small(2)){ //If stack < 2 ints, can't perform operation
        return;
    }
    Datum temp1 = stack.top();
    stack.pop();
    Datum temp2 = stack.top();
    stack.pop();

    if ((not temp1.isInt() or not temp2.isInt()) and operation != "=="){
        cerr << "Error: datum_not_int\n"; //Only == handles non ints
        return;
    } 
    if (operation == "<"){ // a < b
        stack.push(Datum(temp2.getInt() < temp1.getInt()));
        return;
    } else if (operation == ">"){ // a > b
        stack.push(Datum(temp2.getInt() > temp1.getInt()));
        return;
    } else if (operation == "<="){ // a <= b
        stack.push(Datum(temp2.getInt() <= temp1.getInt()));
        return;
    } else if (operation == ">="){ // a >= b
        stack.push(Datum(temp2.getInt() >= temp1.getInt()));            
        return;
    } else if (operation == "=="){ //a == b
        stack.push(Datum(temp1 == temp2));
        return;
    }
    stack.push(Datum(false)); //if none of comparisons are true
}

/*
 * name: bool_manipulate()
 * purpose: Swaps top true or false
 * arguments: Operation being performed
 * returns: None
 */
void RPNCalc::bool_manipulate(string operation){
    if (operation == "#t"){ //adds true
        stack.push(Datum(true));
    } else if (operation == "#f"){ //adds false
        stack.push(Datum(false));
    } else if (operation == "not"){ //not
        if (small(1)){ //if under 1 element on stack 
            return;
        }
        if (stack.top().isBool()){ //2 cases, if not bool or bool
            if (stack.top().getBool()){
                stack.pop();
                stack.push(Datum(false));
            } else {
                stack.pop();
                stack.push(Datum(true));
            }
        } else {
            cerr << "Error: datum_not_bool\n";
        } 
    }
}

/*
 * name: word_cmds()
 * purpose: Handles a bunch of simple word commands
 * arguments: Command done and output stream, really used for just quit
 * returns: None
 */
void RPNCalc::word_cmds(string cmd, ostream &output){
    if (cmd == "quit"){ //quit
        in_prog = false;
        output << "Thank you for using CalcYouLater.\n";
    } else if (cmd == "drop"){ //drop
        if (not small(1)){
            stack.pop();
        }
    } else if (cmd == "print"){
        print_top(cout);
    } else if (cmd == "dup"){ 
        if (not small(1)){ //Edge case of empty stack
            stack.push(stack.top());
        }
    } else if (cmd == "swap"){ 
        if (not small(2)){ //Edge case of <2 elements
            Datum temp = stack.top();
            stack.pop();
            Datum temp2 = stack.top();
            stack.pop();
            stack.push(temp);
            stack.push(temp2);
        }
    } else if (cmd == "clear"){ //clear function
        stack.clear();
    }
}

/*
 * name: addRString()
 * purpose: Adds an Rstring
 * arguments: command which should be { and the istringstream location
 * returns: None
 */
void RPNCalc::addRString(istream &input){
    string s = parseRString(input);
    stack.push(Datum(s));
}

/*
 * name: exec()
 * purpose: Executes R string on top of stack
 * arguments: Something
 * returns: None
 */
void RPNCalc::exec(istream &input){
    if (small(1)){
        return; //if stack empty
    }
    string temp = stack.top().toString();
    bool is_RString = stack.top().isRString();
    stack.pop();
    if (not is_RString){
        cerr << "Error: cannot execute non rstring\n";
        return;
    }
    temp = temp.substr(2, temp.length()-4); //substring w/o end brackets
    int a = 0; //tracking vars
    int b = 0;
    
    for (unsigned int i = 0; i < temp.length(); i++){
        if (temp[i] == ' '){ //parses in a command when space detected
            parse_cmd(temp.substr(a, b), input); //the substring is a command
            a = a + b + 1; //Updates values to avoid double counting
            i = a;
            b = 0;
        }  
        if  (i == temp.length() - 1) { //edge if at last char
            parse_cmd(temp.substr(a, b + 1), input);
        }
        if (temp[i] == '{'){ //see exec_nest(), on how nested case handled
            int z = exec_nest(temp, i); 
            i = z + 1; //Updates i to avoid double counting
            a = z + 2; //Done so substring won't start at a space
            b = 0; //resets length of substring
        }
        b++; //increments length of substring
    }
}


/*
 * name: exec_nest()
 * purpose: Private helper for exec() that helps with nested RStrings
 * arguments: the current string and where the first bracket is
 * returns: Int of '}' to skip over it
 */
int RPNCalc::exec_nest(string s, unsigned int k){
    int con = 1; //num_brackets
    int loc_track = 0; //essentially tracks the end of the nested Rstring

    //This for loop finds the end of the nested Rstring. It uses similar,
    //but not identical logic to parseRString. j < s.length() is to ignore
    //incorrect RString inputs. 
    for (unsigned int j = k + 1; j < s.length() and con != 0; j++){
        if (s[j] == '{'){
            con++;
        } else if (s[j] == '}'){
            con--;
        }
        loc_track = j; //updates length of RString
    }

    //Since the RString is nested, we can just add it directly onto the 
    //stack ussing addRString() 
    istringstream ss(s.substr(k + 1, loc_track - k + 1));
    addRString(ss);

    //Returns this to skip over the rest of this nested Rstring in exec
    //means we don't double count our terms.
    return loc_track; 
}

/*
 * name: file()
 * purpose: Runs the file command
 * arguments: None
 * returns: None
 */
void RPNCalc::file(){
    string base = stack.top().toString(); //placeholder file name

    string filename = base.substr(2, base.length()-4); //removes brackets
    ifstream file_input;
    file_input.open(filename);
    if (not file_input.is_open()){
        cerr << "Unable to read " << filename << endl;
        return;
    }

    //This is kind of a smaller commandloop
    while (not file_input.fail()){ //while reading in input
        string temp = "";
        file_input >> temp; //runs in every command
        if (not temp.empty()){
            parse_cmd(temp, file_input);
        }
    }
    file_input.close();
}

/*
 * name: if_cmd()
 * purpose: Runs the if_cmd
 * arguments: None
 * returns: None
 */
void RPNCalc::if_cmd(){
    if (small(3)){ //need at least 3 elements on stack
         return;
    }
    if (not if_valid()){ //if inputs aren't valid, can't do if statement
        return;
    }

    //exec takes an istream, so pass in both cases as if stream
    istringstream false_case(stack.top().getRString());
    stack.pop();
    istringstream true_case(stack.top().getRString());
    stack.pop();
    bool test_con = stack.top().getBool();
    stack.pop();

    if (test_con){ //If true
        stack.push(Datum(true_case.str()));
        exec(true_case);
    } else { //If false
        stack.push(Datum(false_case.str()));
        exec(false_case);
    }
}


/*
 * name: if_valid()
 * purpose: Checks if if_cmd has valid inputs
 * arguments: None
 * returns: True if it does, false otherwise
 * Note: This was mainly added as if you enter an invalid input like '3 2 3 if'
 * The error statement was about expected boolean rather than rstring.
 */
bool RPNCalc::if_valid(){
    //Already assume that stack has at least 3 elements
    Datum temp1 = stack.top();
    stack.pop();
    Datum temp2 = stack.top();
    stack.pop();
    Datum temp3 = stack.top();
    stack.pop();

    if (not temp3.isBool()){  
        cerr << "Error: expected boolean in if test\n";
        return false;
    }
    if (not temp1.isRString() or not temp2.isRString()){
         cerr << "Error: expected rstring in if branch\n";
         stack.clear();
         return false;
    }

    //Since the elements were pushed off, need to readd them to perform
    //the if statement. 
    stack.push(temp3); 
    stack.push(temp2);
    stack.push(temp1);
    return true;
}

/*
 * name: print_top()
 * purpose: Prints top of the stack
 * arguments: None
 * returns: None
 * Note: Realistically might not need to be a function, but made this for
 * testing.
 */
void RPNCalc::print_top(ostream &output){
    if (stack.size() == 0){ //Empty stack
        cerr << "Error: empty_stack\n";
        return;
    }
    output << stack.top().toString() << endl;
}

/*
 * name: got_int()
 * purpose: Checks if any input arg is a number
 * arguments: The string being checked
 * returns: True if number added, false otherwise
 * Note: This is from got_int.cpp, just copypasted it
 */
bool RPNCalc::got_int(string s, int *resultp){
    /* Holds the first non-whitespace character after the integer */
    char extra;
    return sscanf(s.c_str(), " %d %c", resultp, &extra) == 1;
}

/*
 * name: parseRString()
 * purpose: Checks if any input arg is a number, then adds it onto stack if so
 * arguments: The string being entered
 * returns: True if number added, false otherwise
 * notes: This is parser.cpp, but not included. 
 */
string RPNCalc::parseRString(istream &input){
    int bracket_counter = 1;
    string s;
    string total;
    //reads in everything
    while ((bracket_counter != 0) and (input >> s)){
        total =  total + " " + s;
        if (s == "{"){
            bracket_counter++;
        }
        if (s == "}"){
            bracket_counter--;
        }
    }
    if (bracket_counter != 0){
        cout << "brackets: " << bracket_counter << endl;
        cerr << "Not well balanced expression" << endl;
        exit(1);
    }
    return ("{" + total);
}


/*
 * name: small()
 * purpose: Many operations require a certain amount of elements on the stack,
 * and have empty stack after if they don't, this handles that.
 * arguments: Minimum number datums  on stack needed
 * returns: True if doesn't have number of components, false otherwise.
 */
bool RPNCalc::small(int n){
    if (stack.size() < n){ //If you don't have enough elements, empty_stack
        stack.clear();
        print_top(cerr);
        return true;
    }
    return false;
}