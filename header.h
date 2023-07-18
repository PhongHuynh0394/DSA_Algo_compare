#pragma once
#include <fstream>
using namespace std;

// support function----------------------
// print arr
void Outarr(int *a, int n);
//export txt
void export_result_txt(int *a, int size, int state, int mode);
// size arr: n, mode: 1(sorted), -1(reverse)
void Input(int *a, int n, int mode);
double Counting_time(int *a, int size, int mode);

//sorting algorithm-------------------
void bubbleSort(int *arr, int n);
void Quicksort(int *a, int l, int r);
void Shellsort(int *a,int n);
void selectionSort(int *a, int n);
void insertionSort(int *a, int n);
void merge(int *a, int l, int m, int r);
void mergeSort(int *a, int l, int r);