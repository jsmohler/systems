#include <iostream>

#ifndef MyArray_hpp
#define MyArray_hpp

template <typename T>
class MyArray {
public:
	MyArray(int size);
	~MyArray();
	MyArray(MyArray &);
	MyArray& operator=(const MyArray &);
	T get(int);
	void set(int, T);
	int size();
	void resize(int);
	void PushBack(T value);
	T Back();
	void PopBack();
private:
	int arrSize;
	int numElements;
	T* arr;
};


template <typename T>
MyArray<T>::MyArray(int size = 0) {
	arr = new T[size];
	arrSize = size;
	numElements = 0;
}

template <typename T>
MyArray<T>::~MyArray() {
	delete[] arr;
	arr = NULL;
	arrSize = 0;
	numElements = 0;
}

template <typename T>
MyArray<T>::MyArray(MyArray &source) {
	arr = new T[source.arrSize];
	for (int i = 0; i < source.numElements; i++) {
		arr[i] = source.arr[i];
	}
	arrSize = source.arrSize;
	numElements = source.numElements;
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray& b) {
	if (&b == this) return *this;
	delete[] arr;
	T* temp = new T[b.arrSize];
	for (int i = 0; i < b.numElements; i++) {
		temp[i] = b.arr[i];
	}
	arr = temp;
	arrSize = b.arrSize;
	numElements = b.numElements;
	return *this;
}

template <typename T>
T MyArray<T>::get(int index) {
	return arr[index];
}

template <typename T>
void MyArray<T>::set(int index, T value) {
	arr[index] = value;
}

template <typename T>
int MyArray<T>::size() {
	return numElements;
}

template <typename T>
void MyArray<T>::resize(int newSize) {
	T *temp = new T[newSize];
	if (newSize > arrSize) {
		for (int i = 0; i < arrSize; i++) {
			temp[i] = arr[i];
		}
	}
	else {
		numElements = 0;
	}
	delete[] arr;
	arrSize = newSize;
	arr = temp;
}

template <typename T>
void MyArray<T>::PushBack(T value) {
	if (numElements == arrSize) {
		resize(arrSize * 2);
	}
	arr[numElements] = value;
	numElements++;
}

template <typename T>
T MyArray<T>::Back() {
	return arr[numElements - 1];
}

template <typename T>
void MyArray<T>::PopBack() {
	arr[numElements - 1] = NULL;
	numElements--;
}

#endif
