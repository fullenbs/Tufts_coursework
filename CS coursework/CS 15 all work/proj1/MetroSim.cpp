/* 
 *  MetroSim.cpp
 *  Scott Fullenbaum
 *  2/15/2022
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Implementation for MetroSim class, carries out the gameplay
 *
 */


#include "MetroSim.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


/*
 * name: Constructor for game with no commands given
 * purpose: Sets up station and passengers 
 * arguments: station_file and file where outputs are directed to
 * returns: None
 */
MetroSim::MetroSim(string station_file, string output_file){
    station temp(station_file);
    stations = temp;
    for (int i = 0; i < stations.list_size(); i++){
        PassengerQueue queue;
        train.push_back(queue);
    }

    num_files = 2;
    dest.open(output_file); //already know it can be opened properly
}

/*
 * name: Constructor for game with commands given
 * purpose: Sets up station and passengers 
 * arguments: station file, file for inputs and outputs
 * returns: None
 */
MetroSim::MetroSim(string station_file, string output_file, string commands){
    station temp(station_file);
    stations = temp;
    for (int i = 0; i < stations.list_size(); i++){
        PassengerQueue queue;
        train.push_back(queue);
    }

    num_files = 3;
    dest.open(output_file); //already know it can be opened properly 
    comms.open(commands); 
}


/*
 * name: Destructor 
 * purpose: Clear up any memory and closes all files
 * arguments: None
 * returns: None
 */
MetroSim::~MetroSim(){
    dest.close();
    comms.close();
}

/*
 * name: game_loop 
 * purpose: Runs the main gameplay loop
 * arguments: None
 * returns: None
 */
void MetroSim::game_loop(){
    string c = "";
    while (in_prog){
        display(cout);
        if (num_files == 2){ //if commands are not given
            c = command(cin); 
        } else { //if commands are not given
            c = command(comms);
        }
        det_com(c);
    }
}

/*
 * name: display 
 * purpose: Gives the display for the game
 * arguments: Output stream
 * returns: None
 */
void MetroSim::display(std::ostream &output){
    print_train(output); //prints out passengers
    for (int i = 0; i < stations.list_size(); i++){ //prints out stations
        if (loc != i){
            output << "       "; 
        } else {
            output << "TRAIN: ";
        }
        stations.print_one(output, i);
    }
}

/*
 * name: det_com 
 * purpose: Parses user input into an array of strings, to help figure out 
 * which command should be run. 
 * arguments: The string with the command entered. 
 * Note: I know we can ignore invalid inputs, but I chose to make my code read 
 * inputs in correctly for any amount of whitespace, which the reference does.
 * returns: None
 */
void MetroSim::det_com(string s){
    string a; //gets string as string stream
    stringstream s_prime;
    s_prime.str(s);
    s_prime >> a; //reads in first line

    while (not s_prime.fail()){ //adds all of stream to input_arr
        input_arr.push_back(a);
        s_prime >> a;
    }
    run_com(input_arr); //now figures out command
    input_arr.clear(); //empties array list for each iteration
}

/*
 * name: run_com 
 * purpose: Runs a command
 * arguments: The string with the command entered. 
 * returns: None
 */
void MetroSim::run_com(std::vector<string> arr){
    int p, q;
    if (arr.at(0) == "m" and arr.at(1) == "f"){
        end_game(cout); //means game has ended
    } else if (arr.at(0) == "m" and arr.at(1) == "m"){
        move_station(); //
    } else if (arr.at(0) == "p"){
        try{ //If the other two inputs are numbers, we can add a passenger
            p = stoi(arr[1]); //stoi is string to int
            q = stoi(arr[2]);
        } catch (const std::invalid_argument &e){
            return; //invalid, so don't run anything
        }
        add_passenger(tot_passengers, p, q);
    }
}

/*
 * name: game_loop 
 * purpose: Runs the main gameplay loop
 * arguments: None
 * returns: None
 */
std::string MetroSim::command(std::istream &input){
    string s;
    cout << "Command? ";
    getline(input, s);
    return s;
}

/*
 * name: end_game 
 * purpose: Ends the game
 * arguments: None
 * returns: None
 */
void MetroSim::end_game(std::ostream &output){
    in_prog = false;
    output << "Thanks for playing MetroSim. Have a nice day!" << endl;
}

/*
 * name: add_passenger
 * purpose: Adds a passenger to the train
 * arguments: None
 * returns: None
 */
void MetroSim::add_passenger(int id, int arrive, int dep){
    //edge case if outside range, from reference implementation
    if (arrive > stations.list_size() or dep > stations.list_size()){
        cerr << "Floating exception" <<  endl;
        exit(1);
    }
    Passenger temp(id, arrive, dep);
    stations.new_passenger(temp, arrive);
    tot_passengers++;
}

/*
 * name: move_station
 * purpose: Moves the train from one station to the next
 * arguments: None
 * returns: None
 */
void MetroSim::move_station(){
    int size = stations.queue_size(loc); //vars want to keep track of

    //first line adds first person in line at station to train, second line
    //removes that passenger from the queue
    for (int i = 0; i < size and size != 0; i++){
        if (size != 0){
            Passenger temp = stations.get_front(loc);
            train.at(temp.to).enqueue(temp);
            stations.remove_from_queue(loc);
        }
    }    
    depart(dest); //moves train loc and remmoves arrivals
}

/*
 * name: depart()
 * purpose: Function that handles when train arrives at new station
 * arguments: None
 * returns: None
 */
void MetroSim::depart(std::ostream &output){
    //moves train to next stop, resets to front if at end
    if (loc >= stations.list_size()-1){ 
        loc = 0;
    } else {
        loc++;
    }
    //dequeues and sends passenger info to output
    int size = train.at(loc).size();
    for (int i = 0; i < size; i++){
        Passenger  p = train.at(loc).front();
        output << "Passenger " << p.id << " left train at station " << 
        stations.station_name(loc) << endl;
        train.at(loc).dequeue();
    }
}

/*
 * name: print
 * purpose: Prints out the train
 * arguments: Output stream
 * returns: None
 */
void MetroSim::print_train(std::ostream &output){
    output << "Passengers on the train: {";
    for (unsigned int i = 0; i < train.size(); i++){
        train.at(i).print(output);
    }
    output << "}" << endl;
}


