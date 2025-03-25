#include <iostream>
#include "../../include/AUList.h"

void AUList::PutItem(int value) {
	if (length < 50) {
		items[length] = value;
		length++;
	}
	else {
		std::cout << "The Array-Based Unsorted List is full!" << std::endl;
		return;
	}
}

void AUList::DeleteItem(int value) {
	bool itemFound = false;

	for (int i = 0; i < length; i++) { // Searches for the item
		if (items[i] == value) {
			itemFound = true;
		}
		if (itemFound && i < length - 1) { // Shifts items if there are more than one
			items[i] = items[i + 1];
		}
	}

	// Decreases length if item is found even for edge cases (if empty or last element)
	if (itemFound) {
		length--; 
	}
}

int AUList::GetNextItem() {
	if (length != 0 && currentPos != length - 1) {
		currentPos++;
		return items[currentPos];
	}
	else {
		std::cout << "Error: Not enough values stored in array." << std::endl;
		return -1;
	}

	
}

int AUList::GetItem(int value) {
	for (int i = 0; i < length; i++) { // Searches for the item
		if (items[i] == value) {
			return i;
		}
	}

	return -1; // Returns -1 if item is not found
}

void AUList::AUListDemonstration() {
	std::cout << "Array Based Unsorted List" << std::endl;
	std::cout << "Iterators:" << std::endl;
	std::cout << "------------------------------GetLength---------------------------------------" << std::endl;
	// Testing Observer functions
	// GetLength
	std::cout << "Length of the array..." << GetLength() << std::endl;

	// IsFull
	std::cout << "\n------------------------------IsFull----------------------------------------" << std::endl;
	std::cout << "Checking if the array is full (1: True/ 0: False): " << IsFull() << std::endl;


	// Testing Transformer functions
	// PutItem
	std::cout << "\n------------------------------PutItem---------------------------------------" << std::endl;
	std::cout << "Adding an item: " << std::endl;
	PutItem(100);
	std::cout << "Checking if item was added. The next item is: " << GetNextItem() << std::endl;

	// DeleteItem
	std::cout << "\n------------------------------DeleteItem------------------------------------" << std::endl;
	std::cout << "Deleting that item..." << std::endl;
	DeleteItem(100);
	std::cout << "Checking if it was deleted. Index of item: " << GetItem(100) << std::endl;

	// MakeEmpty
	std::cout << "\n------------------------------MakeEmpty-------------------------------------" << std::endl;
	std::cout << "Emptying the list... " << std::endl;
	MakeEmpty();
	std::cout << "Checking if all items were deleted. Length of the array: " << GetLength() << std::endl;

	// Testing iterators
	//GetNextItem
	std::cout << "\n------------------------------GetNextItem-----------------------------------" << std::endl;
	std::cout << "Checking the next item stored is based on current positon variable (-1 if none or only one element is stored): "
		<< GetNextItem() << std::endl;

	// Adding an item for testing
	std::cout << "\n----------------------------------------------------------------------------" << std::endl;
	std::cout << "Adding an item to empty list... " << std::endl;
	PutItem(100);

	// Reset List
	std::cout << "\n------------------------------ResetList-------------------------------------" << std::endl;
	std::cout << "Resetting the current position variable..." << std::endl;
	ResetList();
	std::cout << "Checking if it was reset by checking the next item in the array: " << GetNextItem() << std::endl;

	// GetItem
	std::cout << "\n------------------------------GetItem---------------------------------------" << std::endl;
	std::cout << "The index of that added item: " << GetItem(100) << std::endl;
}