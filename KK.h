#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>

using namespace std;

template <class  ET>
void add_x(ET** ar, int ar_y, int ar_x);

template <class  ET>
void create(ET** ar, int ar_y, int ar_x);

template <class  ET>
void create_1d(ET* ar, int ar_y, int ar_x);

template<class ET>
void delee(ET** ar, int ar_y);

template <class  ET>
void enter(ET** ar, int ar_y, int ar_x);

template <class  ET>
void show(ET** ar, int ar_y, int ar_x);

template <class  ET>
void show_1d(ET* ar, int size);

template <class  ET>
ET* transformation_2d_in_1(ET** ar, ET*& new_ar, int ar_y, int ar_x);

template <class  ET>
ET **transformation_1_in_2d(ET* ar, ET**& ar_new, int ar_y, int ar_x);

template <typename ET>
ET sum_rows(ET** ar, int rows, int ar_x);

template <typename ET>
ET sum_coloms(ET** ar, int ar_y, int coloms);

template <typename ET>
ET sum_main_diag(ET** ar, int ar_y, int ar_x);

template <typename ET>
ET sum_second_diag(ET** ar, int ar_y, int ar_x);

template<typename ET>
string max_ind_ar(ET** ar, int ar_y, int ar_x);

template<typename ET>
string max_ind_rows(ET** ar, int rows, int ar_x);

template<typename ET>
string max_ind_coloms(ET** ar, int ar_y, int coloms);

template<typename ET>
string max_ind_main_diag(ET** ar, int ar_y, int ar_x);

template<typename ET>
string max_ind_second_diag(ET** ar, int ar_y, int ar_x);

template<typename ET>
string search_el_rows(ET** ar, int rows, int ar_x, ET search);

template<typename ET>
string search_el_coloms(ET** ar, int ar_y, int coloms, ET search);

template<typename ET>
string search_el_main_diag(ET** ar, int ar_y, int ar_x, ET search);

template<typename ET>
string search_el_secind_diag(ET** ar, int ar_y, int ar_x, ET search);

template<typename ET>
string search_el_upper_triangle(ET** ar, int ar_y, int ar_x, ET search);

template<typename ET>
string search_el_lower_triangle(ET** ar, int ar_y, int ar_x, ET search);

template<typename ET>
int sum_search_el_rows(ET** ar, int rows, int ar_x, ET search);

template<typename ET>
int sum_search_el_coloms(ET** ar, int ar_y, int coloms, ET search);

template<typename ET>
int sum_search_el_main_diag(ET** ar, int ar_y, int ar_x, ET search);

template<typename ET>
int sum_search_el_secind_diag(ET** ar, int ar_y, int ar_x, ET search);

template<typename ET>
int sum_search_el_upper_triangle(ET** ar, int ar_y, int ar_x, ET search);

template<typename ET>
int sum_search_el_lower_triangle(ET** ar, int ar_y, int ar_x, ET search);

template<typename ET>
void del_rows(ET** ar, int &ar_y, int ar_x, int rows);

template<typename ET>
void del_coloms(ET** ar, int ar_y, int &ar_x, int coloms);

template<typename ET>
ET** add_rows(ET**& ar, int& ar_y, int ar_x, int rows);

template<typename ET>
ET** add_coloms(ET**& ar, int ar_y, int& ar_x, int coloms);

template<typename ET>
void sort_rows(ET** ar, int ar_y, int ar_x, int rows);

template<typename ET>
void sort_coloms(ET** ar, int ar_y, int ar_x, int coloms);

template<typename ET>
void sort_all_ar(ET** ar, int ar_y, int ar_x);

template<typename ET>
void mult_ar_vec(ET** ar, ET*vec,ET*res, int ar_y, int ar_x);

template<typename ET>
void mult_ar_ar(ET** ar, ET** ar_mul, ET** &res, int ar_y, int ar_x);

template<typename ET>
void mult_ar_number(ET** ar, ET num, ET**& res, int ar_y, int ar_x);

template<typename ET>
void devide_ar_number(ET** ar, ET num, ET**& res, int ar_y, int ar_x);

template<typename ET>
ET** tran_matrix(ET** &ar, int &ar_y, int &ar_x);

template<typename ET>
int sum_nozero_rows(ET** ar, int ar_y, int ar_x);

template<typename ET>
ET max_number_arr(ET** ar, int ar_y, int ar_x);