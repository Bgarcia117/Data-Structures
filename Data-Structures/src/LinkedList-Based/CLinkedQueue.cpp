#include "../../include/CLinkedQueueHeader.h"

void CLinkedQueue::Enqueue(int _value) {
	Node* newNode = new Node(_value);

	// Check if queue is empty
	if (!rear) { // Works as if rear == nullptr
		rear = newNode;
		rear->next = rear;
	}
	else {
		newNode->next = rear->next;


		
	}
}