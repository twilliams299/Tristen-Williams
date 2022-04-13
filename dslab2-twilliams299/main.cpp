// Stack-Queue-Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "StackV.h"
#include "QueueV.h"
using namespace std;
int main()
{
	cout << "StackV and Queue V test program" << endl;

	// Test StackV
    // Create object with new
    StackV* stack = new StackV();
    cout << boolalpha << stack->empty() << endl;
    stack->push(10);
    stack->push(20);
    stack->push(30);
    stack->push(40);
    cout << stack->top() << endl;
    stack->push(50);
    stack->push(60);
    stack->push(70);
    cout << stack->top() << endl;
    stack->pop();
    cout << stack->top() << endl;
    stack->pop();
    cout << stack->top() << endl;
    stack->pop();
    cout << stack->top() << endl;
    // Delete object
    delete stack;
    
	// Test QueueV
    // Create object with new
    QueueV* queue = new QueueV();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->enqueue(40);
    cout << queue->front() << endl;
    queue->enqueue(50);
    queue->enqueue(60);
    queue->enqueue(70);
    cout << queue->front() << endl;
    queue->dequeue();
    cout << queue->front() << endl;
    queue->dequeue();
    cout << queue->front() << endl;
    queue->dequeue();
    cout << queue->front() << endl;
    cout << std::boolalpha << queue->empty() << endl;
    // Delete object
    delete queue;
    
	return 0;
}

