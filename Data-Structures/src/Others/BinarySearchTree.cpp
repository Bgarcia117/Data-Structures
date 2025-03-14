#include "../../include/BinarySearchTree.h"

// Inserts node by finding its place in the Tree
Node* BinarySearchTree::InsertHelper(Node* node, int newItem) {
	// Base case: Empty tree
	if (node == nullptr) return new Node(newItem);

	// Compares value with node to decide which side to be inserted
	// Then recursively calls until base case is reached
	// Return value is stored in node->left or node->right until recursive calls finish
	if (newItem < node->item) {
		node->left = InsertHelper(node->left, newItem);
	}

	else {
		node->right = InsertHelper(node->right, newItem);
	}
	
	// Returns the unmodified pointer to root node
	return root;
}

// Searches for a node. The path will be at most height + 1 (accounts for root node)
bool BinarySearchTree::SearchHelper(Node* node, int item) {
	if (node == nullptr) return false;

	if (item == node->item) return node->item; 

	// Compares values to pick an edge to follow (edge connects nodes)
	
	if (item < node->item) {
		// The new recursive call returns its value to the previous call
		return SearchHelper(node->left, item);
	}
	else {
		return SearchHelper(node->right, item);
	}
} // Note: Professor perfers to return the value itself

int BinarySearchTree::CountNodesHelper(Node* node) {
	if (node == nullptr) return 0; // Base Case: Empty Tree

	// Adds 1 for the current node
	// If there is no child, it returns and adds 0
	return CountNodesHelper(node->left) + CountNodesHelper(node->right) + 1;
}