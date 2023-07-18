#include "header.h"
#include <iostream>
#include <fstream>
using namespace std;

//Sorting function-------
//Bubble sort
void bubbleSort(int *arr, int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = n - 1; j > i; j--)
			if (arr[j] < arr[j -1])
				swap(arr[j],arr[j - 1]);
	}
}

//Quicksort
void Quicksort(int *a, int l, int r){
	// pivot la diem chuan lay gia tri cua phan tu o giua mang
	int left = l, right = r;
	int pivot = a[(l + r) / 2]; 
// bat dau phan chia-xep mang
	while (left < right){
			// neu ben trai be hon pivot -> khong lam gi va tang left
			while (a[left] < pivot) 
				left++;

			// neu ben phai lon hon pivot -> khong lam gi va giam right
			while (a[right] > pivot) 
				right--;

			// neu ben trai lon hon pivot va ben phai be hon pivot, left van ben trai right thi doi cho (cho be hon ra truoc pivot) roi tiep tuc 
			if (left <= right ) {
				swap(a[left],a[right]);
				left++;
				right--;
			}
		}

	// Giai doan de qui de tiep tuc cong viec tren va thay doi left right
	if (left < r)
		Quicksort(a, left, r);
	if (l < right)
		Quicksort(a, l, right);
}

//Shell sort
void Shellsort(int *a,int n){
	// Tao vong lap interval nho dan
	for (int interval = n / 2; interval > 0; interval /= 2){
		// Chi sap xep cac gia tri co khoang cach interval
		for (int i = interval; i < n; i++){
			// Luu lai gia tri a[i] hien tai
			int temp = a[i];
			int j;
			// Doi cac gia tri sau i khoang interval > temp
			for ( j = i; j >= interval && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];
			}

			// Gan gia tri temp vao vi tri thich hop vua duoc doi ra
			a[j] = temp;
		}
	}
}

//Selection sort
void selectionSort(int *a, int n){
//tao 1 bien co ten la "min" de tim lay gia tri nho nhat trong mang
    int min;
    for (int i = 0; i < n - 1; i++){
//cho gan bien min voi phan tu dau tien trong mang
        min = i;
        for (int j = i + 1; j < n; j++){
//so sanh phan tu j voi phan tu min neu dung thi gan cho min bang j
            if (a[j] < a[min])
                min = j;
        }
//so sanh gia tri cua min co bang voi i khong neu khong thi doi cho phan tu min va i
				if(min!=i)
	        swap(a[min], a[i]);
    }
}

void insertionSort(int *a, int n){
//tao mot bien key dung de gan voi phan tu trong mang
    int key, j;
    for (int i = 1; i < n; i++){
//cho bien key bang voi phan tu thu i trong mang
        key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--){
//neu dieu kien vong lap dung thi gan phan tu thu (j+1) voi phan tu thu j
            a[j + 1] = a[j];
        }
//gan phan tu thu (j+1) bang key 
        a[j + 1] = key;
    }
}

//Merge sort
void merge(int *a, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *M = new int[n2];
    for (int i = 0; i < n1; i++){
        L[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++){
        M[j] = a[m + 1 + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2){
        if (L[i] <= M[j]){
            a[k++] = L[i++];
        }
        else{
            a[k++] = M[j++];
        }
    }
    while (i < n1){
        a[k++] = L[i++];
    }
    while (j < n2){
        a[k++] = M[j++];
    }
}

void mergeSort(int *a, int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

//Dem thoi gian thuat toan
double Counting_time(int *a, int size, int mode){
	switch (mode){
		case 0:{
			clock_t begin = clock();
			bubbleSort(a, size);
			clock_t end = clock();
			return (double)(end-begin)/CLOCKS_PER_SEC;
		}
		case 3:{
			clock_t begin = clock();
			Quicksort(a, 0, size-1);
			clock_t end = clock();
			return (double)(end-begin)/CLOCKS_PER_SEC;
		}
		case 7:{
			clock_t begin = clock();
			Shellsort(a, size);
			clock_t end = clock();
			return (double)(end-begin)/CLOCKS_PER_SEC;
		}
		case 1:{
			clock_t begin = clock();
			selectionSort(a, size);
			clock_t end = clock();
			return (double)(end-begin)/CLOCKS_PER_SEC;
		}
		case 2:{
			clock_t begin = clock();
			insertionSort(a, size);
			clock_t end = clock();
			return (double)(end-begin)/CLOCKS_PER_SEC;
		}
		case 4:{
			clock_t begin = clock();
			mergeSort(a, 0, size -1);
			clock_t end = clock();
			return (double)(end-begin)/CLOCKS_PER_SEC;
		}
		
		//Them vao o day theo dung mode
	}
}

// print arr
void Outarr(int *a, int n){
	for (int i =0; i<n; i++)
		{
			cout << a[i] << " ";
		}
}

// create input/file
// size arr: n, mode: 0(sorted), 2(reverse), 1(random)
void Input(int *a, int n, int mode){
	if (mode == 0){
		for (int i = 0; i < n; i++){
				a[i] = i;
			}
	} else if (mode == 2){
		for (int i = 0; i < n; i++){
				a[i] = n - 1 - i;
		}
	} else{
		ifstream in;
		in.open("Random_100000.txt");
		for (int i = 0; i < n; i++){
			in >> a[i];
		}
		in.close();
	}
}
//Xuat ket qua txt
void export_result_txt(int *a, int size, int state, int mode){
	string algo_name [20]{"Bubble sort","Selectionsort","Insertionsort","Quicksort","Mergesort","Heapsort","Countingsort","Shellsort","Shakersort","Radixsort","FlashSort","BinaryInsertionsort"};
	string state_name [5] {"Sorted","Random","Reverse"};
	string size_name;
	switch (size){
		case 1000: {
			size_name = "1000";
			break;
		}
		case 3000:{
			size_name = "3000";
			break;
		}
		case 10000:{
			size_name = "10000";
			break;
		}
		case 30000:{
			size_name = "30000";
			break;
		}
		case 100000:{
			size_name = "100000";
			break;
		}
	}
	
	string name_file = algo_name[mode] + "_" + state_name[state] + "_" +size_name+".txt";
	ofstream out_txt;
	// Xuat file txt
	out_txt.open(name_file);
	for (int i = 0; i < size; i++){
		out_txt << a[i] << " ";
	}
	out_txt.close();
}
// Dem thoi gian chay cua thuat toan
