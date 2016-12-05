#pragma once
#include <iostream>

template <typename T>
class Queue {
public:	
	Queue ();
	~Queue ();
	void printQueue ();	
	void enqueue (T item);
	T dequeue ();
	bool contains (T item);
private:
	struct Node {
		T data;
		Node *next;
	};
	Node* head;
	Node* tail;
	Node* makeNode (T item);
	/*Node* makeNode (T item) {
		Node* n = new Node();
		n->data = item;
		n->next = nullptr;
		return n;
	}*/
};

template <typename T>
Queue<T>::Queue () {
	head = nullptr;
	tail = head;
}

template <typename T>
Queue<T>::~Queue () {
	Node* ptr = head, *tmp;
	if (ptr == nullptr) {
		return;
	}
	while (ptr) {
		tmp = ptr;
		ptr = ptr->next;
		delete(tmp);
	}
}

template <typename T>
typename Queue<T>::Node* Queue<T>::makeNode (T item) {
	Node* n = new Node();
	n->data = item;
	n->next = nullptr;
	return n;
}

template <typename T>
void Queue<T>::printQueue () {
	Node* ptr = head;
	if (ptr == nullptr) {
		std::cout << "head is empty while printing" << std::endl;
		return;
	}
	std::cout << "Current queue is: " << std::endl;
	while (ptr != nullptr) {
		std::cout << ptr->data << std::endl;
		ptr = ptr->next;
	}
}

template <typename T>
void Queue<T>::enqueue (T item) {
	//Node* n = makeNode (item);
	Node* n = new Node{ item, nullptr };
	if (n == nullptr) {
		std::cout << "Unsuccessful to make node n" << std::endl;
		return;
	}
	

	if (tail == nullptr) {
		head = tail = n;
	} else {
		tail->next = n;
		tail = n;
	}
	std::cout << "Successfully enqueue node" << n->data << std::endl;
}

template <typename T>
T Queue<T>::dequeue () {
	if (head == nullptr) {
		std::cout << "head is empty while dequeue" << std::endl;
		return 0;
	}
	T result = head->data;
	Node* temp = head;
	head = head->next;
	delete(temp);
	std::cout << "Successfully dequeue node" << result << std::endl;
	return result;
}

template <typename T>
bool Queue<T>::contains (T item) {
	Node* ptr = head;
	while (ptr != nullptr) {
		if (ptr->data == item) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}