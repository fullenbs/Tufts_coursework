/*
 *  testing_main.cpp
 *  Scott Fullenbaum
 *  2/13/2022
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Testing_main for anything that falls under week 2
 *  All tests used here assume that PassengerQueue and Passenger implementation
 *  work properly.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "MetroSim.h"
#include "station.h"
#include "PassengerQueue.h"
using namespace std;

//Declares all testing functions, each one explained in function contract
//station tests
bool station_constructor_test(string input);
bool station_print_one_test(string input);
void station_print_all_test(string input);
bool new_passenger_test(string input);
bool station_size_test(string input);
bool get_front_test(string input);
bool queue_size_test(string input);
bool station_name_test(string input);

//MetroSim tests
void setup_test(string input, string output);
bool command_test(string input, string output);
bool end_game_test(string input, string output);
void det_com_parse_test(string input, string output);
void det_com_move_test(string input, string output);
void det_com_end_test(string input, string output);
void test_it_all(string input, string output);


//Roger said it was ok to have a testing main over 30 lines
//All tests here were done using medium_stations.txt unless specified
//otherwise.
//Also, all of these tests are uncommented due to spec guidelines,
//but should leave test_it_all commented out when running, as 
//that plays the game. 
int main(int argc, char *argv[]){
    if (argc != 3){
        cerr << "INCORRECT FILES INPUT" << endl;
        exit(1);
    }
    //for all tests 0 = test failed, 1 = test passed
    cout << "STATION TESTS BEGIN:\n" << endl;
    bool test_1 = station_constructor_test(argv[1]);
    cout << "station_constructor_test: " << test_1 << endl; 
    bool test_2  = station_print_one_test(argv[1]);
    cout << "station_print_one_test: " << test_2 << endl;
    station_print_all_test(argv[1]);
    cout << "End station_print_all_test: " << endl;
    bool test_4 = new_passenger_test(argv[1]);
    cout << "new_passenger_test: " << test_4 << endl;
    bool test_5 = station_size_test(argv[1]);
    cout << "station_size_test: " << test_5 << endl;
    bool test_6 = get_front_test(argv[1]);
    cout << "get_front_test: " << test_6 << endl;
    bool test_7 = queue_size_test(argv[1]);
    cout << "queue_size_test: " << test_7 << endl;
    bool test_8 = station_name_test(argv[1]);
    cout << "station_name_test: " << test_8 << endl;

    cout << "STATION TESTS END\n\n";
    cout << "METROSIM TESTS BEGIN:\n";

    setup_test(argv[1], argv[2]);
    bool test_12 = command_test(argv[1], argv[2]);
    cout << "command_test: " << test_12 << endl;
    bool test_13 = end_game_test(argv[1], argv[2]);
    cout << "end_game_test: " << test_13 << endl;
  
    det_com_parse_test(argv[1], argv[2]);
    cout << "End det_com_parse_test" << endl;
    det_com_end_test(argv[1], argv[2]);
    cout << "End det_come_end_test" << endl;
    det_com_move_test(argv[1], argv[2]);
    cout << "End det_com_move_test" << endl;
    test_it_all(argv[1], argv[2]);

    return 0;
}

/*
 * name: station_constructor_test()
 * purpose: Tests station class constructor works
 * arguments: File read in 
 * returns: True if test successful, false otherwise
 */
bool station_constructor_test(string input){
    station test_station(input);
    if (test_station.list_size() == 10){ 
        return true;
    }
    return false;
}

/*
 * name: station_print_one_test()
 * purpose: Checks that can correctly print out one station 
 * arguments: File read in 
 * returns: True if test successful, false otherwise
 */
bool station_print_one_test(string input){
    station test_station(input);
    std::ostringstream ss;
    test_station.print_one(ss, 0);
    if (ss.str() == "[0] Colonel Sanders {}\n"){ 
        return true;
    }
    return false;
}

/*
 * name: station_print_all_test
 * purpose: Checks all stations printed out properly
 * arguments: File read in 
 * returns: True if test successful, false otherwise
 */
void station_print_all_test(string input){
    //Writing a string for this is a bit too much so I manually checked 
    //that everything was added
    station test_station(input);
    test_station.print_all(cout);
}

/*
 * name: new_passenger_test
 * purpose: Checks that you can add a passenger to the list
 * arguments: File read in 
 * returns: True if test successful, false otherwise
 */
bool new_passenger_test(string input){
    station test_station(input);
    std::ostringstream ss;
    Passenger p;
    test_station.new_passenger(p, 0);
    test_station.print_one(ss, 0);
    if (ss.str() == "[0] Colonel Sanders {[-1, -1->-1]}\n"){
        return true;
    }
    return false;
}

/*
 * name: station_size_test
 * purpose: Checks can get size and number of stations in list
 * arguments: File read in 
 * returns: True if test successful, false otherwise
 */
bool station_size_test(string input){
    station test_input(input);
    
    if (test_input.list_size() == 10){
        return true;
    }
    return false;
}

/*
 * name: get_front_test
 * purpose: Checks can get first person at any station
 * arguments: File read in 
 * returns: True if test successful, false otherwise
 */
bool get_front_test(string input){
    station test_input(input);
    Passenger p;
    test_input.new_passenger(p, 0);
    if (test_input.get_front(0).id == -1){
        return true;
    }
    return false;
}

/*
 * name: queueu_size_test
 * purpose: Checks can get size of queue at any station
 * arguments: File read in 
 * returns: True if test successful, false otherwise
 */
bool queue_size_test(string input){
    station test_input(input);
    if (test_input.queue_size(0) == 0){
        return true;
    }
    return false;
}

/*
 * name: station_name_test
 * purpose: Checks properly get name at each station
 * arguments: File read in 
 * returns: True if test successful, false otherwise
 */
bool station_name_test(string input){
    station test_input(input);
    if (test_input.station_name(0) == "Colonel Sanders"){
        return true;
    }
    return false;
}

/******************************* MetroSim tests *******************************/


/*
 * name: setup_test
 * purpose: Tests MetroSim properly sets up game state
 * arguments: File name as string
 * returns: Nothing
 * Notes: this isn't meant to be a perfect check, this info is best verified
 * by diff testing, which will be performed later.
 */
void setup_test(string input, string output){
    MetroSim metrosim(input, output);
    std::ostringstream ss;
    metrosim.display(ss);
    cout << ss.str(); 
}

/*
 * name: command_test
 * purpose: Tests that a command is read in and returned
 * arguments: File name as string
 * returns: True if successful, false otherwise
 */
bool command_test(string input, string output){
    MetroSim metrosim(input, output);
    string s = metrosim.command(cin); 
    if (s == "m f"){ //just any string, assume entered m f
        return true;
    }
    return true;
}

/*
 * name: end_game_test
 * purpose: Tests that game is ended properly
 * arguments: File name as string
 * returns: True if successful, false otherwise
 */
bool end_game_test(string input, string output){
    MetroSim metrosim(input, output);
    std::ostringstream ss;
    metrosim.end_game(ss);
    if (ss.str() == "Thanks for playing MetroSim. Have a nice day!\n"){
        return true;
    }
    return false;   
}

/*
 * name: det_com_parse_test
 * purpose: Tests that program can properly read in command to add passenger
 * arguments: File name as string
 * returns: True if successful, false otherwise
 */
void det_com_parse_test(string input, string output){
    MetroSim metrosim(input, output);
    metrosim.det_com("m f");
}

/*
 * name: det_com_move_test
 * purpose: Tests that Program can move properly
 * arguments: File name as string
 * returns: True if successful, false otherwise
 */
void det_com_move_test(string input, string output){
    MetroSim metrosim(input, output);
    metrosim.display(cout);
    metrosim.move_station();
    metrosim.display(cout);
}

/*
 * name: det_com_end_test
 * purpose: Tests that correct command ends the game
 * arguments: File name as string
 * returns: True if successful, false otherwise
 */
void det_com_end_test(string input, string output){
    MetroSim metrosim(input, output);
    metrosim.det_com("m f"); //End statement should be printed
}

/*
 * name: test_it_all
 * purpose: Runs the game with input and output files given
 * arguments: Both file names as strings
 * returns: Returns true either way
 */
void test_it_all(string input1, string input2){
     MetroSim metrosim(input1, input2);
     metrosim.game_loop();
}
