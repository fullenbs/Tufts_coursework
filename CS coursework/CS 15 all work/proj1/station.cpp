/*
 *  station.cpp
 *  Scott Fullenbaum
 *  2/12/2022
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Implementation for class for station class
 *
 */

#include "station.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

/*
 * name: Station default coonstructor
 * purpose: Make an empty station with no information 
 * arguments: None
 * returns: None
 */
station::station(){
}

/*
 * name: Constructor for reading in file
 * purpose: Initialize list of stations
 * arguments: None
 * returns: None
 */
station::station(std::string filename){
    std::ifstream input;
    std::string line;

    input.open(filename);
    while (not input.eof()){ //reads all the stations in
        station_info new_station;
        PassengerQueue queue;
        getline(input, line);
        if (not line.empty()){
            new_station.name = line;
            new_station.queue = queue;
            Station_List.push_back(new_station);
        }
    }
    input.close();
}

/*
 * name: Destructor for station class
 * purpose: Clear up memory and end processes
 * arguments: None
 * returns: None
 */
station::~station(){
    //Not needed
}

/*
 * name: list_size()
 * purpose: Gets number of stations currently in the list
 * arguments: None
 * returns: Integer
 */
int station::list_size(){
    return Station_List.size();
}

/*
 * name: new_passenger
 * purpose: Adds a passenger at a given station
 * arguments: The passenger being added, and the pos of the station
 * returns: None
 */
void station::new_passenger(Passenger p, int element){
    Station_List.at(element).queue.enqueue(p);
}

/*
 * name: print_one_station()
 * purpose: Prints out station at given index
 * arguments: None
 * returns: None
 */
void station::print_one(std::ostream &output, int curr_station){
    station_info temp = Station_List.at(curr_station);
    PassengerQueue temp_queue = temp.queue;
    output << "[" << curr_station << "] " << temp.name << " ";
    output << "{";
    temp_queue.print(output);
    output << "}" << endl;
}

/*
 * name: print_all_station()
 * purpose: Prints all stations currently in list
 * arguments: None
 * returns: None
 */
void station::print_all(std::ostream &output){
    for (unsigned int i = 0; i < Station_List.size(); i++){
        print_one(output, i);
    }
}

/*
 * name: get_front()
 * purpose: Returns first passenger in the queue at a given station
 * arguments: The station
 * returns: The passenger
 */
Passenger station::get_front(int curr_station){
    return Station_List.at(curr_station).queue.front();
}

/*
 * name: remove_from_queue()
 * purpose: Dequeues first element at a given station
 * arguments: The station
 * returns: The passenger
 */
void station::remove_from_queue(int curr_station){
    Station_List.at(curr_station).queue.dequeue();
}

/*
 * name: queue_size()
 * purpose: Gets size of queue at a given station
 * arguments: Index of station
 * returns: Size of queue
 */
int station::queue_size(int curr_station){
    return Station_List.at(curr_station).queue.size();
}

/*
 * name: station_name()
 * purpose: Returns station_name at a given index
 * arguments: Index of station
 * returns: Station_name
 */
std::string station::station_name(int curr_station){
    return Station_List.at(curr_station).name;
}