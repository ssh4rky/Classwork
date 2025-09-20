#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T value;
	Node<T>* previous;
	Node<T>* next;
	Node(T val) : value(val), previous(nullptr), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	LinkedList() : head(nullptr), tail(nullptr), size(0) {}
	~LinkedList();

	void Append(T val);
	void Find(T val) const;
	void InsertAt(int index, T val);
	void PrintList();

	void forEach(void(*func)(T&));
	T RemoveAt(int index);

	int GetSize() const {
		return size;
	}
	Node<T>* GetHead() const {
		return head;
	}
	Node<T>* GetTail() const {
		return tail;
	}
};

template <typename T>
void LinkedList<T>::Append(T val) {
	Node<T>* newNode = new Node<T>(val);
	if (tail == nullptr) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

template<typename T>
LinkedList<T>::~LinkedList() {
	Node<T>* current = head;
	while (current) {
		Node<T>* nextNode = current->next;
		delete[] current;
		current = nextNode;
	}
}

template<typename T>
T LinkedList<T>::RemoveAt(int index) {
	if (index < 0 || index > size) {
		throw out_of_range("Index out of Bounds");
	}
	Node<T>* toDelete = nullptr;
	if (index == 0) {
		Node<T>* next = head->next;
		toDelete = head;
		head = next;
	}
	else {
		Node<T>* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		toDelete = current->next;
		current->next = toDelete->next;
		if (toDelete == tail) {
			tail = current;
		}
	}
	size--;
	return toDelete->value;
	delete toDelete;
}

template <typename T>
void LinkedList<T>::PrintList() {
	Node<int>* current = GetHead();
	while (current != nullptr) {
		Node<int>* nextNode = current->next;
		cout << current->value << " ";
		current = nextNode;
	}
	cout << endl;
}

template <typename T>
void LinkedList<T>::forEach(void(*func)(T&)) {
	Node<T>* current = head;
	while (current) {
		func(current->value);
		current = current->next;
	}
}

void Increment(int& val) {
	val++;
}

void Square(int& val) {
	val *= val;
}

// Стек на основі динамічного масиву
template<typename T>
class Stack {
private:
	T* data;
	int capacity;
	int top;

	void resize(int newCapacity) {
		T* temp = new T[newCapacity];
		for (int i = 0; i < capacity; i++) {
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		capacity = newCapacity;
	}
public:
	Stack(int initCapacity = 10) : capacity(initCapacity), top(-1) {
		data = new T[capacity];
	}
	~Stack() {
		delete[] data;
	}

	bool isEmpty() const {
		return top == -1;
	}
	int size() const {
		return top + 1;
	}
	void clear() {
		top = -1;
	}

	void push(const T& value) {
		if (top + 1 >= capacity) {
			resize(capacity * 2);
		}
		data[++top] = value;
	}
	T pop() {
		if (isEmpty()) {
			throw out_of_range("Stack is empty");
		}
		return data[top--];
	}
	T peek() const {
		if (isEmpty()) {
			throw out_of_range("Stack is empty");
		}
		return data[top];
	}
};

int main()
{
	LinkedList<int> list;
	list.Append(10);
	list.Append(12);
	list.Append(14);
	list.Append(16);
	list.PrintList();

	list.forEach(Increment);
	list.PrintList();

	list.forEach(Square);
	list.PrintList();

	Stack<char> stack;
	stack.push('q');
	stack.push('w');
	stack.push('t');

	cout << stack.peek() << endl;
	stack.pop();
	cout << stack.peek() << endl;
}
