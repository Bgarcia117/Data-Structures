#include <iostream>
#define MAX_SIZE 10

class ArrayStack {
private:
	int top;
	int stackItems[MAX_SIZE];

public:
	ArrayStack() : top(-1) {}

	void Push(int item);
	int Pop();
	int Peek();
	bool IsEmpty() { return top < 0; }
	bool IsFull() { return top == MAX_SIZE - 1; }
};
