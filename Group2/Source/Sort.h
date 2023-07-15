#include <iostream>
#include <algorithm>
using namespace std;

//Non-counting compares
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n);
//void shakersort
//void shellsort
void heapify(int a[], int n, int i);
void heapSort(int a[], int n);
void merge(int a[], int low, int mid, int high);
void mergeSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void quickSort(int a[], int low, int high);
void countingSort(int a[], int n);
void count(int a[], int n, int base);
void radixSort(int a[], int n);
//Flash_sort

//Counting compares