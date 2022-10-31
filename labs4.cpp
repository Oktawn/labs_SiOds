#include "dual.h"

int main()
{
	listing <int> list1;
	listing <int> list2;
	listing <int> listq;
	list1.AddTail(5);
	list1.AddTail(8);
	list1.AddTail(2);
	list1.AddTail(4);
	list1.OutListHead();
	
	//cout << "search:" << list1.Retrieve(5) << " ";

	list2.AddTail(11);
	list2.AddTail(12);
	list2.AddTail(9);
	list2.AddTail(1);
	list2.OutListHead();

	listq.disjunct(&list1, &list2);

	listq.OutListHead();

	list1.RemoveAll();
	list2.RemoveAll();
	listq.RemoveAll();
	//list2.RemoveAll();
	//listq.RemoveAll();
	return 0;
}

