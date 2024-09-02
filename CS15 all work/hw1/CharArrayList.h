/*
 *  CharArrayList.h
 *  Scott Fullenbaum
 *  1/26/2022
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  Header file for an ArrayList that stores characters
 *
 */
#ifndef CHAR_ARRAY_LIST_H
#define CHAR_ARRAY_LIST_H

#include <string>
// an instance of the class is used to store an ordered list of characters
class CharArrayList {
public:
    CharArrayList(); // Constructors and deconstructors
    CharArrayList(char c);
    CharArrayList(char arr[], int size);
    CharArrayList(const CharArrayList &other);
    ~CharArrayList();

    CharArrayList &operator=(const CharArrayList &other);

    bool isEmpty() const; // getter functions
    int  size() const;
    char first() const;
    char last() const;
    char elementAt(int index) const;

    std::string toString() const; // functions that return string outputs
    std::string toReverseString() const;

    void pushAtBack(char c); // manipulate ArrayList in some way
    void pushAtFront(char c);
    void insertAt(char c, int index);
    void insertInOrder(char c);
    void popFromFront();
    void popFromBack();
    void removeAt(int index);
    void replaceAt(char c, int index);
    void concatenate(CharArrayList *other);
    void shrink();
    void clear();

private:
    int   numChar; // ArrayList properties
    int   capacity;
    char *arr_char;

    void expand(); // helper functions
    void popFromMid(int index);
    void pushAtMid(char c, int index);
};

#endif
