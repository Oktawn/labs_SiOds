#include "Water.h"

bool pred_zero(int i)
{
	return i==0;
}
bool pred_zero(float i)
{
	return i == 0;
}

bool pred_pos(int i)
{
	return i>0;
}
bool pred_pos(float i)
{
	return i > 0;
}

bool pred_neg(int i)
{
	return i < 0;
}
bool pred_neg(float i) 
{
	return i < 0;
}

void enter(int *ar, int n)
{
	for (int i = 0; i < n; i++)
		cin >> ar[i];
}
void enter(float* ar, int n)
{
	for (int i = 0; i < n; i++)
		cin >> ar[i];
}

void show(int* ar, int n)
{
	cout << "Массив: ";
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
}
void show(float* ar, int n)
{
	cout << "Массив: ";
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
}

void create(int* ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		ar[i] = rand() % 150 + (-50);
	}
}
void create(float* ar, int n, float min, float max)
{
	for (int i = 0; i < n; i++)
	{
		ar[i] = (float)(rand()) / RAND_MAX * (max - min)+min;
	}
}

void add_el(int* ar, int n, int a, int b) 
{
	for (int i = n; i > a; i--)
		swap(ar[i - 1], ar[i]);
	ar[a] = b;
}
void add_el(float* ar, int n, int a, float b)
{
	for (int i = n; i > a; i--)
		swap(ar[i - 1], ar[i]);
	ar[a] = b;
}

void del_el(int* ar, int n, int a)
{
	for (int i = a; i < n - 1; i++) swap(ar[i], ar[i + 1]);
	ar[n - 1] = 0;
}
void del_el(float* ar, int n, int a, float b)
{
	for (int i = a; i < n - 1; i++) swap(ar[i], ar[i + 1]);
	ar[n - 1] = 0;
}

int sum_in_pos(int* ar, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) 
		if (pred_pos(ar[i])) sum++;
	return sum;
}
float sum_in_pos(float* ar, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (pred_pos(ar[i])) sum++;
	return sum;
}

int sum_in_nig(int* ar, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (pred_neg(ar[i])) sum++;
	return sum;
}
float sum_in_nig(float* ar, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (pred_neg(ar[i])) sum++;
	return sum;
}

int sum_in_zero(int* ar, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (pred_zero(ar[i])) sum++;
	return sum;
}
float sum_in_zero(float* ar, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (pred_zero(ar[i])) sum++;
	return sum;
}

int sum(int* ar, int n, int a, int b)
{
	int sum = 0;
	for (int i = a; i < b; i++) sum += ar[i];
	return sum;
}
float sum(float* ar, int n, int a, int b)
{
	float sum = 0;
	for (int i = a; i < b; i++) sum += ar[i];
	return sum;
}

int multi(int* ar, int n, int a, int b)
{
	 int mul = 1;
	 for (int i = a; i < b; i++) mul *= ar[i];
	 return mul;
}
int multi(float* ar, int n, int a, int b)
{
	float mul = 1.0;
	for (int i = a; i < b; i++) mul *= ar[i];
	return mul;
}

int sum_nigg(int* ar, int n, bool (*fun) (int))
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if ((*fun)(ar[i])) sum += ar[i];
	}
	return sum;
}
float sum_nigg(float* ar, int n, bool (*fun) (float))
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		if ((*fun)(ar[i])) sum += ar[i];
	}
	return sum;
}

int mult(int* ar,int n)
{
	int mul = 1,min=lin_search_min_in(ar,n), max=lin_search_max_in(ar,n);
	if (min > max) swap(min, max);
	for (int i = min; i <= max; i++)
	{
		mul *= ar[i];
	}
	return mul;
}
float mult(float* ar,int n)
{
	float mul = 1;
	int min = lin_search_min_in(ar, n), max = lin_search_max_in(ar, n);
	if (min > max) swap(min, max);
	for (int i = min; i <= max; i++)
	{
		mul *= ar[i];
	}
	return mul;
}

int lin_search_min_in(int* ar, int n)
{
	int inx=0; int min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		min = (min > ar[i]) ? ar[i] : min;
		inx = (min == ar[i]) ? i : inx;
	}
	return inx;
}
int lin_search_min_in(float* ar, int n)
{
	int inx = 0; float min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		min = (min > ar[i]) ? ar[i] : min;
		inx = (min == ar[i]) ? i : inx;
	}
	return inx;
}

int lin_search_max_in(int* ar, int n)
{
	int max = INT_MIN; int inx = 0;
	for (int i = 0; i < n; i++)
	{
		max = (max < ar[i]) ? ar[i] : max;
		inx = (max == ar[i]) ? i : inx;
	}
	return inx;
}
int lin_search_max_in(float* ar, int n)
{
	float max = INT_MIN; int inx = 0;
	for (int i = 0; i < n; i++)
	{
		max = (max < ar[i]) ? ar[i] : max;
		inx = (max == ar[i]) ? i : inx;
	}
	return inx;
}

int lin_search_min(int* ar, int n)
{
	int min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		min = (min > ar[i]) ? ar[i] : min;
	}
	return min;
}
float lin_search_min(float* ar, int n, float k)
{
	float min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		min = (min > ar[i]) ? ar[i] : min;
	}
	return min;
}

int lin_search_max(int* ar, int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		max = (max < ar[i]) ? ar[i] : max;
	}
	return max;
}
float lin_search_max(float* ar, int n)
{
	float max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		max = (max < ar[i]) ? ar[i] : max;
	}
	return max;
}

void bubble_sort(int* ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (ar[j] > ar[j + 1]) swap(ar[j], ar[j + 1]);
		}
	}

	//for (int i = 0; i < n; i++)
	//{
	//	cout << ar[i] << " ";
	//}
}
void bubble_sort(float* ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (ar[j] > ar[j + 1]) swap(ar[j], ar[j + 1]);
		}
	}

	//for (int i = 0; i < ar.size(); i++)
	//{
	//	cout << ar[i] << " ";
	//}
}

void simple_sort(int* ar, int n)
{
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			min = (ar[j] < min) ? j : min;
		}
		swap(ar[i], ar[min]);
	}

}
void simple_sort(float* ar, int n)
{
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			min = (ar[j] < min) ? j : min;
		}
		swap(ar[i], ar[min]);
	}
}

void inst_sort(int* ar, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && ar[j - 1] > ar[j]; j--)
		{
			swap(ar[j - 1], ar[j]);
		}
	}
}
void inst_sort(float* ar, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && ar[j - 1] > ar[j]; j--)
		{
			swap(ar[j - 1], ar[j]);
		}
	}
}

int bin_search(int* ar, int n, int k)
{
	int l = 0, h = n;

	while (l<=h) {
		int m = (l + h) / 2; 

		if (ar[m] == k) return m;
		if (ar[m] > k) h = m - 1;
		if (ar[m] < k) l = m + 1;		
	}
	return -1;
}

void file_cin(int* ar, int n)
{
	ofstream file("Array.txt");
	file << "Ваш массив с " << n << " элементами: ";
	file.close();
	file.open("Array.txt", ios_base::app);
	if (file.is_open()) {
		for (int i = 0; i < n; i++)
			file << ar[i] << " ";
	}
	else cout << "Ошибка! Не удаётся открыть файл для записи!";
	file.close();
}
void file_cin(float* ar, int n)
{
	ofstream file("Array.txt");
	file << "Ваш массив с " << n << " элементами: ";
	file.close();
	file.open("Array.txt", ios_base::app);
	if (file.is_open()) {
		for (int i = 0; i < n; i++)
			file << ar[i] << " ";
	}
	else cout << "Ошибка! Не удаётся открыть файл для записи!";
	file.close();
}

void binary_file_cin(int* ar, int n)
{
	char name[50] = "Array";
	ofstream file(name, ios_base::binary);
	file << "Ваш массив с " << n << " элементами: ";
	file.close();
	file.open(name, ios_base::app, ios_base::binary);
	if (file.is_open()) {
		for (int i = 0; i < n; i++)
			file << ar[i] << " ";
	}
	file.close();
}
void binary_file_cin(float* ar, int n)
{
	char name[50] = "Array";
	ofstream file(name, ios_base::binary);
	file << "Ваш массив с " << n << " элементами: ";
	file.close();
	file.open(name, ios_base::app, ios_base::binary);
	if (file.is_open()) {
		for (int i = 0; i < n; i++)
			file << ar[i] << " ";
	}
	file.close();
}

void file_cout()
{
	char* text = new char[1500];
	ifstream file("Array.txt");
	if (file.is_open()) {
		file.getline(text, 1500);
		cout << text << endl;
	}
	file.close();
}
void binary_file_cout()
{
	char name[50] = "Array";
	char* text = new char[1500];
	ifstream file(name, ios_base::binary);
	if (file.is_open()) {
		file.getline(text, 1500);
		cout << text << endl;
	}
	file.close();
}


