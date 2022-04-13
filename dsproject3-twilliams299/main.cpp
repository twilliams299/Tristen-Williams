/*-- main.cpp------------------------------------------------------------
   This file implements the driver for the BSTArray
-------------------------------------------------------------------------*/
#include "BSTArray.h"

#include <iostream>
using namespace std;

int main()
{
	// Create object
    BSTArray* array = new BSTArray;
	// Call methods on object
    //all inserts
    array->insert(5);
    array->insert(8);
    array->insert(3);
    array->insert(1);
    array->insert(4);
    array->insert(9);
    array->insert(18);
    array->insert(20);
    array->insert(19);
    array->insert(2);
    array->print();
    //Max
    cout << "MAX:" << array->findmax() << endl;
    //Min
    cout << "MIN:" << array->findmin() << endl;
    //search
    array->search(3);
    array->search(18);
    array->search(19);
    
	// Destroy object
    delete array;
    
    
}


