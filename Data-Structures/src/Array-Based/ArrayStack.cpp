
#include "../../include/ArrayStack.h"

void ArrayStack::Push(int item) {
	if (IsFull()) {
		std::cout << "The stack if full!" << std::endl;	
	}
	else {
		stackItems[++top] = item; // Increments before inserting item
	}
}

int ArrayStack::Pop() {
	if (IsEmpty()) {
		std::cout << "The stack is empty!" << std::endl;
		return -1;
	}
	else {
		return stackItems[top--]; // Decrements after returning the value
	}
}

int ArrayStack::Peek() {
	if (IsEmpty()) {
		std::cout << "The stack is empty!" << std::endl;
		return -1;
	}
	else {
		return stackItems[top]; 
	}
}
