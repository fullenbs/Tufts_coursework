/*
 *  CharArrayList.cpp
 *  Scott Fullenbaum
 *  1/26/2022
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  Stores member functions of CharArrayList class
 *  TODO: According to the autograder, I still fail 3 tests, though I don't know
 *  which functions have issues. I continue to pass all of my tests, and
 *  at the time of this submission, have run out of ideas as to where the
 * remaining bugs might be.
 * TODO: I am aware that modularity could be increased by writing a general
 * pushAt() or removeAt() function, then calling it from within pushAtfront,
 * pushAtBack, etc. However, when I attempted to implement this, it created
 * bugs that I was unable to resolve before this assignment being due, so I
 * have left it as is for now.
 */

#include "CharArrayList.h"
#include <iostream>
#include <sstream>
using namespace std;

/*
 * name: CharArrayList - empty constructor
 * purpose: Intialize empty ArrayList with no values
 * arguments: None
 * returns: None
 */
CharArrayList::CharArrayList() {
    numChar  = 0;
    capacity = 0;
    arr_char = new char[capacity];
}

/*
 * name: CharArrayList constructor - handles one char
 * purpose: Makes ArrayList with one character
 * arguments: None
 * returns: None
 */
CharArrayList::CharArrayList(char c) {
    numChar     = 1;
    capacity    = 1;
    arr_char    = new char[capacity];
    arr_char[0] = c;
}

/*
 * name: CharArrayList constructor - handles an array of chars
 * purpose: Makes ArrayList with an array of characters
 * arguments: Array of characters and int size, which has arr
 * returns: None
 */
CharArrayList::CharArrayList(char arr[], int size) {
    numChar  = size;
    capacity = size;
    arr_char = new char[capacity];
    for (int i = 0; i < numChar; i++) {
        arr_char[i] = arr[i];
    }
}

/*
 * name: CharArrayList deep copy constructor
 * purpose: Initializes an ArrayList identical to an already existing ArrayList
 * while avoiding memory issues.
 * arguments: A CharArrayList
 * returns: None
 */
CharArrayList::CharArrayList(const CharArrayList &other) {
    numChar  = other.size();
    arr_char = new char[numChar];
    for (int i = 0; i < numChar; i++) {
        arr_char[i] = other.arr_char[i];
    }
}

/*
 * name: CharArrayList deconstructor
 * purpose: Prevent memory issues and clear the Heap
 * arguments: None
 * returns: None
 */
CharArrayList::~CharArrayList() {
    delete[] arr_char;
}

/*
 * name: operator=()
 * purpose: Overloads assignment operator to prevent memory issues
 * arguments: An arraylist being read in
 * returns: None
 */
CharArrayList &CharArrayList::operator=(const CharArrayList &other) {
    if (this == &other) { return *this; }

    delete[] arr_char;
    numChar  = other.size();
    capacity = numChar;
    arr_char = new char[capacity];

    for (int i = 0; i < numChar; i++) {
        arr_char[i] = other.arr_char[i];
    }
    return *this;
}

/*
 * name: isEmpty
 * purpose: Checks if ArrayList has no elements in it
 * arguments: None
 * returns: true if ArrayList is empty, false otherwise
 */
bool CharArrayList::isEmpty() const {
    return (numChar == 0);
}

/*
 * name: size
 * purpose: Returns number of items in ArrayList
 * arguments: None
 * returns: Number of characters in ArrayList
 */
int CharArrayList::size() const {
    return numChar;
}

/*
 * name: first
 * purpose: If it exists, returns first char in ArrayList
 * arguments: None
 * returns: arr_char[0] if exists
 */
char CharArrayList::first() const {
    if (isEmpty()) { // error thrown if ArrayList empty
        throw runtime_error("cannot get first of empty ArrayList");
    }
    return arr_char[0];
}

/*
 * name: last
 * purpose: To return last char in ArrayList if it exists
 * arguments: None
 * returns: Last defined char in arrayList if ArrayList exists
 */
char CharArrayList::last() const {
    if (isEmpty()) { // error thrown if ArrayList empty
        throw runtime_error("cannot get last of empty ArrayList");
    }
    return arr_char[numChar - 1];
}

/*
 * name: elementAt
 * purpose: To return element at a given index
 * arguments: None
 * returns: Element at index if the index is within the array
 */
char CharArrayList::elementAt(int index) const {
    if ((index < 0) or (index >= numChar)) { // error if out of range
        throw range_error("index (" + std::to_string(index) +
                          ") not in range [0.." + std::to_string(numChar) +
                          ")");
    }
    return arr_char[index];
}

/*
 * name: toString
 * purpose: Return an output string containing all chars from the ArrayList
 * formatted according to the spec
 * arguments: None
 * returns: The properly formatted string
 */
std::string CharArrayList::toString() const {
    std::string combine = "";
    for (int i = 0; i < size(); i++) {
        combine = combine + arr_char[i];
    }
    combine = " <<" + combine + ">>]"; // formats and returns output
    return "[CharArrayList of size " + std::to_string(size()) + combine;
}

/*
 * name: toReverseString
 * purpose: Returns a string containing all chars from the ArrayList in
 * reverse order formatted according to the spec
 * arguments: None
 * returns: Output string that contains the reversed ArrayList and it's size
 */
std::string CharArrayList::toReverseString() const {
    std::string combine = "";
    for (int i = size() - 1; i >= 0; i--) {
        combine = combine + arr_char[i];
    }
    combine = " <<" + combine + ">>]";
    return "[CharArrayList of size " + std::to_string(size()) + combine;
}

/*
 * name: pushAtBack
 * purpose: Adds character to end of array list
 * arguments: The character being added
 * returns: Nothing
 */
void CharArrayList::pushAtBack(char c) {
    if (numChar >= capacity) { expand(); }
    arr_char[numChar] = c;
    numChar++;
}

/*
 * name: pushAtFront
 * purpose: Adds character to beginning of ArrayList
 * arguments: The character being added
 * returns: Nothing
 */
void CharArrayList::pushAtFront(char c) {
    if (numChar >= capacity) { expand(); }

    char *new_arr = new char[capacity];
    new_arr[0]    = c;
    for (int i = 0; i < numChar; i++) { // maps old elements to new array
        new_arr[i + 1] = arr_char[i];
    }

    numChar++;
    delete[] arr_char;
    arr_char = new_arr;
    new_arr  = nullptr;
}

/*
 * name: pushAtMid
 * purpose: Puts a character in middle of ArrayList
 * arguments: the character and where it is being added (never should be called
 * with first or last char) returns: Nothing
 */
void CharArrayList::pushAtMid(char c, int index) {
    if (numChar == capacity) { expand(); }
    char *new_arr  = new char[capacity];
    new_arr[index] = c;

    for (int i = 0; i < index; i++) {
        new_arr[i] = arr_char[i];
    }
    // all elements at i >= index are now shifted one spot to the right
    for (int i = index; i < numChar; i++) {
        new_arr[i + 1] = arr_char[i];
    }
    delete[] arr_char;
    arr_char = new_arr;
    new_arr  = nullptr;
    numChar++;
}

/*
 * name: insertAt
 * purpose: Adds a character at a given index in the ArrayList
 * arguments: Character being added and where it is being added
 * returns: Nothing
 */
void CharArrayList::insertAt(char c, int index) {
    if (((index < 0) or
         index > numChar)) { // if index out of bounds, throws error
        throw range_error("index (" + std::to_string(index) +
                          ") not in range [0.." + std::to_string(numChar) +
                          "]");
    } else if (index == numChar) { // expands if neccesary
        expand();
    }
    if (index == size()) {
        pushAtBack(c);       // adds to back of list
    } else if (index == 0) { // use pushAtBack for empty list
        pushAtFront(c);
    } else {
        pushAtMid(c, index); // private helper function
    }
    shrink(); // During testing, large ArrayLists ran out of space if this was
              // not used here
}

/*
 * name: insertInOrder
 * purpose: Adds a character based off it's numerical ASCII value
 * arguments: Character being added
 * returns: Nothing
 */
void CharArrayList::insertInOrder(char c) {
    if (numChar >= capacity) { expand(); }

    for (int i = 0; i < numChar; i++) {
        if (c < arr_char[i]) {
            insertAt(c, i);   // inserts c at proper location
            i = numChar + 10; // ends loop as want to insert once
        }
    }
}

/*
 * name: popFromFront
 * purpose: Removes first element of ArrayList
 * arguments: Nothing
 * returns: Nothing
 */
void CharArrayList::popFromFront() {
    if (isEmpty()) { throw runtime_error("cannot pop from empty ArrayList"); }

    char *new_arr = new char[capacity];
    for (int i = 1; i < numChar; i++) {
        new_arr[i - 1] = arr_char[i]; // moves everythhing to index one less
    }
    delete[] arr_char;
    arr_char = new_arr;
    numChar--;
    new_arr = nullptr;
}

/*
 * name: popFromBack
 * purpose: Removes last element of ArrayList
 * arguments: Nothing
 * returns: Nothing
 */
void CharArrayList::popFromBack() {
    if (isEmpty()) { throw runtime_error("cannot pop from empty ArrayList"); }
    char *new_arr = new char[capacity];

    // reassigns everything except last element, as that gets removed
    for (int i = 0; i < numChar - 1; i++) {
        new_arr[i] = arr_char[i];
    }
    delete[] arr_char;
    arr_char = new_arr;
    numChar--;
    new_arr = nullptr;
}

/*
 * name: popFromMid
 * purpose: Removes an element from middle of ArrayList
 * arguments: Index of element being removed
 * returns: Nothing
 */
void CharArrayList::popFromMid(int index) {
    // Function only called from removeAt(), and that makes sure index in bounds
    char *new_arr = new char[capacity];

    // The first for loop keeps all element before the index in place
    // The second for loop moves all elements after arr[index] down one
    for (int i = 0; i < index; i++) {
        new_arr[i] = arr_char[i];
    }
    for (int i = index; i < numChar; i++) {
        new_arr[i] = arr_char[i + 1];
    }
    delete[] arr_char;
    arr_char = new_arr;
    numChar--;
    new_arr = nullptr;
}

/*
 * name: removeAt
 * purpose: Removes an element from anywhere in the ArrayList
 * arguments: Index of element being removed
 * returns: Nothing
 */
void CharArrayList::removeAt(int index) {
    if ((index < 0) or (index > numChar - 1) or isEmpty()) {
        throw range_error("index (" + std::to_string(index) +
                          ") not in range [0.." + std::to_string(numChar) +
                          ")"); // throws error message if out of bounds
    }
    if (index == numChar - 1) {
        popFromBack();
    } else if (index == 0 and (size() != 1)) {
        popFromFront();
    } else {
        popFromMid(index);
    }
}

/*
 * name: replaceAt
 * purpose: Replaces any element in the ArrayList with another element
 * arguments: Index of element being removed and char that's replacing it
 * returns: Nothing
 */
void CharArrayList::replaceAt(char c, int index) {
    if ((index < 0) or (index > (numChar - 1)) or isEmpty()) {
        throw range_error("index (" + std::to_string(index) +
                          ") not in range [0.." + std::to_string(numChar) +
                          ")"); // throws error when out of bounds
    }
    arr_char[index] = c;
}

/*
 * name: concatenate
 * purpose: Adds another arraylist to the end of this arraylist
 * arguments: Pointer to the ArrayList being added
 * returns: Nothing
 */
void CharArrayList::concatenate(CharArrayList *other) {
    capacity      = other->size() + size();
    char *new_arr = new char[capacity];

    // First for loop maps current object to current location
    // Second for loop adds *other to the end of new_arr
    for (int i = 0; i < size(); i++) {
        new_arr[i] = arr_char[i]; // maps current arraylist to be first array
    }
    for (int j = 0; j < other->size(); j++) {
        new_arr[numChar + j] = other->elementAt(j);
    }
    delete[] arr_char;
    arr_char = new_arr;
    numChar  = numChar + other->size();
    new_arr  = nullptr;
}

/*
 * name: shrink
 * purpose: Reduces ArrayList memory to store bare minimum
 * arguments: None
 * returns: None
 */
void CharArrayList::shrink() {
    capacity = size();
}

/*
 * name: clear
 * purpose: Clears all entries in the arraylist, meaning isEmpty() == true
 * arguments: None
 * returns: None
 */
void CharArrayList::clear() {
    numChar = 0;
}


/*
 * name: expand
 * purpose: Increases size of CharArrayList by increasing capacity
 * arguments: None
 * returns: None
 */
void CharArrayList::expand() {
    int   new_capacity = 2 * capacity + 2;
    char *new_arr      = new char[new_capacity];
    for (int i = 0; i < capacity; i++) {
        new_arr[i] = arr_char[i]; // maps old array to updated one
    }
    delete[] arr_char; // reassigns new array
    arr_char = new_arr;
    capacity = new_capacity;
    new_arr  = nullptr;
}