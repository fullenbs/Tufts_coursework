/*
 * rev.cpp -- NameList driver
 * 
 * Author: Samuel J. Berman (sberma04)
 * 
 * CS 11: Lab 9
 * Tufts University, Fall 2021
 * 
 */

#include <iostream>

#include "namelist.h"

using namespace std;

void commandLoop(NameList *list);
void executeCommand(char command, NameList *list);

int main()
{
    NameList list;

    commandLoop(&list);

    return 0;
}

/*
 * commandLoop()
 * 
 * Purpose:   Prompt users for a command until they enter "q"
 * Arguments: A NameList pointer
 * Returns:   None
 * Notes:     None
 * 
 */
void commandLoop(NameList *list)
{
    char command;
    cout << "Command: ";
    cin >> command;

    while (command != 'q') {
        executeCommand(command, list);
        cout << "Command: ";
        cin >> command;
    }
}

/*
 * executeCommand()
 * 
 * Purpose:   Execute commands that are entered by the user
 * Arguments: A command and a NameList pointer
 * Returns:   None
 * Notes:     None
 * 
 */
void executeCommand(char command, NameList *list)
{
    if (command == 's') {
        cout << list->getSize() << endl;
    } else if (command == 'c') {
        cout << list->getCapacity() << endl;
    } else if (command == 'v') {
        int index;
        cin >> index;
        cout << list->getValAt(index) << endl;
    } else if (command == 'a') {
        string element;
        cin >> element;
        list->add(element);
    } else if (command == 'i') {
        string element;
        int index;
        cin >> element >> index;
        list->insertAt(element, index);
    } else if (command == 'p') {
        list->print();
    } else if (command == 'r') {
        list->revPrint();
    } else if (command == 'f') {
        string filename;
        cin >> filename;
        list->readFromFile(filename);
    } else {
        cout << "Command not found." << endl;
    }
}
