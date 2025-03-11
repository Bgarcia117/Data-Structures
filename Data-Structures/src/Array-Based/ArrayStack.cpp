
#include "../../include/ArrayStack.h"

void ArrayStack::push(int item) {
	if (isFull()) {
		std::cout << "The stack if full!" << std::endl;	
	}
	else {
		stackItems[++top] = item; // Increments before inserting item
	}
}

int ArrayStack::pop() {
	if (isEmpty()) {
		std::cout << "The stack is empty!" << std::endl;
		return -1;
	}
	else {
		return stackItems[top--]; // Decrements after returning the value
	}
}

int ArrayStack::peek() {
	if (isEmpty()) {
		std::cout << "The stack is empty!" << std::endl;
		return -1;
	}
	else {
		return stackItems[top]; 
	}
}
