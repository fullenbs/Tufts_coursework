/*  Passenger.cpp
 *  Scott Fullenbaum
 *  2/13/2022
 *
 *  CS 15 Proj1 MetroSim
 *
 *  Implementation for Passenger struct
 *
 */

#include "Passenger.h"
#include <iostream>
#include <string>

/*
 * name: print
 * purpose: Prints out a passenger
 * arguments: None
 * returns: None
 */
void Passenger::print(std::ostream &output){
    output << "[" + std::to_string(id) + ", " +
                std::to_string(from) + "->" + std::to_string(to) + "]";
    
}
