#pragma once
// Add header comments here

#include <iostream>
#include "Node.h"
using namespace std;

class StackLL
{
public:
    // all the methods
    //Constructor
    StackLL();
    //Destructor
    ~StackLL();
    //Pop
    void pop();
    //Push
    void push(int e);
    //Empty
    bool empty();
    //Top
    int top();
    //Display
    void display();
private:
    Node* myTop;
};
