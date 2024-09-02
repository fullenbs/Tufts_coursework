/*
 *  CharLinkedList.cpp
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  Implementation for CharLinkedList
 *
 */

#include "CharLinkedList.h"
#include <iostream>
#include <sstream>
using namespace std;

/*
 * name: Constructor for empty list
 * purpose: Creates a linked list with zero nodes
 * arguments: None
 * returns: None
 */
CharLinkedList::CharLinkedList() {
    front     = nullptr;
    list_size = 0;
}

/*
 * name: Constructor with one char
 * purpose: Creates a linked list with one node
 * arguments: The character the only node has
 * returns: None
 */
CharLinkedList::CharLinkedList(char c) {
    Node *first = newNode(c, nullptr, nullptr);
    front       = first;
    list_size   = 1;
}

/*
 * name: Constructor for array of chars
 * purpose: Creates a linked list with several nodes
 * arguments: The array of characters and the size of the array
 * returns: None
 */
CharLinkedList::CharLinkedList(char arr[], int size) {
    list_size = 0;
    front     = nullptr;
    for (int i = size - 1; i >= 0; i--) {
        pushAtFront(arr[i]);
    }
}


/*
 * name: Copy constructor
 * purpose: Creates a copy linked list from another linked list
 * arguments: The linked list being copies
 * returns: None
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other) {
    list_size = 0;
    front     = nullptr;

    for (int i = 0; i < other.size(); i++) {
        pushAtBack((other.recurNode(other.front, i))->data);
    }
}

/*
 * name: Overloads assignment operator
 * purpose: Allows to assign a deep copy
 * arguments: The linked list being copies
 * returns: None
 */
CharLinkedList &CharLinkedList::operator=(const CharLinkedList &other) {
    if (this == &other) { return *this; }

    this->clear(); // clears current list
    list_size = 0;
    front     = nullptr;

    for (int i = 0; i < other.size(); i++) {
        this->pushAtBack(other.elementAt(i));
    }
    return *this;
}

/*
 * name: Deconstructor
 * purpose: Clears memory
 * arguments: None
 * returns: None
 */
CharLinkedList::~CharLinkedList() {
    clear();
}

/*
 * name: isEmpty
 * purpose: Checks if list is empty
 * arguments: None
 * returns: True if empty, false if not
 */
bool CharLinkedList::isEmpty() const {
    return (list_size == 0);
}

/*
 * name: size
 * purpose: Give user size of linked list
 * arguments: None
 * returns: Size of Linked list
 */
int CharLinkedList::size() const {
    return list_size;
}


char CharLinkedList::first() const {
    if (isEmpty()) { // throws error
        throw runtime_error("cannot get first of empty LinkedList");
    }
    return elementAt(0);
}

char CharLinkedList::last() const {
    if (isEmpty()) {
        throw runtime_error("cannot get last of empty LinkedList");
    }
    return elementAt(size() - 1);
}


/*
 * name: pushAtFront
 * purpose: Adds a character to a new node at front of list
 * arguments: Character being added
 * returns: None
 */
char CharLinkedList::elementAt(int index) const {
    if (index < 0 or index >= size()) {
        throw range_error("index (" + std::to_string(index) +
                          ") not in range [0.." + std::to_string(size()) + ")");
    } // throws error
    Node *temp = recurNode(front, index);
    return temp->data;
}

/*
 * name: toString()
 * purpose: Displays the LinkedList nodes as a string
 * arguments: None
 * returns: String output in accordance to spec
 */
std::string CharLinkedList::toString() const {
    std::string combine = "";

    Node *curr = front;
    while (curr != nullptr) {
        combine = combine + curr->data;
        curr    = curr->next;
    }
    return "[CharLinkedList of size " + std::to_string(size()) + " <<" +
           combine + ">>]";
}

/*
 * name: toReverseString()
 * purpose: Displays the LinkedList nodes as a string in reverse order
 * arguments: None
 * returns: String output in accordance to spec
 */
std::string CharLinkedList::toReverseString() const {
    std::string combine = "";
    for (int i = size() - 1; i >= 0; i--) {
        combine = combine + elementAt(i);
    }
    return "[CharLinkedList of size " + std::to_string(size()) + " <<" +
           combine + ">>]";
}

/*
 * name: pushAtFront
 * purpose: Adds a character to a new node at front of list
 * arguments: Character being added
 * returns: None
 */
void CharLinkedList::pushAtFront(char c) {
    Node *new_node = newNode(c, nullptr, front);
    if (front != nullptr) {
        front->prev = new_node; // if not empty list, changes prev
    }
    front = new_node;
    list_size++;
}

/*
 * name: pushAtBack
 * purpose: Adds a character to a new node at back of list
 * arguments: Character being added
 * returns: None
 */
void CharLinkedList::pushAtBack(char c) {
    Node *temp = front;

    // needed as if empty list, then can't get value for temp
    if (front != nullptr) { temp = recurNode(front, size() - 1); }

    Node *new_node = newNode(c, nullptr, temp);

    if (front == nullptr) { // edge case if have empty list
        new_node->prev = nullptr;
        front          = new_node;
        list_size++;
        return;
    }
    temp->next     = new_node; // remaps so that new_node is at end
    new_node->prev = temp;
    new_node->next = nullptr;
    list_size++;
}

/*
 * name: insertAt
 * purpose: Adds a char at any position in the linked list
 * arguments: Character being added and where it is added
 * returns: None
 */
void CharLinkedList::insertAt(char c, int index) {
    if (index < 0 or index > size()) {
        throw range_error("index (" + std::to_string(index) +
                          ") not in range [0.." + std::to_string(size()) + "]");
    } // throws error
    Node *temp = front;
    if (index == 0) { // pushAtFront called if empty list
        pushAtFront(c);
    } else if (index == size()) {
        pushAtBack(c);
    } else {
        temp           = recurNode(front, index); // gets node pushed to right
        Node *new_node = newNode(c, nullptr, temp);

        temp->prev->next = new_node; // remaps nodes to insert in mid
        new_node->prev   = temp->prev;
        temp->prev       = new_node;
        list_size++;
    }
}

/*
 * name: clear
 * purpose: Delete all nodes from the list
 * arguments: None
 * returns: None
 */
void CharLinkedList::clear() {
    Node *curr = front;
    while (curr != nullptr) { // goes through each node and deletes it
        Node *end = curr;
        curr      = curr->next;
        delete end;
        list_size--; // need to decrease list size
    }
    delete curr; // just in case
}

/*
 * name: popFromFront()
 * purpose: Removes first node of the list
 * arguments: None
 * returns: None
 */
void CharLinkedList::popFromFront() {
    if (isEmpty()) { throw runtime_error("cannot pop from empty LinkedList"); }
    removeAt(0); // removeAt handles general removal, so call it here
}

/*
 * name: popFromBack()
 * purpose: Removes last node of the list
 * arguments: None
 * returns: None
 */
void CharLinkedList::popFromBack() {
    if (isEmpty()) { throw runtime_error("cannot pop from empty LinkedList"); }
    removeAt(size() - 1); // removeAt handles general removal, so call it here
}

/*
 * name: removeAt
 * purpose: Removes a node at the given position
 * arguments: Index where node is being removed
 * returns: None
 */
void CharLinkedList::removeAt(int index) {
    if (index < 0 or index >= size()) {
        throw range_error("index (" + std::to_string(index) +
                          ") not in range [0.." + std::to_string(size()) + ")");
    } // error thrown if index out of bounds

    Node *del = recurNode(front, index); // gets node being deleted

    // the if statements remap the nodes, checking that the node being
    // deleted isn't at the end or beginning, so nullptr isn't accidently
    // assigned
    if (front == del) { front = del->next; }
    if (del->next != nullptr) { del->next->prev = del->prev; }
    if (del->prev != nullptr) { del->prev->next = del->next; }

    delete del;
    list_size--;
}

/*
 * name: replaceAt
 * purpose: Replaces a node at any given index
 * arguments: Index where replacement happens and what char is replacing it
 * returns: None
 */
void CharLinkedList::replaceAt(char c, int index) {
    if (index < 0 or index >= size()) {
        throw range_error("index (" + std::to_string(index) +
                          ") not in range [0.." + std::to_string(size()) + ")");
    }                                  // throws error
    recurNode(front, index)->data = c; // changes value in node
}

/*
 * name: insertInOrder
 * purpose: Inserts a char in linked list so that it's alphabetically sorted
 * arguments: The char being added
 * returns: None
 */
void CharLinkedList::insertInOrder(char c) {
    Node *curr = front;

    // loops through linked list
    for (int i = 0; i < list_size and curr->next != nullptr; i++) {
        if (c <= curr->data) {
            insertAt(c, i);
            return; // ends loop as insertion occurs and assume list sorted
        }
        curr = curr->next;
    }
    pushAtBack(c); // if not inserted, then it's at end of list
}

/*
 * name: concatenate
 * purpose: Adds a linked list to the end of another linked list
 * arguments: The linked list being added
 * returns: None
 */
void CharLinkedList::concatenate(CharLinkedList *other) {
    // adds each element to end in respective order
    for (int i = 0; i < other->size(); i++) {
        pushAtBack(other->elementAt(i));
    }
}

/******************* Private helper functions are below ***********************/

/*
 * name: recurNode
 * purpose: Recursively finds a node at a certain point
 * arguments: A node, and number of elements left until target node reached
 * returns: A node
 */
CharLinkedList::Node *CharLinkedList::recurNode(Node *curr, int index) const {
    if (index == 0) {
        return curr; // base case
    } else {
        return recurNode(curr->next, index - 1); // recursive case
    }
}


/*
 * name: newNode
 * purpose: Make a new node with a next and prev pointer.
 * arguments: Data of node, and what the prev and next pointers will be.
 * returns: A node
 */
CharLinkedList::Node *CharLinkedList::newNode(char c, Node *left, Node *right) {
    Node *new_node = new Node;
    new_node->data = c;
    new_node->next = right;
    new_node->prev = left;
    return new_node;
}
