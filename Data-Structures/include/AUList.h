class AUList {
private:
	int items[50];
	int length;

public: 
	AUList() : length(0) {} // Default constructor

	AUList(int value) : length(1) {
		items[0] = value;
	}

	// Observer functions
	int GetLength() const { return length; }

	bool IsFull() const { return length == 123; }

	// Transformers
	void PutItem(int);
	void DeleteItem(int);
};