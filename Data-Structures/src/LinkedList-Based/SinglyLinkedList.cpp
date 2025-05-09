#include <vector>
#include "../../include/SinglyLinkedList.h"

void SinglyLinkedList::insertAtHead(int val) {
	Node* newNode = new Node(val);
	newNode->next = head;               // Stores nullptr if list was empty
	head = newNode;
	if (!tail) { tail = newNode; }      // If list was empty, set tail to head
}

void SinglyLinkedList::insertAtTail(int val) {
	Node* newNode = new Node(val);

	if (!tail) {
		tail = head = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

bool SinglyLinkedList::deleteNode(int index) {
	// Case: Empty List
	if (!head) { return false; }

	// Case: Removing the Head node 
	if (index == 0) {
		Node* temp = head;              
		head = head->next;              // If next is nullptr, it stores nullptr
		if (!head) { tail = nullptr; }  // If the new head (next) is nullptr
		delete temp;
		return true;
	}

	// Traverse to the node before the one to be removed
	Node* position = head;

	// position in the condition ensures it's not a nullptr
	// Stops if we reach the index or if we reach a nullptr
	for (int i = 0; position && i < index - 1; ++i) {
		position = position->next;
	}

	// If the current position is a nullptr (for loop can leave it as nullptr)
	// next checks if we reached the index but no value is stored
	if (!position || !position->next) { return false; }

}

std::vector<int> SinglyLinkedList::getValues() {
	std::vector<int> values;

	Node* position = head;

	// While position != nullptr
	while (position) {
		values.push_back(position->value);
		position = position->next;
	}

	return values;
}