#pragma once
template<class T>

class Queue
{
	int size;
	int capacity;
	T* arr;
	int start;
	int end;
	void expand();
public:
	Queue();
	void push(T element);
	void pop();
	T front();
	T back();
	int getSize();
	bool empty();
	~Queue();
};
template class Queue<int>;