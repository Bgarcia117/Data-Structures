#pragma once

class CircularQueue {
private:
	struct Node {
		int value;
		Node* next;
		Node(int _value) : value(_value), next(nullptr) {}
	};

	Node* rear; // Rear pointer will point to front node

public:
	CircularQueue() : rear(nullptr) {}

	void Enqueue(int _value);
	int Dequeue();
	
	bool IsEmpty() { return rear == nullptr; }
};