#pragma once

#include <iostream>

using namespace std;

template <class T>
struct Heap
{
private:
	int size_max=10;
	T* array;
	int size;

public:
	Heap();

	void buildHeap();
	void pushHead(T val);
	popHeap();
	void heapify();
	peekHeap();
	sortHeap();
};

template<class T>
inline Heap<T>::Heap()
{
	array = new T[size_max];
	size = 0;
}

template<class T>
inline void Heap<T>::buildHeap()
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{

	}
}

template<class T>
inline void Heap<T>::pushHead(T val)
{
	int cur = array[ind];
}
