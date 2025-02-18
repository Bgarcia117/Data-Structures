#include <stdio.h>
#include "../include/AUList.h"

void AUList::PutItem(int value) {
	if (length < 50) {
		items[length] = value;
		length++;
	}
	else {
		std::cout << "The Array-Based Unsorted List is full!" << endl;
		return;
	}
}

void AUList::DeleteItem(int value) {
	currentPos = items[]
}