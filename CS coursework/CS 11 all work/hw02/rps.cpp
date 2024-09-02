/*
 *  Program name: guess.cpp
 *  Author: Scott Fullenbaum
 *  Purpose: Plays rock, paper, scissors with the user 
 */

#include <iostream>

// The following are for srand() and time()
// for random numbers. Leave them 
// in your program.
#include <cstdlib>
#include <ctime>

using namespace std;

//function declaration 
char compMove(); 
void victory(char comp, char player);
void rock(char comp);
void paper(char comp);
void scissors(char comp);


int main()
{
        //enables rand() 
        srand(time(nullptr));
        
        char player = ' ';
        char comp = ' ';
        
        cout << "Enter rock (r), paper (p), or scissors (s): ";
        cin >> player; 
        
        player = tolower(player); //accounts for upper case inputs
        comp = compMove(); //gets r, p, or s for computer
        
        victory(comp, player); //Figures out the winner
        return 0;
}

/* compMove
* Parameters: None
* Purpose: Determines if computer is using, r, p, or s
* Returns: Reeturns the computer's randomly selected move
*/
char compMove(){
    int move = rand()%2; 
    if (move == 0){
        return 'r';
    } else if (move == 1){
        return 'p';
    } else if (move == 2){
        return 's';
    } else {
        return '%';
    }
    return '%';
}

/* victory
* Parameters: Computer and player moves
* Purpose: Helps figure out victor
* Returns: Doesn't need to return anything
*/
void victory(char comp, char player){ 
    if (player == 'r'){
        rock(comp); 
    }
    if (player == 'p'){
        paper(comp);
    }
    if (player == 's'){
        scissors(comp);
    }
}


/* rock
* Parameters: computer decision 
* Purpose: Check who won if player picks rock. Split from victory to make      
* shorter functions
* Returns: Nothing, doesn't need to return a value
*/
void rock(char comp){
    if (comp == 'r'){
        cout << "It's a tie. The computer also chose rock." << endl;
    }
    if (comp == 'p'){
        cout << "You lost. The computer chose paper." << endl;
    }
    if (comp == 's'){
        cout <<"You won! The computer chose scissors." << endl;
    }
    
}

/* paper
* Parameters: computer decision 
* Purpose: Check who won if player picks paper
* Returns: Nothing, doesn't need to return a value
*/
void paper(char comp){
    if (comp == 'p'){
        cout << "It's a tie. The computer also chose rock." << endl;
    }
    if (comp == 's'){
        cout << "You lost. The computer chose paper." << endl;
    }
    if (comp == 'r'){
        cout <<"You won! The computer chose scissors." << endl;
    }
}

/* scissors
* Parameters: computer decision 
* Purpose: Check who won if player picks scissors
* Returns: Nothing, doesn't need to return a value
*/
void scissors(char comp){
    if (comp == 's'){
        cout << "It's a tie. The computer also chose rock." << endl;
    }
    if (comp == 'r'){
        cout << "You lost. The computer chose paper." << endl;
    }
    if (comp == 'p'){
        cout <<"You won! The computer chose scissors." << endl;
    }
}
