#include <iostream>
#define MAX_SIZE 10

class ArrayStack {
private:
	int top;
	int stackItems[MAX_SIZE];

public:
	ArrayStack() : top(-1) {}

	void push(int item);
	int pop();
	int peek();
	bool isEmpty() { return top < 0; }
	bool isFull() { return top == MAX_SIZE - 1; }
};
