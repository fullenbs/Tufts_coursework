/*
 * CS 11: Lab 05
 * moviedb.cpp
 *
 * Purpose: Interact with arrays of structs by manipulating
 *          and searching a movie database
 *
 * Written by: Keisha Mukasa, Spring 2021
 * With updates by: Sam Berman (sberma04) and 
 *                  Jackson Parsells (jparse01), Fall 2021
 *
 * Modified by:
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

const int NUM_MOVIES = 450;
const int NUM_ACTORS = 5;
const int YEARS = 119;

struct Movie
{
    string title;
    int year;
    double gross;
    string director;
    string actors[NUM_ACTORS];
};

void read_movie_data(Movie movies[NUM_MOVIES]);
void find_movie(string s, Movie movie_list[NUM_MOVIES]);
void movie_year(int year, Movie movie_list[NUM_MOVIES]);
void box_office(Movie movie_list[NUM_MOVIES]);
void big_year(Movie movie_list[NUM_MOVIES]);
void actor_movie(string s, Movie movie_list[NUM_MOVIES]);

int main()
{
    // This line of code declares a list of 450 movies obje
    Movie movie_list[NUM_MOVIES];
    //string title; 
    //int year;
    string name;
    // This function call is populating the movie list with all
    // the movies in the file. Do not worry about its implementation.
    read_movie_data(movie_list);
    
    /* TODO: Your lab code goes here */
    //cout << "Enter a movie name: " << endl;
    //getline(cin, title);
    //find_movie(title, movie_list);
    
    //cout << "Enter a year:" << endl;
    //cin >> year; 
    //movie_year(year, movie_list);
    
    //box_office(movie_list);
    //big_year(movie_list);
    
    cout << "Enter a name:" << endl;
    getline(cin, name);
    actor_movie(name, movie_list);
    return 0;
}


/*find_movie
* Check if movie is in directive and displays it if found
*/
void find_movie(string title, Movie movie_list[NUM_MOVIES]){
    bool found = false;
    for (int i = 0; i < NUM_MOVIES; i++){
        if (title == movie_list[i].title){
            cout << "year: " << movie_list[i].year << endl;
            cout << "gross: " << movie_list[i].gross << endl;
            cout << "director: " << movie_list[i].director << endl;
            cout << "actors: " << endl;
            
            for (int j = 0; j < NUM_ACTORS; j++){
                cout << movie_list[i].actors[j] << " " << endl;
            }
            found = true;
            break; //don't want to repeat loop if movie found
        }
    }

    if (found == false){
        cout << title << " was not found in the directory." << endl;
     }
}

//Finds all movies made in a year
void movie_year(int year, Movie movie_list[NUM_MOVIES]){
    int counter = 0;
    for (int i = 0; i < NUM_MOVIES; i++){
        if (movie_list[i].year == year){
            cout << movie_list[i].title << " " << endl;
            counter++;
        }
    }
    if (counter == 0){
        cout << "No movies were made this year" << endl;
    }
}
//determines movies with min and max box office, and finds avg box office
void box_office(Movie movie_list[NUM_MOVIES]){
    double max = movie_list[0].gross;
    double min = movie_list[0].gross; 
    string max_movie = movie_list[0].title;
    string min_movie = movie_list[0].title;
    
    double sum = 0;
    
    for (int i = 0; i < NUM_MOVIES; i++){
        if (movie_list[i].gross > max){
            max = movie_list[i].gross;
            max_movie = movie_list[i].title;
        }
        if (movie_list[i].gross < min){
            min = movie_list[i].gross;
            min_movie = movie_list[i].title;
        }
        sum = sum + movie_list[i].gross;
    }
    double average = sum / NUM_MOVIES; 
    cout << "Highest box office: " << max_movie << endl;
    cout << "Lowest box office: " << min_movie << endl;
    cout << "Average box office: " << average << endl; 
}

//finds year with highest box office
void big_year(Movie movie_list[NUM_MOVIES]){
    double years [YEARS] = {};
    double max = 0;
    int maxyear = 1900;
    for (int i = 0; i < YEARS; i++){
        for (int j = 0; j < NUM_MOVIES; j++){
            if (movie_list[j].year == i + 1900){
                years[i] = years[i] + movie_list[j].gross;
            }
        }
        if (years[i] > max){
            max = years[i];
            maxyear = i + 1900;
        }
    }
    cout << "The year with highest gross is: " << maxyear << endl;
}

void actor_movie(string name, Movie movie_list[NUM_MOVIES]){
    for (int i = 0; i < NUM_MOVIES; i++){
        for (int j = 0; j < NUM_ACTORS; j++){
            if (name == movie_list[i].actors[j]){
                cout << movie_list[i].title << endl;
            }
        }
    }
}

















/****************************************************************
 *                         NOTE                               
 * The functions below are part of the starter code that enable
 * you to read in from a file. You do not need to understand
 * the code below to complete the lab and we encourage you to
 * ignore this code. This implementation will be covered in the
 * future but is not currently required for lab or homework.
****************************************************************/

/*  
*   READ_MOVIE_DATA
*   Parameters: Empty movie array
*   Purpose: Read lists of movies data from a file and store in array
*   Returns: Does not return anything
*/
void read_movie_data(Movie movies[NUM_MOVIES])
{
    // ifstream object declaration in order to open and read
    // from a file
    ifstream infile;
    string filename = "moviedata.txt";

    // open file
    infile.open(filename);

    // check if file successfully opened if it isn't the program is
    // exited immediately
    if (infile.fail())
    {
        cerr << "ERROR: Error opening file, please check file name: "
             << filename << endl;
        exit(EXIT_FAILURE);
    }

    // read through file
    for (int i = 0; i < NUM_MOVIES; i++)
    {
        getline(infile, movies[i].title);
        infile >> movies[i].year;
        infile >> movies[i].gross;
        infile.ignore();
        getline(infile, movies[i].director);

        // reads in each actors name
        for (int j = 0; j < NUM_ACTORS; j++)
        {
            getline(infile, movies[i].actors[j]);
        }
    }
}
