#pragma once

#include "all.h"

template <typename T>
class Deque
{
private:
	T* array;
	int head;
	int tail;
	int size;

public:
	Deque(int tails);
	~Deque();

	bool isFull_deque();
	bool isEmpty_deque();

	void pushHead(T val);
	void pushTail(T val);
	void print();
	void clear();

	T popHead();
	T popTail();
	T retrieveHead();
	T retrieveTail();

	int size_deque();
};

template <typename T>
inline Deque<T>::Deque(int tails)
{
	size = tails;
	tail = size - 1;
	array = new T[size];
	head = 0;
}

template <typename T>
inline Deque<T>::~Deque()
{
	if (tail > 0)
		delete[] array;
}

template <typename T>
inline bool Deque<T>::isFull_deque()
{
	return head == tail;
}

template <typename T>
inline bool Deque<T>::isEmpty_deque()
{
	return head == 0;
}

template<typename T>
inline void Deque<T>::pushHead(T val)
{
	if (!isFull_deque()) array[head] = val;
	head++;
}

template<typename T>
inline void Deque<T>::pushTail(T val)
{
	if (!isFull_deque()) array[tail] = val;
	tail--;
}

template <typename T>
inline void Deque<T>::clear()
{
	head = 0;
}

template <typename T>
inline void Deque<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

template <typename T>
inline T Deque<T>::popHead()
{
	if (!isFull_deque() && !isEmpty_deque())
	{
		head--;
		return array[head];
	}
	return 0;
}

template <typename T>
inline T Deque<T>::popTail()
{
	if (!isFull_deque() && (tail != (size - 1)))
	{
		tail++;
		return array[tail];
	}
	return array[head];
}

template <typename T>
inline T Deque<T>::retrieveHead()
{
	return array[head];
}

template <typename T>
inline T Deque<T>::retrieveTail()
{
	return array[tail];
}

template <typename T>
inline int Deque<T>::size_deque()
{
	return head;
}