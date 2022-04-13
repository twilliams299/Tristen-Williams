#include "StackV.h"


void StackV::push(int e)
{
    //push a value onto stack
    v.push_back(e);
}

void StackV::pop()
{
    //pop a value onto stack
    v.pop_back();
}

bool StackV::empty()
{
    //check if empty
    return (v.size()==0);
}

int StackV::top()
{
    //access to top of stack
    if(!this->empty())
    {
        return v[v.size()-1];
    }
    else
    {
        return -99999;
    }
}

