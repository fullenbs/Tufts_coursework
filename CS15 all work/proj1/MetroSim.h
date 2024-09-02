/*
 *  MetroSim.h
 *  Scott Fullenbaum
 *  2/15/2022
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Interface for MetroSim class. The train stores an array list of passengers
 *  currently on the train, along with an integer marking where the train is
 *
 */



#ifndef METROSIM_H
#define METROSIM_H

#include "MetroSim.h"
#include "PassengerQueue.h"
#include "station.h"
#include <fstream>
using namespace std;

class MetroSim{
public:
    //first constructor is with two inputs, second is with 3
    MetroSim(string station_file, string output_file);
    MetroSim(string station_file, string output_file, string commands);
    ~MetroSim();

    void game_loop(); //plays the game
    void display(std::ostream &output);
    std::string command(std::istream &input); //reads in commands
    void det_com(string s);


    //three commands
    void move_station(); //m m 
    void add_passenger(int id, int arrive, int dep); // p a b
    void end_game(std::ostream &output); //m f


    //train related functions
    void print_train(std::ostream &output);
    void depart(std::ostream &output);
private:
    station stations; //list of stations

    bool in_prog = true; //for boolean logic
    int tot_passengers = 1; //keeps track of id currently at
    int num_files;  //used for figuring out istream

    string dest_file; //output file name
    ofstream dest; //for sending to file

    ifstream comms; //for reading in commands

    std::vector<PassengerQueue> train; 
    int loc = 0; //location of train

    //helper function for figuring out which command to run
    void run_com(std::vector<string> arr);
   
    std::vector<string> input_arr;
};

#endif