#include "BSTArray.h"
#include <iostream>
// Create BSTArray methods here

BSTArray::BSTArray()
{
    for(int i =0; i < CAPACITY; i++)
    {
        myArray[i] = 0;
    }
}


void BSTArray::insert(int x)
{

//is root empty
if (myArray[1] == 0)
{
    myArray[1] = x;
}
else
{
    int p = 1;
    int parent = 0;
    while ((myArray[p] != 0) && (myArray[p] != x)) //find the right location for the new node
    {
        if (x < myArray[p])
        {
            parent = p;
            p = parent *2;
        }
        else
        {
            parent = p;
            p = parent *2 +1;
            
        }
    }
    if (myArray[p] == 0) //if the element is not in the BST
    {
        if(x < p)
        {
        myArray[p]=x;
        }
        else
        {
            myArray[p]= x;
        }
    }
    else
    {
        std::cout << "node duplicate!" << std::endl;

    }
}
   
}

int BSTArray::findmin()
{
    
    int i = 1;
    while(myArray[i*2]==0)
    {
    i=i*2;
    return myArray[i];
    }
    return i;

}

int BSTArray::findmax()
{
    int p =1;
    if(myArray[p] == 0)
        return 0;
    while(myArray[p*2+1]!=0)
    {
        p = p*2+1;
    }
    return myArray[p];
}
int BSTArray::search(int x)
{
    int p = 1;
    if (myArray[p] == 0) //if the element is not in the BST
    {
        return 0;
    }
    while((myArray[p] != 0)&& (myArray[p] != x)) //find the right location for the new node
    {
        
        if (x < myArray[p])
        {
            std::cout << myArray[p] << "-";
            p = p *2;
            
        }
        else
        {
            std::cout << myArray[p] << "-";
            p = p *2 +1;
            
        }
        
    }
   if(x == myArray[p])
   {
       std::cout << x << std::endl;
       return x;
   }
    if(x != myArray[p])
    {
        return 0;
    }
    
    return x;
   
}


void BSTArray::print()
{
    int i=0;
    for(i=1;i<=CAPACITY;i++)
    {
        if(myArray[i]!=0)
        {
            std::cout<<myArray[i]<<" ";
            
        }
    
}
}
