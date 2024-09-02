/*
 *  DatumStack.h
 *  Scott Fullenbaum
 *  2/26/2022
 *
 *  CS 15 Project 2 CalcYouLater
 *
 *  Header file for DatumStack
 *
 */


#ifndef DATUM_STACK_H
#define DATUM_STACK_H

#include "Datum.h"
#include <vector>

class DatumStack{
public:
    DatumStack();
    DatumStack(Datum elem[], int size);

    ~DatumStack();
    int size(); //gets size
    Datum top(); //gets top of stack
   
    void pop(); //removes from top of stack
    void push(Datum elem); //adds to top 
    void clear(); //clears stack
    bool isEmpty();

private:
    std::vector<Datum> stack;
};

#endif