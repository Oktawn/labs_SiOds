#pragma once

#include "all.h"

template <class T>
struct knot_queue
{
	T valin;
	knot_queue <T>* next;
	knot_queue <T>* prev;
};

template <class T>
struct Queue
{
private:

	knot_queue<T>* begin;
	knot_queue<T>* end;
	int countt;

	bool isEmply_Queue(int count);

public:

	Queue();
	~Queue();

	void enqueue(T _valin);
	void peekHead();
	void peekTail();
	void outlist_queue();

	T dequeue();
	int lenght();
	void clear();
	void clear_queue();

};


template<class T>
inline bool Queue<T>::isEmply_Queue(int count)
{
	return (count == NULL);
}

template <class T>
Queue<T>::Queue()
{
	begin = end = nullptr;
	countt = 0;
}

template <class T>
Queue<T>::~Queue()
{
	clear();
}




template<class T>
inline void Queue<T>::enqueue(T _valin)
{
	knot_queue<T>* knott = new knot_queue<T>;
	knott->valin = _valin;
	knott->prev = nullptr;
	knott->next = begin;
	if (!isEmply_Queue(countt))
	{
		begin->prev = knott;
		begin = knott;
	}
	else begin = end = knott;
	countt++;
}

template <class T>
inline void Queue<T>::peekHead()
{
	if (isEmply_Queue(countt))
	{
		cout << " Queue empty\n";
		return;
	}
	knot_queue<T>* knot_queueting = begin;
	cout << knot_queueting->valin << endl;
}

template <class T>
inline void Queue<T>::peekTail()
{
	if (isEmply_Queue(countt))
	{
		cout << " Queue empty\n";
		return;
	}
	knot_queue<T>* knot_queueting = end;
	cout << knot_queueting->valin << endl;
}

template<class T>
inline void Queue<T>::outlist_queue()
{
	knot_queue<T>* knott = begin;
	for (int i = 0; i < countt; i++)
	{
		cout << knott->valin << " ";
		knott = knott->next;
	}
	cout << "\n";
}

template <class T>
inline T Queue<T>::dequeue()
{
	if (isEmply_Queue(countt)) return 0;
	knot_queue<T>* delknot_queue = end;
	T _valin = delknot_queue->valin;
	end = delknot_queue->prev;
	delete delknot_queue;
	countt--;
	return _valin;
}

template<class T>
inline int Queue<T>::lenght()
{
	return countt;;
}

template <class T>
inline void Queue<T>::clear()
{
	int temp = countt;
	while (temp--)
	{
		dequeue();
	}
}

template<class T>
inline void Queue<T>::clear_queue()
{
	countt = 0;
}

