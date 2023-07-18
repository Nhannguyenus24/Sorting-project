#include "Function.h"

void cloneArray(int source[], int des[], int size){
    for (int i = 0; i < size; i++)
        des[i] == source[i];
}
long long runningTime(int a[], int n, void (*ptr)(int[], int)) {
    auto start = chrono::high_resolution_clock::now();
    ptr(a, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    return chrono::duration_cast<chrono::milliseconds>(elapsed).count();
}

bool isNumber(char num[]){
    for (int i = 0; num[i] != '\0'; i++){
        if (!isdigit(num[i]))
            return false;
    }
    return true;
}
bool checkExist(char name[], string array[], int len, int& order){
    for (int i = 0; i < len; i++){
        order = i;
        if (strcmp(name, array[i].c_str()) == 0)
            return true;
    }
    return false;
}

void command(int argv, char* argc[]){
	if (strcmp(argc[1], "-a") == 0){
        cout <<"ALGORITHM MODE" << endl;
		Algorithm_mode(argv, argc);
    }
	else if (strcmp(argc[1], "-c") == 0){
        cout <<"COMPARISON MODE"  << endl;
		Comparison_mode(argv, argc);
    }
	else
		cout<<"Input wrong command!" << endl;
}
void Algorithm_mode(int argv, char* argc[]){
    const char* file = ".txt";
    int input_order, output_order, sort_order, size;
	if (argv == 5){
        if (checkExist(argc[2], sortnArray, 11, sort_order) && (strstr(argc[3],file) != NULL) && checkExist(argc[4],outputParameter, 3, output_order)){
            //Command 1
            cout << "Algorithm: " << argc[2] << endl;
            cout << "Input file: " << argc[3] << endl;
            fstream in(argc[3]);
            in >> size;
            int* arr = new int[size];
            for (int i = 0; i < size; i++)
                in >> arr[i];
            in.close();
            cout << "Input size: " << size << endl;
            cout <<"-------------------------" << endl;
            if (output_order == 2 || output_order == 0){
                long long time = runningTime(arr, size, sortfArray[sort_order]);
                cout << "Running time: " << time <<endl;
            }
            if (output_order == 1 || output_order == 2){
                long long comparisions = 0;
                sortc_ptr sort_count_compare = sortcArray[sort_order];
                sort_count_compare(arr, size, comparisions);
                cout << "Comparisions: " << comparisions << endl;
            }
            delete[] arr;
        }
        else if (checkExist(argc[2], sortnArray, 11, sort_order) && isNumber(argc[3]) && checkExist(argc[4],outputParameter, 3, output_order)){
            //Command 3
            size = atoi(argc[3]);
            cout << "Features under development!" << endl; 

        }
        else 
            cout <<"Input wrong command!"<<endl;
    }
    else if (argv == 6){
        if (checkExist(argc[2], sortnArray, 11, sort_order) && isNumber(argc[3]) && checkExist(argc[4], inputOrder, 4, input_order) && checkExist(argc[5],outputParameter, 3, output_order)){
            //Command 2
            size = atoi(argc[3]);
            cout << "Algorithm: " << argc[2] << endl;
            cout <<"Input size: " << size << endl;
            cout <<"Input order: " << dataType[input_order] << endl;
            cout << "-------------------------" << endl;
            int* arr = new int[size];
            GenerateData(arr, size, input_order);
            if (output_order == 2 || output_order == 0){
                long long time = runningTime(arr, size, sortfArray[sort_order]);
                cout << "Running time: " << time <<endl;
            }
            if (output_order == 1 || output_order == 2){
                long long comparisions = 0;
                sortc_ptr sort_count_compare = sortcArray[sort_order];
                sort_count_compare(arr, size, comparisions);
                cout << "Comparisions: " << comparisions << endl;
            }
            delete[] arr;
        }
        else {
            cout <<"Input wrong command!"<<endl;
        }
    }
    else 
        cout <<"Input wrong command!"<<endl;
}
void Comparison_mode(int argv, char* argc[]){
	const char* file = ".txt";
    int sort_order1, sort_order2, input_order, size;
    if (argv == 5){
        if (checkExist(argc[2], sortnArray, 11, sort_order1) && checkExist(argc[3], sortnArray, 11, sort_order2) && (strstr(argc[4],file) != NULL)){
            //Command 4
            fstream in(argc[4]);
            in >> size;
            int* arr = new int[size];
            for (int i = 0; i < size; i++)
                in >> arr[i];
            in.close();
            cout <<"Algorithm: " << argc[2] << " | " << argc[3]<< endl;
            cout << "Input file: " << argc[4] << endl;
            cout <<"------------------------"<<endl;
            int* arr2 = new int[size];
            cloneArray(arr, arr2, size);
            long long time1 = runningTime(arr2, size, sortfArray[sort_order1]);
            cloneArray(arr, arr2, size);
            long long time2 = runningTime(arr2, size, sortfArray[sort_order2]);
            cloneArray(arr, arr2, size);
            long long comparision1 = 0, comparision2 = 0;
            sortc_ptr sort_count_compare1 = sortcArray[sort_order1];
            sortc_ptr sort_count_compare2 = sortcArray[sort_order2];
            sort_count_compare1(arr, size, comparision1);
            sort_count_compare2(arr2, size, comparision2);
            cout << "Running time: " << time1 << " | " << time2 << endl;
            cout <<"Comparisions: " << comparision1 << " | " << comparision2 << endl;
            delete[] arr;
            delete[] arr2;
        }
        else 
            cout << "Input wrong command!" << endl;
    }
    else if (argv == 6){
        if (checkExist(argc[2], sortnArray, 11, sort_order1) && checkExist(argc[3], sortnArray, 11, sort_order2) && isNumber(argc[4]) && checkExist(argc[5], inputOrder, 4, input_order)){
            //Command 5
            size = atoi(argc[4]);
            int* arr = new int[size];
            GenerateData(arr, size, input_order);
            cout <<"Algorithm: " << argc[2] << " | " << argc[3]<< endl;
            cout << "Input size: " << size << endl;
            cout << "Input order: " << dataType[input_order] << endl;
            cout <<"------------------------"<<endl;
            int* arr2 = new int[size];
            cloneArray(arr, arr2, size);
            long long time1 = runningTime(arr2, size, sortfArray[sort_order1]);
            cloneArray(arr, arr2, size);
            long long time2 = runningTime(arr2, size, sortfArray[sort_order2]);
            cloneArray(arr, arr2, size);
            long long comparision1 = 0, comparision2 = 0;
            sortc_ptr sort_count_compare1 = sortcArray[sort_order1];
            sortc_ptr sort_count_compare2 = sortcArray[sort_order2];
            sort_count_compare1(arr, size, comparision1);
            sort_count_compare2(arr2, size, comparision2);
            cout << "Running time: " << time1 << " | " << time2 << endl;
            cout <<"Comparisions: " << comparision1 << " | " << comparision2 << endl;
            delete[] arr;
            delete[] arr2;
        }
        else 
            cout << "Input wrong command!" << endl;
    }
    else 
        cout <<"Input wrong command!" << endl;
}