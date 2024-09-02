/*
 * namelist.cpp -- An ArrayList class that grows as data are added
 * 
 * Author: Samuel J. Berman (sberma04)
 * 
 * CS 11: Lab 9
 * Tufts University, Fall 2021
 * 
 * Modified by: Scott Fullenbaum
 * 
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "namelist.h"

using namespace std;

/*
 * NameList()
 * 
 * Purpose:   Default constructor -- initialize a NameList with capcity of
 *            INIT_SIZE elements
 * Arguments: None
 * Returns:   None
 * Notes:     Starts with default initial size
 * 
 */
NameList::NameList()
{
    capacity   = INIT_SIZE;
    data       = new string[capacity];
    n_elements = 0;
}

/*
 * ~NameList()
 * 
 * Purpose:   Destructor -- destroys the NameList
 * Arguments: None
 * Returns:   None
 * Notes:     None
 * 
 */
NameList::~NameList()
{
    delete [] data;
}

/*
 * getSize()
 * 
 * Purpose:   Returns number of items in the NameList
 * Arguments: None
 * Returns:   Number of elements in the NameList
 * Notes:     None
 * 
 */
int NameList::getSize()
{
    return n_elements;
}

/*
 * getCapacity()
 * 
 * Purpose:   Returns current capacity of the NameList
 * Arguments: None
 * Returns:   Maximum number of elements that can be stored in the NameList
 * Notes:     None
 * 
 */
int NameList::getCapacity()
{
    return capacity; 
}

/*
 * getValAt()
 * 
 * Purpose:   Returns element at the given index
 * Arguments: Index of the element
 * Returns:   Element at the given index
 * Notes:     Make sure index in in range
 * 
 */
string NameList::getValAt(int index)
{
    if (index < 0 || index >= n_elements) {
        cerr << "ERROR: trying to access elements outside the bounds of "
             << "the array" << endl;
        exit(EXIT_FAILURE);
    }
    return data[index];
}

/*
 * add()
 * 
 * Purpose:   Adds the given element to end of the array
 * Arguments: Element to be added
 * Returns:   None
 * Notes:     Expands the capacity of the NameList, if necessary
 * 
 */
void NameList::add(string element)
{
    if (n_elements >= capacity){
        expand();
    }
    n_elements = n_elements + 1;

    data[n_elements] = element;
}

/*
 * insertAt()
 * 
 * Purpose:   Places the given element at the given index
 * Arguments: Element and index
 * Returns:   True if element is successfully added, false otherwise
 * Notes:     Expands the capacity of the NameList, if necessary
 * 
 */
bool NameList::insertAt(string element, int index)
{
    if (index < 0 or index > n_elements) {
        cerr << "ERROR: trying to insert an element out of bounds" << endl;
        return false;
    }

    // TODO (JFFE)
    (void)element;
    return false;
}

/*
 * print()
 * 
 * Purpose:   Prints the NameList, one name per line
 * Arguments: None
 * Returns:   None
 * Notes:     None
 * 
 */
void NameList::print()
{
    for (int i = 0; i <= n_elements; i++){
        cout << data[i] << endl;
    }
}

/*
 * revPrint()
 * 
 * Purpose:   Prints the namelist in reverse, one name per line
 * Arguments: None
 * Returns:   None
 * Notes:     None
 * 
 */
void NameList::revPrint()
{
    for (int i = n_elements-1; i >= 0; i--){
        cout << data[i] << endl;
    }
}

/*
 * readFromFile()
 * 
 * Purpose:   Reads in data lines from named file
 * Arguments: Name of file as string
 * Returns:   False if cannot open file, true otherwise
 * Notes:     Uses getline
 * 
 */
bool NameList::readFromFile(string filename)
{
    ifstream input;
    string   line;

    input.open(filename);
    if (not input.is_open()) {
        return false;
    }

    getline(input, line);
    while (not input.eof()) {
        add(line);
        getline(input, line);
    }

    input.close();
    return true;
}

/*
 * expand()
 * 
 * Purpose:   Doubles the ArrayList's capacity by allocating a new array 
 *            twice the size of the current array
 * Arguments: None
 * Returns:   None
 * Notes:     None
 * 
 */
void NameList::expand()
{
    int new_size = 2*capacity;
    string *arr_new;
    arr_new = new string[new_size];
    for (int i = 0; i < new_size; i++){
        arr_new[i] = data[i];
    }
    delete [] data; 
    data = arr_new;
}
