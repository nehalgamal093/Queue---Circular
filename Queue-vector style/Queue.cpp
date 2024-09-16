#include "Queue.h"

template <class T>
Queue<T>::Queue() {
	size = 0;
	capacity = 1;
	arr = new T[capacity];
	start = end = -1;
};
template <class T>
void Queue<T>::expand() {
	capacity *= 2;
	T* tmp = new T[capacity];
	int j = 0;
	int i = start;
	for (; i != end; i = (i + 1) % size, j++) {
		tmp[j] = arr[i];
	}
	tmp[j] = arr[i];
	delete[]arr;
	arr = tmp;
	start = 0;
	end = size - 1;
}

template <class T>
void Queue<T>::push(T element) {
	if (size == capacity) {
	expand();
	}
	if (start == -1) {
		start = 0;
	}
	end = (end + 1)%capacity;
	arr[end] = element;
	size++;
};


template <class T>
void Queue<T>::pop() {
	if (size == 0) {
		return;
	}
	if (size == 1) {
		start = end - 1;
		size--;
		return;
	}
	start = (start + 1) % capacity;
	size--;
};

template <class T>
T Queue<T>::front() {
	return arr[start];
};

template <class T>
T Queue<T>::back() {
	return arr[end];
}

template <class T>
int Queue<T>::getSize() {
	return size;
};

template <class T>
bool Queue<T>::empty() {
	return (size == 0);
};

template <class T>
Queue<T>::~Queue() {
	while (size > 0) {
		pop();
	}
};