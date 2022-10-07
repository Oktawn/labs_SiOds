#include "student.h"

void addSt(Stydent st[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nFIO: ";cin>>st[i].FIO;

		cout << "\nBall\n";

		for (int j = 0; j < 5; j++)
		{
			cout << j+1 << " stydu:"; cin >> st[i].mark[j];
			cout << endl;
			st[i].avgball += st[i].mark[j];
		}
		st[i].avgball /= 5;
	}
}

void showST(Stydent st[], int size)
{
	cout << endl << "List Studens";
	for (int i = 0; i < size; i++)
	{
		cout << endl << st[i].FIO<<" ";
		for (int j = 0; j < 5; j++)
		{
			cout << " " << j+1 << " mark: " << st[i].mark[j];
		}
		cout << " avgmark: " << st[i].avgball;
	}
}

void search_student(Stydent st[], int size, string men)
{
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (st[i].FIO == men)
		{

			cout << endl << st[i].FIO << " ";
			for (int j = 0; j < 5; j++)
			{
				cout << " " << j << " mark: " << st[i].mark[j];
			}
			cout << " avgmark: " << st[i].avgball;
			flag = true;
			break;
		}
	}
	if (flag == false) cout << " there is no such student\n";
}

void search_maxMark_student(Stydent st[], int size, string search)
{
	int idx = 0,max_mark=INT_MIN,idx_max=0;
	for (int i = 0; i < 5; i++)
	{
		if (st[0].obj[i] == search) {idx = i; break;}
	}

	for (int i = 0; i < size; i++)
	{
		if (max_mark > st[i].mark[idx])
		{
			max_mark = st[i].mark[idx];
			idx_max = i;
		}
	}
	cout<<"max mark on "<< search <<" have "<< st[idx_max].FIO;
}

void bubble_sort_student_avgball(Stydent st[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (st[i].avgball > st[j].avgball)
				swap(st[i], st[j]);
		}
	}
}

void bubble_sort_student_leks(Stydent st[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(st[i].FIO.c_str(), st[j].FIO.c_str()))
				swap(st[i].FIO, st[j].FIO);
		}
	}
}

void binary_file_cin(Stydent st[], int size)
{
	char name[50] = "student list";
	ofstream file;
	file.open(name, ios_base::binary);
	file.write((char*)&st,sizeof(Stydent));
	file.close();
}

void binary_file_cout(Stydent st[], int size)
{
	char name[50] = "student list";

	ifstream file;
	Stydent tmp;
	file.open(name, ios_base::binary);
	while (file.read((char*)&st, sizeof(Stydent)))
	{
		
	}
	file.close();
}



void add_path(Marsh tr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nnumber marsh: "; cin >> tr[i].numer;
		cout << "\nstarting point: "; cin >> tr[i].begst;
		cout << "\nending point: "; cin >> tr[i].term;
	}
}

void showTR(Marsh tr[], int size)
{
	cout << endl << "List trafic";
	for (int i = 0; i < size; i++)
	{
		cout << "\nnumber marsh: " << tr[i].numer;
		cout << "\nstarting point: " << tr[i].begst;
		cout << "\nending point: " << tr[i].term;
	}
}

void show_one_TR(Marsh tr[], int position)
{
	cout << "\nnumber marsh: " << tr[position].numer;
	cout << "\nstarting point: " << tr[position].begst;
	cout << "\nending point: " << tr[position].term;

}

void search_starting_path(Marsh tr[], int size, string start)
{
	cout << endl;
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (tr[i].begst == start) { show_one_TR(tr, i); flag = true; }
	}
	if (flag == false) cout << " there is no such starting point\n";
}

void search_enging_path(Marsh tr[], int size, string end)
{
	cout << endl;
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (tr[i].term == end) { show_one_TR(tr, i); flag = true; }
	}
	if (flag == false) cout << " there is no such ending point\n";
}

void search_number_path(Marsh tr[], int size, int number)
{
	cout << endl;
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (tr[i].numer == number) { show_one_TR(tr, i); flag = true; }
	}
	if (flag == false) cout << " there is no such path\n";
}