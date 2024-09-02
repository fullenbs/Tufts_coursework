//
// Program name: make_change.cpp
// Author: Scott Fullenbaum
// Purpose: Calculate the least amount of coins to give someone change
//
//

#include <iostream> //does stuff
using namespace std;

int main(){
    //change is total money, the rest of variables are # of coins of each type
    int change = 0; 
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    
    //Gets input
    cout << "Amount of change in cents: " << endl;
    cin >> change;
    
    /*
     Formula explanation: First, do (change % coin1 value) to give change left over after using max number of coin1. Next, subtract that from change, which gives the amount of change accounted for by coin1 and divide by the value which number of coin1 used. The 2nd line subtracts amount of change accounted for by the coin from the change. Repeat this with each coin. 
    */
    quarters = (change - (change%25))/25;
    change = change - (25*quarters);
    
    dimes = (change - (change%10))/10;
    change = change - (10*dimes);
    
    nickels = (change - (change%5))/5;
    change = change - (5*nickels);
    
    pennies = change - (change%1);
    change = change - pennies; 
    
    //Outputs change
    cout << quarters << " quarters, " << dimes << " dimes, ";
    cout << nickels << " nickels, " << pennies << " pennies";
}