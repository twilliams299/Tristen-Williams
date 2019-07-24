//
//  arrays.cpp
//  arrays
//
//  Created by Michelle Talley on 1/3/19.
//  Copyright © 2019 Michelle Talley. All rights reserved.
//

#include <iostream>
using namespace std;

void printArray(int n, int arr[])
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}
    
int main(int argc, const char * argv[]) {

    const int CAPACITY = 10;
    typedef int IntegerArray[CAPACITY];
    // Static Array
    IntegerArray a;
    
    // Initialize static array
    for (int i = 0; i < CAPACITY; i++) {
        a[i] = i+1;
    }

    // Print array
    for (int i = 0; i < CAPACITY; i++) {
        cout << a[i] << ",";
    }
    cout << endl;

    // Dynamic array
    int * arrayPtr = new int[CAPACITY];
    
    // Dynamic array with [] access, initializatoion
    for (int i = 0; i < CAPACITY; i++) {
        arrayPtr[i] = i;
    }
    // Print Dynamic array
    for (int i = 0; i < CAPACITY; i++) {
        cout << arrayPtr[i] << ",";
    }
    cout << endl;

    // Dynamic array with ptr access, set all to zero
    int * ptr = arrayPtr;
    for (int i = 0; i < CAPACITY; i++) {
        *ptr = 0;
        ptr++;
    }

    // Print out with ptr access
    ptr = arrayPtr;
    for (int i = 0; i < CAPACITY; i++) {
        cout << *ptr << ",";
        ptr++;
    }
    cout << endl;
    
    // Print out with [] access
    for (int i = 0; i < CAPACITY; i++) {
        cout << arrayPtr[i] << ",";
    }
    cout << endl;
    
    printArray(CAPACITY, a);
    
    delete [] arrayPtr;
        
    return 0;
}
