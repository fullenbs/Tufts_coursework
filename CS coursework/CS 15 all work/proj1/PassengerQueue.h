/*
 *  CharLinkedList.h
 *  Scott Fullenbaum
 *  2/10/2022
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Header file for a queue data structure
 *
 */

#ifndef PASSENGER_QUEUE_H
#define PASSENGER_QUEUE_H

#include <list>
#include <iostream>
#include "Passenger.h"

class PassengerQueue {
public:
    PassengerQueue();
    ~PassengerQueue();

    int       size();
    void      print(std::ostream &output);
    void dequeue();
    void enqueue(const Passenger &passenger); 
    Passenger front();

private:
    std::list<Passenger> Queue;  
};


#endif