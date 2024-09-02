//
//                         CardLinkedList.cpp
//
//           A class that manages a linked list of cards
//
//  The data are stored as a singly-linked sequence of nodes accessed
//  from a single pointer (in the data member 'm_front') to the first
//  node in the list (or the nullptr if the list is empty). Each node
//  has a Card instance named card.
//
//  Author: Noah Mendelsohn 
//
//  Tufts University, Fall 2021
//  CS 11: Project 2
//
//  Modified by: Scott Fullenbaum
//  Date: 11/19/21
// 
//  Anything else you would like to include:
//
/**********************************************************/
/***      Students: Fill in the TODO items below        ***/
/***  You may add additional private member functions   ***/
/**********************************************************/

#include <iostream>
#include <iomanip>     // gets setw for debug printing
#include <string>

#include "CardLinkedList.h"

using namespace std;

/*------------------------------------------------------------------
 *                    Constructor(s) and Destructor
 *----------------------------------------------------------------*/

//
// Purpose:  Constructor initializes an empty list
//
CardLinkedList::CardLinkedList()
{
    m_front = nullptr;
    m_list_length = 0;
}

//
// Purpose:  Destructor recycles the space associated with all nodes
//           in the list
//
CardLinkedList::~CardLinkedList()
{
    unsigned int temp = m_list_length; 
    for (unsigned int i = 0; i < temp; i++){
        remove_card_at(0);
    }
}

/*------------------------------------------------------------------
 *          Public functions to manipulate and query the list
 *----------------------------------------------------------------*/

//
// Purpose:  Return the current size of the list
//           i. e., the number of words/nodes in the list
//
unsigned int CardLinkedList::num_cards()
{
    return m_list_length;
}


//
// Purpose:  Add Card node to the list at the specified position. If index is
//           out of range then return quietly
//
//           Recycles the node containing the word (and its count)
//
void CardLinkedList::add_card_at(unsigned int index, Card c)
{
    //three cases: end of list, beginning of list, middle of list
    if (index == num_cards() and index != 0){
        add_end_list(c);
     } else if (index == 0 or m_list_length == 0){
         add_beginning_list(c);
     } else if (index < num_cards()){
         insert_in_list(index, c);
     }
}

//add_beginning_list
// Parameters: Card c
// Purpose: Add a card c to the beginning of the linked List
// Returns: Nothing
void CardLinkedList::add_beginning_list(Card c)
{
    Node *pos;
    pos = new_Node(c, m_front);
    m_front = pos; 
    m_list_length++;
}

//add_end_list
//Parameters: Card you want added 
//Purpose: Adds a card to the end of the linked List
//Returns: Nothing
void CardLinkedList::add_end_list(Card c)
{
    Node *temp = m_front;
    Node *pos;
    while (temp->next != nullptr){ //finds last node
        temp = temp->next;
    }
    pos = new_Node(c, nullptr);
    temp->next = pos;
    m_list_length++;
}

//insert_in_list
//Parameters: Index where card is added, and card you want added 
//Purpose: Adds a card to the middle of the list, at given index 
//Returns: Nothing 
void CardLinkedList::insert_in_list(unsigned int index, Card c)
{
    Node *temp = m_front;
    Node *second, *pos;
    //finds loc of where node needs to go 
    for (unsigned int i = 0; i < index-1; i++){ 
        second = temp;
        temp = temp->next;
    }
    
    pos = new_Node(c, second);    
    pos->next = temp->next;
    temp->next = pos;
    m_list_length++;
}

//
// Purpose:  Remove word from the list.  That is, it removes and
//           recycles the node containing the word (and its count)
//
void CardLinkedList::remove_card_at(unsigned int index)
{
    //three cases: end of list, beginning of list, middle of list
    if (index == 0){
        remove_card_at_beg();
    } else if (index + 1 == num_cards()){
        remove_card_at_end();
    } else if (index < num_cards()) {
        remove_card_at_mid(index);
    }
}


//remove_card_at_end
//Parameters: None
//Purpose: Removes the last node of a linked List
//Returns: Nothing
void CardLinkedList::remove_card_at_end()
{
    Node *end;
    Node *temp = m_front;

    while (temp->next != nullptr){
        end = temp;
        temp = temp->next;
    }
    delete temp;
    end->next = nullptr;
    m_list_length--;
}

//remove_card_at_beg
//Parameters: None
//Purpose: Remove the first node of a linked list 
//Returns: Nothing
void CardLinkedList::remove_card_at_beg(){
    m_list_length--;
    Node *temp = m_front;
    m_front = temp->next;
    delete temp;
}

//remove_card_at_mid
//Parameters: Index of card
//Purpose: Remove node at given index and recycle space 
//Returns: Nothing 
void CardLinkedList::remove_card_at_mid(unsigned int index){
    Node *temp = m_front;
    Node *second;
    m_list_length--;
    for (unsigned int i = 0; i < index; i++){
        second = temp;
        temp = temp->next;
    }
    second->next = temp->next;
    delete temp;
}

//
// Purpose:  Return the index-th element of the list
// Params:   index must be in range [0 .. size) where
//           size is the number of words stored in the list
// Effects:  if index is out of range, prints error message and returns
//           NO_CARD_HERE
Card CardLinkedList::get_card_at(unsigned int index)
{
    Node *temp = m_front;
    if (index > m_list_length){
        cerr << "THIS CARD DOES NOT EXIST" << endl;
        return NO_CARD_HERE;
    } else {
    for (unsigned int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->card;
    }
    return temp->card;
    
}

void CardLinkedList::mystery(){
    Node *t = nullptr;
    Node *t2;
    Node *np = m_front;
    
    while(np != nullptr){
        t2 = np->next;
        np->next = t;
        t = np;
        np = t2;
    }
    m_front = t;
    for (Node *np = m_front; np != nullptr; np = np->next){
        cout << np->card.value() << endl;
    }
}
//new_Node
//Parameters: Card and pointer
//Purpose: Creates a node with card c using input pointer
//Returns: The new Node 
CardLinkedList::Node *CardLinkedList::new_Node(Card c, Node *ptr)
{
    Node *result = new Node;
    result->card = c;
    result->next = ptr;
    return result;
}

//
// Purpose:  Print out the underlying list to cout
// Effects:  Prints to cout
// Notes:    This function is here for debugging purposes.
//           It will not be called in the final version of the program.
//           Still LEAVE IT AS-IS:  WE WILL USE IT FOR TESTING.
//
void CardLinkedList::debug_print()
{
    int index_num = 0;

    cout << "DEBUG: CardLinked List (num_cards = " << num_cards()
         << ") ["  << endl;
    cout <<  "  Index_num   Node Address  Face Value" << endl;
    for (Node *curr_p = m_front; curr_p != nullptr; curr_p = curr_p->next) {
        cout <<  setw(9) << index_num++;
        cout <<  setw(16) << curr_p;
        cout <<  "       ";
        curr_p->card.debug_print();
        cout << endl;
    }
    cout << "]" << endl;
}

