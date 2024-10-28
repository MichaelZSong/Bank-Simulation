/*
 * Queue.cpp
 *
 * Description: This is a linked list-based implementation of a Queue ADT class.
 *
 * Author: Zhengxuan Song
 * Date: November 11, 2022
 */

#include "EmptyDataCollectionException.h"
#include <iostream>

using std::cout;
using std::endl;

/* Node class implementations */

template<class ElementType>
Queue<ElementType>::Node::Node() {
}

template<class ElementType>
Queue<ElementType>::Node::Node(ElementType& theData) :
        data(theData) {
}

template<class ElementType>
Queue<ElementType>::Node::Node(ElementType& theData, Node* theNextNode) :
        data(theData), next(theNextNode) {
}

// Description: Default constructor
template<class ElementType>
Queue<ElementType>::Queue() {
    front = nullptr;
    back = nullptr;
    elementCount = 0;
}

/* Queue class implementations */

// Description: Destructor
template<class ElementType>
Queue<ElementType>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Class Invariant: FIFO or LILO order
// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return elementCount == 0;
}

// Description: Inserts newElement at the "back" of this Queue
//              (not necessarily the "back" of this Queue's data structure)
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement) {
    Node* newNode = new Node(newElement);

    if (front == nullptr) {
        front = newNode;
        back = front;
        elementCount++;
        return true;
    } else {
        back->next = newNode;
        back = back->next;
        elementCount++;
    }

    return true;
}

// Description: Removes (but does not return) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
void Queue<ElementType>::dequeue() {
    if (isEmpty()) {
        throw EmptyDataCollectionException("Queue is empty.");
    } else {
        Node* toBeRemoved = front;
        front = front->next;
        elementCount--;
        delete toBeRemoved;
    }
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType& Queue<ElementType>::peek() const {
    if (isEmpty()) {
        throw EmptyDataCollectionException("Queue is empty.");
    } else {
        return front->data;
    }
}

// For Testing Purposes
// Description: Prints the content of the Queue.
template<class ElementType>
void Queue<ElementType>::printQueue() const {
    Node* current = front;

    cout << "{";
    // Traverse the list
    while (current != nullptr) {
        cout << current->data.getType() << " " << current->data.getTime() << " "
                << current->data.getLength();   // Print data
        current = current->next;    // Go to next Node
        if (current != nullptr) {
            cout << ",";    // Print a comma unless at the end of the list
        }
    }
    cout << "}"; // Don't print a newline - it might not be wanted
}
