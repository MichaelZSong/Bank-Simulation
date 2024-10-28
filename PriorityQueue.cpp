/*
 * PriorityQueue.cpp
 *
 * Description: Implementation file of a Priority Queue ADT class.
 *
 * Author: Zhengxuan Song
 * Date: November 11, 2022
 */

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

// Description: Default constructor
template<class ElementType>
PriorityQueue<ElementType>::PriorityQueue() {
    aBH = new BinaryHeap<ElementType>(3);
}

// Description: Destructor
template<class ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {
    delete aBH;
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return aBH->getElementCount() == 0;
}

// Description: Inserts newElement in this Priority Queue and
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template<class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType& newElement) {
    return aBH->insert(newElement);
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template<class ElementType>
void PriorityQueue<ElementType>::dequeue() {
    aBH->remove();
}

// Description: Returns (but does not remove) the element with the next
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType& PriorityQueue<ElementType>::peek() const {
    return aBH->retrieve();
}

// For Testing Purposes
// Description: Prints the content of the Queue.
template<class ElementType>
void PriorityQueue<ElementType>::printPQ() const {
    aBH->printBH();
}
