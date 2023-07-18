#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
#include <chrono>
#include "Sort.h"
#include "sort_with_count_compare.h"
#include "DataGenerator.cpp"

typedef void (*sortf_ptr)(int[], int);
typedef void (*sortc_ptr)(int[], int, long long&);
sortf_ptr sortfArray[11] = {selectionSort, insertionSort, bubbleSort, shakerSort, shellSort, heapSort, mergeSort, quickSort, countingSort, radixSort, flashSort};
sortc_ptr sortcArray[11] = {selectionSort_c, insertionSort_c, bubbleSort_c, shakerSort_c, shellSort_c, heapSort_c, mergeSort_c, quickSort_c, countingSort_c, radixSort_c, flashSort_c};
string sortnArray[11] = {"selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort"};
string inputOrder[4] = {"-rand", "-sorted", "-rev", "-nsorted"};
string outputParameter[3] = {"-time", "-comp", "-both"};
string dataType[4] = {"random data", "sorted data", "reverse data", "nearly sorted data"};

void cloneArray(int source[], int des[], int size);
long long runningTime(int a[], int n, void (*ptr)(int[], int));
bool checkExist(char name[], string array[], int len, int& order);
bool isNumber(char num[]);
void command(int argv, char* argc[]);
void Algorithm_mode(int argv, char* argc[]);
void Comparison_mode(int argv, char* argc[]);

