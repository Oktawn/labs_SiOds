#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Stydent
{
	string FIO;
	int mark[5];
	string obj[5] = { "russian", "math", "physics","programming", "literate"};
	float avgball=0;
};

void addSt(Stydent st[], int size);

void showST(Stydent st[], int size);

void search_student(Stydent st[], int size, string men);

void search_maxMark_student(Stydent st[], int size, string search);

void bubble_sort_student_avgball(Stydent st[], int size);

void bubble_sort_student_leks(Stydent st[], int size);

void binary_file_cin(Stydent st[], int size);

void binary_file_cout(Stydent st[], int size);