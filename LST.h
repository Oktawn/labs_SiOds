#pragma once

#include <iostream>
#include <stdio.h>

using namespace std;

//template <class T>
//struct  knot
//{
//	T way;
//	struct knot* ways_next;
//	knot(T _way) : way(_way), ways_next(nullptr){}
//};
//
//template <class T>
//struct ray
//{
//	knot<T>* first;
//	knot<T>* end;
//	ray() : first(nullptr), end(nullptr) {}
//};
//

template <class T>
struct ray
{
	T pat;
	ray* next;
};


template <class T>
bool isEmpty(ray<T>* head);
template <class T>
bool insertPos(ray<T>* head,int pos,T value);

template <class T>
void showList(ray<T>* head);
template<class T>
void addAfter(ray<T>* pos, ray<T>* knot);

template <class T>
int size_Node(ray<T>* head);


template <class T>
ray<T>* addHead(ray<T>* head, T value);
template <class T>
ray<T>* addTail(ray<T>* head, T value);


template <class T>
ray<T>* removeHead(ray<T>* head);
template <class T>
void removeTail(ray<T>*& head);
template <class T>
void remove(ray<T>*& head, ray<T>* del);
template <class T>
void removeAll(ray<T>*& head);


template <class T>
ray<T>* findData(ray<T>* head, T value);
template <class T>
ray<T>* findPos(ray<T>* head, int pos);

template <class T>
T retrieve(ray<T>* head, int pos);


template <class T>
void disjunct(ray<T>* head, ray<T>* headS, ray<T>* &qual);



//struct ray
//{
//	int pat;
//	ray* next;
//};
//
//bool isEmpty(ray* head);
//
//void showList(ray* head);
//
//ray* addHead(ray* head, int value);