#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
#include "header.h"
#define sizearr 100005
#define len_state 3
#define len_size 5
using namespace std;

int main() {
	// Dieu chinh loai ket qua----------------
	int set_size [6] = {1000,3000,10000,30000,100000}; 
	bool txt = false; // chon true neu muon xuat ra txt
	int len_mode = 6; 
	int set_mode [17] = {0,1,2,3,4,7};
	/*0:Bubblesort 1:Selectionsort  2:Insertionsort 3:Quicksort 4:Mergesort 5:Heapsort 6:Countingsort 7:Shellsort 8:Shakersort 9:Radixsort 10:FlashSort 11:BinaryInsertionsort */
//---------------------------------------------------
	int set_state [4] = {0,1,2}; //stade: Sorted = 0, Random = 1, reverse = 2
	string state_name [4] = {"Sorted", "Random","Reverse"};
	ofstream outcsv;
	outcsv.open("runtime.csv");
	//---------------------------------

	// // Test chuong trinh tai day---------------
	// Dat ten field
		outcsv << "Input_state" << ','<< "Input_size" <<','<< "Bubble" << ',' << "Selection"<< ','<< "Insertion" << ',' << "Quick" << ','<<"Merge" <<',' << "Shell" << endl;

	// Chay bat dau ghi ket qua vao csv va txt (tuy chon)
	 	for (int state = 0; state < len_state; state++){
	  	for(int size = 0; size < len_size; size++ ){
				outcsv << state_name[state] << ',' << set_size[size] << ',';
	 			for (int mode = 0; mode < len_mode; mode++){
					// Tao mang moi
	 				int *arr = new int [sizearr];
					Input(arr,set_size[size],set_state[state]);
					//Ket qua chay chuong trinh
					double result_time = Counting_time(arr, set_size[size], set_mode[mode]);
					// Tuy chon co muon xuat txt khong
					if (txt == true && size == 2 && state == 2){
						export_result_txt(arr, set_size[size], set_state[state], set_mode[mode]);
					}
					
					// ghi csv
					outcsv << result_time;
					
					// Neu la chi so cuoi cung cua doi tuong thi xuong dong, khong thi ghi ','
					if (mode == len_mode - 1){
						outcsv << endl;
					} else outcsv << ',';
					
					//xoa mang
					delete [] arr;
	 			}
	 		}
	 	}
	//Outarr(arr,set_size);
	//Ket thuc---------------------------
	outcsv.close();
  return 0;
}