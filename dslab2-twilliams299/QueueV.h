#pragma once
#include <iostream>
#include <vector>
using namespace std;

class QueueV
{
public:
    // all the methods
    void dequeue();
    void enqueue(int e);
    bool empty();
    int front();
private:
    vector<int> v;
};

