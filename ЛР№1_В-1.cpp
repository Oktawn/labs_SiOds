#include "Water.h"


int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int n;
	cout << "size array: "; cin >> n;
	int* ar = new int[n];
	
	create(ar, n);
	show(ar, n);


	//cout << "\nniggative sum : "<< sum_nigg(ar, n);
	//printf("\nmultiplication in range %d of %d  = %d\n",lin_search_min(ar,n),lin_search_max(ar,n), mult(ar,n));

	//cout << endl;

	//cout << "sort_bubble\n"; bubble_sort(ar, n);show(ar, n);

	system("pause");
	return 0;
}