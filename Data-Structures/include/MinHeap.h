#pragma once

class MinHeap{
private:
	int* elements;
	int numOfElements;
	int capacity;

	int Parent(int i) { return (i - 1) / 2; }
	int LeftChild(int i) { return (2 * i) + 1; }
	int RightChild(int i) { return (2 * i) + 2; }

	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

public:
	// Default argument constructor, different value can be passed
	MinHeap(int startCapacity = 10) {
		elements = new numOfElements[startCapacity];
		numOfElements = 0;
		capacity = startCapacity;
	}

	~MinHeap() { delete[] element; }

	// Observer Functions
	bool IsFull() { return numOfElements == capacity; }
	bool IsEmpty() { return numOfElements == 0; }

	// Transformer functions
	void MakeEmpty() { numOfElements = 0; } 
	void Insert(int value);
	void HeapifyUp(int index);
	void HeapifyDown(int index);
	
};

class PriorityQueue {
private:
	MinHeap heap;

public:
	PriorityQueue(int startCapacity = 10) : heap(startCapacity) {}
};