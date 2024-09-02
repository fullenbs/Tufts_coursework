/*
 * A program which produces some common memory leaks and errors that can be
 * dectected using valgrind
 * 
 * (c) Sydney Nepo, Tufts University, Fall 2021
 *
 * Valgrind is a tool useful for detecting memory leaks and errors in your 
 * program. This file contains examples of some common issues that you can 
 * use valgrind to catch. To run your program with valgrind, do the 
 * following: 
 *      - Compile your program with the -g flag. This will make error 
 *        reading easier. To compile this program, run: 
 *
 *      g++ -o valgrinderrors -g -Wall -Wextra -Werror valgrinderrors.cpp
 *
 *      - Run your program with valgrind. The terminal command for this 
 *        example is: 
 *      
 *      valgrind ./valgrinderrors
 *
 *      - If your program is interactive, interact with it until it terminates. 
 *        This program is not interactive, so it will terminate without any 
 *        input.
 *
 *      - Read the valgrind output. Specifically, in the summary you want to 
 *        look at the following things: 
 *              - HEAP SUMMARY: This field should always be 72,704 bytes in 
 *                              1 blocks. It is also expected to have exactly 
 *                              1 more allocs than frees
 *              - LEAK SUMMARY: There should be 0 bytes in 0 blocks for all of 
 *                              the "lost" categories. 
 *              - ERROR SUMMARY: This should say 0 errors from 0 contexts
 *
 *      - If any of the summaries do not appear as described above, you have 
 *        a bug! Scroll up to parse through the error messages, starting with 
 *        the topmost error. It is okay if you do not fully understand these 
 *        error messages, just try to gather enough information to figure out 
 *        where the error is coming from!
 */


#include <iostream>

using namespace std;

int main()
{
        /* The first error we will look at is a memory leak. Uncomment the next 
           line, compile, and run the following code using valgrind. What is 
           the valgrind output showing you? */
        int *arr = new int[5];
        
        /* Now let's look at an invalid read. Compile, run with valgrind, and 
           look to the error summary. */
        int num = arr[5];
        
        /* Watch what happens when we free the memory. Our memory leaks go 
           away! */
        delete [] arr;
        
        /* Uh oh, now we are trying to free the memory twice. Luckily 
           valgrind will tell us! Look at the error summary and see if you 
           can find where the error is by looking at the error report. */
        delete [] arr;
        
        /* What happens when we try to derefence a variable containing the null 
           pointer? */
        // int *p = nullptr;
        // cout << *p;
        
        cout << num << endl;
        return 0;
}



