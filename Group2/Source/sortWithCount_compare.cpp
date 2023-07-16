void mergeWithCount_compare(int a[], int low, int mid, int high,int &count_compare) {
    int leftSize = mid - low + 1;    
    int rightSize = high - mid;    
    int* left = new int[leftSize];
    int*right = new int[rightSize];
    for (int i = 0;++count_compare && i < leftSize; i++)
        left[i] = a[low + i];
    for (int j = 0;++count_compare && j < rightSize; j++)
        right[j] = a[mid + 1 + j];

    int i = 0;  
    int j = 0;  
    int k = low;  
    while (++count_compare && i < leftSize && ++count_compare && j < rightSize) {
        if (++count_compare && left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (++count_compare && i < leftSize) {
        a[k] = left[i];
        i++;
        k++;
    }
    while (++count_compare && j < rightSize) {
        a[k] = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}



void merge_sortWithCount_compare(int a[], int low, int high,int &count_compare) {
    if (++count_compare && low < high) {
        int mid = low + (high - low) / 2;
        merge_sortWithCount_compare(a, low, mid,count_compare);
        merge_sortWithCount_compare(a, mid + 1, high,count_compare);
        mergeWithCount_compare(a, low, mid, high,count_compare);
    }
}

void mergeSortWithCount_compare(int a[], int n,int &count_compare){
    merge_sortWithCount_compare(a, 0, n - 1,count_compare);
}


int partitionWithCount_compare(int a[], int low, int high,int &count_compare) 
{
    int pivot = a[low];
    int i = low + 1;

    for (int j = low + 1;++count_compare && j <= high; j++) 
	{
        if (++count_compare && a[j] < pivot) 
		{
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
    int temp = a[low];
    a[low] = a[i - 1];
    a[i - 1] = temp;
    return (i - 1);
}
void quick_sortWithCount_compare(int a[], int low, int high,int &count_compare) 
{
    if (++count_compare && low < high) {
        int pi = partitionWithCount_compare(a, low, high, count_compare);
        quick_sortWithCount_compare(a, low, pi - 1,count_compare);
        quick_sortWithCount_compare(a, pi + 1, high, count_compare);
    }
}
void quickSortWithCount_compare(int a[], int n,int &count_compare){
    quick_sortWithCount_compare(a, 0, n - 1,count_compare);
}




void countingSortWithCount_compare(int a[],int n,int &count_compare) {
    int maxElement = a[0];
    for (int i = 1;++count_compare && i < n; i++) {
        if (++count_compare && a[i] > maxElement) {
            maxElement = a[i];
        }
    }
    int* count = new int[maxElement + 1];
    for (int i = 0;++count_compare && i < maxElement + 1; i++)
        count[i] = 0;
    int* sortedArray = new int[n];
    for (int i = 0;++count_compare && i < n; i++) {
        count[a[i]]++;
    }
    for (int i = 1;++count_compare && i <= maxElement; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1;++count_compare && i >= 0; i--) {
        sortedArray[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0;++count_compare && i < n; i++) {
        a[i] = sortedArray[i];
    }
    delete[] count;
    delete[] sortedArray;
}



void countWithCount_compare(int a[], int n, int base,int& count_compare) {
    int count[10] = { 0 }, i;
    int* output = new int[n];
    for (i = 0;++count_compare && i < n; i++)
        count[(a[i] / base) % 10]++;
    for (i = 1;++count_compare && i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1;++count_compare && i >= 0; i--) {
        output[count[(a[i] / base) % 10] - 1] = a[i];
        count[(a[i] / base) % 10]--;
    }
    for (int i = 0;++count_compare && i < n; i++)
        a[i] = output[i];
    delete[] output;
}
void radixSortWithCount_compare (int a[], int n,int &count_compare) {
    int Max = a[0];
    for (int i = 1;++count_compare && i < n; i++)
        if (++count_compare && a[i] > Max)
            Max = a[i];
    for (int base = 1;++count_compare &&  Max / base > 0; base *= 10)
        countWithCount_compare(a, n, base,count_compare);
}


void flashSortWithCount_compare(int a[], int n,int &count_compare) {
    int minValue = a[0];
    int maxIndex = 0;
    int lengthToConsider = int(0.45 * n);
    int *countArray = new int[lengthToConsider];

    for (int i = 0;++count_compare && i < lengthToConsider; i++)
        countArray[i] = 0;

    for (int i = 1;++count_compare && i < n; i++)
    {
        if (++count_compare && a[i] < minValue)
            minValue = a[i];
        if (++count_compare && a[i] > a[maxIndex])
            maxIndex = i;
    }

    if (++count_compare && a[maxIndex] == minValue)
    {
        delete[] countArray;
        return;
    }

    double coefficient = (double)(lengthToConsider - 1) / (a[maxIndex] - minValue);

    for (int i = 0;++count_compare &&  i < n; i++)
    {
        int countIndex = int(coefficient * (a[i] - minValue));
        countArray[countIndex] += 1;
    }

    for (int i = 1;++count_compare &&  i < lengthToConsider; i++)
        countArray[i] += countArray[i - 1];

    int temp = a[maxIndex];
    a[maxIndex] = a[0];
    a[0] = temp;

    int elementsMoved = 0;
    int currentIndex = 0;
    int countIndex = lengthToConsider - 1;
    int tempIndex = 0;
    int flash;

    while (++count_compare && elementsMoved < n - 1)
    {
        while (++count_compare && currentIndex > countArray[countIndex] - 1)
        {
            currentIndex += 1;
            countIndex = int(coefficient * (a[currentIndex] - minValue));
        }
        flash = a[currentIndex];
        if (++count_compare && countIndex < 0)
            break;
        while (++count_compare && currentIndex != countArray[countIndex])
        {
            countIndex = int(coefficient * (flash - minValue));
            int hold = a[tempIndex = --countArray[countIndex]];
            a[tempIndex] = flash;
            flash = hold;
            elementsMoved += 1;
        }
    }

    delete[] countArray;

    for (int i = 1;++count_compare && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (++count_compare && j >= 0 && ++count_compare && a[j] > key)
        {
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = key;
    }
}
