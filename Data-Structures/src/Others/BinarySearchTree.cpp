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

// Finds the minimum value in a subtree by reaching the leftmost node
// Can be used on left or right subtrees
Node* BinarySearchTree::FindMinValue(Node* node) {

	// The current node is checked each time as an extra saftey check
	// Equivalent to checking current node before the loop
	// != is omitted in the loop becuase it is implied
	while (node && node->left) {
		node = node->left;
	}

	// Returns pointer to the node (b/c of function return type)
	return node;
}

Node* BinarySearchTree::DeleteHelper(Node* node, int _item) {
	if (node == nullptr) return nullptr; // Base Case: Empty Tree

	// Continues to next node after comparing
	if (_item < node->item) {
		node->left = DeleteHelper(node->left, _item);
	}
	else if (_item > node->item) {
		node->right = DeleteHelper(node->right, _item);
	}
	else {
		// Base Case: Node with no children
		if (node->left == nullptr && node->right == nullptr) {
			// Deallocates memory for node obj allocated by "new"
			delete node;

			// Pointer is set to nullptr and is stored in root, left, or right
			// If not stored in root, last line of function returns root
			return nullptr;

		}
		// Case 2: One child
		// Child on the right side
		// Previous if statement checked if both children == nullptr, so one child != nullptr
		else if (node->left == nullptr) {
			// Stores right child before parent is deleted
			Node* temp = node->right;

			// Deallocates parent node from heap
			delete node;

			// Returns child node to previous node
			return temp;
		}
		// Child on the left side
		else if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			return temp;
		}
		// Case 3: Node with two children
		else {
			// Finds successor (smallest in the right subtree)
			Node* successor = FindMinValue(node->right);

			// Replaces the value of current node with value of successor
			node->item = successor->item;

			// Finds and deletes orignal successor node
			node->right = DeleteHelper(node->right, successor->item);
		}
	}

	// Returns nullptr if the only (root) node is deleted 
	// Otherwise it returns unchanged root
	return node;
}

// Prints nodes using In Order Traversal
void BinarySearchTree::PrintInOrder(Node* node) {
	// Base Case: nullptr/empty tree
	// Unwinds the call stack
	if (node == nullptr) return; 

	// Travereses to the left most node
	PrintInOrder(node->left);

	// Runs once the left most node is reached
	std::cout << node->item << " ";

	// Traveres to right child
	PrintInOrder(node->right);
}

void BinarySearchTree::DeleteTree(Node* node) {
	if (node == nullptr) return;

	// Recursive calls to delete left, right, then root nodes
	DeleteTree(node->left);
	DeleteTree(node->right);

	// Deallocates node memory
	delete node;
}

Node* BinarySearchTree::DeepCopy(Node* original) {
	if (original == nullptr) return nullptr;

	// Creates a copy of the original parent node for the new tree
	Node* newNode = new Node(original->item);

	// Reucursive calls for left and right subtrees
	// Stores new nodes as children of parent nodes
	newNode->left = DeepCopy(original->left);
	newNode->right = DeepCopy(original->right);

	// Returns the new parent node with children
	return newNode;


}

void BinarySearchTree::TraverseAndEnqueue(TraversalOrder order) {
	switch (order) {
	    case PRE_ORDER:
			PreOrderEnqueue(root);
			break;

		case IN_ORDER:
			InOrderEnqueue(root);
			break;

		case POST_ORDER:
			PostOrderEnqueue(root);
			break;

	}
}

// Pre-Order Traversal
void BinarySearchTree::PreOrderEnqueue(Node* node) {
	if (node == nullptr) return; // Base Case: Null node

	// Process parent node first
	LinkedQueue.Enqueue(node->item);

	// Traverse left subtree
	PreOrderEnqueue(node->left);

	// Traverse right subtree
	PreOrderEnqueue(node->right);
}

// In-Order Traversal: Processes left subtree, then right subtree, then root
void BinarySearchTree::InOrderEnqueue(Node* node) {
	if (root == nullptr) return;

	InOrderEnqueue(node->left);

	LinkedQueue.Enqueue(node->item);

	InOrderEnqueue(node->right);
}

// Post-Order Traversal: Process left subtree, then right subtree, then root
void BinarySearchTree::PostOrderEnqueue(Node* node) {
	if (root == nullptr) return;

	PostOrderEnqueue(node->left);

	PostOrderEnqueue(node->right);

	LinkedQueue.Enqueue(node->item);
}

void BinarySearchTree::BSTDemonstration() {
	BinarySearchTree tree;

	tree.InsertNode(15);
	tree.InsertNode(12);
	tree.PrintBST;
}