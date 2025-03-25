// Array Based Unsorted List
#include <iostream>
#include "../include/AUList.h"

int main() {
	int userChoice;

	std::cout << "Select a Data Structure to see a demonstration (1-4): " << std::endl;
	std::cout << "1) Array Based Unsorted List " << std::endl;
	std::cout << "2) Array Based Stack " << std::endl;
	std::cout << "3) Linked List Stack " << std::endl;
	std::cout << "4) Binary Search Tree " << std::endl;

	while (true) {
		std::cin >> userChoice;

		if (userChoice >= 1 && userChoice <= 4) {
			break;
		}
		else {
			std::cout << "Invalid Choice. Please enter a number (1-4)" << std::endl;
		}
	}
	
	switch (userChoice) {
	    case 1:
			AUList list(25); 
			list.AUListDemonstration();

	}

	return 0;
}