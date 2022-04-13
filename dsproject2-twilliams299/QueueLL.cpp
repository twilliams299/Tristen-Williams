// QueueLL.cpp
// Add cpp comments here
#include "QueueLL.h"
#include <iostream>

using namespace std;

// constructor to create an empty queue
QueueLL::QueueLL()
{
    myFront= NULL;
    myBack= NULL;
}

// destructor to delete the nodes of the queue
QueueLL::~QueueLL()
{
    // loop from front to back, deleting the node of queue
    while(myFront != NULL)
    {
        Node* temp = myFront;
        myFront = myFront->next;
        delete temp;
    }
    // update myBack to null
    myBack = NULL;
}

// function that returns true if queue is empty else return false
bool QueueLL:: empty()
{
    return myFront == NULL;
}

// function to insert data into the queue
void QueueLL:: enqueue(int e)
{
    // create a new node
    Node *node = new Node(e);
    // set data and next
    node->data = e;
    node->next = NULL;
    // empty queue, set myFront to node
    if(myFront == NULL)
    {
        myFront = node;
    }
    // else set next of myBack to node
    else
    {
        myBack->next = node;
    }
    // update myBack to node
    myBack = node;
}

// function to delete the front element of queue
void QueueLL:: dequeue()
{
    // empty queue, display error
    if(empty())
    {
        cout << "ERROR: Cannot dequeue from an EMPTY QUEUE" << endl;
    }
    else
    {
        // set temp to front node
        Node *temp = myFront;
        // update front to node next to front
        myFront = myFront->next;
        // queue is empty after removal, set myBack to null
        if(myFront == NULL)
        {
            myBack = NULL;
        }
        // delete temp node
        delete temp;
    }
}

// function to return the front element of the queue
int QueueLL:: front()
{
    // queue is not empty, return the data stored in myFront
    if(!empty())
    {
        return myFront->data;
    }
    // queue is empty, return default value
    return -99999;
}

// function to display the queue elements from front to back
void QueueLL:: display()
{
    // queue is empty
    if(empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue(from front to back):" << endl;
        // set temp to myFront
        Node* temp = myFront;
        // loop over the queue displaying the elements
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        
        cout << endl;
    }
}
