/*
 *  unit_tests.h
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  Tests for Linked List
 *
 */

#include "CharLinkedList.h"
#include <cassert>
#include <iostream>
#include <sstream>

// runs a test on each constructor except for overloaded constructor
// Done due to overload requiring more tests
void constructor_test() {
    CharLinkedList test_list1;
    assert(test_list1.size() == 0);
    assert(test_list1.isEmpty());

    CharLinkedList test_list2('a');
    assert(test_list2.size() == 1);
    assert(test_list2.elementAt(0) == 'a');

    char           arr_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list3(arr_test, 5);
    assert(test_list3.size() == 5);
    for (int i = 0; i < 5; i++) {
        assert(test_list3.elementAt(i) == arr_test[i]);
    }
}

// tests overloaded constructor with nonempty linked list
void overload_constructor_nonempty_test() {
    char           arr_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list(arr_test, 5);

    CharLinkedList test_list2(test_list);
    for (int i = 0; i < 5; i++) { // check each element
        assert(test_list2.elementAt(i) == arr_test[i]);
    }
}

// overloaded constructor with using empty linked list
void overload_constructor_empty_test() {
    CharLinkedList test_list3;
    CharLinkedList test_list4(test_list3);
    assert(test_list4.isEmpty());
}

// tests overloaded assignment operator
void overload_assignment_test() {
    CharLinkedList test_list1('a');
    CharLinkedList test_list2('b');
    CharLinkedList test_list3('c');
    CharLinkedList test_list4;

    test_list2.insertAt('b', 1);
    test_list2.insertAt('c', 2);

    // Assignment with two linked lists of different size
    test_list1 = test_list2;

    // two empty LinkedLists of same size
    test_list3 = test_list4;

    // tests I have to verify elements transferred properly
    // could be done using toString() as well
    assert(test_list1.elementAt(0) == 'b');
    assert(test_list1.elementAt(1) == 'b');
    assert(test_list1.elementAt(2) == 'c');
    assert(test_list3.isEmpty());
}

// tests isEmpty, should return true
void isEmpty_empty_test() {
    CharLinkedList test_list;
    assert(test_list.isEmpty());
}

// tests isEmpty(), should return false
void isEmpty_nonempty_test() {
    CharLinkedList test_list2('b');
    assert(not test_list2.isEmpty());
}

// tests size is properly assigned in constructor initialization
void size_constructor_test() {
    CharLinkedList test_list; // default constructor
    assert(test_list.size() == 0);

    CharLinkedList test_list2('a'); // char constructor
    assert(test_list2.size() == 1);

    char           test_arr[3] = {'a', 'b', 'c'}; // array constructor
    CharLinkedList test_list3(test_arr, 3);
    assert(test_list3.size() == 3);

    CharLinkedList test_list4(test_list3); // copy constructor
    assert(test_list4.size() == 3);
}


// tests elementAt function when given index in LinkedList bounds
void elementAt_inbounds_test() {
    CharLinkedList test_list1('a'); // test 1
    assert(test_list1.elementAt(0) == 'a');

    char           test_arr[3] = {'a', 'b', 'c'}; // test 2
    CharLinkedList test_list2(test_arr, 3);

    for (int i = 0; i < 3; i++) { // checks each element
        assert(test_list2.elementAt(i) == test_arr[i]);
    }
}

// checks elementAt when given error outside LinkedList range
void elementAt_outbounds_test() {
    CharLinkedList test_list;
    bool           runtime_error_thrown = false;
    std::string    error_message        = "";
    char           c;
    try {
        c = test_list.first();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message        = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot get first of empty LinkedList");
}

// Tests first() with nonempty LinkedList
void first_inbounds_test() {
    CharLinkedList test_list('a');
    assert(test_list.first() == 'a');

    char           test_arr[3] = {'a', 'b', 'c'};
    CharLinkedList test_list2(test_arr, 3);
    assert(test_list.first() == 'a');
}

// Tests first() with empty LinkedList
void first_test_outbounds() {
    CharLinkedList test_list;
    bool           runtime_error_thrown = false;
    std::string    error_message        = "";
    char           c;
    try {
        c = test_list.first();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message        = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot get first of empty LinkedList");
}

// Tests last() with nonempty LinkedList
void last_inbounds_test() {
    char           arr_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list(arr_test, 5);
    assert(test_list.last() == 'e');

    CharLinkedList test_list2('a');
    assert(test_list2.last() == 'a');
}

// Tests last() with empty LinkedList
void last_outbounds_test() {
    CharLinkedList test_list;
    bool           runtime_error_thrown = false;
    std::string    error_message        = "";
    char           c;

    try {
        c = test_list.last();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message        = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot get last of empty LinkedList");
}

// tests toString with nonempty LinkedList
void toString_nonempty_test() {
    CharLinkedList test_list;
    test_list.pushAtFront('a'); // Tested assuming PushAtFront works
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    test_list.pushAtFront('d');
    assert(test_list.toString() == "[CharLinkedList of size 4 <<dcba>>]");
}

// tests toString with empty LinkedList
void tostring_nonempty_test() {
    CharLinkedList test_list;
    assert(test_list.toString() == "[CharLinkedList of size 0 <<>>]");
}

// Tests toReverseString() with nonempty LinkedList
void toReverseString_nonempty_test() {
    CharLinkedList test_list;
    test_list.pushAtFront('a'); // Tested knowing pushAtFront works
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');
    assert(test_list.toReverseString() == "[CharLinkedList of size 3 <<abc>>]");
}

// tests to ReverseString on an empty LinkedList
void toReverseString_empty_test() {
    CharLinkedList test_list;
    assert(test_list.toReverseString() == "[CharLinkedList of size 0 <<>>]");
}

// Checks that pushAtFront can add to an empty list
void pushAtFront_empty_test() {
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    assert(test_list.toString() == "[CharLinkedList of size 1 <<a>>]");
}

// Checks that pushAtFront can add to a nonempty list
void pushAtFront_nonempty_test() {
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.pushAtFront('b');
    test_list.pushAtFront('c');

    assert(test_list.toString() == "[CharLinkedList of size 3 <<cba>>]");
}

// checks pushAtBack works with an empty LinkedList
void pushAtBack_empty_test() {
    CharLinkedList test_list;
    test_list.pushAtBack('a');
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.size() == 1);
}

// tests pushAtBack  works for nonempty LinkedList
void pushAtBack_nonempty_test() {
    CharLinkedList test_list('a');
    test_list.pushAtBack('b');
    test_list.pushAtBack('c');
    test_list.pushAtBack('d');
    assert(test_list.toString() == "[CharLinkedList of size 4 <<abcd>>]");
    assert(test_list.size() == 4);
}

// tests insertAt with an empty LinkedList
void insertAt_empty_test() {
    CharLinkedList test_list;
    test_list.insertAt('a', 0);
    assert(test_list.toString() == "[CharLinkedList of size 1 <<a>>]");
}


// Insert at with front, middle, or back with nonempty list
void insertAt_inbounds_test() {
    // tests inserting at front
    char           arr_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list(arr_test, 5);
    test_list.insertAt('H', 0);
    assert(test_list.toString() == "[CharLinkedList of size 6 <<Habcde>>]");

    // tests inserting at middle
    char           arr_test2[5] = {'1', '2', '3', '4', '5'};
    CharLinkedList test_list2(arr_test2, 5);
    test_list2.insertAt('K', 3);
    assert(test_list2.toString() == "[CharLinkedList of size 6 <<123K45>>]");

    // tests inserting at end of list
    char           arr_test3[5] = {'A', 'B', 'C', 'D', 'E'};
    CharLinkedList test_list3(arr_test3, 5);
    test_list3.insertAt('2', 5);
    assert(test_list3.toString() == "[CharLinkedList of size 6 <<ABCDE2>>]");
}

// tests insertAt when given index out of bounds
void insertAt_outbounds_test() {
    CharLinkedList test_list('a');
    bool           runtime_error_thrown = false;
    std::string    error_message        = "";

    try {
        test_list.insertAt('c', 500);
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message        = e.what();
    }
    assert(runtime_error_thrown); // if error thrown properly, test passed
    assert(error_message == "index (500) not in range [0..1]");
}


// tests replaceAt for linked list when index is in bounds
void replaceAt_inbounds_test() {
    // Linkedlist used for all tests in this function
    char           arr_test[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    CharLinkedList test_list(arr_test, 8);

    // replaces at front
    test_list.replaceAt('1', 0);

    // replaces at middle
    test_list.replaceAt('0', 2);

    // replaces at end
    test_list.replaceAt('9', 7);

    // checks all replacement correct
    assert(test_list.toString() == "[CharLinkedList of size 8 <<1B0DEFG9>>]");
}

// Tests replaceAt() with out of bounds index
void replaceAt_outbounds_test() {
    char           arr_test[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    CharLinkedList test_list(arr_test, 8);
    bool           range_error_thrown = false;
    std::string    error_message      = "";
    try {
        test_list.replaceAt('0', 100);
    } catch (const std::runtime_error &e) {
        range_error_thrown = true;
        error_message      = e.what();
    }
    assert(range_error_thrown); // if both asserts passed, throw successful
    assert(error_message == "index (100) not in range [0..8)");
}

// Tests removeAt, this handles removing at front, middle, or back
void removeAt_inbounds_test() {
    // Use test_list for all tests in this function
    char           arr_test[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    CharLinkedList test_list(arr_test, 8);

    // tests removing the first element
    test_list.removeAt(0);
    assert(test_list.toString() == "[CharLinkedList of size 7 <<BCDEFGH>>]");

    // tests removing middle element
    test_list.removeAt(2);
    assert(test_list.toString() == "[CharLinkedList of size 6 <<BCEFGH>>]");

    // tests removing the last element
    test_list.removeAt(5);
    assert(test_list.toString() == "[CharLinkedList of size 5 <<BCEFG>>]");
}

// Tests removeAt when index out of bounds
void removeAt_outbounds_test() {
    char           arr_test[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    CharLinkedList test_list(arr_test, 7);

    bool        range_error_thrown = false;
    std::string error_message      = "";
    try { // checks out of bounds error
        test_list.removeAt(100);
    } catch (const std::runtime_error &e) {
        range_error_thrown = true;
        error_message      = e.what();
    }
    assert(range_error_thrown); // if both asserts passed, throw successful
    assert(error_message == "index (100) not in range [0..7)");
}

// Tests with popFromFront() and nonempty list
void popFromFront_inbounds_test() {
    // tests popFromFront() with list size 1
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.popFromFront();
    assert(test_list.toString() == "[CharLinkedList of size 0 <<>>]");

    // tests popFromFront() with list size 5
    char           arr_test[5] = {'A', 'B', 'C', 'D', 'E'};
    CharLinkedList test_list2(arr_test, 5);
    test_list2.popFromFront();
    assert(test_list2.toString() == "[CharLinkedList of size 4 <<BCDE>>]");
}

// tests popFromFront() when have empty list
void popFromFront_outbounds_test() {
    bool           runtime_error_thrown = false;
    std::string    error_message        = "";
    CharLinkedList test_list;
    try {
        test_list.popFromFront();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message        = e.what();
    }
    assert(runtime_error_thrown); // if both asserts passed, throw successful
    assert(error_message == "cannot pop from empty LinkedList");
}

// popFromBack when list made empty and list made nonempty
void popFromBack_inbounds_test() {
    // tests with LinkedList of size 1
    CharLinkedList test_list;
    test_list.pushAtFront('a');
    test_list.popFromBack();
    assert(test_list.toString() == "[CharLinkedList of size 0 <<>>]");

    // tests with LinkedList of size 5
    char           arr_test[5] = {'A', 'B', 'C', 'D', 'E'};
    CharLinkedList test_list2(arr_test, 5);
    test_list2.popFromBack();
    assert(test_list2.toString() == "[CharLinkedList of size 4 <<ABCD>>]");
}

// tests popFromBack() when list empty
void popFromBack_outbounds_test() {
    bool           runtime_error_thrown = false;
    std::string    error_message        = "";
    CharLinkedList test_list3;
    try {
        test_list3.popFromFront();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message        = e.what();
    }
    assert(runtime_error_thrown); // if both asserts passed, throw successful
    assert(error_message == "cannot pop from empty LinkedList");
}

// tests concatenate with two nonempty lists
void concat_nonempty_test() {
    char            arr[3] = {'a', 'b', 'c'};
    CharLinkedList  test_list(arr, 3);
    CharLinkedList *test_list2 = new CharLinkedList();
    test_list2->pushAtBack('1');
    test_list2->pushAtBack('2');
    test_list2->pushAtBack('3');

    test_list.concatenate(test_list2);
    assert(test_list.toString() == "[CharLinkedList of size 6 <<abc123>>]");
    delete test_list2;
}

// tests concatenate with adding an empty linked list
void concat_empty_test() {
    CharLinkedList  test_list('a');
    CharLinkedList *test_list2 = new CharLinkedList();
    test_list.concatenate(test_list2);
    assert(test_list.toString() == "[CharLinkedList of size 1 <<a>>]");
    delete test_list2;
}


// On HW1, I failed some tests regarding insertInOrder, and this function
// runs the failed tests that I could see the inputs.
void insertInOrder_w1_failed_test() {
    // Tests with addinge empty linked list
    CharLinkedList test_list;
    test_list.insertInOrder('a');
    assert(test_list.elementAt(0) == 'a');

    // tests failed case with a, b, c, d, adding z to get abcdz
    char           test_arr[4] = {'a', 'b', 'c', 'd'};
    CharLinkedList test_list2(test_arr, 4);
    test_list2.insertInOrder('z');
    assert(test_list2.toString() == "[CharLinkedList of size 5 <<abcdz>>]");
}

// tests insertInOrder with some more specific cases
void insertInOrder_generic_test() {
    // List already alphabetically sorted
    char           arr_test[5] = {'A', 'B', 'D', 'E', 'F'};
    CharLinkedList test_list(arr_test, 5);
    test_list.insertInOrder('C');
    assert(test_list.toString() == "[CharLinkedList of size 6 <<ABCDEF>>]");

    // Adding a char already present in list
    CharLinkedList test_list2(arr_test, 5);
    test_list2.insertInOrder('E');
    assert(test_list2.toString() == "[CharLinkedList of size 6 <<ABDEEF>>]");
}

// Tests insertInOrder() with some more edge cases
void insertInOrder_edges_test() {
    // Tests with non ordered list
    char           arr_test[3] = {'E', 'Z', 'D'};
    CharLinkedList test_list(arr_test, 3);
    test_list.insertInOrder('F');
    assert(test_list.toString() == "[CharLinkedList of size 4 <<EFZD>>]");

    // tests having upper/lower case
    char           arr_test2[3] = {'b', 'c', 'd'};
    CharLinkedList test_list2(arr_test2, 3);
    test_list2.insertInOrder('Z');
    assert(test_list2.toString() == "[CharLinkedList of size 4 <<Zbcd>>]");
}