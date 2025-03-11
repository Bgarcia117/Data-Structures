#pragma once
// Binary Search Tree
// The root node should be greater than the left child but less than the right
// The left most child should be the min value and rightmost should hold the max

struct Node {
	int item;
	Node* left; // Left Child
	Node* right; // Right Child
};

class BinarySearchTree {
private:
	Node* root; // Entry point node for the tree
	Node* curPos; // Tracks the position in the tree during traversal

	void Insert(Node* &node, int newItem);
	int FindItem(Node* node, int _item);
	void Delete(Node* &node, int _item);
	void DeleteNode(Node*& node);
public:
	BinarySearchTree();

	int GetItem(int _item);
	void PutItem(int newItem);
	void DeleteItem(int _item);
};