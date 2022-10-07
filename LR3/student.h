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
struct Marsh
{
	string begst;
	string term;
	short int numer;
};

void addSt(Stydent st[], int size);
void add_path(Marsh tr[], int size);

void showST(Stydent st[], int size);
void showTR(Marsh tr[], int size);
void show_one_TR(Marsh tr[], int position);

void search_student(Stydent st[], int size, string men);
void search_maxMark_student(Stydent st[], int size, string search);

void search_starting_path(Marsh tr[], int size, string start);
void search_enging_path(Marsh tr[], int size, string end);
void search_number_path(Marsh tr[], int size, int number);

void bubble_sort_student_avgball(Stydent st[], int size);

void bubble_sort_student_leks(Stydent st[], int size);

void binary_file_cin(Stydent st[], int size);

void binary_file_cout(Stydent st[], int size);