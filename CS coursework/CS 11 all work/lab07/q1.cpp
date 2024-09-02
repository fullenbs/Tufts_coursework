#include <iostream>
using namespace std;

int main()
{
    int   m, n;
    int   *p1, *p2;

    p1 = &m; //has p1 and p2 point to address of m and n respectively
    p2 = &n;
    
    *p1 = 3; //*p1 gets m, and m = 3 
    *p2 = 5; //*p2 gets n and n = 3
    
    cout << m << " " << n << endl;
    return 0;                     
} 