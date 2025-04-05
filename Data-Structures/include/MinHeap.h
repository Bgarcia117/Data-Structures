#pragma once

struct MinHeap {
	int* element;
	int numOfElements;
	int capacity;

	// Default argument constructor, different value can be passed
	MinHeap(int startCapacity = 10) {
		elements = new numOfElements[startCapacity];
		numOfElements = 0;
		capacity = startCapacity;
	}

	~MinHeap() { delete[] element; }
};

class PriorityQueue {
private:
	MinHeap heap;

public:
	PriorityQueue(int startCapacity = 10) : heap(startCapacity);
};