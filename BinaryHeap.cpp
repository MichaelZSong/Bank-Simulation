/*
 * BinaryHeap.cpp
 *
 * Description: Implementation of a Minimum Binary Heap ADT class.
 *
 * Class Invariant: Always a Minimum Binary Heap.
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
BinaryHeap<ElementType>::BinaryHeap(int size) {
    elements = new ElementType[size];
    capacity = size;
    elementCount = 0;
}

// Description: Destructor
template<class ElementType>
BinaryHeap<ElementType>::~BinaryHeap() {
    delete[] elements;
}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: Inserts newElement into the Binary Heap.
//              It returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template<class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType& newElement) {
    if (elementCount == capacity) {
        ElementType* newBH = new ElementType[capacity * 2];

        for (unsigned int i = 0; i < capacity; i++) {
            newBH[i] = elements[i];
        }

        capacity *= 2;

        delete[] elements;  // delete the old array
        elements = newBH;   // point elements to the new Binary Heap
    }

    unsigned int indexOfBottom = elementCount;

    elements[indexOfBottom] = newElement;
    elementCount++;

    reHeapUp(indexOfBottom);

    return true;
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template<class ElementType>
void BinaryHeap<ElementType>::remove() {
    if (elementCount == 0)
        throw EmptyDataCollectionException(
                "remove() called with an empty Binary Heap.");

    elements[0] = elements[elementCount - 1];
    elementCount--;
    reHeapDown(0);

    return;
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType& BinaryHeap<ElementType>::retrieve() const {
    if (getElementCount() <= 0) {
        throw EmptyDataCollectionException(
                "retrieve() called with an empty Binary Heap.");
    } else {
        return elements[0];
    }
}

/* Utility methods */

// Description: Recursively sort the array starting from the last element up.
template<class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfRoot) {
    if (indexOfRoot > 0) {

        unsigned int indexOfParent = floor((indexOfRoot - 1) / 2);

        if (elements[indexOfParent].getTime()
                > elements[indexOfRoot].getTime()) {
            ElementType temp = elements[indexOfRoot];
            elements[indexOfRoot] = elements[indexOfParent];
            elements[indexOfParent] = temp;

            reHeapUp(indexOfParent);
        }
    }

    return;
}

// Description: Recursively put the array back into a Minimum Binary Heap.
template<class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

    unsigned int indexOfMinChild = indexOfRoot;

    // Find indices of children
    unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
    unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

    // Base case: elements[indexOfRoot] is a leaf as it has no children
    if (indexOfLeftChild > elementCount - 1)
        return;

    // If we need to swap, select the smallest child
    // If (elements[indexOfRoot] > elements[indexOfLeftChild])
    if (!(elements[indexOfRoot] <= elements[indexOfLeftChild]))
        indexOfMinChild = indexOfLeftChild;

    // Check if there is a right child, is it the smallest?
    if (indexOfRightChild < elementCount) {
        // if (elements[indexOfMinChild] > elements[indexOfRightChild])
        if (!(elements[indexOfMinChild] <= elements[indexOfRightChild]))
            indexOfMinChild = indexOfRightChild;
    }

    // Swap parent with smallest of children.
    if (indexOfMinChild != indexOfRoot) {

        ElementType temp = elements[indexOfRoot];
        elements[indexOfRoot] = elements[indexOfMinChild];
        elements[indexOfMinChild] = temp;

        // Recursively put the array back into a heap
        reHeapDown(indexOfMinChild);
    }
    return;
}

// For Testing Purposes
// Description: Prints the content of the Queue.
template<class ElementType>
void BinaryHeap<ElementType>::printBH() const {
    cout << "{" << endl;
    for (unsigned int i = 0; i < elementCount; i++) {
        cout << elements[i].getTime() << " " << elements[i].getLength() << endl;
    }
    cout << "}" << endl;
}
