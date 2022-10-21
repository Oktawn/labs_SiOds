#include "KK.h"

template <typename  ET>
void add_x(ET** ar, int ar_y, int ar_x)
{
	for (int i = 0; i < ar_y; i++)
	{
		ar[i] = new ET[ar_x];
	}
}

template<class ET>
void create(ET** ar, int ar_y, int ar_x)
{
	for (int i=0; i<ar_y;i++)
		for (int j = 0; j < ar_x; j++)
		{
			ar[i][j] = (ET)rand() % (150 - 50)+50;
		}
}

template<class ET>
void create_1d(ET* ar, int ar_y, int ar_x)
{
	for(int i=0;i<ar_y*ar_x;i++) ar[i]= (ET)rand() % (150 - 50) + 50;
}

template<class ET>
void delee(ET** ar, int ar_y)
{
	for (int i = 0; i < ar_y; i++)
	{
		delete[] ar[i];
	}
	delete[]ar;
}

template <class  ET>
void enter(ET** ar, int ar_y, int ar_x)
{
	for (int i = 0; i < ar_y; i++)
		for (int j = 0; j < ar_x; j++)
			cin >> ar[i][j];
}

template <class  ET>
void show(ET** ar, int ar_y, int ar_x)
{
	for (int i = 0; i < ar_y; i++)
	{
		for (int j = 0; j < ar_x; j++)
			cout << ar[i][j] << " ";

		cout << endl;
	}
}

template<class ET>
void show_1d(ET* ar, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
}

template <class  ET>
ET *transformation_2d_in_1(ET ** ar, ET*&new_ar, int ar_y, int ar_x)
{
	int k = -1;
	for (int i = 0; i < ar_x; i++)
	{
		for (int j = 0; j < ar_y; j++)
		{
			k+=1;
			new_ar[k] = ar[i][j];
		}
	}

	return new_ar;
}

template <class  ET>
ET **transformation_1_in_2d(ET *ar, ET**&ar_new, int ar_y, int ar_x)
{
	for (int i = 0, k=0; i < ar_y; i++)
	{
		for (int j = 0; j < ar_x; j++)
		{
			ar_new[i][j] = ar[k++];
		}
	}
	return ar_new;
}

template<typename ET>
ET sum_rows(ET** ar, int rows,int ar_x)
{
	ET sum = 0;
	for (int i = 0; i < ar_x; i++)
		sum += ar[rows][i];

	return ET(sum);
}

template<typename ET>
ET sum_coloms(ET** ar, int ar_y, int coloms)
{
	ET sum = 0;
	for (int i = 0; i < ar_y; i++)
		sum += ar[i][coloms];

	return ET(sum);
}

template<typename ET>
ET sum_main_diag(ET** ar, int ar_y, int ar_x)
{
	ET sum = 0;
	for (int i = 0; i < ar_y; i++)
		sum += ar[i][i];

	return ET(sum);
}

template<typename ET>
ET sum_second_diag(ET** ar, int ar_y, int ar_x)
{
	ET sum = 0;
	for (int i = 0; i < ar_y; i++)
	{
			for (int j = 0; j < ar_x; j++)
			{
				sum = (i + j == ar_x - 1) ? sum += ar[i][j] : sum;
			}
	}
	return ET(sum);
}

template<typename ET>
string max_ind_ar(ET** ar, int ar_y, int ar_x)
{
	string ind = "fk";
	ET max = 0;
	for (int i = 0; i < ar_y; i++)
		for (int j = 0; j < ar_x; j++)
		{
			if (max < ar[i][j])
			{
				max = ar[i][j];
				ind = to_string(i) + " " + to_string(j);
			}

		}
	return ind;
}

template<typename ET>
string max_ind_rows(ET** ar, int rows, int ar_x)
{
	string ind = "fk";
	ET max = 0;
		for (int j = 0; j < ar_x; j++)
		{
			if (max < ar[rows][j])
			{
				max = ar[rows][j];
				ind = to_string(rows) + " " + to_string(j);
			}

		}
	return ind;
}

template<typename ET>
string max_ind_coloms(ET** ar, int ar_y, int coloms)
{
	string ind = "fk";
	ET max = 0;
	for (int j = 0; j < ar_y; j++)
	{
		if (max < ar[j][coloms])
		{
			max = ar[j][coloms];
			ind = to_string(j) + " " + to_string(coloms);
		}

	}
	return ind;
}

template<typename ET>
string max_ind_main_diag(ET** ar, int ar_y, int ar_x)
{
	string ind = "fk";
	ET max = INT_MIN;
	for (int i = 0; i < ar_y; i++)
		{
			if (max < ar[i][i])
			{
				max = ar[i][i];
				ind = to_string(i) + " " + to_string(i);
			}

		}
	return ind;
}

template<typename ET>
string max_ind_second_diag(ET** ar, int ar_y, int ar_x)
{
	string ind = "fk";
	ET max = INT_MIN;
	for (int i = 0; i <ar_y; i++)
	{
		for (int j = 0; j <ar_x; j++)
		{
			if ((i + j == ar_x - 1) &&(max < ar[i][j]))
			{
				max = ar[i][j];
				ind = to_string(i) + " " + to_string(j);
			}
		}
	}

	return ind;
}

template<typename ET>
string search_el_rows(ET** ar, int rows, int ar_x, ET search)
{
	for (int j = 0; j < ar_x; j++)
		if (ar[rows][j] == search) return to_string(rows) + " " + to_string(j);
	return "no el";
}

template<typename ET>
string search_el_coloms(ET** ar, int ar_y, int coloms, ET search)
{
	for (int j = 0; j < ar_y; j++)
		if (ar[j][coloms] == search) return to_string(j) + " " + to_string(coloms);
	return "no el";
}

template<typename ET>
string search_el_main_diag(ET** ar, int ar_y, int ar_x, ET search)
{
	for (int i = 0; i < ar_y; i++)
		{
			if (search == ar[i][i]) return to_string(i) + " " + to_string(i);
		}
	return "no el";
}

template<typename ET>
string search_el_secind_diag(ET** ar, int ar_y, int ar_x, ET search)
{
	for (int i = 0; i < ar_y; i++)
	{
		for (int j = 0; j < ar_x; j++)
		{
			if ((i + j == ar_x - 1) && (search == ar[i][j]))
			{
				return to_string(i) + " " + to_string(j);
			}
		}
	}

	return "no el";
}

template<typename ET>
string search_el_upper_triangle(ET** ar, int ar_y, int ar_x, ET search)
{
	for (int i=0;i<ar_y;i++)
		for (int j=0;j<ar_x;j++)
			if (search==ar[i][j]) return to_string(i) + " " + to_string(j);
	return "no el";
}

template<typename ET>
string search_el_lower_triangle(ET** ar, int ar_y, int ar_x, ET search)
{
	for (int i=0;i<ar_y;i++)
		for (int j=0;j<ar_x-i+1;j++)
			if (search == ar[i][j]) return to_string(i) + " " + to_string(j);
	return "no el";
}

template<typename ET>
int sum_search_el_rows(ET** ar, int rows, int ar_x, ET search)
{
	int sum = 0;
	for (int j = 0; j < ar_x; j++)
		if (search == ar[rows][j]) sum++;
	return sum;
}

template<typename ET>
int sum_search_el_coloms(ET** ar, int ar_y, int coloms, ET search)
{
	int sum = 0;
	for (int j = 0; j < ar_y; j++)
		if (search == ar[j][coloms]) sum++;
	return sum;
}

template<typename ET>
int sum_search_el_main_diag(ET** ar, int ar_y, int ar_x, ET search)
{
	int sum = 0;
	for (int i = 0; i < ar_y; i++)
		{
			if (search == ar[i][i]) sum++;

		}
	return sum;
}

template<typename ET>
int sum_search_el_secind_diag(ET** ar, int ar_y, int ar_x, ET search)
{
	int sum = 0;
	for (int i = 0; i < ar_y; i++)
	{
		for (int j = 0; j < ar_x; j++)
		{
			if ((i + j == ar_x - 1) && (search == ar[i][j]))
			{
				sum++;
			}
		}
	}
	return 0;
}

template<typename ET>
int sum_search_el_upper_triangle(ET** ar, int ar_y, int ar_x, ET search)
{
	int sum = 0;
	for (int i = 0; i < ar_y; i++)
		for (int j = i; j < ar_x; j++)
			if (search == ar[i][j]) sum++;
	return sum;
}

template<typename ET>
int sum_search_el_lower_triangle(ET** ar, int ar_y, int ar_x, ET search)
{
	int sum = 0;
	for (int i = 0; i < ar_y; i++)
		for (int j = 0; j <  i + 1; j++)
			if (search == ar[i][j]) sum++;
	return sum;
}

template<typename ET>
void del_rows(ET** ar, int &ar_y, int ar_x, int rows)
{
	for (int i = rows; i < ar_y-1; i++)
		for (int j = 0; j < ar_x; j++)
		{
			 ar[i][j] = ar[i + 1][j];
		}
ar_y-=1;
}

template<typename ET>
void del_coloms(ET** ar, int ar_y, int &ar_x, int coloms)
{
	for (int i = 0; i < ar_y; i++)
		for (int j = coloms; j < ar_x-1; j++)
			ar[i][j] = ar[i][j+1];
ar_x-=1;
}

template<typename ET>
ET** add_rows(ET** &ar, int &ar_y, int ar_x, int rows)
{
	ET** ar_1 = new ET * [ar_y + 1];
	add_x(ar_1, ar_y + 1, ar_x);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < ar_x; j++)
		{
			ar_1[i][j] = ar[i][j];
		}
	}
	for (int i = 0; i < ar_y - rows; i++)
	{
		for (int j = 0; j < ar_x; j++)
		{
			ar_1[i + rows + 1][j] = ar[i + rows][j];
		}
	}
	ar_y++;
	for (int i = rows; i < rows+ 1; i++)
	{
		for (int j = 0; j < ar_x; j++)
		{
			ar_1[i][j] = rand() % (150 - 50) + 50;
		}
	}
	delee(ar, ar_y - 1);
	ar = ar_1;
	return ar;


}

template<typename ET>
ET** add_coloms(ET** &ar, int ar_y, int& ar_x, int coloms)
{
	ET** ar_1 = new ET * [ar_y];
	add_x(ar_1, ar_y, ar_x+1);
	for (int i = 0; i < ar_y; i++)
	{
		for (int j = 0; j < coloms; j++)
		{
			ar_1[i][j] = ar[i][j];
		}		
	}
	for (int i = 0; i < ar_y; i++)
	{
		for (int j = 0; j < ar_x-coloms; j++)
		{
			ar_1[i ][j+ coloms + 1] = ar[i ][j+ coloms];
		}
	}
	ar_x++;
	for (int i = 0; i < ar_y; i++)
	{
		for (int j = coloms; j < coloms+1; j++)
		{
			ar_1[i][j] = rand() % (150 - 50) + 50;
		}
	}
	delee(ar, ar_y);
	ar = ar_1;
	return ar;
}

template<typename ET>
void sort_rows(ET** ar, int ar_y, int ar_x, int rows)
{
	for (int i = 1; i < ar_x; i++)
		for (int j = i; j > 0 && ar[rows][j - 1] > ar[rows][j]; j--)
			swap(ar[rows][j - 1], ar[rows][j]);
}

template<typename ET>
void sort_coloms(ET** ar, int ar_y, int ar_x, int coloms)
{
	for (int i = 1; i < ar_y; i++)
		for (int j = i; j > 0 && ar[j-1][coloms] > ar[j][coloms]; j--)
			swap(ar[j-1][coloms], ar[j][coloms]);
}

template<typename ET>
void sort_all_ar(ET** ar, int ar_y, int ar_x)
{
	for (int k = 0; k < ar_y * ar_x; k++)
	{
		for (int i = 0; i < ar_y; i++)
		{
			for (int j = 0; j < ar_x - 1; j++)
			{
				if (ar[i][j] > ar[i][j + 1]) swap(ar[i][j], ar[i][j + 1]);
			}
		}
		for (int i = 0; i < ar_x; i++)
		{
			for (int j = 0; j < ar_y - 1; j++)
			{
				if (ar[j][i] > ar[j + 1][i]) swap(ar[j][i], ar[j + 1][i]);
			}
		}

	}
}

template<typename ET>
void mult_ar_vec(ET** ar, ET* vec, ET* res, int ar_y, int ar_x)
{
	for (int i = 0; i < ar_y; i++)
	{
		ET temple = 0;
		for (int j = 0; j < ar_x; j++)
		{
			temple += ar[i][j] * vec[j];
		}
		res[i] = temple;
	}

}

template<typename ET>
void mult_ar_ar(ET** ar, ET** ar_mul, ET** &res, int ar_y, int ar_x)
{

	for (int i = 0; i < ar_y; i++)
	{
		for (int j = 0; j < ar_x; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < ar_x; k++)
			{
				res[i][j] += ar[i][k] * ar_mul[k][j];

			}
		}
	}


}

template<typename ET>
void mult_ar_number(ET** ar, ET num, ET**& res, int ar_y, int ar_x)
{
	for (int i = 0; i < ar_y; i++)
	{
		for (int j = 0; j < ar_x; j++)
		{
			res[i][j] = 0;
			res[i][j] = ar[i][j] * num;
			
		}
	}
}

template<typename ET>
void devide_ar_number(ET** ar, ET num, ET**& res, int ar_y, int ar_x)
{
	for (int i = 0; i < ar_y; i++)
	{
		for (int j = 0; j < ar_x; j++)
		{
			res[i][j] = 0;
			res[i][j] = ar[i][j] / num;

		}
	}
}

template<typename ET>
ET** tran_matrix(ET** &ar, int &ar_y, int &ar_x)
{
	ET** ar_new = new ET * [ar_y];
	add_x(ar_new, ar_y, ar_x);
	for (int i = 0; i < ar_x; i++)
	{
		for (int j = 0; j < ar_y; j++)
		{
			ar_new[j][i] = ar[i][j];
		}
	}
	delete[] ar;
	ar = ar_new;
	return ar;
}

template<typename ET>
int sum_nozero_rows(ET** ar, int ar_y, int ar_x)
{
	int sum = 0;
	for (int i = 0; i < ar_y; i++)
	{
		bool flag = true;
		for (int j = 0; j < ar_x; j++)
		{
			flag = (ar[i][j] == 0) ? flag = false : flag;
		}
		sum = (flag == true) ? sum++ : sum;
	}
	return sum;
}

template<typename ET>
ET max_number_arr(ET** ar, int ar_y, int ar_x)
{
	int ed = 0;
	for (int i = 0; i < ar_y; i++) 
	{
		for (int j = 0; j < ar_x; j++) 
		{
			if (ar[i][j] > ed) 
			{
				for (int k = 0; k < ar_x; k++) 
				{
					if (j == k) continue;

					if (ar[i][j] == ar[i][k])
					{
						ed = ar[i][j];
						break;
					}
				};
			}
		};
	};

	/*ET ed = INT_MIN;
	int kl;
	bool flag = false;
	
	do 
	{
		for (int i = 0; i < ar_y; i++)
		{	
			for (int j = 0; j < ar_x; j++)
			{
				ed = (ed < ar[i][j]) ? ar[i][j] : ed;
			}
		}
		kl = 0;
		for (int i = 0; i < ar_y; i++)
		{
			for (int j = 0; j < ar_x; j++)
			{
				if (ar[i][j] == ed) kl++;
			}
		}
		if (kl > 1) flag = true;
		else 
			for (int i = 0; i < ar_y; i++)
			{
				for (int j = 0; j < ar_x; j++)
				{
					if (ar[i][j] == ed)
						ar[i][j] = INT_MIN;
				}
			}

	} while (!flag);*/

	return ET(ed);
}

