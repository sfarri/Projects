#ifndef BNODE_H
#define BNODE_H

#include <iostream> 
#include <cassert>
using namespace std;

/*****************************************************************
 * BINARY NODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <class T>
class Node
{
public:
//Constructors
   //Default
   Node() : pFather(NULL), pMother(NULL), pChild(NULL), pNext(NULL), pPrev(NULL) {};
   //Nondefault
   Node(T t) { this->data = t; pFather = NULL; pMother = NULL; pChild = NULL; pNext = NULL; }
   //Destructor
   ~Node() { pFather = NULL; pMother = NULL; pChild = NULL; pNext = NULL, pPrev = NULL; }
   
   // since no validation is done, everything is public
   Node <T> * pFather;
   Node <T> * pMother;
   Node <T> * pChild;
   Node <T> * pNext;
   Node <T> * pPrev;

   // the data of unknown type: cannot validate so is public
   T data;
};

#endif // BNODE_H
