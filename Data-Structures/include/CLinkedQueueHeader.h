#pragma once

class CircularQueue {
private:
	struct Node {
		int value;
		Node* next;
		Node(int _value) : value(_value), next(nullptr) {}
	};

	Node* rear; // Rear pointer will point to front

public:
	CircularQueue() : rear(nullptr) {}

	void Enqueue();
	void Dequeue();
};