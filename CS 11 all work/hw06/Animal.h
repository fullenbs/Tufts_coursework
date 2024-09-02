//*********************************************************************
//
//                             Animal.h
//       
//        Interface to a class representing a single animal
//
//  Author:  Noah Mendelsohn
//  Date:    April 6, 2021
//
//                        DO NOT MODIFY THIS FILE
//
//*********************************************************************

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <fstream>

class Animal
{
public:
        Animal();                     // No argument constructor
        Animal(ifstream& input_file); // Construct from file input

        // Accessor functions
        std::string name();
        std::string origin();
        std::string diet();
        std::string ear_size();
        std::string classification();

        // Print function
        void print();


private:
        // Note: in these variables, m_ suggests that this is a member
        std::string m_name; 
        std::string m_origin;         // Continents
        std::string m_diet;           // Carnivore, Herbivore, Omnivore
        std::string m_ear_size;       // Large, Medium, Small, None
        std::string m_classification; // Mammal, Reptile, Avian, Insect, Fish

//////////////////////////////////////////////////////////////////
        // Following is used for grading your submission
        // YOU MUST LEAVE THIS HERE
        // Do NOT implement the AnimalDB_Tester class.
        friend class AnimalDB_Tester;  
};

#endif
