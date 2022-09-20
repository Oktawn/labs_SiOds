#pragma once

#include <iostream>
#include <ctime>
#include <stdio.h>
#include <fstream>

using namespace std;


bool pred_zero(int i);
bool pred_zero(float i);

bool pred_pos(int i);
bool pred_pos(float i);

bool pred_neg(int i);
bool pred_neg(float i);

void enter(int* ar, int n);
void enter(float* ar, int n);

void show(int* ar, int n);
void show(float* ar, int n);

void create(int* ar, int n);
void create(float* ar, int n, float min, float max);

void add_el(int* ar, int n, int a, int b);
void add_el(float* ar, int n, int a, float b);

void del_el(int* ar, int n, int a);
void del_el(float* ar, int n, int a, float b);

int sum_in_pos(int* ar, int n);
float sum_in_pos(float* ar, int n);

int sum_in_nig(int* ar, int n);
float sum_in_nig(float* ar, int n);

int sum_in_zero(int* ar, int n);
float sum_in_zero(float* ar, int n);

int sum(int* ar, int n, int a,int b);
float sum(float* ar, int n, int a, int b);

int multi(int* ar, int n, int a, int b);
int multi(float* ar, int n, int a, int b);

int sum_nigg(int *ar, int n);
float sum_nigg(float* ar, int n);

int mult(int* ar, int n);
float mult(float* ar, int n);

int lin_search_min_in(int* ar, int n);
int lin_search_min_in(float* ar, int n);

int lin_search_max_in(int* ar, int n);
int lin_search_max_in(float* ar, int n);

int lin_search_min(int* ar, int n);
float lin_search_min(float* ar, int n, float k);

int lin_search_max(int* ar, int n);
float lin_search_max(float* ar, int n);

void bubble_sort(int *ar, int n);
void bubble_sort(float* ar, int n);

void simple_sort(int* ar, int n );
void simple_sort(float* ar, int n);

void inst_sort(int* ar, int n);
void inst_sort(float* ar, int n);

int bin_search(int* ar, int n, int k);

void file_cin(int* ar, int n);
void file_cin(float* ar, int n);

void binary_file_cin(int* ar, int n);
void binary_file_cin(float* ar, int n);

void file_cout();
void binary_file_cout();