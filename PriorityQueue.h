/*
 * PriorityQueue.h
 *
 * Description: Header file of a Priority Queue ADT class.
 *
 * Author: Zhengxuan Song
 * Date: November 11, 2022
 */

#include "BinaryHeap.h"

template<class ElementType>
class PriorityQueue {

private:

    BinaryHeap<ElementType>* aBH = nullptr;

public:

    // Description: Default constructor
    PriorityQueue<ElementType>();

    // Description: Destructor
    ~PriorityQueue();

    /******* Start of Priority Queue Public Interface *******/

    // Description: Returns true if this Priority Queue is empty, otherwise false.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement in this Priority Queue and
    //              returns true if successful, otherwise false.
    // Time Efficiency: O(log2 n)
    bool enqueue(ElementType& newElement);

    // Description: Removes (but does not return) the element with the next
    //              "highest" priority value from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
    // Time Efficiency: O(log2 n)
    void dequeue();

    // Description: Returns (but does not remove) the element with the next
    //              "highest" priority from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType& peek() const;

    /*******  End of Priority Queue Public Interface *******/

    // For Testing Purposes
    // Description: Prints the content of the Queue.
    void printPQ() const;

};
#include "PriorityQueue.cpp"
