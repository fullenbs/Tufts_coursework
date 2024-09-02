/*
 *  CharLinkedList.h
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  FILE PURPOSE HERE
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

#include <string>
class CharLinkedList {
public:
    CharLinkedList(); // constructors, destructor, and overloaded assignment
    CharLinkedList(char c);
    CharLinkedList(char arr[], int size);
    CharLinkedList(const CharLinkedList &other);
    ~CharLinkedList();
    CharLinkedList &operator=(const CharLinkedList &other);

    std::string toString() const; // string outputs
    std::string toReverseString() const;

    char first() const; // getter functions for the LinkedList
    char last() const;
    char elementAt(int index) const;
    bool isEmpty() const;
    int  size() const;

    void pushAtFront(char c); // manipulate the LinkedList in some way
    void clear();
    void pushAtBack(char c);
    void insertAt(char c, int index);
    void insertInOrder(char c);
    void popFromFront();
    void popFromBack();
    void removeAt(int index);
    void replaceAt(char c, int index);
    void concatenate(CharLinkedList *other);


private:
    struct Node {
        char  data;
        Node *next;
        Node *prev;
    };
    int   list_size;
    Node *front;

    // private helper functions, explained in CharLinkedList.cpp
    Node *newNode(char c, Node *next, Node *prev);
    Node *recurNode(Node *curr, int index) const;
};

#endif
