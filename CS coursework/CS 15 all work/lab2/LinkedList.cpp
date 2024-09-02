/*
 * LinkedList.cpp
 *
 * COMP 15 homework 1
 * by Tyler Calabrese, January 2020
 * Edited by Matt Russell, Juliana Vega, and Alexis Blair, Jan 2021
 *
 * An implementation of the LinkedList interface, the LinkedList can be used
 * to store Planets.
 *
 * NOTE: This is implemented using a singly-linked list with no back pointer.
 */
#include "LinkedList.h"
#include <sstream>
#include <string>

/* Purpose: Initializes an empty LinkedList */
LinkedList::LinkedList() {
    front = nullptr;
    size  = 0;
}

LinkedList::~LinkedList() {
    int temp_var = size;
    for (int i = 0; i < temp_var; i++) {
        Node *end; // it's not perfect, but it works as a deconstuctor
        Node *temp = front;
        while (temp->next != nullptr) {
            end  = temp;
            temp = temp->next;
        }
        delete temp;
        end->next = nullptr;
    }
}

/* toString
 *    Purpose: Report the state of the list as a string
 * Parameters: None
 *    Returns: A string with the state of the list
 */
std::string LinkedList::toString() const {
    std::stringstream ss;
    ss << "LinkedList of size " << this->size << "\n";
    ss << "---------------------\n";

    Node *curr = this->front;
    while (curr != nullptr) {
        ss << curr->toString() << "\n";
        curr = curr->next;
    }

    return ss.str();
}


/* pushAtFront
 *    Purpose: Adds a Planet to the front of the list
 * Parameters: The Planet to be added to the list
 *    Returns: None
 */
void LinkedList::pushAtFront(Planet p) {
    Node *pos;
    pos   = newNode(p, front);
    front = pos;
    size++;
}


/* ****************************************
 * TODO: implement the reverse function
 * ****************************************
 * reverse
 *    Purpose: Reverses the list
 * Parameters: None
 *    Returns: None
 */
void LinkedList::reverse() {}


/*
 *    Purpose: Adds a Planet to the back of the list
 * Parameters: The Planet to be added to the list
 *    Returns: None
 */
void LinkedList::pushAtBack(Planet p) {
    Node *pos;
    pos = newNode(p, nullptr);

    if (front == nullptr) {
        front = pos; // in case empty list
    } else {
        Node *temp = front;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = pos;
    }
    size++;
}

/*
 *    Purpose: Create a node
 * Parameters: Planet stored at node, and where node is pointing to
 *    Returns: The new node
 */
LinkedList::Node *LinkedList::newNode(Planet p, Node *next) {
    Node *new_node = new Node;
    new_node->info = p;
    new_node->next = next;
    return new_node;
}
