#include "../../include/BinarySearchTree.h"

// Traverses through the tree until it finds its NULL spot
Node* BinarySearchTree::InsertHelper(Node* root, int newItem) {
	// Base case: Empty tree
	if (node == NULL) {
		return new Node(newItem);
	}

	// Compares value with node to decide which side to be inserted
	// Then recursively calls until base case is reached
	else if (newItem < node->item) {
		node->left = InsertHelper(node->left, newItem);
	}

	else {
		node->right = InsertHelper(node->right, newItem);
	}
	
	// Returns the unmodified pointer to root node
	return root;
}

bool BinarySearchTree::SearchHelper(Node* node, int item) {
	if (node == nullptr) return false;

	if (item == node->item) return node->item; 

	// Compares values to pick an edge to follow (edge connects nodes)
	if (item < node->item) {
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