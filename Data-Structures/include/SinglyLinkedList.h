#pragma once
#include <vector>

class SinglyLinkedList {
private:
	struct Node {
		int value;
		Node* next;
		Node(int val) : value(val), next(nullptr) {}
	};

	Node* head;
	Node* tail;

public:
	SinglyLinkedList() : head(nullptr), tail(nullptr) {}

	void insertAtHead(int val);
	void insertAtTail(int val);
	void deleteNode(int val);
	vector<int> getValues();
};

