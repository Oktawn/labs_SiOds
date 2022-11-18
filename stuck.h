#pragma once

#include "all.h"

template <typename T>
class STACK
{
private:
	T* array;
	int count;

public:

	STACK();
	~STACK();


	bool IsEmpty();
	void push(T val);
	void outList();
	void clear();

	T pop();
	T retrieve();
	int size_stack();

};

template <typename T>
inline STACK<T>::STACK()
{
	count = 0;
}

template <typename T>
inline STACK<T>::~STACK()
{
	if (IsEmpty()) delete array;
}


template<typename T>
inline bool STACK<T>::IsEmpty()
{
	return count == 0;
}

template<typename T>
inline void STACK<T>::push(T val)
{
	T* temp;	temp = array;
	count++;
	array = new T[count];

	for (int i = 0; i < count - 1; i++)
		array[i] = temp[i];
	array[count - 1] = val;
	delete[] temp;

}

template<typename T>
inline void STACK<T>::outList()
{
	if (IsEmpty()) cout << "stack is empty\n";

	else
	{
		for (int i = 0; i < count; i++)
		{
			cout << array[i] << " ";

		}
		cout << "\n";
	}
}

template<typename T>
inline void STACK<T>::clear()
{
	while (count)
	{
		pop();
	}
}


template <typename T>
inline T STACK<T>::pop()
{
	if (IsEmpty()) return 0;
	count--;
	return array[count];
}

template<typename T>
inline T STACK<T>::retrieve()
{
	if (IsEmpty()) return 0;
	return array[count - 1];
}

template<typename T>
inline int STACK<T>::size_stack()
{
	return count;
}

