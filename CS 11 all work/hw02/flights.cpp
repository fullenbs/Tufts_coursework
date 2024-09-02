/*
* Program name: flight.cpp
* Author: Scott Fullenbaum
* Purpose: Calculate flight times 
*/

#include <iostream> //does stuff
using namespace std;

//function declaration 
int timediff(int f1, int f2, int f3, int f4);

int main(){
    
    /*I came up w/ this variable naming scheme to explain var name:
    * flight number (1 or 2) + d for depart/ a for arrival + hr/min 
    */
    int f1dhr = 0;
    int f1dmin = 0;
    int f1ahr = 0;
    int f1amin = 0;
    
    int f2dhr = 0;
    int f2dmin = 0;
    int f2ahr = 0; 
    int f2amin = 0;
    
    //variables that represent totals, gotten through running timediff
    int total = 0; 
    int totalhr = 0;
    int totalmin = 0;
    int layoverhr = 0;
    int layovermin = 0;
    
    cout << "Flight 1: ";
    cin >> f1dhr >> f1dmin >> f1ahr >> f1amin; 
    
    cout << "Flight 2: ";
    cin >> f2dhr >> f2dmin >> f2ahr >> f2amin; 
    
    //gets time of each flight in minutes
    int f1time = timediff(f1dhr, f1dmin, f1ahr, f1amin);
    int f2time = timediff(f2dhr, f2dmin, f2ahr, f2amin);
    int layover = timediff(f1ahr, f1amin, f2dhr, f2dmin);
    
    
    //determines total hours and minutes of entire trip using modulus
    total = f1time + f2time + layover;
    totalhr = (total - (total%60))/60;
    totalmin = total - 60*totalhr;
    layoverhr = (layover - layover%60)/(60);
    layovermin = layover - (60*layoverhr);
        
    //displays outputs
    cout << "Layover: " << layoverhr << " hr " << layovermin << " min" << endl;
    cout << "Total: " << totalhr << " hr " << totalmin << " min" << endl;
}

/* timediff
* Parameters: The start and end time of the flight/layover period
* Purpose: Calculate the amount of time, in minutes, between them.
* Returns: The time difference in minutes
*/
int timediff(int t1, int t2, int t3, int t4){
    int start = 60*t1 + t2;
    int end = 60*t3+t4;

    /* deals with overnight time differences
    * Works since knowing flight <= 12 hours, then the end time will be a lower 
    * time than the start time. To make it feel like a next day, all we have to
    * do is add 24 hours to the end time since day 2 is hours 24-48.
    */
    if (end < start){ 
        end = end + 24*60;
    }
    int diff = end - start; 
    return diff; 
}



