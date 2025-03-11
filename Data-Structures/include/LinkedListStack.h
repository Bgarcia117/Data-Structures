struct Node {
	int item;
	Node* next;

	Node(int value) : item(value), next(nullptr) {}
};

class LLStack {
private:
	Node* head; // Top of the stack

public:
	LLStack() : head(nullptr) {}

	void push(int item);
	int pop();
	int peek();
	bool isEmpty() { return head == nullptr; }
};