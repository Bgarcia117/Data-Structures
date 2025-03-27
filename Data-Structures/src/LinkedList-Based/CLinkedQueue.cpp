#include "../../include/CLinkedQueue.h"

void CircularQueue::Enqueue(int _value) {
	Node* newNode = new Node(_value);

	// Check if queue is empty
	if (IsEmpty()) { // !rear would also work
		rear = newNode;
		rear->next = rear;
	}
	else {
		// newNode is the new rear, so it must point to front node
		newNode->next = rear->next;

		// Link the old rear node to the newNode / new rear
		// The old rear is now in front of old rear in the queue
		rear->next = newNode;

		// Nodes are inserted at rear so newNode is now rear
		rear = newNode;
		
	}
}

int CircularQueue::Dequeue() {
	if (IsEmpty()) { return -1; }

	Node* front = rear->next;
	int frontValue = front->value;

	// If there is only one element
	if (front == rear) {
		delete front;
		rear = nullptr;
	}
	else { 
		// Rear points to new front
		rear->next = front->next;
		delete front;
	}

	// Returns the value of the node removed
	return  frontValue;
}

