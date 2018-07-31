#include <iostream>
#include "LinkedList.h"

//constructor
LinkedList::LinkedList() {
	ptr = NULL;
}

LinkedList::~LinkedList() {
	delete ptr;
	ptr = nullptr;
}

void LinkedList::InsertAtHead(int v) {
	Node* n = new Node(v, ptr);
	ptr = n;
};

void LinkedList::PrintList() {
	Node* n = ptr;
	while (n != NULL) {
		n->PrintNode();
		n = n->GetNext();
	}
	std::cout << "\n";
};

void LinkedList::freeList() {
	Node* n = ptr;
	Node* set;
	while (n != NULL) {
		set = n->GetNext();
		delete ptr;
		n = set;
	}
	ptr = nullptr;
};