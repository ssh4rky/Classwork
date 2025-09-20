#include <iostream>
#include <string>

using namespace std;

template <typename T>

struct Node {
	T value;
	Node<T>* next;
	Node(T val) : value(val), next(nullptr) {}
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

int main()
{
	LinkedList<int> list;
	list.Append(10);
	list.Append(12);

	Node<int>* current = list.GetHead();
	while (current != nullptr) {
		Node<int>* nextNode = current->next;
		cout << current->value << endl;
		current = nextNode;
	}
}
