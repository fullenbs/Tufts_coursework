/*
 *  Program name: guess.cpp
 *  Author: Scott Fullenbaum
 *  Purpose: Guess a random number between 5 and 15
 */

#include <iostream>

// The following are for srand() and time()
// for random numbers. Leave them 
// in your program.
#include <cstdlib>
#include <ctime>

using namespace std;
 
void input(int secretNum, int guessCount);
int compare(int secretNum, int guessNum, int guessCount);

int main()
{
        //runs srand() 
        srand(time(nullptr));

        //generates random number between 5 and 15
        int secretNum = (rand()%10) + 5;
        int guessCount = 0;
        
        input(secretNum, guessCount);
        
        return 0;
}

/* input
*  Parameters: computer number, amount of guesses made
*  Purpose: Get's user input, then sends it to be compared to the secret num
*  Returns: Nothing, it doesn't need to return anything.
*/
void input(int secretNum, int guessCount){
    int guessNum = 0;
    cout << "Enter a guess: ";
    cin >> guessNum;
    guessCount = compare(secretNum, guessNum, guessCount);
}

/* compare
* Parameters: number computer chooses, player's guess, amount of guesses
* Purpose: Determine if guess was correct, also ends game on third guess
* Returns: Returns the amount of guesses, in case none of the if statements run
*/
int compare(int secretNum, int guessNum, int guessCount){
    guessCount = guessCount + 1; //starts from 0, so third guess on count = 3
    
    /* The first if and else if require guessCount <= 2 since it is rerunning  
    * input() gives them another guess which we don't want if they made their   
    * third guess. 
    */
    if ((secretNum > guessNum) and (guessCount <= 2)){
        cout << "That was too low. ";
        input(secretNum, guessCount); //gives user another guess
    } else if(secretNum < guessNum and guessCount <= 2){
        cout << "That was too high. ";
        input (secretNum, guessCount);
    } else if(secretNum == guessNum){
        cout << "You guessed it! Good job!";
    } 
    if ((guessCount == 2) and (secretNum != guessNum)){
        cout << "The number was " << secretNum << ". Better luck next time!";
        cout <<endl; 
    }
    return guessCount; 
}
