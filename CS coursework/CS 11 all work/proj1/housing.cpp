//===============================================================
// Program name: housing.cpp
// Author: Scott Fullenbaum
// Purpose: Create an application that reads in housing information and 
// displays it

// IMPORTATNT NOTE: DON'T CHANGE CODE UNLESS TOLD SO
//
//===============================================================

#include <iostream>
#include <fstream>
using namespace std;

// DO NOT CHANGE THE FOLLOWING CONSTANTS. WHEN YOU SUBMIT,
// THEY MUST HAVE THESE VALUES AND THEY MUST BE USED 
// AS THE DIMENSIONS FOR YOUR all_houses ARRAY.
const int ROWS = 50;
const int COLS = 20;
//===============================================================
//
//                             House
//
//     Each House struct records the information about one
//     house.  Three of the fields are declared for you and
//     you MUST use them as given.  You should declare below
//     them any additional members that you need.
//
//     Note that if the "no_house_here" member field is set
//     to true, then the other fields are not used.  Of course,
//     if no_house_here is false; then all the fields should
//     be set.
//
//===============================================================

struct House {
    bool no_house_here;  // true if there is NO house on this location
    int id;             // id from the data file, converted to int
    string lot_code;       // lot_code string from the data file
    float price;             //my struct statements
    int bedrooms; 
    string color; 
    string available;      //is stored as yes or no string
};

/*===============================================================
                   Required Function Prototypes

        DO NOT CHANGE ANYTHING IN THIS SECTION. YOUR CODE
        MUST ADHERE TO THESE FUNCTION DECLARATIONS OR YOU WILL
        RECEIVE NO CREDIT.
  ===============================================================*/

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
House read_one_house(ifstream& input_file);
void print_house(House h);

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
int col_from_lot(string lot);
int row_from_lot(string lot);
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]);
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]);

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions for week 2 (ignore during week 1)
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
 bool is_available(int house_id, House all_houses[ROWS][COLS]);
 int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS]); 
 int num_neighbors(int house_id, House all_houses[ROWS][COLS]);
 int rent_house(string house_id, House all_houses[ROWS][COLS]);


/*===============================================================
                   Additional Function Prototypes
                   
        Write any additional function prototypes that you 
        define here. You may not need any, or you may choose 
        to write several
  ===============================================================*/

// FUNCTION PROTOTYPES WEEK 1
int string_to_int(string s); //gets the lot id
int exp(int a, int b);
void input_loop(House all_houses[ROWS][COLS]);

//FUNCTION PROTOTYPES WEEK 2
void command_loop_wk2(House all_houses[ROWS][COLS]);
int func_det(string input, House all_houses[ROWS][COLS]);
void run_is_available(int a, House all_houses[ROWS][COLS]);
void run_matching_houses(float p, string c, int b, 
                        House all_houses[ROWS][COLS]);
void run_num_neighbors(int a, House all_houses[ROWS][COLS]);
bool run_rent_house(int a, House all_houses[ROWS][COLS]);
int grid_checker(House all_houses[ROWS][COLS], int t_row, int t_col);
//======================================================================
//                              main 
//======================================================================

int main(int argc, char *argv[]){   
    if (argc != 2){ //command line tests
        cerr << "ERROR ERROR ERROR" << endl;
    }
    string filename = argv[1]; 
    House all_houses[ROWS][COLS];
    fill_with_no_houses(ROWS, COLS, all_houses);
    
    bool b = read_all_house_data(filename, all_houses);
    if (b == false){
        cerr << "DID NOT WORK ERROR READING FILE" << endl;
        return 1;
    }
    command_loop_wk2(all_houses); //week 2 output
    //input_loop(all_houses); //week 1 output
    return 0;
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

/* read_one_house
* Parameters: A file
* Purpose: Read in a line of the file with
* Returns: The house with all the info read in
*/
House read_one_house(ifstream& input_file){
    House house; 
    house.no_house_here = false; //if being read in, then a house is there
    input_file >> house.id;
    input_file >> house.lot_code;
    input_file >> house.price;
    input_file >> house.bedrooms;
    input_file >> house.color;
    input_file >> house.available;
     
    //since want outputs for available in yes/no use this if statement
    if (house.available == "booked"){ 
        house.available = "No";
    } else {
        house.available = "Yes";
    }
    return house;
}

/* print_house  
* Parameters: A house
* Purpose: Display information about a house
* Returns: Nothing
*/
void print_house(House h){
    if (h.no_house_here == false){ //if the house exists
        cout << "Id: " << h.id << " Lot: " << h.lot_code;
        cout << " Color: " << h.color  << " Price: " << h.price; 
        cout <<  " Bedrooms: " << h.bedrooms << " Available: " << h.available;
        cout << endl;
    } else { //if the house doesn't exist
        cout << "No house" << endl;
    }
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

/* col_from_lot
* Parameters: The string lot
* Purpose: Finds the column
* Returns: The integer value of the column
*/
int col_from_lot(string lot){
        int col_val = (lot[0] - 'A');
        return col_val;  
}

/* row_from_lot
* Parameters: The lot id
* Purpose: Find the row in the array where the lot is located
* Returns: the row minus 1, to account for rows starting from 1
*/
int row_from_lot(string lot) {    
    int final = 0; 
    int num_zero = 0;
    for (unsigned int i = 0; i < lot.length(); i++){
        if ((lot[i] - '0') <= 9 and (lot[i] - '0') >= 0){
            num_zero++;
        }
    }
    
    //just adds the numbers back together
    for (unsigned int i = 0; i < lot.length(); i++){
        if ((lot[i] - '0') <= 9 and (lot[i] - '0') >= 0){
            final = final + (lot[i] - '0')*exp(10, num_zero - 1);
            num_zero--; 
        }
    }
    return (final-1);//rows start from 1, so subtract 1 for array index
}

/* exp
* Parameters: base a and exponent b
* Purpose: For row_from_lot, useful for finding row number
* Returns: a^b as an integer
*/
int exp(int a, int b){
    int c = 1;
    for (int i = 0; i < b; i++){
        c = c*a;
    }
    return c; 
}

/* fill_with_no_houses
* Parameters: A 2D array and the dimensions of said array
* Purpose: Fill the house array with empty houses
* Returns: Nothing
*/
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]){    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            all_houses[i][j].no_house_here = true;
            all_houses[i][j].id = 0;
        }
    }
}

/* read_all_house_data
* Parameters: filename and the array of houses
* Purpose: Add all info from file to the array
* Returns: True if it works, false if it doesn't
*/
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]){
    ifstream input_file;  //File I/O stuff makes sure it all works  
    input_file.open(filename);
    if (not input_file.is_open()) {
        cerr << "fileread.cpp: could not open file: " << filename << endl;
        return false; // non-zero return from main means error
    }

    int test_size = 0; 
    input_file >> test_size; //num of houses
    
    //gets row and col of house, then puts it there in the array
    for (int i = 0; i < test_size; i++){
        House temp = read_one_house(input_file); 
        int temp_row = row_from_lot(temp.lot_code);
        int temp_col = col_from_lot(temp.lot_code);
        all_houses[temp_row][temp_col] = temp;
    }
    
    input_file.close();
    return true;  
}

/* input_loop
* Parameters: The array of houses
* Purpose: Allow user to input location to get housing information
* Returns: Nothing, it provides outputs
*/
void input_loop(House all_houses[ROWS][COLS]){
    int row, col;
    cout << "Enter row: ";
    cin >> row; 
    if (row < 0){ //ends immediately if negative value entered
        return;
    }
    cout << "Enter col: ";
    cin >> col;
    if (col < 0){ //also ends immediately if negative value entered
        return;
    }
    print_house(all_houses[row][col]); 
    input_loop(all_houses); //runs the loop again
}


// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions for week 2 (ignore during week 1)
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 


/* is_available
* Parameters: house_id and the array of houses
* Purpose: Determine if specific house id is available
* Returns: True if house_id is available, false otherwise
*/
bool is_available(int house_id, House all_houses[ROWS][COLS]){
    //Goes through each array element to fulfill function purpose
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if (all_houses[i][j].id == house_id){
                if (all_houses[i][j].available == "Yes"){
                    return true;
                } else {
                    return false;
                }
            }
        }
    }   
    return false; 
} 

/* matching_houses
* Parameters: Desired price, color, bedrooms, array of houses and results
* Purpose: Finds house that matches parameters
* Returns: The number of matching houses
*/
int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS]){
    int counter = 0; //num of houses that meets parameters
    //goes thru each array element to check function parameters
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            House temp = all_houses[i][j];
            if (temp.price <= max_price and temp.color == desired_color
            and temp.bedrooms >= desired_bedrooms){
                results[counter] = temp;
                counter++; 
            }
        }
    }
    return counter;     
}

/* num_neighbors
* Parameters: house_id, all_houses array
* Purpose: Figure out number of neighbors
* Returns: Number of neighbors
*/
int num_neighbors(int house_id, House all_houses[ROWS][COLS]){
    int temp_row, temp_col;
    //finds array location for house with certain ID.
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if (all_houses[i][j].id == house_id){
                temp_row = i;
                temp_col = j;
                //cout << temp_row << " " << temp_col << endl; //debugger
            }
        }
    }
    //gets the num of neighbors 
    int neighbors = grid_checker(all_houses, temp_row, temp_col);
    return neighbors;
}

/* grid_checker
* Parameters: 2D array of houses, and the array location of the house
* Purpose: Keep num_neighbors under 30 lines and find all neighbors
* Returns: The number of neighbors
*/
int grid_checker(House all_houses[ROWS][COLS], int t_row, int t_col){
    int neighbors = 0;
    for (int i = -1; i < 2; i++){
        if ((t_row + i) < 0 or (t_row+i) > ROWS){
            if ((i+1) >= 2){
                i = 1;
            } else { 
                i++; //if the row outside array bounds
            }
        }
        for (int j = -1; j < 2; j++){
            if ((t_col + j) < 0 or (t_col + j > COLS)){
                if ((j+1) >= 2){
                    j = 1;
                } else {
                    j++;
                } 
            }
            if (all_houses[t_row + i][t_col + j].available == "No"){
                neighbors++;
            }
        }
    }
    if (all_houses[t_row][t_col].available == "No"){
        return (neighbors - 1);
    }
    return neighbors;
}

/* rent_house
* Parameters: House_id
* Purpose: Figures out if house is available, then rents it if it is
* Returns: An int based off what it's supposed to return
*/
int rent_house(int house_id, House all_houses[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){   
            if (all_houses[i][j].id == house_id){    
                if (all_houses[i][j].available == "Yes"){
                    all_houses[i][j].available = "No";
                    return 1;
                } else {
                    return 2;
                }
            }
        }
    }
    //cout << "How did we get here?" << endl; //debugging statement
    return 0;   
}

/* command_loop 
* Parameters: The house array
* Purpose: Run all input and week 2 functions
* Returns: Nothing
*/
void command_loop_wk2(House all_houses[ROWS][COLS]){
    string command_code = "";
    cin >> command_code;

    if (command_code != "q"){
        int k = func_det(command_code, all_houses);
        if (k == 1){
            return;
        }
    } else {
        return;
    }
    command_loop_wk2(all_houses);
}

/* func_det
* Parameters: The command prompt and the house array
* Purpose: Calls the function with correct inputs
* Returns: 1 if a house was successfully rented, otherwise 0
*/
int func_det(string input, House all_houses[ROWS][COLS]){
    int id, bedrooms; //all appropriate inputs
    float max_price;
    string color;
    if (input == "a"){ //gets additional inputs and runs functions
        cin >> id;
        run_is_available(id, all_houses);
    } else if (input == "m"){
        cin >> max_price >> color >> bedrooms; 
        run_matching_houses(max_price, color, bedrooms, all_houses);
    } else if (input == "n"){
        cin >> id; 
        run_num_neighbors(id, all_houses);
    } else if (input == "r"){
        cin >> id;
        bool j = run_rent_house(id, all_houses);
        if (j == true){ //Condition for ending program
            return 1;
        }
    } else {
        cout << input << endl;    
    }
    return 0;
}

/* run_is_available
* Parameters: The house id and the house array
* Purpose: Runs the function is_available and gets outputs
* Returns: Nothing
*/
void run_is_available(int a, House all_houses[ROWS][COLS]){
    bool available = is_available(a, all_houses);
    if (available == true){
        cout << "House " << a << " is available" << endl;
    } else {
        cout << "House " << a << " is not available" << endl;
    }
}

/* run_matching_houses
* Parameters: The inputs for matching_houses and the house array
* Purpose: Run matching_houses and display correct outputs
* Returns: Nothing
*/
void run_matching_houses(float p, string c, int b, 
                         House all_houses[ROWS][COLS]){                     
    House results [ROWS * COLS]; //results array
    int j = matching_houses(p, c, b, all_houses, results);

    cout << "Matching Houses:" << endl;
    for (int i = 0; i < j; i++){
        print_house(results[i]);
    }
}

/* run_num_neighbors
* Parameters: An integer input argument and the houses array
* Purpose: Tells you how many neighbors you have
* Returns: Nothing
*/
void run_num_neighbors(int a, House all_houses[ROWS][COLS]){
    int neighbors = num_neighbors(a, all_houses); //runs num_neighbors
    if (neighbors == 0){
        cout << "You have no neighbors, practice your drums!" << endl;
    } else {
        cout << "You have " << neighbors << " neighbors" << endl;
    }
}

/* run_rent_house
* Parameters: lot number and array of houses
* Purpose: Runs rent_house function
* Returns: True if house rented, false otherwise
*/
bool run_rent_house(int a, House all_houses[ROWS][COLS]){
    int j = rent_house(a, all_houses); //runs rent house
    
    if (j == 0){ //gives outputs
        cout << "You can't rent a house that doesn't exist, but nice try";
        cout << endl;
    } else if (j == 1){
        cout << "Congrats, you rented a house! Hope your doorknobs";
        cout << " don't fall off" << endl;
        return true;
    } else if (j == 2){
        cout << "Too late...i hear the dumpster behind hill has some spaces";
        cout <<" open" << endl;
    }
    return false;
}
// ============================================================
//     INCLUDE COMP11 TESTING CODE
//
//   LEAVE THIS STATEMENT IN PLACE. IT MUST COME 
//   BE THE LAST LINE OF CODE IN YOUR housing.cpp FILE
// ============================================================

#include "housing_hooks.hpp"