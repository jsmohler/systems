
#ifndef LinkedList_h
#define LinkedList_h

template <typename T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	bool isEmpty();
	void InsertAtHead(T item);
	T PeekHead();
	T RemoveHead();
	void Print();
private:
	struct Node { T item; Node* next; };
	Node* head;
};

//constructor
template <typename T>
LinkedList<T>::LinkedList() {
	head = NULL;
};

template <typename T>
LinkedList<T>::~LinkedList() {
	Node* n = head;
	Node* set;
	while (n != NULL) {
		set = n->next;
		delete n;
		n = set;
	}
	head = nullptr;
};

template <typename T>
bool LinkedList<T>::isEmpty() {
	if (head == NULL) {
		return true;
	}
	return false;
}

template <typename T>
void LinkedList<T>::InsertAtHead(T item) {
	Node* n = new Node{ item, head };
	head = n;
};

template <typename T>
T LinkedList<T>::PeekHead() {
	Node n = *head;
	return n.item;
};

template <typename T>
T LinkedList<T>::RemoveHead() {
	if (!isEmpty()) {
		Node* n = head->next;
		T i = head->item;
		delete head;
		head = n;
		return i;
	}
};

template <typename T>
void LinkedList<T>::Print() {
	Node* n = head;
	while (n != NULL) {
		std::cout << n->item;
		n = n->next;
	}
	std::cout << "\n";
};

#endif
