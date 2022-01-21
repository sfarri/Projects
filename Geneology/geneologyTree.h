//
//  geneologyTree.h
//  ponder13
//
//  Created by Pootis on 12/11/17.
//  Copyright © 2017 Pootis. All rights reserved.
//

#ifndef geneologyTree_h
#define geneologyTree_h

#include "superNode.h"
#include "person.h"

template<class T>
class ListIterator;

/*****************************************************************
 * Header:
 *    Person
 * Summary:
 *
 *
 * Author
 *    Seth Farr
 *****************************************************************/
template <class T>
class Geneology
{
public:
   //Default Constructor
   Geneology() : head(NULL), tail(NULL), root(NULL), numItems(0) {};
   //Destructor
   ~Geneology() { clear(); }
   
   void insert(const T & item);
   void clear();
   void nodeInsert(T data, Node<T> *& pNode, bool isGreater = false);
   ListIterator <T> find(string value);
   
   // add a node the left/right
   void addFather (ListIterator<T> child, string ID);
   void addMother (ListIterator<T> child, string ID);
   void setRoot();
   Node <T> * getRoot()      { return root;                  }
   
   // return an iterator to the beginning of the list
   ListIterator <T> begin()  { return ListIterator<T>(head); }
   ListIterator <T> rbegin() { return ListIterator<T>(tail); }
   // return an iterator to the end of the list
   ListIterator <T> end()    { return ListIterator<T>(NULL); }
   ListIterator <T> rend()   { return ListIterator<T>(NULL); }
   
private:
   int numItems;
   Node<T>*root;
   Node<T>*head;
   Node<T>*tail;
};

/*****************************************************************
 * Insert
 *
 *****************************************************************/
template <class T>
void Geneology<T> :: insert(const T & item)
{
   T temp = item;
   if (begin() == NULL)
   {
      numItems++;
      nodeInsert(item, head);
      return;
   }
   for (ListIterator<T> it = begin(); it != end(); it++)
   {
      if (temp < *it)
      {
         numItems++;
         nodeInsert(item, it.p);
         return;
      }
   }
   numItems++;
   nodeInsert(item, tail, true);
   return;
}

/*****************************************************************
 * NODEINSERT
 *
 *****************************************************************/
template <class T>
void Geneology<T> :: nodeInsert(T data, Node<T> *& pNode, bool isGreater)
{
   Node <T> *pNew = new Node<T>(data);
   
   //first item
   if (pNode == NULL)
   {
      pNew->pNext = NULL;
      pNew->pPrev = NULL;
      pNode = pNew;
      tail = pNode;
   }
   //insert to the back
   else if (isGreater == true)
   {
      pNew->pPrev = pNode;
      pNew->pNext = pNode->pNext;
      pNode->pNext = pNew;
      pNode = pNew;
   }
   else
   {
      pNew->pNext = pNode;
      pNew->pPrev = pNode->pPrev;
      if (pNode->pPrev != NULL)
      {
         pNode->pPrev->pNext = pNew;
      }
      else
         head = pNew;
      pNode->pPrev = pNew;
   }
}

/*****************************************************************
 * CLEAR
 * Set data to zero and pointers to NULL
 *****************************************************************/
template <class T>
void Geneology<T> :: clear()
{
   while(head)
   {
      Node<T>* pNew;
      pNew = head->pNext;
      head = NULL;
      delete head;
      head = pNew;
   }
   head = NULL;
   tail = NULL;
   root = NULL;
   numItems = 0;
}

/*****************************************************************
 * FIND
 * Take in an ID, search through the list, return the location
 *****************************************************************/
template <class T>
ListIterator<T> Geneology<T> :: find(string value)
{
   for (ListIterator<T> it = this->begin(); it != this->end(); it++)
   {
      Person temp = *it;
      if (temp.getID() == value)
      {
         return it;
      }
   }
   return NULL;
}

/*****************************************************************
 * ADDFATHER
 * Once the ID has been found, set the child's pointer.
 *****************************************************************/
template <class T>
void Geneology<T> :: addFather (ListIterator<T> child, string ID)
{
   ListIterator<T> father = find(ID);
   if (father == NULL)
      return;
   child.p->pFather = father.p;
   father.p->pChild = child.p;
}

/*****************************************************************
 * ADDMOTHER
 * Once the ID has been found, set the child's pointer.
 *****************************************************************/
template <class T>
void Geneology<T> :: addMother (ListIterator<T> child, string ID)
{
   ListIterator<T> mother = find(ID);
   if (mother == NULL)
      return;
   child.p->pMother = mother.p;
   mother.p->pChild = child.p;
}

/*****************************************************************
 * SETROOT
 * Set the root to the last child.
 *****************************************************************/
template <class T>
void Geneology<T> :: setRoot()
{
   ListIterator<T> root = find("1");
   this->root = root.p;
}

/**************************************************
 * LISTITERATOR
 * An iterator through List
 *************************************************/
template <class T>
class ListIterator
{
   friend class Geneology<T>;
public:
   // default constructor
   ListIterator() : p(NULL) {}
   
   //assignment operator
   ListIterator <T> & operator = (const ListIterator & rhs)
   {
      // attempt to allocate
      try
      {
         this->p = rhs.p;
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate buffer for List";
      }
      return *this;
   }
   
   // initialize to direct p to some item
   ListIterator(Node<T> * p) : p(p) {}
   
   // not equals operator
   bool operator != (const ListIterator & rhs) const
   {
      return rhs.p != this->p;
   }
   
   // equals operator
   bool operator == (const ListIterator & rhs) const
   {
      return rhs.p == this->p;
   }
   
   // dereference operator
   T & operator * ()
   {
      return p->data;
   }
   
   // prefix increment
   ListIterator <T> & operator ++ ()
   {
      p = p->pNext;
      return *this;
   }
   
   // postfix increment
   ListIterator <T> operator++(int postfix)
   {
      ListIterator tmp(*this);
      p = p->pNext;
      return tmp;
   }
   
   //prefix decrement
   ListIterator <T> operator -- ()
   {
      p = p->pPrev;
      return *this;
   }
   
   //postfix decrement
   ListIterator <T> operator--(int postfix)
   {
      ListIterator tmp(*this);
      p = p->pPrev;
      return tmp;
   }
   
private:
   Node<T> * p;
};

#endif /* geneologyTree_h */
