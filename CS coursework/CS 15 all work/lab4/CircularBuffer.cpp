/*
 *      CircularBuffer.cpp
 *      PartyPlaylist
 *      Comp 15 Lab 3
 *
 *      2016-09-16 Created by Yennie Jun
 *      2016-09-20 Documentation added by Mark A. Sheldon, Tufts University
 *      2019-08-01 Modified by Alice Dempsey
 *      2020-01-31 Modified by Juliana Vega
 *                 Removed "sequence" wording
 *      2020-09-21 Modified by Matt Champlin
 *                 Added prevIndex function that wraps around.
 *                 Note: "front" always points to first element. "back" always
 *                       points to the next available empty slot.
 *      2022-02-09 Modified by Matt Russell
 *                 printBuffer->toString

 */

#include "CircularBuffer.h"
#include <iostream>
#include <sstream>
#include <stdexcept>


using namespace std;


/*  Purpose:    Gets the next index in the buffer
 *  Parameters: index - the index to increment
 *  Returns:    The index of the next element in the buffer.
 *  Notes:      Wraps around!
 */
int CircularBuffer::nextIndex(int index) const {
    return (index+1)%INIT_CAPACITY;
}


/*  Purpose: Default constructor
 *  Notes:   INIT_CAPACITY is set to 5 in .h file
 */
CircularBuffer::CircularBuffer() {
    init(INIT_CAPACITY);
}


/*  Purpose:    Overloaded Constructor for a buffer with a hint for an initial
 *              capacity.
 *  Parameters: initialCapacity - Capacity user wants buffer to be
 */
CircularBuffer::CircularBuffer(int initialCapacity) {
    init(initialCapacity);
}

/*  Purpose:    Initialize a new, empty CircularBuffer with an initial capacity
 *  Parameters: initialCapacity - Capacity user wants buffer to be
 */
void CircularBuffer::init(int initialCapacity) {
    capacity    = initialCapacity;
    bufferArray = new ElementType[capacity];
    currentSize = 0;
    front       = 0;
    back        = 0;
}

/*  Purpose: Destructor. Recycles the dynamically allocated array containing
 *           the data.
 */
CircularBuffer::~CircularBuffer() {
    delete[] bufferArray;
}


/*  Purpose:    Add given element to the back of the buffer
 *  Parameters: elem - object to add to the buffer
 *  Notes:      ElementType is defined in ElementType.h
 */
void CircularBuffer::addAtBack(ElementType elem) {
    if (currentSize == capacity) { expand(); }
    bufferArray[back] = elem;
    currentSize++;
    back = nextIndex(back);
}

/*  Purpose:    Add given element to the front of the list
 *  Parameters: elem - object to add to the buffer
 *  Notes:      ElementType is defined in ElementType.h
 */
void CircularBuffer::addAtFront(ElementType elem)
{
    if (currentSize == capacity) { expand(); }
    bufferArray[front] = elem;
    currentSize++;
   front = nextIndex(front);
}

/*  Purpose:    Remove the element at the back of the list and return it.
 *  Returns:    The ElementType at the back of the list.
 */
ElementType CircularBuffer::removeFromBack() {
    ElementType temp = bufferArray[back];
    if (back == 0){
        back = capacity - 1;
    } else {
        back--;
    }
    return temp;
}

/*  Purpose:    Remove the element at the front of the list and return it.
 *  Returns:    The ElementType at the front of the list.
 */
ElementType CircularBuffer::removeFromFront() {
    ElementType temp = bufferArray[front];
    front = nextIndex(front);
    return temp;
}

/*  Purpose:    Expand the capacity of the array by a factor of 2 + 2.
 *  Parameters: None
 *  Notes:      This one is tricky! It will be different than the expand you
 *              are used to writing. Think about how to handle wrapping. Also
 *              think about how you are going to ensure that "front" and "back"
 *              maintain their meaning once you've copied the items over.
 */
void CircularBuffer::expand() {
    int new_capacity = 2*capacity+2;
    ElementType *buffer_temp = new ElementType[new_capacity];
    int counter = 0;
    for (int i = front; i != back; i=nextIndex(i)){
        buffer_temp[counter] = bufferArray[i];
        counter++;
    }
    front = 0;
    back = capacity-1;
    delete[] bufferArray;
    bufferArray = buffer_temp;
    capacity = new_capacity;
    buffer_temp = nullptr;


}

/*  Purpose: return a string of the contents of the CircularBuffer, with
 *           one element per line
 *  Notes:   adds the elements starting at front; 1-indexed output
 */
std::string CircularBuffer::toString() const {
    std::stringstream ss;
    for (int i = front; i != back; i=nextIndex(i)) {
        ss << i + 1 << ": " << bufferArray[i] << endl;
    }
    return ss.str();
}
