#include "../../include/SinglyLinkedList.h"

void SinglyLinkedList::insertAtHead(int val) {
	Node* newNode = new Node(val);
	newNode->next = head;
	head = newNode;
	if (!tail) { tail = newNode; }
}

void SinglyLinkedList::insertAtTail(int val) {
	Node* newNode = new Node(val);

}
