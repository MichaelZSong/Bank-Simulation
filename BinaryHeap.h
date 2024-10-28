/*
 * BinaryHeap.h
 *
 * Description: Header file of a Minimum Binary Heap ADT class.
 *
 * Class Invariant: Always a Minimum Binary Heap.
 *
 * Author: Zhengxuan Song
 * Date: November 11, 2022
 */

template<class ElementType>
class BinaryHeap {

private:

    ElementType* elements;
    unsigned int capacity;
    unsigned int elementCount;

    void reHeapUp(unsigned int indexOfRoot);
    void reHeapDown(unsigned int indexOfRoot);

public:

    // Description: Default constructor
    BinaryHeap<ElementType>(int size);

    // Description: Destructor
    ~BinaryHeap();

    /******* Start of Binary Heap Public Interface *******/

    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition: The Binary Heap is unchanged by this operation.
    // Time Efficiency: O(1)
    unsigned int getElementCount() const;

    // Description: Inserts newElement into the Binary Heap.
    //              It returns true if successful, otherwise false.
    // Time Efficiency: O(log2 n)
    bool insert(ElementType& newElement);

    // Description: Removes (but does not return) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(log2 n)
    void remove();

    // Description: Retrieves (but does not remove) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Postcondition: This Binary Heap is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(1)
    ElementType& retrieve() const;

    /******* End of Binary Heap Public Interface *******/

    // For Testing Purposes
    // Description: Prints the content of the Queue.
    void printBH() const;

};
#include "BinaryHeap.cpp"
