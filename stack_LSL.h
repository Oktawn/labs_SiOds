#pragma once

#include "all.h"

template <typename T>
struct knot
{
	T val;
	knot<T>* next;
};

template <typename T>
class STACK_knot
{
private:

	knot <T>* top;

public:
	STACK_knot();
	~STACK_knot();


	bool IsEmpty_list();

	void push(T valie);
	void outlist();
	void clear();

	T pop();
	int size_knot();


};

template<typename T>
inline bool STACK_knot<T>::IsEmpty_list()
{
	return top == NULL;
}


template<typename T>
inline STACK_knot<T>::STACK_knot()
{
	top = NULL;
}

template<typename T>
inline STACK_knot<T>::~STACK_knot()
{
	clear();
}

template <typename T>
inline void STACK_knot<T>::push(T valie)
{
	knot<T>* knotting = new knot<T>;
	knotting->val = valie;
	knotting->next = top;
	top = knotting;
}

template <typename T>
inline T STACK_knot<T>::pop()
{
	if (IsEmpty_list()) return 0;
	knot<T>* del_knot = top;
	T val = top->val;
	top = top->next;
	delete del_knot;
	return val;
}

template <typename T>
inline void STACK_knot<T>::outlist()
{
	if (IsEmpty_list()) cout << "stack is empty\n";
	knot<T>* knott = top;
	while (knott)
	{
		cout << knott->val << " ";
		knott = knott->next;
	}
	cout << "\n";
}

template <typename T>
inline int STACK_knot<T>::size_knot()
{
	if (IsEmpty_list()) return 0;
	int count = 0;
	knot<T>* knott = top;
	while (knott)
	{
		count++;
		knott = knott->next;
	}
	return count;
}

template <typename T>
inline void STACK_knot<T>::clear()
{
	knot<T>* knott = top;
	knot<T>* delknot;
	while (knott)
	{
		delknot = knott;
		knott = knott->next;
		delete delknot;
	}
	top = NULL;
}