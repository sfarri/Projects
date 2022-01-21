//
//  person.h
//  ponder13
//
//  Created by Pootis on 12/11/17.
//  Copyright © 2017 Pootis. All rights reserved.
//
#ifndef person_h
#define person_h

#include <string>
using namespace std;

/*****************************************************************
 * Header:
 *    Person
 * Summary:
 *    This will have everything about the person, including the
 *    operators necessary to compare Persons and sort them in the list.
 *
 * Author
 *    Seth Farr
 *****************************************************************/
class Person
{
public:
   Person() : ID(""), first(""), last(""), dob("") {};
   Person(string f, string l, string d, string i) : first(f), last(l), dob(d), ID(i) {};
   ~Person()               { clear();                                   }
   string getID()          { return this->ID;                           }
   string getFirst()       { return this->first;                        }
   string getName()        { return this->first + " " + last;           }
   string getLast()        { return this->last;                         }
   string getDOB()         { return this->dob;                          }
   void setID(string i)    { this->ID = i;                              }
   void setFirst(string f) { this->first = f;                           }
   void setLast(string l)  { this->last = l;                            }
   void setDOB(string d)   { this->dob = d;                             }
   void clear()            { ID = ""; first = ""; last = ""; dob = "";  }
   Person & operator = (const Person & rhs);
   bool operator == (const Person & rhs);
   bool operator < (const Person & rhs);
   bool operator <= (const Person & rhs);
   bool operator > (const Person & rhs);
private:
   string ID;
   string first;
   string last;
   string dob;
};
/***************************************************
 * Person : Assignment Operator
 * Take in a Person and copy into a new Person
 ***************************************************/
Person & Person :: operator = (const Person & rhs)
{
   this->ID = rhs.ID;
   this->first = rhs.first;
   this->last = rhs.last;
   this->dob = rhs.dob;
   return *this;
}

/***************************************************
 * Person : Comparison Operator
 * find out if two Persons are identical.
 ***************************************************/
bool Person :: operator == (const Person & rhs)
{
   if (this->ID == rhs.ID && this->first == rhs.first && this->last == rhs.last && this->dob == rhs.dob)
      return true;
   else
      return false;
}

/***************************************************
 * Person : Less-than operator
 * Take in a Person and compare it to this, find out
 * which comes first.
 ***************************************************/
bool Person :: operator < (const Person & rhs)
{
   string lhsFirst = this->first;
   string lhsLast = this->last;
   string rhsFirst = rhs.first;
   string rhsLast = rhs.last;
   for (int i = 0; i < lhsFirst.length(); i++)
   {
      lhsFirst[i] = tolower(lhsFirst[i]);
   }
   for (int i = 0; i < lhsLast.length(); i++)
   {
      lhsLast[i] = tolower(lhsLast[i]);
   }
   for (int i = 0; i < rhsFirst.length(); i++)
   {
      rhsFirst[i] = tolower(rhsFirst[i]);
   }
   for (int i = 0; i < rhsLast.length(); i++)
   {
      rhsLast[i] = tolower(rhsLast[i]);
   }
   if (lhsFirst == "job" && rhsFirst == "job")
   {
      return true;
   }
   if (lhsLast == "" && rhsLast == "")
   {
      if (lhsFirst == rhsFirst)
      {
         if (this->dob.length() >= 4 && rhs.dob.length() >= 4)
         {
            if (this->dob.substr(dob.length() - 4, 4) < rhs.dob.substr(dob.length() - 4, 4))
            {
               return true;
            }
            else
            {
               return false;
            }
         }
         else
         {
            return false;
         }
      }
      else if (lhsFirst < rhsFirst)
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   else if (lhsLast == rhsLast)
   {
      if (lhsFirst == rhsFirst)
      {
         if (this->dob.length() >= 4 && rhs.dob.length() >= 4)
         {
            if (this->dob.substr(dob.length() - 4, 4) < rhs.dob.substr(dob.length() - 4, 4))
            {
               return true;
            }
            else
            {
               return false;
            }
         }
         else
         {
            return false;
         }
      }
      else if (lhsFirst < rhsFirst)
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   else if (lhsLast < rhsLast)
   {
      return true;
   }
   else
   {
      return false;
   }
}


/***************************************************
 * Person : Greater-than operator
 * Take in a Person and compare it to this, find out
 * which comes first.
 ***************************************************/
bool Person :: operator > (const Person & rhs)
{
   string lhsFirst = this->first;
   string lhsLast = this->last;
   string rhsFirst = rhs.first;
   string rhsLast = rhs.last;
   for(int i = 0; i < lhsFirst.length(); i++)
   {
      lhsFirst[i] = tolower(lhsFirst[i]);
   }
   for(int i = 0; i < lhsLast.length(); i++)
   {
      lhsLast[i] = tolower(lhsLast[i]);
   }
   for(int i = 0; i < rhsFirst.length(); i++)
   {
      rhsFirst[i] = tolower(rhsFirst[i]);
   }
   for(int i = 0; i < rhsLast.length(); i++)
   {
      rhsLast[i] = tolower(rhsLast[i]);
   }
   
   if(lhsLast == rhsLast)
   {
      if(lhsLast == "" && rhsLast == "")
      {
         if(lhsFirst == rhsFirst)
         {
            if(this->dob.length() >= 4 && rhs.dob.length() >= 4 )
            {
               if(this->dob.substr(dob.length() - 5, 4) > rhs.dob.substr(dob.length() - 5, 4))
               {
                  return true;
               }
               else
               {
                  return false;
               }
            }
            else
            {
               return false;
            }
            
         }
         else if(lhsFirst > rhsFirst)
         {
            return true;
         }
         else
         {
            return false;
         }
      }
      else if (lhsLast == "")
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   else if(lhsLast == rhsLast)
   {
      if(lhsFirst == rhsFirst)
      {
         if(this->dob.length() > 4 && rhs.dob.length() > 4 )
         {
            if(this->dob.substr(dob.length() - 5, 4) > rhs.dob.substr(dob.length() - 5, 4))
            {
               return true;
            }
            else
            {
               return false;
            }
         }
         else
         {
            return this -> dob > rhs.dob;
         }
         
      }
      else if(lhsFirst > rhsFirst)
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   else if(lhsLast > rhsLast)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/***************************************************
 * Person : Less-than-or-equal-to operator
 * Take in a Person and compare it to this, find out
 * which comes first.
 ***************************************************/
bool Person :: operator <= (const Person & rhs)
{
   string lhsFirst = this->first;
   string lhsLast = this->last;
   string rhsFirst = rhs.first;
   string rhsLast = rhs.last;
   for(int i = 0; i < lhsFirst.length(); i++)
   {
      lhsFirst[i] = tolower(lhsFirst[i]);
   }
   for(int i = 0; i < lhsLast.length(); i++)
   {
      lhsLast[i] = tolower(lhsLast[i]);
   }
   for(int i = 0; i < rhsFirst.length(); i++)
   {
      rhsFirst[i] = tolower(rhsFirst[i]);
   }
   for(int i = 0; i < rhsLast.length(); i++)
   {
      rhsLast[i] = tolower(rhsLast[i]);
   }
   
   if(lhsLast == rhsLast)
   {
      if(lhsLast == "" && rhsLast == "")
      {
         if(lhsFirst == rhsFirst)
         {
            if(this->dob.length() >= 4 && rhs.dob.length() >= 4 )
            {
               if(this->dob.substr(dob.length() - 5, 4) > rhs.dob.substr(dob.length() - 5, 4))
               {
                  return true;
               }
               else
               {
                  return false;
               }
            }
            else
            {
               return false;
            }
            
         }
         else if(lhsFirst > rhsFirst)
         {
            return true;
         }
         else
         {
            return false;
         }
      }
      else if (lhsLast == "")
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   else if(lhsLast == rhsLast)
   {
      if(lhsFirst == rhsFirst)
      {
         if(this->dob.length() > 4 && rhs.dob.length() > 4 )
         {
            if(this->dob.substr(dob.length() - 5, 4) > rhs.dob.substr(dob.length() - 5, 4))
            {
               return true;
            }
            else
            {
               return false;
            }
         }
         else
         {
            return this -> dob > rhs.dob;
         }
         
      }
      else if(lhsFirst > rhsFirst)
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   else if(lhsLast > rhsLast)
   {
      return true;
   }
   else
   {
      return false;
   }
}


/***************************************************
 * Person : Display
 * Take in a Person and display its contents
 ***************************************************/
ostream & operator << (ostream & out, Person &rhs)
{
   if(rhs.getFirst() != "")
   {
      out << rhs.getFirst();
      if(rhs.getLast() != "")
      {
         out << " " << rhs.getLast();
      }
      if(rhs.getDOB() != "")
      {
         out << ", b. " << rhs.getDOB();
      }
   }
   else if(rhs.getLast() != "")
   {
      out << rhs.getLast();
      if(rhs.getDOB() != "")
      {
         out << " b. " << rhs.getDOB();
      }
   }
   out << endl;
   return out;
}

#endif /* person_h */
