#include "QueueV.h"

void QueueV::dequeue()
{
    //Removes and returns the object at the beginning of the Queue
    v.erase(v.begin());
}

void QueueV::enqueue(int e)
{
    //Adds an object to the end of the Queue
    v.push_back(e);
}

bool QueueV::empty()
{
    //Returns whether the queue is empty
    return (v.size()==0);
}

int QueueV::front()
{
    //Returns a reference to the next element in the queue
    if(!this->empty())
        return v[0];
    else
        return -99999;
}
