// Array Based Unsorted List
#include <iostream>
#include "../include/AUList.h"

int main() {
	AUList first; // Invokes default constructor
	AUList second(25); // Invokes parameterized constructor


	std::cout << "Array Based Unsorted List" << std::endl;
	std::cout << "Iterators:" << std::endl;
	std::cout << "------------------------------GetLength---------------------------------------" << std::endl;
	// Testing Observer functions
	// GetLength
	std::cout << "First Object: " << std::endl;
	std::cout << "Length of the array..." << first.GetLength() << std::endl;

	std::cout << "Second Object: " << std::endl;
	std::cout << "Length of the array..." << second.GetLength() << std::endl;

	// IsFull
	std::cout << "\n------------------------------IsFull----------------------------------------" << std::endl;
	std::cout << "First Object: " << std::endl;
	std::cout << "Checking if the array is full (1: True/ 0: False): " << first.IsFull() << std::endl;

	std::cout << "Second Object: " << std::endl;
	std::cout << "Checking if the array is full (1: True/ 0: False): " << second.IsFull() << std::endl;
	
	// Testing Transformer functions
	// PutItem
	std::cout << "\n------------------------------PutItem---------------------------------------" << std::endl;
	std::cout << "First Object: " << std::endl;
	std::cout << "Adding an item: " << std::endl;
	first.PutItem(100);
	std::cout << "Checking if item was added. The next item is: " << first.GetNextItem() << std::endl;

	std::cout << "Second Object: " << std::endl;
	std::cout << "Adding an item: " << std::endl;
	second.PutItem(100);
	std::cout << "Checking if item was added. The next item is: " << second.GetNextItem() << std::endl;

	// DeleteItem
	std::cout << "\n------------------------------DeleteItem------------------------------------" << std::endl;
	std::cout << "First Object: " << std::endl;
	std::cout << "Deleting that item..." << std::endl;
	first.DeleteItem(100);
	std::cout << "Checking if it was deleted. Index of item: " << first.GetItem(100) << std::endl;

	std::cout << "Second Object: " << std::endl;
	std::cout << "Deleting that item..." << std::endl;
	second.DeleteItem(100);
	std::cout << "Checking if it was deleted. Index of item: " << second.GetItem(100) << std::endl;

	// MakeEmpty
	std::cout << "\n------------------------------MakeEmpty-------------------------------------" << std::endl;
	std::cout << "First Object: " << std::endl;
	std::cout << "Emptying the list... " << std::endl;
	first.MakeEmpty();
	std::cout << "Checking if all items were deleted. Length of the array: " << first.GetLength() << std::endl;

	std::cout << "Second Object: " << std::endl;
	std::cout << "Emptying the list... " << std::endl;
	second.MakeEmpty();
	std::cout << "Checking if all items were deleted. Length of the array: " << second.GetLength() << std::endl;
	
	// Testing iterators
	//GetNextItem
	std::cout << "\n------------------------------GetNextItem-----------------------------------" << std::endl;
	std::cout << "First Object: " << std::endl;
	std::cout << "Checking the next item stored is based on current positon variable (-1 if none or only one element is stored): "
		      << first.GetNextItem() << std::endl;

	std::cout << "Second Object: " << std::endl;
	std::cout << "Checking the next item stored is based on current positon variable (-1 if none or only one element is stored): "
		      << second.GetNextItem() << std::endl;
	
	// Adding an item for testing
	std::cout << "\n----------------------------------------------------------------------------" << std::endl;
	std::cout << "First Object: " << std::endl;
	std::cout << "Adding an item to empty list... " << std::endl;
	first.PutItem(100);

	std::cout << "Second Object: " << std::endl;
	std::cout << "Adding an item to empty list... " << std::endl;
	second.PutItem(100);

	// Reset List
	std::cout << "\n------------------------------ResetList-------------------------------------" << std::endl;
	std::cout << "First Object: " << std::endl;
	std::cout << "Resetting the current position variable..." << std::endl;
	first.ResetList();
	std::cout << "Checking if it was reset by checking the next item in the array: " << first.GetNextItem() << std::endl;

	std::cout << "Second Object: " << std::endl;
	std::cout << "Resetting the current position variable..." << std::endl;
	second.ResetList();
	std::cout << "Checking if it was reset by checking the next item in the array: " << second.GetNextItem() << std::endl;

	// GetItem
	std::cout << "\n------------------------------GetItem---------------------------------------" << std::endl;
	std::cout << "First Object: " << std::endl;
	std::cout << "The index of that added item: " << first.GetItem(100) << std::endl;

	std::cout << "Second Object: " << std::endl;
	std::cout << "The index of that added item: " << second.GetItem(100) << std::endl;
	


	return 0;
}