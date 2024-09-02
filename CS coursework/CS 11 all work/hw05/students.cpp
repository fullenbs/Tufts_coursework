/*
* Program name: students.cpp
* Author: Scott Fullenbaum
* Purpose: Get student info from their ID  
*/

#include <iostream>
#include <string>

using namespace std;

// declare the Student struct
struct Student {
    int    id;
    string firstName;
    char   lastInitial;
    float  gpa; 
};

const int TOTAL_STUDENTS = 10;

// Function prototypes
int  find_student(int id, Student students[TOTAL_STUDENTS], int num_students);
void print_student(int index, Student students[TOTAL_STUDENTS]);

int main() {
    int input = 0;
    Student students [TOTAL_STUDENTS] = {
        {268, "Dana",     'J', 4.0},
        {123, "Rachel",   'G', 3.42},
        {126, "Sam",      'B', 3.8},
        {431, "Keisha",   'M', 3.9},
        {231, "Joe",      'W', 2.7},
        {272, "Isabella", 'U', 3.73},
        {112, "Sook-Hee", 'E', 3.54},
        {289, "Molly",    'C', 3.6},
        {345, "Talia",    'K', 3.63},
        {228, "Jackson",  'P', 3.33}
    };
    cin >> input; 
    int loc = find_student(input, students, TOTAL_STUDENTS);
    if (loc == -1){
        cout << "Sorry, this ID doesn't exist." << endl;
    } else {
        print_student(loc, students);
    }
    return 0;
}

/* find_student
* Parameters: id entered, student array, and size of the array
* Purpose: Match the ID to it's respective student
* Returns: The ID's owner's position in the array, returning -1 if not true
*/
int find_student(int id, Student students[TOTAL_STUDENTS], int num_students){
    for (int i = 0; i < num_students; i++){
        if (students[i].id == id){
            return i;
        }
    }
    return -1;
}

/* print_student
* Parameters: index in array of student, and the array itself
* Purpose: Display info about the student
* Returns: Nothing 
*/
void print_student(int index, Student students[TOTAL_STUDENTS]){
    cout << "Name: " << students[index].firstName << " ";
    cout << students[index].lastInitial << endl;
    cout << "GPA: " << students[index].gpa << endl;
}