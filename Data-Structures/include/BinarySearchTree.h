#pragma once
// Binary Search Tree
// The root node should be greater than the left child but less than the right
// The left most child should be the min value and rightmost should hold the max

struct Node {
	int item;
	Node* left; // Left Child
	Node* right; // Right Child

	Node(int _item) : item(_item), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
	Node* root; // Entry point node for the tree

	Node* InsertHelper(Node* root, int newItem);
	bool SearchHelper(Node* node, int _item);
	void DeleteHelper(Node* node, int _item);
	int CountNodesHelper(Node* node);
	
public:
	BinarySearchTree() : root(nullptr) {}

	void InsertNode(int newItem) { root = InsertHelper(root, newItem); }
	bool SearchNode(int item) { return SearchHelper(root, item); }
	void DeleteNode(int _item);
	int CountNodes() { return CountNodesHelper(root); }
};