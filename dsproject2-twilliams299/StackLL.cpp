// Add cpp comments here
#include "StackLL.h"
#include <iostream>

using namespace std;

// constructor to create an empty stack
StackLL::StackLL()
{
    myTop = NULL;
}

// destructor to delete the memory allocated to stack nodes
StackLL::~StackLL()
{
    // loop over the stack from top to bottom deleting the nodes from the stack
    while(myTop != NULL)
    {
        Node *temp = myTop;
        myTop = myTop->next;
        delete temp;
    }
}

// function that returns true if stack is empty else return false
bool StackLL:: empty()
{
    return myTop == NULL;
}

// function to insert data into the stack
void StackLL:: push(int e)
{
    // create a new node
    Node *node = new Node(e);
    // set the data
    node->data = e;
    // set next of node to myTop
    node->next = myTop;
    // update myTop to node
    myTop = node;
}

// function to remove the top node from stack
void StackLL:: pop()
{
    // stack is empty, display error
    if(empty())
        cout << "ERROR: Cannot pop from an EMPTY STACK" << endl;
    else
    {
        // get the top node
        Node *temp = myTop;
        // update myTop to node next to myTop
        myTop = myTop->next;
        // delete temp
        delete temp;
    }
}

// function to return the data stored at the top of stack
int StackLL:: top()
{
    return myTop->data;
}

// function to display the stack elements from top to bottom
void StackLL:: display()
{
    Node* ptr;
    for (ptr = myTop; ptr != NULL; ptr = ptr->next)
    {
        cout << ptr->data << endl;
    }
}

