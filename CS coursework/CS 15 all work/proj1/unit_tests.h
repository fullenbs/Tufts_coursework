/*
 *  unit_tests.h
 *  Scott Fullenbaum
 *  2/11/2022
 *
 *  MetroSim Unit_test
 *
 *  Tests for Linked List
 *
 */


#include "PassengerQueue.h"
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

//Only test for passenger
void Passenger_print_test(){
    Passenger passenger(0, 2, 5);
    Passenger passenger2;
    
    passenger.print(cout);
    passenger2.print(cout);
}

/************************  PassengerQueue Tests *******************************/
//Checks PassengerQueue enqueue function;
void PassengerQueue_enqueue_test(){
    PassengerQueue test_queue;
    Passenger p1(0, 1, 2);
    test_queue.enqueue(p1);

    assert(test_queue.size() == 1);
}

//Checks PassengerQueue print() function
void PassengerQueue_print_nonempty_test(){
    PassengerQueue test_queue; //test setup
    std::ostringstream ss;
    Passenger p1(0, 1, 2); 
    Passenger p2(2, 3, 4);
    
    test_queue.enqueue(p2); //assumes enqueue works
    test_queue.enqueue(p1);

    test_queue.print(ss);
    assert(test_queue.size() == 2);
    assert(ss.str() == "[2, 3->4][0, 1->2]");
}

//tests print function when given an empty list
void PassengerQueue_print_empty_test(){
    PassengerQueue test_queue;
    std::ostringstream ss;
    test_queue.print(ss);
    assert(ss.str() == "");
}

//tests size() function
void PassengerQueue_size_nonempty_test(){
    PassengerQueue test_queue; //test setup;
    Passenger p1; //doesn't matter if empty passengers
    Passenger p2;
    test_queue.enqueue(p1);
    test_queue.enqueue(p2);

    assert(test_queue.size() == 2);
}

//tests size( function with an empty queue
void PassengerQueue_size_empty_test(){
    PassengerQueue test_queue;
    assert(test_queue.size() == 0);
}

//tests PassengerQueue front() function
void PassengerQueue_nonempty_front_test(){
    PassengerQueue test_queue;
    Passenger p1;
    std::ostringstream ss;
    test_queue.enqueue(p1);
    (test_queue.front()).print(ss);
    assert(ss.str() == "[-1, -1->-1]");
}

//tests PassengerQueue_front with an empty queue
void PassengerQueue_test_empty_front(){
    PassengerQueue test_queue;
    bool           range_error_thrown = false;
    std::string    error_message        = "";
    try{
        test_queue.front();
    } catch (const std::range_error &e){
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown); //if both passed, error thrown properly
    assert(error_message == "Cannot see first in empty list"); 

}
//tests dequeue() with an empty list
//I know we assume correct inputs, but this is to check
void PassengerQueue_dequeue_test(){
    PassengerQueue test_queue;
    bool           range_error_thrown = false;
    std::string    error_message        = "";
    try{
        test_queue.dequeue();
    } catch (const std::range_error &e){
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(range_error_thrown); //if both passed, error thrown properly
    assert(error_message == "Cannot dequeue from empty list"); 
}
/**********************  End PassengerQueue Tests *****************************/
