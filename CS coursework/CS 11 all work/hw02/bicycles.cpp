/*  Program name: bicycles.cpp
*   Author: Scott Fullenbaum
*   Purpose: Calculate bicycle parts needed
*
*/

#include <iostream> //does stuff
using namespace std;

//function declaration
void bikecalc(int wheels, int frames, int links);
void display(int wheelF, int frameF, int linkF, int totBike);
string plural(string word, int val);

int main(){
    int wheels = 0;
    int frames = 0;
    int links = 0;
    
    cout << "Enter the number of wheels: ";
    cin >> wheels; 
    
    cout << "Enter the number of frames: ";
    cin >> frames;
    
    cout << "Enter the number of links: ";
    cin >> links;
    
    bikecalc(wheels, frames, links);
    
}

/* bikecalc
* Parameters: Initial number of wheels, frames, and links
* Purpose: Determine max amount of bikes made, along with parts left over
* Void: Doesn't need to return anything, as it runs display to get outputs.
*/
void bikecalc(int wheels, int frames, int links){
    //figures out how many bikes can be made with quantity of each part
    int wheelUsed = (wheels - wheels%2)/2; 
    int frameUsed = frames;
    int linkUsed = (links - links%50)/50;
    
    int totBike = 0;
    
    //finds which makes smallest amount of bikes, as that is limiting factor
    if (wheelUsed <= frameUsed and wheelUsed <= linkUsed ){
        totBike = wheelUsed;
    } else if(frameUsed <= wheelUsed and frameUsed <= linkUsed){
        totBike = frameUsed;
    } else if (linkUsed <= wheelUsed and linkUsed <=  frameUsed){
        totBike = linkUsed;
    }
    
    int wheelF = wheels - 2*totBike; //figures out left overs
    int frameF = frames - totBike;
    int linkF = links - 50*totBike; 
    
    display(wheelF, frameF, linkF, totBike); //shows the output
}

/* display
* Parameters: Final amount of each object, and total amount of bikes.
* Purpose: Display amount of bikes made and number of parts remaining
* Returns: Nothing, since it's using cout, it has no reason to return a value.
*/
void display(int wheelF, int frameF, int linkF, int totBike){
    cout << "You can make " << totBike << " " << plural("bike", totBike) << ".";
    cout << " There are " << wheelF << " " << plural("wheel", wheelF) << ", ";
    cout << frameF << " " << plural("frame", frameF) << ", ";
    cout << linkF << " " << plural("link", linkF) << " leftover." <<endl;
}

/* plural
* Parameters: The string you might want pluralized, and the quantity of said
* string.
* Purpose: Determines if a string should be plural, and if so, adds s to it.
* Returns: The new string if change, the old string if it is still singular.
*/
string plural(string word, int val){
    string plural = "s";
    if (val == 1){
        return word;
    } else {
        return (word + "s"); //combines the two strings into one
    }
    return "this didn't work!";
}