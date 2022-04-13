// Stack-Queue-LL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StackLL.h"
#include "QueueLL.h"
using namespace std;

int main()
{
    //create stackLL object
    StackLL stack;
    cout << "Stack and Queue using Linked List\n";

    // Test StackLL
    // Push the elements of stack
    stack.push(11);
    stack.push(22);
    stack.push(33);
    stack.push(44);
    
    // Display stack elements
    stack.display();
    
    // Print top element of stack
    cout << "\nTop element is " << stack.top() << endl;
    
    // Delete top elements of stack
    stack.pop();
    stack.pop();
    
    // Display stack elements
    stack.display();
    
    // Print top element of stack
    cout << "\nTop element is " << stack.top() << endl;
    
    
    
    //Create QueueLL Object
QueueLL queue;
    // test QueueLL

    queue.enqueue(10);
    queue.enqueue(20);
    cout << "Queue Front : " << queue.front() << endl;
    queue.display();
    queue.dequeue();
    queue.dequeue();
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.display();
    queue.dequeue();
    queue.display();
    cout << "Queue Front : " << queue.front() << endl;
   
    return 0;
}

