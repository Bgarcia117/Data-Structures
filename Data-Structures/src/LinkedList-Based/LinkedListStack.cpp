#include <iostream>
#include "../../include/LinkedListStack.h"

void LLStack::push(int item) {
	Node* newNode = new Node(item); // Creates and allocates space for a new node
	newNode->next = head; // The node points to the top (the previous node)
	head = newNode; // The new node is now the top
}

int LLStack::pop() {
	if (isEmpty()) {
		std::cout << "The stack is empty" << std::endl;
		return -1;
	}
	
	Node* temp = head; 
	head = temp->next; // The next node is now the top
	int tempItem = head->item; // Temporarily stores the data from node being deleted

	delete temp;
	return tempItem; // Returns the data in the temp variable from the delted node
}

int LLStack::peek() {
	if (isEmpty()) {
		std::cout << "The stack is empty" << std::endl;
		return -1;
	}

	return head->item;
}
