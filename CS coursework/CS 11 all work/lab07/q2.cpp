#include <iostream>
using namespace std;

int main()
{
    int    m, n;
    int   *p1, *p2;

    p1 = &m; //p1 and p2 point to address of m and n
    p2 = &n;
    
    *p1 = 8; //p1 which points to m = 8
    *p2 = (*p1)++; //*p2 = *p1, so n = 8, then *p1 is incremented so *p1 = 9
    *p2 += *p2; //double n so n = 16

    //E(x) = 9, 16, 9, 16
    cout << m << " " << n << " " << *p1 << " " << *p2 << endl;

    return 0;
}
