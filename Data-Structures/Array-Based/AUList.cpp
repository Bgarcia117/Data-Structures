#include <iostream>
#include "../include/AUList.h"

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