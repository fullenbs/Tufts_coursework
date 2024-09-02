/*
 * unit_tests.h
 *
 * CS 15 homework 1
 * by Tyler Calabrese, January 2021
 *
 * Uses Matt Russell's unit_test framework to test the CharArrayList class.
 *
 * Instructions for using testing framework can be found at in CS 15's lab
 * 1 -- both in the spec and in the provided ArrayList_tests.h and Makefile.
 * More in-depth information for those who are curious as to how it works can
 * be found at http://www.github.com/mattrussell2/unit_test.
 */

#include "CharArrayList.h"
#include <cassert>
/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/


// Tests each constructor, is dependent that size() and isEmpty() works
// Makes sure the ArrayList is of the correct size. There aren't any
// edge cases I could think of for each constructor.
void constructor_test() {
    CharArrayList test_list; // default constructor
    assert(test_list.isEmpty());

    CharArrayList test_list2('a'); // one char constructor
    assert(test_list2.size() == 1);

    char          test_arr[4] = {'a', 'b', 'c', 'd'}; // input array
    CharArrayList test_list3(test_arr, 4);
    assert(test_list3.size() == 4);

    CharArrayList test_list4 = test_list3; // overloaded constructor
    assert(test_list4.size() == 4);
}

// tests overloaded assignment operator function
// Check with two test cases
void op_overload_test() {
    CharArrayList test_list1('a');
    CharArrayList test_list2('b');
    CharArrayList test_list3('c');
    CharArrayList test_list4;

    test_list2.insertAt('b', 1);
    test_list2.insertAt('c', 2);
    // this involves dealing with assignment of two different ArrayList sizes
    test_list1 = test_list2;

    // two empty ArrayLists of same size
    test_list3 = test_list4;

    // tests I have to verify elements transferred properly
    // could be done using toString() as well
    assert(test_list1.elementAt(0) == 'b');
    assert(test_list1.elementAt(1) == 'b');
    assert(test_list1.elementAt(2) == 'c');
    assert(test_list3.isEmpty());
}

// Checks that isEmpty gets correct results.
// isEmpty() is implicity used work
// throughout the ArrayList
void isEmpty_test() {
    // tests fully empty list, should be true
    CharArrayList test_list;
    assert(test_list.isEmpty());

    // tests nonempty list, should be false
    CharArrayList test_list2('c');
    assert(not test_list2.isEmpty());
}

// Tests the size function
// Expected results are: 0 for first test, 1 for second test, 4 for third test
// Size() is used work properly throughout the ArrayList
void size_test() {
    CharArrayList test_list; // tests empty list
    assert(test_list.size() == 0);

    CharArrayList test_list2('a'); // tests 1 char list
    assert(test_list2.size() == 1);

    char          arr_test[4] = {'a', 'b', 'c', 'd'}; // tests array
    CharArrayList test_list3(arr_test, 4);
    assert(test_list3.size() == 4);
}

// Make sure that properly return first_char of array and that throws error
// properly.
void first_test() {
    // Makes an ArrayList and checks first char is correct
    CharArrayList test_list('a');
    assert(test_list.first() == 'a');

    // full test for throwing exception
    CharArrayList test_list2;
    bool          runtime_error_thrown = false; // testing variables
    std::string   error_message        = "";
    char          c;
    try {
        c = test_list2.first(); // just need to check existence
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message        = e.what();
    }
    assert(runtime_error_thrown); // if both pass, throw successful
    assert(error_message == "cannot get first of empty ArrayList");
}

// Makes sure last element is displayed correctly and that exception thrown
// properly
void last_test() {
    // tests with populated ArrayList
    char          arr_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list(arr_test, 5);
    assert(test_list.last() == 'e');

    // tests exception thrown properly
    CharArrayList test_list2;                   // tests with empty ArrayList
    bool          runtime_error_thrown = false; // testing variables
    std::string   error_message        = "";
    char          c;

    try {
        c = test_list2.last();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message        = e.what();
    }
    assert(runtime_error_thrown); // if both asserts passed, throw successful
    assert(error_message == "cannot get last of empty ArrayList");
}


// Makes sure elementAt works, need only to test exception thrown properly
// and that gives proper index, due to how elementAt is written, as exception
// is thrown only when out of array bounds
void elementAt_test() {
    // tests for index in bounds
    char          arr_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list(arr_test, 5);
    assert(test_list.elementAt(2) == 'c');

    // tests exception thrown properly
    bool        range_error_thrown = false; // testing for index out of bounds
    std::string error_message      = "";
    char        c;
    try {
        c = test_list.elementAt(-1); //-1 out of range
    } catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message      = e.what();
    }
    assert(range_error_thrown); // if both asserts passed, throw successful
    assert(error_message == "index (-1) not in range [0..5)");
}

// tests that toString reads in arraylist as and formats output correctly.
// This test assumes pushAtFront works, which is tested further down.
void toString_test() {
    // tests nonempty string converted correctly
    CharArrayList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    test_list.pushAtFront('d');
    assert(test_list.toString() == "[CharArrayList of size 4 <<dcba>>]");

    // tests with empty ArrayList
    CharArrayList test_list2;
    assert(test_list2.toString() == "[CharArrayList of size 0 <<>>]");
}

// tests that toReverseString properly reads in the arraylist as and formats
// outputs correctly. This test assumes insertAt works, which is tested
// further down.
void toReverseString_test() {
    // tests nonempty ArrayList
    CharArrayList test_list;
    test_list.insertAt('a', 0);
    test_list.insertAt('b', 0);
    test_list.insertAt('c', 0);
    test_list.insertAt('d', 0);
    assert(test_list.toReverseString() ==
           "[CharLinkedList of size 4 <<abcd>>]");

    // tests empty ArrayList
    CharArrayList test_list2;
    assert(test_list2.toReverseString() == "[CharLinkedList of size 0 <<>>]");
}

// Tests that pushAtFront properly adds the char to the front of the list. Use
// toString(), which was tested earlier to make sure I'm getting the correct
// output. This working also tests expand() as if the ArrayList couldn't expand,
// it wouldn't work.
void pushAtFront() {
    // testing for starting from empty ArrayList
    CharArrayList test_list;
    test_list.pushAtFront('b');
    test_list.pushAtFront('a');
    assert(test_list.toString() == "[CharArrayList of size 2 <<ab>>]");

    // testing for nonempty ArrayList
    char          arr_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(arr_test, 5);
    test_list2.pushAtFront('Z');
    assert(test_list2.toString() == "[CharArrayList of size 6 <<Zabcde>>]");
} // View bottom for insertAt tests

// tests for insertinOrder()
// Verify that it sorts based on ASCII values, meaning is alphabetical and upper
// case before lower case
void insertInOrder_test() {
    // tests with list already alphabetically sorted
    char          arr_test[5] = {'A', 'B', 'D', 'E', 'F'};
    CharArrayList test_list(arr_test, 5);
    test_list.insertInOrder('C');
    assert(test_list.toString() == "[CharArrayList of size 6 <<ABCDEF>>]");

    // Tests with non ordered list
    char          arr_test2[3] = {'Z', 'E', 'D'};
    CharArrayList test_list2(arr_test2, 3);
    test_list2.insertInOrder('A');
    assert(test_list2.toString() == "[CharArrayList of size 4 <<AZED>>]");

    // Tests with adding uppercase to lowercase only ArrayList
    char          arr_test3[3] = {'b', 'c', 'd'};
    CharArrayList test_list3(arr_test3, 3);
    test_list3.insertInOrder('Z');
    assert(test_list3.toString() == "[CharArrayList of size 4 <<Zbcd>>]");
}

// tests for popFromFront, I use toString() to verify the correct output.
// For 0, I make sure the error is thrown properly.
void popFromFront_test() {
    // tests removing from array list of size 1
    CharArrayList test_list;
    test_list.pushAtFront('a');
    test_list.popFromFront();
    assert(test_list.toString() == "[CharArrayList of size 0 <<>>]");

    // tests removing front of array list of size 5
    char          arr_test[5] = {'A', 'B', 'C', 'D', 'E'};
    CharArrayList test_list2(arr_test, 5);
    test_list2.popFromFront();
    assert(test_list2.toString() == "[CharArrayList of size 4 <<BCDE>>]");

    // tests removing from empty array list
    bool          runtime_error_thrown = false;
    std::string   error_message        = "";
    CharArrayList test_list3;
    try {
        test_list3.popFromFront();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message        = e.what();
    }
    assert(runtime_error_thrown); // if both asserts passed, throw successful
    assert(error_message == "cannot pop from empty ArrayList");
}

// Uses the exact same tests as popFromFront, as I felt I covered the key
// cases.
void popFromBack_test() {
    // tests with ArrayList of size 1
    CharArrayList test_list;
    test_list.pushAtFront('a'); // Making an empty ArrayList
    test_list.popFromBack();
    assert(test_list.toString() == "[CharArrayList of size 0 <<>>]");

    // tests with ArrayList of size 5
    char          arr_test[5] = {'A', 'B', 'C', 'D', 'E'}; // generic array
    CharArrayList test_list2(arr_test, 5);
    test_list2.popFromBack();
    assert(test_list2.toString() == "[CharArrayList of size 4 <<ABCD>>]");

    // tests with empty ArrayList
    bool          runtime_error_thrown = false; // testing for out of bounds
    std::string   error_message        = "";
    CharArrayList test_list3;
    try {
        test_list3.popFromFront();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message        = e.what();
    }
    assert(runtime_error_thrown); // if both asserts passed, throw successful
    assert(error_message == "cannot pop from empty ArrayList");
}

// Tests removeAt, removing at any possible bound. Testing at middle entries
// also tests the private helper function popFromMid()
void removeAt_test() {
    // ArrayList used for all tests
    char          arr_test[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    CharArrayList test_list(arr_test, 8);

    // tests removing the first element
    test_list.removeAt(0);
    assert(test_list.toString() == "[CharArrayList of size 7 <<BCDEFGH>>]");

    // tests removing a  middle element
    test_list.removeAt(2);
    assert(test_list.toString() == "[CharArrayList of size 6 <<BCEFGH>>]");

    // tests removing the last element
    test_list.removeAt(5);
    assert(test_list.toString() == "[CharArrayList of size 5 <<BCEFG>>]");

    // tests for out of bounds index
    bool        range_error_thrown = false;
    std::string error_message      = "";
    try { // checks out of bounds error
        test_list.removeAt(100);
    } catch (const std::runtime_error &e) {
        range_error_thrown = true;
        error_message      = e.what();
    }
    assert(range_error_thrown); // if both asserts passed, throw successful
    assert(error_message == "index (100) not in range [0..5)");
}

// Tests replaceAt using arr_test.
void replaceAt_test() {
    // ArrayList used for both tests
    char          arr_test[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    CharArrayList test_list(arr_test, 8);

    // tests replacing a character in ArrayList bounds
    test_list.replaceAt('0', 2);
    assert(test_list.elementAt(2) == '0');

    // tests replacing out of bounds
    bool        range_error_thrown = false;
    std::string error_message      = "";
    try {
        test_list.replaceAt('0', 100);
    } catch (const std::runtime_error &e) {
        range_error_thrown = true;
        error_message      = e.what();
    }
    assert(range_error_thrown); // if both asserts passed, throw successful
    assert(error_message == "index (100) not in range [0..8)");
}

// Tests concatenate function with empty and nonempty ArrayLists. Output is
// verified using toString()
void concatenate_test() {
    CharArrayList  test_list;
    CharArrayList *test_list2 = new CharArrayList();
    CharArrayList *test_list3 = new CharArrayList();

    test_list.pushAtBack('a');
    test_list.pushAtBack('b');
    test_list.pushAtBack('c');

    test_list2->pushAtBack('d');
    test_list2->pushAtBack('e');
    test_list2->pushAtBack('f');

    // tests adding a populated ArrayList to the end of test_list
    test_list.concatenate(test_list2);
    assert(test_list.toString() == "[CharArrayList of size 6 <<abcdef>>]");

    // tests adding empty ArrayList to an ArrayList
    test_list.concatenate(test_list3); // tests adding an empty string
    assert(test_list.toString() == "[CharArrayList of size 6 <<abcdef>>]");

    delete test_list2; // recycles memory
    delete test_list3;
}

// Tests the clear() function. The function works if the ArrayList is now empty,
// due to how the function is written, there is only one test case
void clear_test() {
    CharArrayList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    test_list.clear();
    assert(test_list.isEmpty());
}

// Tests the shrink() function
// In style guide, told to delete all commented code, but the way I verified
// this worked was by printing out capacity before and after in the shrink
// function. I also know it works because my code would bug out due to memory
// issues with insertAt_many testing, and that doesn't happen with shrink
// implemented.
void shrink_test() {
    // Shrinks the array list
    char          arr_test[5] = {'a', 'b', 'c', 'd'};
    CharArrayList test_list(arr_test, 5);
    test_list.shrink();
    assert(not test_list.isEmpty()); // makes sure the function still exists
}


// Below is tests provided for InsertAt, most had minor, if any, changes
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

// Tests correct insertion into an empty AL.
// Afterwards, size should be 1 and element at index 0
// should be the element we inserted.
void insertAt_empty_correct() {
    CharArrayList test_list;
    test_list.insertAt('a', 0);
    assert(test_list.size() == 1);
    assert(test_list.elementAt(0) == 'a');
}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {
    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList test_list;
    try {
        // insertAt for out-of-range index
        test_list.insertAt('a', 42);
    } catch (const std::range_error &e) {
        // if insertAt is correctly implemented, a range_error will be
        // thrown, and we will end up here
        range_error_thrown = true;
        error_message      = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");
}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {
    // initialize 1-element list
    CharArrayList test_list('a');
    test_list.insertAt('b', 0);

    // correct outputs
    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
}

// Tests correct insertAt for back of 1-element list.
// Modified by adding a couple elements
void insertAt_back_singleton_list() {
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);
    test_list.insertAt('c', 2);
    test_list.insertAt('d', 3);

    // checks correct assignment
    assert(test_list.size() == 4);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
    assert(test_list.elementAt(1) == 'c');
    assert(test_list.elementAt(1) == 'd');
}

// Tests calling insertAt for a large number of elements.
// Not only does this test insertAt, it also checks that
// array expansion works correctly.
void insertAt_many_elements() {
    CharArrayList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.insertAt('a', i);
    }
    assert(test_list.size() == 1000);
    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
}

// Tests insertion into front, back and middle of a larger list
void insertAt_front_back_middle() {
    char          test_arr[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    CharArrayList test_list(test_arr, 8);

    // insertAt middle
    test_list.insertAt('z', 3);
    assert(test_list.size() == 9);
    assert(test_list.elementAt(3) == 'z');
    assert(test_list.toString() == "[CharArrayList of size 9 <<abczdefgh>>]");

    // insertAt front
    test_list.insertAt('y', 0);
    assert(test_list.size() == 10);
    assert(test_list.elementAt(0) == 'y');
    assert(test_list.toString() == "[CharArrayList of size 10 <<yabczdefgh>>]");

    // insertAt back
    test_list.insertAt('x', 10);
    assert(test_list.size() == 11);
    assert(test_list.elementAt(10) == 'x');
    assert(test_list.toString() ==
           "[CharArrayList of size 11 <<yabczdefghx>>]");
}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {
    char          test_arr[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    CharArrayList test_list(test_arr, 8);

    // track error message statuses
    bool        range_error_thrown = false;
    std::string error_message      = "";

    try {
        test_list.insertAt('a', 42);
    } catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message      = e.what();
    }

    assert(range_error_thrown); // if pass both, error thrown correctly
    assert(error_message == "index (42) not in range [0..8]");
}