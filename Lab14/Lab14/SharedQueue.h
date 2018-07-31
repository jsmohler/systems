#ifndef __Lab14__SharedQueue__
#define __Lab14__SharedQueue__

#include <mutex>

template <typename T>
class SharedQueue {
public:
  SharedQueue();
  ~SharedQueue();
  
    /*
     These declarations mean that we do NOT get the automatically
     defined copy/copy-assign functions.  If you try to call one
     by copying the queue, you'll get a compiler error.
     
     This is a common technique for things that are uncopyable (like std::thread and std::mutex, for example).
     
     We really DO want a destructor, so cheating at the
     rule of 3 here makes sense here.
     */
    SharedQueue(const SharedQueue<T>&) = delete;
    SharedQueue<T>& operator=(const SharedQueue<T>&) = delete;

    
  //Return true if the queue is empty
  bool IsEmpty() const;
  
  //Enqueue the next item at the tail of the queue.
  void Add(T value);
  
  //Dequeue the next queue element and store it in "item" variable.  The function returns false if the queue is empty and no item can be retrieved.
  bool Remove(T &item);
  void Print();

private:
  struct QueueItem {
	QueueItem(T i, QueueItem *n = nullptr) :item(i), next(n) {}
    T item;
    QueueItem *next;
  };

  //Helper Method
  void FreeList(QueueItem *);

  //Fill in the The private data members.
  QueueItem* head;
  QueueItem* tail;
  std::mutex lock;
};

//Fill in the function definitions
template <typename T>
SharedQueue<T>::SharedQueue() {
	head = nullptr;
	tail = nullptr;
}

template <typename T>
SharedQueue<T>::~SharedQueue() {
	lock.lock();
	FreeList(head);
	head = 0;
	lock.unlock();
}

template <typename T>
void SharedQueue<T>::FreeList(QueueItem *q){
	if (q == 0)
		return;
	FreeList(q->next);
	delete q;
}

//Return true if the queue is empty
template <typename T>
bool SharedQueue<T>::IsEmpty() const {
	if (head == nullptr) { return true; }
	return false;
}

//Enqueue the next item at the tail of the queue.
template <typename T>
void SharedQueue<T>::Add(T value) {
	lock.lock();
	//Create new item
	QueueItem* newItem = new QueueItem(value);

	if (head == nullptr) {
		head = newItem;
	}
	else {
		if (tail != nullptr) {
			QueueItem* last = tail;
			last->next = newItem;
		}
		tail = newItem;
	}
	lock.unlock();
}

//Dequeue the next queue element and store it in "item" variable.  The function returns false if the queue is empty and no item can be retrieved.
template <typename T>
bool SharedQueue<T>::Remove(T &item) {
	lock.lock();
	if (head == nullptr) {
		lock.unlock();
		return false;
	}
	T i = head->item;
	QueueItem *tmp = head;
	head = head->next;
	delete tmp;
	item = i;
	lock.unlock();
	return true;
}

template <typename T>
void SharedQueue<T>::Print() {
	lock.lock();
	for (QueueItem *n = head; n; n = n->next) {
		std::cout << n->item << " ";
	}
	std::cout << "\n";
	lock.unlock();
}

#endif
