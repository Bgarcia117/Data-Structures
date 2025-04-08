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

	elements[numOfElements] = value;
	numOfElements++;

	// Passes the index through to maintain heap
	HeapifyUp(numOfElements - 1);
}

// Used for inserting new elements
void MinHeap::HeapifyUp(int index) {
	// Checks if new element is at the root or in the right place
	// New element needs to be greater than the parent
	if (index == 0 || elements >= elements[Parent(index)]) {
		return;
	}

	// Swaps places with its parent
	swap(elements[index], elements[Parent(index)]);

	// Checks and fixes parent node after swapping
	HeapifyUp(Parent(index));
}

// Used when root is removed (Dequeue)
// or when the inserted
void MinHeap::HeapifyDown(int index) {
	int min = index; // Root to be removed
	int left = LeftChild(index);
	int right = RightChild(index);

	// Checks if there is anything at the index for the left child
	// Compares to the left child
	if (left < numOfElements && elements[left] < elements[min]) {

	}






}

