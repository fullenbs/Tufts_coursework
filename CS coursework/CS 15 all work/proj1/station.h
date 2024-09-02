/*
 *  station.h
 *  Scott Fullenbaum
 *  2/12/2022
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Interface for station class. The station class is a linked list that 
 *  stores a PassengerQueue and a station name.
 *
 */


#ifndef STATION_H
#define STATION_H


#include <vector>
#include <iostream>
#include "PassengerQueue.h"

class station{
public:
    station();
    station(std::string filename);
    ~station();

    void print_one(std::ostream &output, int curr_station);
    void print_all(std::ostream &output);
    Passenger get_front(int curr_station); //gets first of station
    void remove_from_queue(int curr_station); //dequeues from train
    void new_passenger(Passenger p, int element);
    int queue_size(int curr_station);

    void get_station(int curr_station);
    int list_size(); 
    std::string station_name(int curr_station);

private:
    struct station_info{
        std::string name;
        PassengerQueue queue;
    };

    std::vector<station_info> Station_List;
};

#endif