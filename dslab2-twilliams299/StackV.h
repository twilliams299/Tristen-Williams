#pragma once
#include <iostream>
#include <vector>
using namespace std;

class StackV
{
public:
    // all the methods
    void pop();
    void push(int e);
    bool empty();
    int top();
private:
    vector<int> v;
};

