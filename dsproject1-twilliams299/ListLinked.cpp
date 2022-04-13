/*-- ListLinked.cpp------------------------------------------------------------
   This file implements the ListLinked member functions.
-------------------------------------------------------------------------*/
#include "ListLinked.h"
#include <cstddef>
#include <iostream>
using namespace std;

/* Constructor  */
ListLinked::ListLinked()
{
		first = NULL;
}

/* destructor - clean up memory for remaining nodes in list */
ListLinked::~ListLinked()
{
	Node* temp;
	temp = first;
	while (temp != NULL)
	{
		Node* save = temp;
		temp = temp->next;
		delete save;
	}
}


/* empty */
bool ListLinked::empty()
{
	if (first == NULL)
		return true;
	else
		return false;
}

/* display */
void ListLinked::display()
{
	Node* temp;
	temp = first;
	while (temp != NULL)
	{
		cout << temp->data << ",";
		temp = temp->next;
	}
	cout << endl;
}

/* Insert an item into the list after the node
 with the specified preptr_value */
void ListLinked::insert(ElementType e, ElementType preptr_value)
{
    // initialize the node
	Node* newptr = new Node(e);
    if(preptr_value == 0)
    {
        newptr->next = first;
        first = newptr;
        return;
    }
     // start it from first
    Node* start = first;
    // start it from next of first
    Node* then = first->next;
    
    //search for the node containing preptr_value
    while(start->data != preptr_value)
    {
        start = start->next;
        
        if(start == NULL)
        {
            cout << "Given value " << preptr_value << " is not in the list." <<endl;
            return;
        }
        
        then = then->next;
    }
    
    start->next = newptr;
    newptr->next = then;
    
}

void ListLinked::erase(ElementType preptr_value)
{
    // start it from first
    Node* start = first;
    // start it from next of first
    Node* then = first->next;
    
    //first search for the node containing the preptr_value
    while(start->data != preptr_value)
    {
       start = start->next;
        
        if(start == NULL){
            cout << "Given value " << preptr_value << " is not in the list." << endl;
            return;
        }
        
        then = then->next;
    }
    
    start->next = then->next;
    then->next = NULL;
    delete then;
    
}

