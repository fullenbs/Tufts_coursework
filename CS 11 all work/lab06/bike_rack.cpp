/*
 * CS 11: Lab 06
 * bike_rack.cpp
 *
 * Purpose: To practice reading in data from a file, interacting with
 *          command line arguments, and initializing 2D arrays of structs
 *
 * Written by: Sam Berman (sberma04), Fall 2021
 *
 * Modified by: Sccott Fullenbaum
 *
 */

#include <iostream>
#include <fstream>    // Needed to use ifstream

using namespace std;

// Global constants indicating the size of the 2D array
const int NUM_ROWS = 4;
const int NUM_COLS = 5;

struct Bike
{
    bool   no_bike_here;
    string color;
    int    price;
    string bike_type;
    string owner;
};

// Function declarations
Bike read_one_bike(ifstream &infile);
void print_one_bike(Bike bike_to_print);

int main(int argc, char *argv[]){    
    
    Bike bike_rack [NUM_ROWS][NUM_COLS];
    for (int i = 0; i < NUM_ROWS; i++){
        for (int j = 0; i < NUM_COLS; i++){
            bike_rack[i][j].no_bike_here = true;
        }
    }
    if (argc != 2){
        cerr << "ERROR" << endl;
    }
    
    string filename = argv[1];
    ifstream input_file;   

    input_file.open(filename);

    if (not input_file.is_open()) {
        cerr << "fileread.cpp: could not open file: "
             << filename << endl;
        return 1; // non-zero return from main means error
    }
    
    int num_bike;
    input_file >> num_bike;
    cout << num_bike << endl;
    
    // ================================================================
    int counter =  0; 
    for (int i = 0; i < NUM_ROWS; i++){
        for (int j = 0; j < NUM_COLS; j++){
            counter++;
            if (counter <= num_bike){
            bike_rack[i][j].no_bike_here = false;
            bike_rack[i][j] = read_one_bike(input_file);
            print_one_bike(bike_rack[i][j]);
            }
        }
    }
    
    // ================================================================
    
    // When you are done with a file, you "close" it, which tells C++ 
    // do any cleaning up that is necessary.
    input_file.close();

    return 0;
}

Bike read_one_bike(ifstream &infile){
    Bike bike; 
    infile >> bike.color;
    infile >> bike.price;
    infile >> bike.bike_type;
    infile >> bike.owner;
    return bike;
}

void print_one_bike(Bike bike_to_print)
{
    cout << "Printing Bike's attributes:" << endl;
    cout << "Color: " << bike_to_print.color << endl;
    cout << "Price: $" << bike_to_print.price << endl;
    cout << "Bike type: " << bike_to_print.bike_type << endl;
    cout << "Owner's name: " << bike_to_print.owner << endl;
    cout << endl;         // for visual clarity when printing
}
