#pragma once

#include "../../include/MinHeap.h"

void MinHeap::Insert(int value) {
	// Checks if heap is full and resizes if needed
	if (IsFull()) {
		// New array of elements with double the capcity
		int* newElements = new int[capacity * 2];

		// Copies over old elements
		for (int i = 0; i < numOfElements; i++) {
			newElements[i] = elements[i];
		}

		delete[] elements;
		elements = newElements; // Points to new array
		capacity *= 2;
	}

	// Stores the new value
	elements[numOfElements] = value;
	numOfElements++;

	// Passes the index through to maintain heap
	HeapifyUp(numOfElements - 1);
}

// Used for moving values "up" the heap
void MinHeap::HeapifyUp(int index) {
	// Checks if it is the only items in the heap
	// Stops the function once it is in the correct position
	if (index == 0 || elements >= elements[Parent(index)]) {
		return;
	}

	// Swaps places with its parent
	swap(elements[index], elements[Parent(index)]);

	// Checks and fixes parent node after swapping
	HeapifyUp(Parent(index));
}

// Used for moving values "down" the heap
// Used for after deleting the root
// Or for building heaps from unsorted arrays
void MinHeap::HeapifyDown(int index) {
	int minValue = index; // Index of current element
	int leftChild = LeftChild(index);
	int rightChild = RightChild(index);

	// Checks if there is anything at the index for the left child
	// Compares to the left child to current node
	if (left < numOfElements && elements[left] < elements[minValue]) {
		minValue = leftChild;
	}

	// Repeats checks on left child on right child
	if (right < numOfElements && elements[right] < elements[minValue]) {
		minValue = rightChild;
	}

	// If original element was not the smallest, make another recursive call
	if (minValue != index) {
		swap(elements[minValue], elements[index]);
		HeapifyDown(minValue);
	}

}

