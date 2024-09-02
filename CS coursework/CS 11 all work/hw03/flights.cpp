/*
* Program name: flight.cpp
* Author: Scott Fullenbaum
* Purpose: Calculate flight times and improve upon HW02 answer
*/

#include <iostream> //does stuff
using namespace std;

//function declaration 
int time_diff(int f1, int f2, int f3, int f4);
int time_min(int hr, int min);
void output(int time);
int diff_calc(int t1, int t2);
int hr_left(int time);

int main(){
    /* variable naming scheme:
      flight number (1 or 2) + d for depart/ a for arrival + hr/min */
    int f1dhr = 0;
    int f1dmin = 0;
    int f1ahr = 0;
    int f1amin = 0;
    
    int f2dhr = 0;
    int f2dmin = 0;
    int f2ahr = 0; 
    int f2amin = 0;
    
    cout << "Flight 1: ";
    cin >> f1dhr >> f1dmin >> f1ahr >> f1amin; 
    cout << "Flight 2: ";
    cin >> f2dhr >> f2dmin >> f2ahr >> f2amin; 
    
    //gets duration of flights and layover in minutes
    int f1time = time_diff(f1dhr, f1dmin, f1ahr, f1amin);
    int f2time = time_diff(f2dhr, f2dmin, f2ahr, f2amin);
    int layover = time_diff(f1ahr, f1amin, f2dhr, f2dmin);
    
    cout << "Layover: " ;
    output(layover); //gets layover time
    
    cout << "Total: " ;
    output(f1time + f2time + layover); //gets total flight time
    return 0;
}

/* hr_left
* Parameters: Total time
* Purpose: Find hours when given number of minutes
* Returns: The amount of hours
*/
int hr_left(int time){
    return (time - (time % 60))/60;
}

/* output
* Parameters: Time, in minutes
* Purpose: Determines time in hrs and minutes and displays it
* Returns: Nothing
*/
void output(int time){    
    int hr = hr_left(time);
    int min = time - (60*hr);
    
    cout << hr << " hr " << min << " min" << endl;
}


/* time_diff
* Parameters: The start and end time of the flight/layover period
* Purpose: Calculate the amount of time, in minutes, between them.
* Returns: The time difference in minutes
*/
int time_diff(int t1, int t2, int t3, int t4){
    int start = time_min(t1, t2);
    int end = time_min(t3, t4);
        
    return diff_calc(start, end);
}

/* diff_calc
* Parameters: Start and end time in minutes
* Purpose: Find time difference between two times, accounts for diff days
* Returns: The difference in time
*/
int diff_calc(int start, int end){
    if (end < start){
        end = end +24*60;
    }
    return (end - start);
}

/* time_min
* Parameters: hours and minutes
* Purpose: Converts hr min to just minutes
* Returns: The amount of minutes
*/
int time_min(int hr, int min){
    return (60*hr + min);
}