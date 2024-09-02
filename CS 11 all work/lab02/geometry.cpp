// geometry.cpp
// CS 11 Fall 2021
// Lab 02
//
// Purpose: Practice using functions to easily calculate various 
//          geometric equations.
// 
// Modified by: Scott Fullenbaum
// Date: 9/22/21
//

#include <iostream>
using namespace std;

//function declarations 
int triangle_area(int base, int height);
int square_perimeter(int side);
int regular_perimeter(int sides, int length);
int area_trapezoid(int base1, int base2, int height);
bool area_greater_than(int base, int height, int minArea);


int main(){
        //all function inputs needed for calculations 
        int base = 10;
        int height = 5;
        int side = 11; 
        int length = 8; 
        int minArea = 50; 
        int base2 = 15; 
        
        //variables for storing results of each function
        bool areaTest; 
        int area;
        int square_p;
        int regular_p;
        int areaTrapezoid;
        
        //calls the function stores result to a variable 
        area = triangle_area(base, height);
        square_p = square_perimeter(side);
        regular_p = regular_perimeter(side, length);
        areaTest = area_greater_than(base, height, minArea);
        areaTrapezoid = area_trapezoid(base, base2, height);
        
        cout << area << endl;
        cout << square_p << endl;
        cout << regular_p << endl;
        cout<< areaTest << endl;
        cout << areaTrapezoid << endl; //displays output of one function 
            
        return 0;
} 

/* triangle_area 
* Parameters: base and height of triangle 
* Purpose: Find area of a triangle
* Returns: The area of a triangle 
*/
int triangle_area(int base, int height){
    return .5*base*height;
}

/* square_perimeter
* Parameter: side length
* Purpose: Find perimeter of a sqaure
* Returns: The perimeter of the square
*/
int square_perimeter(int side){
    return 4*side;
}

/* regular_perimeter
* Parameters: Number of sides and length of each side
* Purpose: Calculate the perimeter of a regular polygon
* Returns: Perimter of the polygon
*/
int regular_perimeter(int sides, int length){
    return sides*length; 
}

/* area_greater_than
* Parameters: base and height of triangle, comparison area
* Purpose: See if the area of one triangle is greater than area of another
* Returns: True if  new area is greater, false if new area is smaller
*/
bool area_greater_than(int base, int height, int minArea){
    int area = .5 * base * height;
    if (area > minArea){
        return true;
    } else {
        return false; 
    }
    return false; 
}

/* area_trapezoid
* Parameters: Both bases of trapezoid, along with it's height
* Purpose: Find area of trapezoid
* Returns: Area of trapezoid
*/
int area_trapezoid(int base1, int base2, int height){
    int step1 = base1 + base2; 
    return .5*(step1*height); 
}