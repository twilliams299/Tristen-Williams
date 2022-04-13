/*-- main.cpp------------------------------------------------------------
   This file is the driver for testing ListLinked
-------------------------------------------------------------------------*/
#include "ListLinked.h"
#include <iostream>
using namespace std;

/* main is the entrypoint into every C++ program */
int main() 
{
    ListLinked* ll = new ListLinked();
    ll->insert(10,0); //current linked list: 10 (default status, when empty)
    ll->display();
    
    ll->insert(20,10); //current linked list: 10->20
    ll->insert(30,20); //current linked list: 10->20->30
    ll->insert(40, 20); //current linked list: 10->20->40->30
    ll->insert(50, 30); //current linked list: 10->20->40->30->50
    ll->display();
    
    ll->insert(60, 50); //current linked list: 10->20->40->30->50->60
    ll->insert(70, 5); //error, no 5 existed in the linked list
    ll->display();
    ll->erase(30); //current linked list: 10->20->40->30->60
    ll->display();
    ll->erase(10); //current linked list: 10->40->30->60
    ll->display();
    ll->erase(50); //error, no 50 existed in the linked list
    ll->display();
    
    return 0;
}
