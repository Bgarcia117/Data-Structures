#pragma once
#include <iostream>
#include "CLinkedQueue.h"
// Binary Search Tree
// The root node should be greater than the left child but less than the right
// The left most child should be the min value and rightmost should hold the max

enum TraversalOrder {
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
};

struct Node {
	int item;
	Node* left; // Left Child
	Node* right; // Right Child

	Node(int _item) : item(_item), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
	CircularQueue LinkedQueue;
	Node* root; // Entry point node for the tree

	// Traversal Function Helpers
	bool SearchHelper(Node* node, int _item);
	int CountNodesHelper(Node* node);
	void PrintInOrder(Node* node);
	void PreOrderEnqueue(Node* node);
	void InOrderEnqueue(Node* node);
	void PostOrderEnqueue(Node* node);

	// Transformer Funciton Helpers
	Node* InsertHelper(Node* root, int newItem);
	Node* DeleteHelper(Node* node, int _item);
	void DeleteTree(Node* node);

	// Observer Funciton Helpers
	Node* FindMinValue(Node* node);
	Node* DeepCopy(Node* original);
	
public:
	BinarySearchTree() : root(nullptr) {}
	BinarySearchTree(const BinarySearchTree& otherBST) { root = DeepCopy(otherBST.root); }

	~BinarySearchTree() { DeleteTree(root); }
	
	// Traversal Functions
	void TraverseAndEnqueue(TraversalOrder order);
	int CountNodes() { return CountNodesHelper(root); }
	void PrintBST() { PrintInOrder(root); std::cout << std::endl; }

	// Transformer Functions
	void InsertNode(int newItem) { root = InsertHelper(root, newItem); }
	bool SearchNode(int item) { return SearchHelper(root, item); }
	void DeleteNode(int _item) { root = DeleteHelper(root, _item); }

	void BSTDemonstration();
};