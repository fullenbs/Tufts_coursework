//*********************************************************************
//
//                         Animal_Array_List.h
//       
//        Interface to a class representing an array list
//        of animals
//
//        Author:  Noah Mendelsohn
//        Date:    April 6, 2021
//
//                        DO NOT MODIFY THIS FILE
//
//*********************************************************************


#ifndef ANIMALARRAYLIST_H
#define ANIMALARRAYLIST_H

#include <string>
#include "Animal.h"

class Animal_Array_List
{

public:
         //
         // Default constructor
         // 
        Animal_Array_List();

         //
         // Frees heap-allocated memory associated with arraylist
         // 
        ~Animal_Array_List();

         //
         // Adds a to the back of the list.
         // Effects: may expand if necessary
         // 
        void add(Animal a);

         //
         // Returns the number of Animals currently stored
         // 
        int num_animals();

         //
         // Returns the Animal located at position index  
         // 
        Animal animal_at(int index);

         //
         // Useful for debugging: prints the entire array.
         // This function will not be tested but should be here
         // 
        void print();

         //
         //  DO NOT REMOVE OR CHANGE THE FOLLOWING...
         //  IT IS NEEDED FOR TESTING YOUR CODE
         //
        friend class AnimalTesting;

private:
        const static int INITIAL_CAPACITY = 4;

        Animal *animals;
        int     m_num_animals;
        int     m_capacity;

        //
        // Doubles the capacity of the animals array
        //
        void expand();

//////////////////////////////////////////////////////////////////
        // The following is used for grading your submission
        // YOU MUST LEAVE THIS HERE
        // Do NOT implement the AnimalDB_Tester class.
        friend class AnimalDB_Tester;  
};

#endif
