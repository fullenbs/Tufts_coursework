/*
 * CS 11 Lab 04
 * 
 * printlist.cpp  -- shows how to read a list of numbers into an array
 *
 *      1. read in data
 *      2. then prints out the list with line numbers using another loop
 *
 *   Exercises:
 *    [a] print the list in reverse
 *    [b] change loop to print out only the birthdays in October
 *    [c] after printing out the October bdays, print a count of how many
 *    [d] change to print the count for each month, not the actual bdays
 *    [e] use a function to do [c]
 *    [f] EXTRA: print which month has the MOST birthdays
 * 
 * Modified by:
 *
 */
#include <iostream>

using namespace std;

const int CAPACITY = 1000;         // change as needed
const int MONTH = 12; 
int main() 
{
        int bdays[CAPACITY];    // birthday data
        int months[MONTH];
        //int used;               // number of spaces used so far
        int pos;                // position in array

        // read in CAPACITY values
        pos = 0;
        while (pos < CAPACITY){ 
                cin >> bdays[pos];
                pos++;
        }
        //used = pos;             // position is how far we got

        // now to print out the list
        // you can switch to a for loop if you know about those
        pos = 0;

        //while (pos < used) {
        //        cout << pos << ". " << bdays[pos] << endl;
        //        ++pos;
        //}
        
        //for (int i = CAPACITY-1; i >=0; i--){ //prints out in reverse order
        //    cout << i << ". " << bdays[i] << endl;
        //}
        
        //for (int i = CAPACITY-1; i >=0; i--){ //prints out only October months
        //    if (1000 <= bdays[i] and bdays[i] <= 1031){
        //    cout << i << ". " << bdays[i] << endl;
        //    }
        //}
        
        //int count = 0;
        //for (int i = CAPACITY-1; i >=0; i--){ //prints out num of Oct bdays
        //    if (1000 <= bdays[i] and bdays[i] <= 1031){
        //    cout << i << ". " << bdays[i] << endl;
        //    count++; 
        //    }
        //}
        //cout << "Num of bdays in October: " << count << endl;
        
        for (int i = 0; i< MONTH; i++){
            months[i] = 0;
        }
        
        
        for (int i = 0; i  < CAPACITY; i++){
            int temp = bdays[i];
            cout << temp << endl;
            if ( temp >= 100  and temp < 200){
                months[0]++;
            } else if (200 <= temp and temp < 300){
                months[1]++;
            } else if (300 <= temp and temp < 400){
                months[2]++;
            } else if (400 <= temp and temp < 500){
                months[3]++;
            } else if (500 <= temp and temp < 600){
                months[4]++;
            } else if (600 <= temp and temp < 700){
                months[5]++;
            } else if (700 <= temp and temp < 800){
                months[6]++;
            } else if (800 <= temp and temp < 900){
                months[7]++;
            } else if (900 <= temp and temp < 1000){
                months[8]++;
            } else if (1000 <= temp and temp < 1100){
                months[9]++;
            } else if (1100 <= temp and temp < 1200){
                months[10]++;
            } else { 
                months[11]++;
            }    
        }
        
        for (int i = 0; i < MONTH; i++){
            cout << months[i] << " ";
        }
        cout << endl;
        return 0;
}
