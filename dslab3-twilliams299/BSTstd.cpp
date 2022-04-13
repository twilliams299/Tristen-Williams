/*-- BSTstd.cpp------------------------------------------------------------
   This file implements the BSTstd member functions.
-------------------------------------------------------------------------*/
#include "BSTstd.h"
#include <iostream>
using namespace std;

/* Constructor */
BSTstd::BSTstd()
{
	root = NULL;
}

/* Destructor */
BSTstd::~BSTstd()
{
	if (root != NULL) TreeNode::deleteTree(root);
}

/* Insert an element into the BST */
void BSTstd::insert(ElementType element)
{
	TreeNode* newptr = new TreeNode(element);

	if (root == NULL)
	{
		root = newptr;
	}
	else
	{
		TreeNode* p = root;
		TreeNode* parent = NULL;
		while ((p != NULL) && (p->data != element)) //find the right location for the new node
		{
			if (element < p->data)
			{
				parent = p;
				p = p->left;
			}
			else
			{
				parent = p;
				p = p->right;
			}
		}

		if (p == NULL) //if the element is not in the BST
		{
			if (element < parent->data)
				parent->left = newptr;
			else
				parent->right = newptr;
		}
		else
			cout << "node duplicate!" << endl;
	}
    
    
}

/* Remove an element from the BST */
void BSTstd::remove(ElementType element)
{
	TreeNode* p = root;
	TreeNode* parent = NULL;
	
	if (root == NULL) // No nodes in the tree
	{
		cout << "tree is empty, unable to remove element" << endl;
		return;
	}

	while ((p != NULL) && (p->data != element)) //find the correct location for the new node
	{
		if (element < p->data)
		{
			parent = p;
			p = p->left;
		}
		else
		{
			parent = p;
			p = p->right;
		}
	}

	if (p == NULL)  // Element not found
	{
		cout << "Unable to find element.  It will not be removed" << endl;
	} 
	else             // Element was found, so let's remove it
	{
		if (p->left == NULL && p->right == NULL) //case 1
		{
			if (p == root) {  // node is root node
				root = NULL;
			}
			else
			{
				if (element < parent->data)
					parent->left = NULL;
				else
					parent->right = NULL;
			}
			delete p;
		}
		else if (p->left != NULL && p->right == NULL) //case 2
		{
			if (p == root)   // node is root nodes
			{
				root = p->left;
			}
			else
			{
				if (element < parent->data)
					parent->left = p->left;
				else
					parent->right = p->left;
			}
			delete p;
		}
		else if (p->left == NULL && p->right != NULL) //case 2
		{
			if (p == root)  // node is root node
			{
				root = p->right;
			}
			else
			{
				if (element < parent->data)
					parent->left = p->right;
				else
					parent->right = p->right;
			}
			delete p;
		}
		else //case 3 - neither child is NULL
		{
			int min_of_right_child = findmin(p->right);
			remove(min_of_right_child);
			p->data = min_of_right_child;
		}
	}
}

/* Find the minimum value recursively starting from a specific node */
int BSTstd::findmin(TreeNode* p)
{
	while (p->left != NULL)
		p = p->left;
	return p->data;
}

/* Find the minimum value for the entire tree */
int BSTstd::findmin()
{
	return findmin(root);
}

/* Find the maximum value recursivly starting from a specific node */
int BSTstd::findmax(TreeNode* p)
{
	while (p->right != NULL)
		p = p->right;
	return p->data;
}

/* Find the minimum value for the entire tree */
int BSTstd::findmax()
{
	return findmax(root);
}

/* Traverse the tree recursively from a node using inorder */
void BSTstd::inorder(TreeNode* p)
{
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->data << " ";
		inorder(p->right);
	}

}

/* Traverse the tree inorder */
void BSTstd::inorder()
{
	inorder(root);
}

/* Display output of various traversal methods */
void BSTstd::traversal()
{
	cout << " Min value: " << findmin() << endl;
	cout << " Max value: " << findmax() << endl;
	cout << " Inorder: ";
    inorder();
    cout << endl <<" Preorder: ";
    preorder();
    cout << endl <<" Preorder: ";
    postorder();
	cout << endl;
	cout << endl;

}

/* Traverse the tree preorder */
void BSTstd::preorder()
{
    preorder(root);
}
void  BSTstd::preorder(TreeNode* p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}

/* Traverse the tree posorder */
void BSTstd::postorder()
{
    postorder(root);
}
void BSTstd::postorder(TreeNode* p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }
}
/* Search for an element in the binary search tree */
/* Search for an element in the binary search tree */
bool BSTstd::search(ElementType element)
{
    if(root == NULL)
    {
    element = search(element);
        return true;
    }
    else
    {
        return false;
    }
}
