/*
 * Queue.h
 *
 * Description: This is a linked list-based implementation of a Queue ADT class.
 *
 * Author: Zhengxuan Song
 * Date: November 11, 2022
 */

template<class ElementType>
class Queue {

private:

    class Node {

    public:

        // Public attributes
        ElementType data = nullptr;
        Node* next = nullptr;   // Pointer to next node

        // Constructors
        Node();
        Node(ElementType& theData);
        Node(ElementType& theData, Node* theNextNode);

    };

    Node* front;   // Pointer to front of queue
    Node* back;    // Pointer to back of queue
    unsigned int elementCount;  // Number of elements currently in the queue

public:
    // Constructors and Destructors

    // Description: Default constructor
    Queue<ElementType>();

    // Description: Destructor.
    ~Queue();

    /******* Start of Queue Public Interface *******/

    // Class Invariant: FIFO or LILO order
    // Description: Returns true if this Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement at the "back" of this Queue
    //              (not necessarily the "back" of this Queue's data structure)
    //              and returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue(ElementType& newElement);

    // Description: Removes (but does not return) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    void dequeue();

    // Description: Returns (but does not remove) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType& peek() const;

    /******* End of Queue Public Interface *******/

    // For Testing Purposes
    // Description: Prints the content of the Queue.
    void printQueue() const;

};
#include "Queue.cpp"
