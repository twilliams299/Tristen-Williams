//
//  main.cpp
//  DSProject
//
//  Created by Tristen Williams, Sang Din, Tommy Nguyen on 4/17/22.
//  Copyright © 2022 Tristen Williams, Sang Din, Tommy Nguyen . All rights reserved.
//

#include <iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
const int MAX = 1000;
const int RUN = 32;
// TimSort implementation
//https://cplusplus.algorithmexamples.com/web/sorting/Tim%20Sort.html
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// merge function merges the sorted runs
//https://www.geeksforgeeks.org/merge-sort/
void merge(int arr[], int const l, int const m, int const r)
{
    // original array is broken in two parts, left and right array
    auto const len1 = m - l + 1;
    auto const len2 = r - m;
    
    auto *left = new int[len1];
    auto *right = new int[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    
    int i = 0;
    int j = 0;
    int k = l;
    
    // after comparing, we merge those two array in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    // copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    
    // copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

// iterative Timsort function to sort the array[0...n-1] (similar to merge sort)
void timSort(int arr[], int n)
{
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+31), (n-1)));
    
    // start merging from size RUN (or 32). It will merge to form size 64, then 128, 256 and so on ....
    for (int size = RUN; size < n; size = 2*size)
    {
        // pick starting point of left sub array. We are going to merge arr[left..left+size-1] and arr[left+size, left+2*size-1]
        // After every merge, we increase left by 2*size
        for (int left = 0; left < n; left += 2*size)
        {
            // find ending point of left sub array
            // mid+1 is starting point of right sub array
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n-1));
            
            // merge sub array arr[left.....mid] & arr[mid+1....right]
            merge(arr, left, mid, right);
        }
    }
}

// selectionsort implementation
//https://www.programiz.com/dsa/selection-sort
// function to swap the the position of two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to print an array
void printArraySe(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//
void selectionSort(int arr[], int N) {
    for (int step = 0; step < N - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < N; i++) {
            
            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (arr[i] < arr[min_idx])
                min_idx = i;
        }
        
        // put min at the correct position
        swap(&arr[min_idx], &arr[step]);
    }
}

//Bubble sort implementation
// https://www.programiz.com/dsa/bubble-sort
// perform bubble sort
void bubbleSort(int arr[], int N1) {
    
    // loop to access each array element
    for (int step = 0; step < N1; ++step) {
        
        // loop to compare array elements
        for (int i = 0; i < N1 - 1; ++i) {
            
            // compare two adjacent elements
            // change > to < to sort in descending order
            if (arr[i] > arr[i + 1]) {
                
                // swapping elements if elements
                // are not in the intended order
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

//quick sort implementation and its sperate functions
//citation website: https://www.geeksforgeeks.org/quick-sort/
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arr, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Radix sort and its functions
//citation website: https://www.geeksforgeeks.org/radix-sort/
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[], int n, int exp)
{
    int output[1000]; // output array <--- Output Array size should be same as input array
    int i, count[10] = { 0 };
    
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
    
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// print array
void printArrayBu(int arr[], int N1) {
    for (int i = 0; i < N1; ++i) {
        cout << "  " << arr[i];
    }
    cout << "\n";
}





int main()
{
    //Create arrray
    
    
    int randArray[MAX];
    int copy1[MAX];
    int copy2[MAX];
    int copy3[MAX];
    int copy4[MAX];
    int copy5[MAX];
    int copy6[MAX];
    int sorted[MAX];
    int sorted1[MAX];
    int sorted2[MAX];
    int sorted3[MAX];
    int sorted4[MAX];
    int sorted5[MAX];
    int sorted6[MAX];
    int j =0;
    // Generate sorted values
    for(int i=0;i<MAX ;i++)
    {
        
        sorted[i]=j++;
    }
    
    //copy sorted numbers to other arrays to use
    for(int i=0; i< MAX; i++)
    {
        sorted1[i] = sorted[i];
        sorted2[i] = sorted[i];
        sorted3[i] = sorted[i];
        sorted4[i] = sorted[i];
        sorted5[i] = sorted[i];
        sorted6[i] = sorted[i];
    }
    // Generate Random values
    for(int i=0;i<MAX ;i++)
    {
        randArray[i]=rand()%1000;
    }
    
    //copy random numbers to other arrays to use
    for(int i=0; i< MAX; i++)
    {
        copy1[i] = randArray[i];
        copy2[i] = randArray[i];
        copy3[i] = randArray[i];
        copy4[i] = randArray[i];
        copy5[i] = randArray[i];
        copy6[i] = randArray[i];
    }
    
    //selection sort
    // Get starting timepoint
    auto startSelec = high_resolution_clock::now();
    //Calculate size of array
    int N = sizeof(randArray) / sizeof(randArray[0]);
    cout << "Unsorted array :\n";
    printArraySe(copy1, 5);
    selectionSort(copy1, N);
    cout << "Array after selection sort: \n";
    for (int i = 0; i < N; i++)
        cout << copy1[i] << " ";
    // Get ending timepoint
    auto stopSelec = high_resolution_clock::now();
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto durationSelec = duration_cast<microseconds>(stopSelec - startSelec);
    
    cout << "\nTime taken by selection sort function: "
    << durationSelec.count() << " microseconds" << endl << endl;
    
    //Sorted selection search
    // Get starting timepoint
    auto startSelecSort = high_resolution_clock::now();
    //Calculate size of array
    int NSort1 = sizeof(sorted) / sizeof(sorted1[0]);
    cout << "Sorted array :\n";
    printArraySe(sorted1, 5);
    selectionSort(sorted1, NSort1);
    cout << "Array after selection sort: \n";
    for (int i = 0; i < NSort1; i++)
        cout << sorted1[i] << " ";
    // Get ending timepoint
    auto stopSelecSort = high_resolution_clock::now();
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto durationSelecSort = duration_cast<microseconds>(stopSelecSort - startSelecSort);
    
    cout << "\nTime taken by selection sort function: "
    << durationSelecSort.count() << " microseconds" << endl << endl;
    
    
    //bubble sort
    // Get starting timepoint
    auto startBubble = high_resolution_clock::now();
    //Calculate size of array
    int N1 = sizeof(randArray)/sizeof(randArray[0]);
    cout << "Unsorted Array :\n";
    printArraySe(copy2, 5);
    bubbleSort(copy2, N1);
    cout << "Array after bubble sort: \n";
    for (int i = 0; i < N1; i++)
        cout << copy2[i] << " ";
    
    
    // Get ending timepoint
    auto stopBubble = high_resolution_clock::now();
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto durationBubble = duration_cast<microseconds>(stopBubble - startBubble);
    
    cout << "\nTime taken by bubble sort function: "
    << durationBubble.count() << " microseconds" << endl << endl;
    
    //Sorted
    // Get starting timepoint
    auto startBubbleSort = high_resolution_clock::now();
    //Calculate size of array
    int NSort2 = sizeof(sorted)/sizeof(sorted2[0]);
    cout << "Unsorted Array :\n";
    printArraySe(sorted2, 5);
    bubbleSort(sorted2, NSort2);
    cout << "Array after bubble sort: \n";
    for (int i = 0; i < NSort2; i++)
        cout << sorted2[i] << " ";
    
    
    // Get ending timepoint
    auto stopBubbleSort = high_resolution_clock::now();
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto durationBubbleSort = duration_cast<microseconds>(stopBubbleSort - startBubbleSort);
    
    cout << "\nTime taken by bubble sort function: "
    << durationBubbleSort.count() << " microseconds" << endl << endl;
    
    //tim sort
    // Get starting timpoint
    auto start = high_resolution_clock::now();
    //Calculate size of array
    int N2 = sizeof(randArray)/sizeof(randArray[0]);
    cout << "TimSort array to be sorted: \n";
    for (int i=0; i<5; i++)
        cout << copy3[i] << " ";
    timSort(copy3, N);
    cout << "\nArray after TimSort: \n";
    for (int i=0; i<N2; i++)
        cout << copy3[i] << " ";
    
    // Get ending timpoint
    auto stop = high_resolution_clock::now();
    
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "\nTime taken by function: "
    << duration.count() << " microseconds" << endl;
    
    //tim sorted array
    auto startSortedTime = high_resolution_clock::now();
    //Calculate size of array
    int NSort3 = sizeof(sorted)/sizeof(sorted[0]);
    cout << "TimeSort array to be sorted: \n";
    for (int i=0; i<5; i++)
        cout << sorted3[i] << " ";
    timSort(sorted3, NSort3);
    cout << "\nArray after TimeSort: \n";
    for (int i=0; i<NSort3; i++)
        cout << sorted3[i] << " ";
    
    // Get ending timepoint
    auto stopSortedTime = high_resolution_clock::now();
    
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto durationSortedTime = duration_cast<microseconds>(stopSortedTime - startSortedTime);
    
    cout << "\nTime taken by function: "
    << durationSortedTime.count() << " microseconds" << endl;
    
    //quick sort
    //Get starting timepoint
    auto startQuick = high_resolution_clock::now();
    //Calculate size of array
    int N3 = sizeof(randArray) / sizeof(randArray[0]);
    cout << "Quicksort array to be sorted: \n";
    for (int i = 0; i < 5; i++)
        cout << copy4[i] << " ";
    quickSort(copy4, 0, N3 - 1);
    cout << "\nArray after quick sort: \n";
    for (int i = 0; i < N3; i++)
        cout << copy4[i] << " ";
    
    // Get ending timepoint
    auto stopQuick = high_resolution_clock::now();
    
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);
    
    cout << "\nTime taken by function: "
    << durationQuick.count() << " microseconds" << endl;
    
    //Sorted
    //Get starting timepoint
    auto startQuickSort = high_resolution_clock::now();
    //Calculate size of array
    int N4Sort = sizeof(sorted) / sizeof(sorted4[0]);
    cout << "Quicksort array to be sorted: \n";
    for (int i = 0; i < 5; i++)
        cout << sorted4[i] << " ";
    quickSort(sorted4, 0, N4Sort - 1);
    cout << "\nArray after quick sort: \n";
    for (int i = 0; i < N4Sort; i++)
        cout << sorted4[i] << " ";
    
    // Get ending timepoint
    auto stopQuickSort = high_resolution_clock::now();
    
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto durationQuickSort = duration_cast<microseconds>(stopQuickSort - startQuickSort);
    
    cout << "\nTime taken by function: "
    << durationQuickSort.count() << " microseconds" << endl;
    
    //radix sort
    //Get starting timepoint
    auto startRadix = high_resolution_clock::now();
    //Calculate size of array
    int N4 = sizeof(randArray) / sizeof(randArray[0]);
    cout << "Radixsort array to be sorted: \n";
    for (int i = 0; i < 5; i++)
        cout << copy6[i] << " ";
    radixsort(copy6, N4);
    cout << "\nArray after Radix sort: \n";
    for (int i = 0; i < N4; i++)
        cout << copy6[i] << " ";
    
    // Get ending timepoint
    auto stopRadix = high_resolution_clock::now();
    
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto durationRadix = duration_cast<microseconds>(stopRadix - startRadix);
    
    cout << "\nTime taken by function: "
    << durationRadix.count() << " microseconds" << endl;
    
    //Sorted
    //Get starting timepoint
    auto startRadixSort = high_resolution_clock::now();
    //Calculate size of array
    int N5Sort = sizeof(sorted) / sizeof(sorted5[0]);
    cout << "Radixsort array to be sorted: \n";
    for (int i = 0; i < 5; i++)
        cout << sorted5[i] << " ";
    radixsort(sorted5, N5Sort);
    cout << "\nArray after Radix sort: \n";
    for (int i = 0; i < N5Sort; i++)
        cout << sorted5[i] << " ";
    
    // Get ending timepoint
    auto stopRadixSort = high_resolution_clock::now();
    
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto durationRadixSort = duration_cast<microseconds>(stopRadixSort - startRadixSort);
    
    cout << "\nTime taken by function: "
    << durationRadixSort.count() << " microseconds" << endl;
    
    
    
    return 0;
    
}




