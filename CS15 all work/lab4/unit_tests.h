/*
 *  unit_tests.h
 *  PartyPlaylist
 *  Comp 15 Lab 3
 *
 *  unit testing file for the PartyPlaylist lab.
 *  The tests here are the same as in `main.cpp'
 *
 *  Students can choose how they'd like to test!
 */

#include "CircularBuffer.h"
#include "Queue.h"
#include "Stack.h"
#include <cassert>
#include <iostream>


/*  Purpose: Test all CircularBuffer functions are working as expected. */
void testCircularBuffer() {

    CircularBuffer myBuffer(2);
    myBuffer.addAtBack("Positions");
    myBuffer.addAtBack("Holy");

    assert(myBuffer.toString() == "1: Positions\n2: Holy\n");
}

/*  Purpose: Given a string that's 'our' output, and one that's the reference
 *           output, print both for easy debugging
 */
void printCompare(std::string ourString, std::string testStr) {
    std::cout << "ourStr\n------\n" << ourString << "-----\n";
    std::cout << "testStr\n------\n" << testStr << "-----\n";
}

/*  Purpose: Tests Stack class */
void testStack() {
    std::string songs[] = {"Positions", "Holy", "Mood", "Lonely", "34+35"};
    const int   nSongs  = sizeof(songs) / sizeof(std::string);
    std::string testStr = "";

    Stack myStack;

    /* add the songs to the stack, and build up the string to test against */
    for (int i = 0; i < nSongs; i++) {
        myStack.push(songs[i]);
        testStr += std::to_string(i + 1) + ": " + songs[nSongs - i - 1] + "\n";
    }
    printCompare(myStack.toString(), testStr);
    assert(myStack.toString() == testStr);

    /* take a song off the stack - make sure it's right! */
    assert(myStack.pop() == "34+35");

    /* reset and rebuild the test string */
    testStr = "";
    for (int i = 0; i < nSongs - 1; i++) {
        testStr += std::to_string(i + 1) + ": " + songs[nSongs - i - 2] + "\n";
    }

    assert(myStack.toString() == testStr);

    /*
     * Nice work! Do you think this data structure works well as
     * a playlist for a party? Would a Queue work better or worse?
     */
}

/*  Purpose: Tests Queue class. */
void testQueue() {
    std::string songs[] = {"Positions", "Holy", "Mood", "Lonely", "34+35"};
    const int   nSongs  = sizeof(songs) / sizeof(std::string);
    std::string testStr = "";

    Queue myQueue;

    /* add the songs to the queue, and build up the string to test against */
    for (int i = 0; i < nSongs; i++) {
        myQueue.enqueue(songs[i]);
        testStr += std::to_string(i + 1) + ": " + songs[i] + "\n";
    }

    /* Make sure our queue is as expected! */
    assert(std::string(myQueue.toString()) == testStr);

    /* play a song - make sure it's the right one! */
    assert(myQueue.dequeue() == "Positions");
    std::cout << myQueue.toString() << std::endl;

    /* reset and rebuild the test string */
    testStr = "";
    for (int i = 0; i < nSongs - 1; i++) {
        testStr += std::to_string(i + 1) + ": " + songs[i + 1] + "\n";
    }

    /* test our queue */
    assert(myQueue.toString() == testStr);
}
