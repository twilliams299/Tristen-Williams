#pragma once
#include "ElementType.h"
#include <iostream>
// Create BSTArray class defintiion here
// Remember, your underlying data type will be an array, not a linked list!
// Don't forget class definitions end with a semi-colon!
#ifndef BSTARRAY
#define BSTARRAY

const int CAPACITY= 256;

class BSTArray
{
public:
    /* constructor */
    BSTArray();
    //insert method
    void insert(int x);
    //find min
    int findmin();
    //find max
    int findmax();
    //print
    void print();
    //search
    int search(int x);
    
private:
    int myArray[CAPACITY] = {0};
    int highestIndex = 0;
    int lowestIndex = 0;
    
    
};
    #endif
