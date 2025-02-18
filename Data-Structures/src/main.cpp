// Array Based Unsorted List
#include <iostream>
#include "../include/AUList.h"

int main() {
	AUList first; // Invokes default constructor
	AUList second(25); // Invokes parameterized constructor

	// Testing Observer functions
	std::cout << "------------First Object-------------" << std::endl;
	std::cout << "Length of the array: " << first.GetLength() << std::endl;
	std::cout << "Checking if the array is full (1: True/ 0: False): " << first.IsFull() << std::endl;
	
	// Testing Transformer functions
	std::cout << "Adding an item: " << std::endl;
	first.PutItem(100);
	std::cout << "Checking if it was added: " << first.GetNextItem() << std::endl;

	std::cout << "Deleting that item..." << std::endl;
	first.DeleteItem(100);
	std::cout << "Checking if it was deleted: " << first.GetItem(100) << std::endl;

	std::cout << "Emptying the list... " << std::endl;
	first.MakeEmpty();
	std::cout << "Checking if all items were deleted. The length of the array: " << first.GetLength() << std::endl;
	
	// Testing iterators
	first.GetNextItem();
	first.ResetList();
	first.GetItem(0);


	return 0;
}