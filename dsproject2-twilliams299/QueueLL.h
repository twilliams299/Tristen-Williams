#pragma once
// Add header comments here
#include <iostream>
#include "Node.h"
class QueueLL
{
public:
    // all the methods
    QueueLL();
    ~QueueLL();
    void dequeue();
    void enqueue(int e);
    bool empty();
    int front();
    void display();
private:
    Node *myFront;
    Node *myBack;
    
};

