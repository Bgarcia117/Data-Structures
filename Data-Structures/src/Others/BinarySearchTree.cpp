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

// Traverses tree until the value is found or NULL is reached
int BinarySearchTree::FindItem(Node* node, int item) {
	if (node == NULL) {
		return -1; // Use a dummy value not -1
	}
	else if (item == node->item) {
		return node->item; // Returns value if found
	}
	// Compares values to pick and edge to follow (edge connects nodes)
	else if (item < node->item) {
		return FindItem(node->left, item);
	}
	else {
		return FindItem(node->right, item);
	}
}