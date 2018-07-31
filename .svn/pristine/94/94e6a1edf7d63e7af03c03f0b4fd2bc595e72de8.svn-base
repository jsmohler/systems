#include <iostream>
#include "LinkedList.h"

//constructor
template <typename T>
LinkedList::LinkedList() {
	head = NULL;
}

template <typename T>
LinkedList::~LinkedList() {
	Node* n = head;
	Node* set;
	while (n != NULL) {
		set = n.next;
		delete n;
		n = set;
	}
	head = nullptr;
}

template <typename T>
bool LinkedList::isEmpty() {
	if (head == NULL) {
		return true;
	}
	return false;
}

template <typename T>
void LinkedList::InsertAtHead(T item) {
	Node* n = new Node(item, head);
	head = n;
};

template <typename T>
T LinkedList::PeekHead() {
	return *head.item;
};

template <typename T>
T LinkedList::RemoveHead() {
	Node* n = *head.next;
	delete head;
	head = n;
};

template <typename T>
void LinkedList::Print() {
	Node* n = head;
	while (n != NULL) {
		std::cout << n.item;
		n = n.next;
	}
	std::cout << "\n";
};
