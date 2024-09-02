/*
 * unit_tests.h
 * Matt Russell && Matt Champlin
 * 1/6/2021
 * This file demonstrates test style for the unit_test unit testing framework.
 *
 * Rules for unit tests:
 *     Test file name must be unit_tests.h
 *     All test functions must take no arguments
 *     All test functions must return void
 *
 * Background info for tests:
 *     If a test finishes execution, it is considered successful.
 *     Use assert(boolean_expression) to test for known conditions.
 *     If the expression evaluates to false, then the assertion fails.
 *     Tests will also fail on segfaults, etc.
 *
 * Other notes:
 *     Be sure to #include any .h files as necessary
 *     Each test must have a unique name
 *     Valgrind will be run automatically on all tests
 *
 * Workflow encouragements:
 *     You are encouraged to write MANY, MANY tests!!!
 *     Furthermore, you are encouraged to write and run tests as you work.
 *     So, the workflow should be something along the lines of:
 *            1) Write a function (or part of a function)
 *            2) Write at least 1 test for the code you just wrote
 *            3) Run the tests, and fix all errors (including memory issues)
 *            4) Rinse and Repeat!
 *    *** It is wise to debug BEFORE moving on to writing the next function. ***
 *
 * NB: The ArrayList code has bugs, so (some) tests will fail first on purpose!
 * Be sure to ask questions!!
 */

#include "ArrayList.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

/*
 * constructor test 0
 * Make sure no fatal errors/memory leaks in the default constructor
 */
void constructor_test_0() {
    ArrayList list;
}

/*
 * constructor test 1
 * Make sure no items exist in the list upon construction
 * Note: given the provided code, this test should fail. Fix it!
 */
void constructor_test_1() {
    ArrayList list; // One way to invoke the default constructor.
    assert(list.size() == 0);
}


/*
 * TODO: Write a test that checks if the ArrayList is empty.
 * NOTE: Uncomment the function header below when you are ready.
 *
 * isEmpty test
 * Make sure we report an empty list correctly.
 */
 void isEmpty_test() {
     ArrayList list;
     assert(list.isEmpty());
 }


/*
 * toString_test_0
 * Checks that the given list is as we expect it to be
 * Note: You might want to create a simpler test which doesn't push any
 *       elements back before asserting the result of list.toString().
 *       In some sense, this test will inevitably have to work in tandem
 *	 with the pushAtBack test below.
 */

void toString_test_0() {
    ArrayList list;
    list.pushAtBack(1);
    list.pushAtBack(2);
    list.pushAtBack(3);
    assert(list.toString() == "[1,2,3]");
}

/*
 * TODO: Write a test that inserts a single integer into the ArrayList.
 * Print the list to cout and make sure num_items is correctly updated.
 * Note: Uncomment the function header below when you are ready.
 */
void pushAtBack_test() {
    ArrayList list;
    for (int i = 0; i < 5; i++){
        list.pushAtBack(i); //meant to test expand and pushAtBack simultaneously
    }
    assert(list.size() == 5);
}

/*
 * TODO: Write a test that inserts multiple integers into the ArrayList, forcing
 *       the ArrayList to expand.
 * Make sure num_items is correctly updated and print the inserted numbers to
 * cout.
 * Note: Uncomment the function header below when you are ready.
 */
void expand_test() {
    ArrayList list;
    for (int i = 0; i < 20; i++){
        list.pushAtBack(i); //Pick a value of i large enough that expand is triggered
    }
    assert(list.toString() == "[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19]");
}


/********************** JFFE (Just For Fun) Excersises ***********************/

/*
 * TODO: Write a test to make sure your 'find' function returns true when an
 * integer is in the ArrayList.
 * Note: you must create the function declaration yourself!
 *
 * find_returns_true test
 * Make sure find returns true when an integer is present in the ArrayList
 */
void find_test_1(){
    ArrayList list;
    for (int i = 0; i < 8; i++){
        list.pushAtBack(i);
    }
    assert(list.find(5));
}

/*
 * TODO: Write a test to make sure your 'find' function returns false when an
 * integer is NOT in the ArrayList.
 * Note: you must create the function declaration yourself!
 *
 * find_returns_false test
 * Make sure find returns false when an integer is NOT present in the ArrayList
 */
void find_test_2(){
    ArrayList list;
    for (int i =0; i < 8; i++){
        list.pushAtBack(i);
    }
    assert(list.find(10) == false);
}


/*
 * TODO: Write a test that inserts a single integer into the ArrayList and then
 * removes it. Print the empty list to verify it has in fact been removed.
 * Make sure num_items is correctly updated.
 * Note: Uncomment the function header below when you are ready.
 */
 void popFromBack_test() {
     ArrayList list;
     list.pushAtBack(1);
     list.popFromBack();
     assert(list.toString() == "[]");
 }


/* Write any other tests you can think of below! */
