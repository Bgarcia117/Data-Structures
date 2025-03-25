// Array Based Unsorted List

class AUList {
private:
	int items[50] = {};
	int length;
	int currentPos; // Tracks index of items in items array

public: 
	AUList() : length(0), currentPos(-1) {} // Default constructor

	AUList(int value) : length(1) { // Parameterized constructor
		items[0] = value;
		currentPos = 0;
	}

	// Observer functions
	int GetLength() const { return length; }

	bool IsFull() const { return length == 50; }

	// Transformers
	void PutItem(int); // Inserts a value in the items array
	void DeleteItem(int); // Deletes an item from the items array
	void MakeEmpty() { length = 0; } // Empties the array

	// Iterators
	int GetNextItem(); // Returns the next element based on the current position variable

	void ResetList() { currentPos = -1; } // Resets index of the current position variable
	int GetItem(int value); // Returns the index of an element

	void AUListDemonstration(); // Creates AUList instances and displays functions
};