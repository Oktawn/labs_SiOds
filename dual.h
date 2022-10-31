#pragma once
#include <iostream>
using namespace std;


template <class T>
struct knot
{
	T numb;
	knot<T>* next;
	knot<T>* prev;
};

template <class T>
struct listing
{
	private:

		knot<T>* begin;
		knot<T>* end;
		int count;

		knot<T>* findPosHead(int inx);
		knot<T>* findPosTail(int inx);
		knot<T>* findDataHead(T _num);
		knot<T>* findDataTail(T _num);

		bool CorInx(int inx);
		bool isEmply(int count);

	public:

		listing();
		~listing();


		void AddHead(T _num);
		void AddTail(T _num);
		void Insert(T _num, int inx);
		void Remove(int inx);
		void RemoveHead();
		void RemoveTail();

		void OutListHead();
		void OutListTail();

		void RemoveAll();

		T Retrieve(T _num);

		void disjunct(listing<T>* list, listing<T>* list2);

		listing<T>& operator+(const listing<T>& obj);

};


template <class T>
knot <T>* listing<T>::findPosHead(int inx)
{
	if (!CorInx(inx)) return NULL;
	knot<T>* curr = begin;
	for (int i = 0; i < inx; i++)
		curr = curr->next;
	return curr;
}

template<class T>
inline knot<T>* listing<T>::findPosTail(int inx)
{
	if (!CorInx(inx)) return NULL;
	knot<T>* curr = end;
	for (int i = (count - 1); i > inx; i--)
		curr = curr->prev;
	return curr;
}

template<class T>
inline knot<T>* listing<T>::findDataHead(T _num)
{
	knot<T>* curr = begin;
	for (int i = 0; i < count; i++)
	{
		if (curr->numb == _num) return curr;
		curr = curr->next;
	}
	return curr;
}

template<class T>
inline knot<T>* listing<T>::findDataTail(T _num)
{
	knot<T>* curr = end;
	for (int i = (count - 1); i > 0; i--)
	{
		if (curr->numb == _num) return curr;
		curr = curr->prev;
	}
	return curr;
}

template<class T>
inline bool listing<T>::CorInx(int inx)
{
	return (inx >= 0) && (inx < count);
}

template<class T>
inline bool listing<T>::isEmply(int count)
{
	return (count==NULL);
}

template <class T>
listing<T> ::listing()
{
	begin = end = nullptr;
	count = 0;
}

template <class T>
listing<T> ::~listing()
{
	RemoveAll();
}

template<class T>
inline void listing<T>::AddHead(T _num)
{
	knot<T>* knoting = new knot<T>;
	knoting->numb = _num;
	knoting->prev = nullptr;
	knoting->next = begin;
	if (count > 0)
	{
		begin->prev = knoting;
		begin = knoting;
	}
	else begin = end = knoting;
	count++;
}

template<class T>
inline void listing<T>::AddTail(T _num)
{
	knot<T>* knoting = new knot<T>;
	knoting->next = nullptr;
	knoting->prev = end;
	knoting->numb = _num;

	if (end != nullptr)
		end->next = knoting;
	if (count == 0)
	{
		begin = end = knoting;
	}
	else end = knoting;

	count++;
}

template<class T>
inline void listing<T>::Insert(T _num, int inx)
{
	if (!CorInx(inx)) return;
	if (inx == count) 
	{
		AddTail(_num);
		return;
	}
	if (inx == 0)
	{
		AddHead(_num);
		return;
	}
	else
	{
		knot<T>* knoting_prev = findPosHead(inx-1);
		knot<T>* knoting_now = findPosHead(inx);
		knot<T>* knoting = new knot<T>;
		knoting->numb = _num;
		knoting->prev = knoting_prev;
		knoting->next = knoting_now;
		knoting_prev->next = knoting;
		knoting_now->prev = knoting;
		count++;

	}
}

template<class T>
inline void listing<T>::Remove(int inx)
{
	if (isEmply(count) || !CorInx(inx)) return;
	knot<T>* delknoting = findPosHead(inx);
	knot<T>* delknoting_prev = delknoting->prev;
	knot<T>* delknoting_next = delknoting->next;
	if ((count > 1) && (delknoting_prev != nullptr))
	{
		delknoting_prev->next = delknoting_next;
	}
	if ((delknoting_next != nullptr) && (count > 1))
	{
		delknoting_next->prev = delknoting_prev;
	}
	if (inx == 0) { RemoveHead(); return; }
	if (inx == count-1) { RemoveTail(); return; }
	delete delknoting;
	count--;
}

template<class T>
inline void listing<T>::RemoveHead()
{
	if (isEmply(count)) return;
	knot<T>* delknotting = begin;
	begin = delknotting->next;
	delete delknotting;
	count--;

}

template<class T>
inline void listing<T>::RemoveTail()
{
	if (isEmply(count)) return;
	knot<T>* delknotting = end;
	end = delknotting->prev;
	delete delknotting;
	count--;
}

template<class T>
inline void listing<T>::OutListHead()
{
	knot<T>* knotting = begin;
	for (int i = 0; i < count; i++)
	{
		cout << knotting->numb << " ";
		knotting= knotting->next;
	}
	cout << "\n";
}

template<class T>
inline void listing<T>::OutListTail()
{
	knot<T>* knotting = end;
	for (int i = count; i > 0; i--)
	{
		cout << knotting->numb << " ";
		knotting = knotting->prev;
	}
	cout << "\n";
}

template<class T>
inline void listing<T>::RemoveAll()
{
	int temp = count;
	for (int i = 0; i < temp; i++)
	{
		RemoveHead();
	}
}

template<class T>
inline T listing<T>::Retrieve(T _num)
{
	knot<T>* knotting = findDataTail(_num);
	if (knotting== NULL) return 0;
	return T(knotting->numb);
}

template<class T>
inline void listing<T>::disjunct(listing<T>* list, listing<T>* list2)
{
	knot<T>* knot1 = list->begin;
	knot<T>* knot2 = list2->begin;
	knot<T>* knotq = new knot<T>;
	T val;
	while (knot1!=NULL || knot2!=NULL)
	{
		val = knot1->numb + knot2->numb;
		AddTail(val);
		knot1 = knot1->next;
		knot2 = knot2->next;
	}
}

template<class T>
inline listing<T>& listing<T>::operator+(const listing<T>& obj)
{
	// TODO: вставьте здесь оператор return
	knot<T>* knotting = obj.begin;
	while (knotting)
	{
		AddTail(knotting->numb);
		knotting= knotting->next;
	}
	return *this;
}

