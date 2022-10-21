#include "LST.h"


template<class T>
bool isEmpty(ray<T>* head)
{
	return head == NULL;
}

template<class T>
bool insertPos(ray<T>* head, int pos, T value)
{
	if (pos == 1) return false;
	ray<T> knot_last = findPos(head, pos - 1);
	if (knot_last == NULL) return false;
	ray<T> knot = new ray<T>;
	knot->pat = value;
	knot->next = knot_last->next;
	knot_last->next = knot;
	return true;
}

template<class T>
void showList(ray<T>* head)
{
	ray<T> *knot = head;
	while (knot)
	{
		cout << knot->pat <<' ';
		knot = knot->next;
	}
	cout << "\n";
}

template<class T>
void addAfter(ray<T>* pos, ray<T>* knot)
{
	if (pos == NULL) return;
	knot->next = pos->next;
	pos->next = knot;
}

template<class T>
int size_Node(ray<T>* head)
{
	ray<T>* knot = head;
	int count = 0;
	while (knot)
	{
		count++;
		knot = knot->next;
	}
	return count;
}

template<class T>
ray<T>* addHead(ray<T>* head, T value)
{
	ray<T>* knot = new ray<T>;
	knot->next = head;
	knot->pat = value;
	head = knot;
	return head;
}

template<class T>
ray<T>* addTail(ray<T>* head, T value)
{
	if (isEmpty(head)) return addHead(head, value);
	ray<T>* knotPos = findPos(head, size_Node(head));
	ray<T>* knot = new ray<T>;
	knot->pat = value;
	addAfter(knotPos, knot);
	return head;
}


template<class T>
ray<T>* removeHead(ray<T>* head)
{
	if (head == NULL) return 0;
	ray<T>* knot = head;
	head = knot->next;
	delete knot;
	return head;
}

template<class T>
void removeTail(ray<T>*& head)
{
	ray<T>* knot = head;
	ray<T>* knotDel = findPos(head, size_Node(head));
	if (head == knotDel) head = removeHead(head);
	while (knot->next && knot->next != knotDel)
		knot = knot->next;
	if (knot->next)
	{
		knot->next = knot->next->next;
		delete knotDel;
	}
}

template<class T>
void remove(ray<T>*& head, ray<T>* del)
{
	if (head == del) head = removeHead(head);
	ray<T> *knot = head;
	while (knot->next && knot->next != del)
		knot = knot->next;
	if (knot->next)
	{
		knot->next = knot->next->next;
		delete del;
	}
}

template<class T>
void removeAll(ray<T>*& head)
{
	ray<T>* knot = head;
	ray<T>* knotDel;
	while (knot)
	{
		knotDel = knot;
		knot = knot->next;
		delete knotDel;
	}
	head = NULL;
}

template<class T>
ray<T>* findData(ray<T>* head, T value)
{
	ray<T>* knot = head;
	while (knot)
	{
		if (knot->pat == value) return knot;
	}
	return NULL;
}

template<class T>
ray<T>* findPos(ray<T>* head, int pos)
{
	ray<T> *knot= head;
	while (knot!=NULL && pos>1)
	{
		knot = knot->next;
		pos--;
	}
	return knot;
}

template<class T>
T retrieve(ray<T>* head, int pos)
{
	ray<T>* knot = findPos(head, pos);

	return T(knot->pat);
}

template<class T>
void disjunct(ray<T>* head, ray<T>* headS, ray<T>* &qual)
{
	ray<T>* knot = head;
	ray<T>* knotS = headS;
	ray<T>* knotQ = new ray<T>;
	T value;/*
	while (knot!=NULL || knotS!=NULL)
	{		
		value = ((knot->pat) + (knotS->pat));
		qual = addHead(qual, value);
		knot = knot->next;
		knotS = knotS->next;
		i++;
	}*/
	while (knot != NULL || knotS != NULL)
	{
		value = ((knot->pat) + (knotS->pat));
		qual = addTail(qual, value);
		knot = knot->next;
		knotS = knotS->next;
	}


}
