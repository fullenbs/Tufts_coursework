/*
 *  CharLinkedList.cpp
 *  Scott Fullenbaum
 *  2/10/2022
 *
 *  CS 15 Proj1 MetroSim
 *
 *  Implementation for PassengerQueue
 *
 */

#include "PassengerQueue.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

/*
 * name: Constructor for the queue
 * purpose: Initialize PassengerQueue object, though serves no purpose
 * arguments: None
 * returns: None
 */
PassengerQueue::PassengerQueue(){
    //Empty constructor, std::list makes the constructor for us
}

/*
 * name: Destructor
 * purpose: Deletes the queue
 * arguments: None
 * returns: None
 */
PassengerQueue::~PassengerQueue(){
    //empty destructor as use std::list which implements it for us
}

/*
 * name: size()
 * purpose: Returns size of the list
 * arguments: None
 * returns: Integer size of the queue
 */
int PassengerQueue::size(){
    return Queue.size();
}

/*
 * name: front()
 * purpose: To get first node in list
 * arguments: None
 * returns: First node in the last
 */
Passenger PassengerQueue::front(){
    if (Queue.size() == 0){ //just in case
        throw range_error("Cannot see first in empty list");
    }
    return Queue.front();
}

/*
* name: print()
* purpose: Prints out queue to output file
* arguments: None
* returns: None
*/
void PassengerQueue::print(std::ostream &output){
    //found this syntax and using type auto on c++ reference
    for (auto &i: Queue){ 
        i.print(output);
    }
}

/*
* name: dequeue()
* purpose: Removes first node from queue
* arguments: None
* returns: None
*/
void PassengerQueue::dequeue(){
    if (Queue.size() == 0){ //just in case
        throw range_error("Cannot dequeue from empty list");
    }
    Queue.pop_front(); //removes first passenger
}

/*
* name: enqueue()
* purpose: Removes first node from queue
* arguments: None
* returns: None
*/
void PassengerQueue::enqueue(const Passenger &passenger){
    Queue.push_back(passenger);
}
