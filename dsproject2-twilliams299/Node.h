#ifndef NODE
#define NODE
/*-- Node.h ---------------------------------------------------------------

  This header file defines the Node class for building linked lists.
  Basic operations are:
	 Constructor
  This class has two public data members as well:
      data - data element for the node
	  next - pointer to the next node in the list or null if no items 
	         follow
-------------------------------------------------------------------------*/
#include "ElementType.h"
#include <cstddef>
class Node {
public:
	Node(ElementType, Node* n = NULL);
	
	ElementType data;
	Node* next;

};

#endif

