//*********************************************************************
//
//                       Animal_Array_list.cpp
//       
//        Member function and constructor/destructor implementations for 
//        the Animal_Array_List class.
//
//  Author: Scott Fullenbaum
//  Date: 11/15/21
//
//  Purpose:  File holds the member functions and constructor for the 
//            Animal_Array_list class.
//   
//
//  Known bugs: Currently none.
//
//  Testing performed: Explained in written.text
//
//*********************************************************************

#include <fstream>
#include <iostream>

using namespace std;

#include "Animal.h"
#include "Animal_Array_List.h"


// *****************************************************************
//         STARTER CODE PROVIDES EMPTY FUNCTION BODIES
// *****************************************************************

//                  ****STUDENT CODE NEEDED HERE***             //

//   
//   FILL IN THE REMAINDER OF THIS FILE WITH DEFINITIONS OF 
//   ALL THE MEMBER FUNCTIONS REQUIRED FOR THE AnimalArrayList
//   TYPE.
//
//   You do not need to update the function contracts.  We have not
//   provided full contracts according to the style guide, but
//   we believe the abbreviated contracts are sufficient here.
//   Just complete the functions.
//

//
// Default constructor
//
Animal_Array_List::Animal_Array_List()
{
    m_capacity = INITIAL_CAPACITY; 
    animals = new Animal[m_capacity];
    m_num_animals = 0;
}

//
// Destructor: Frees heap-allocated memory associated with arraylist
//
Animal_Array_List::~Animal_Array_List()
{
    delete [] animals;
    animals = nullptr;
}

//
// Adds a to the back of the list.
// Effects: may expand if necessary
//
void Animal_Array_List::add(Animal a)
{
    if (m_num_animals >= m_capacity){
        expand();
    }
    
    animals[m_num_animals] = a;
    m_num_animals++;
}

//
// Returns the number of Animals currently stored
//
int Animal_Array_List::num_animals()
{
    return m_num_animals;      
}

//
// Returns the Animal located at position index  
// 
Animal Animal_Array_List::animal_at(int index)
{
    return animals[index];
}

//
// Doubles the capacity of the animals array
//
void Animal_Array_List::expand()
{
    int new_size = 2*m_capacity; //creates new capacity
    
    Animal *arr_new; 
    arr_new = new Animal[new_size];
    //maps each element from animals to the new array
    for (int i = 0; i < m_capacity; i++){
        arr_new[i] = animals[i];
    }
    m_capacity = m_capacity*2; //doubles capacity as well
    
    //Gets rid of the animals array on the heap, then animals is now pointing 
    //to arr_new, which is of twice the size.
    delete [] animals; 
    animals = arr_new; 
}


//
//                       print
//
//       Ask all the Animals in the list to print themselves
//
void Animal_Array_List::print()
{
    for (int i = 0; i < m_num_animals; i++){
        animals[i].print();
    }
}
