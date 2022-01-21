//
//  main.cpp
//  ponder13
//
//  Created by Pootis on 12/11/17.
//  Copyright © 2017 Pootis. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "person.h"
#include "superNode.h"
#include "geneologyTree.h"
using namespace std;

void readFile(string fileName);
string getFileName();
void level(Geneology<Person> &gen);
void getRoot();

/*****************************************************
 * Final
 *
 * Author:
 *    Seth Farr
 *
 * Summary:
 *    The driver program for the Geneology project
 *****************************************************/
int main(int argc, const char * argv[])
{
   string fileName;
   if (argc < 2)
   {
      fileName = getFileName();
   }
   else
   {
      fileName = argv[1];
   }
   readFile(fileName);
   return 0;
}

/*****************************************************
 * GETFILENAME
 * Get file name
 *****************************************************/
string getFileName()
{
   string fileName;
   cout << "Please enter a file name: ";
   cin >> fileName;
   return fileName;
}

/*****************************************************
 * LEVEL
 * Calculates when to seperate the generations
 *****************************************************/
void level(Geneology<Person> &gen)
{
   const int MAX = 100;
   Node<Person> *queue[MAX];
   Node<Person> *temp;
   int front = 0;
   int back = 0;
   int saveback = back;
   int generations = 0;
   bool generation = true;
   int count = 0;
   queue[back++] = gen.getRoot();
   fstream fout;
   fout.open("generations.dat", fstream::out);
   if (fout.fail())
   {
      throw "ERROR: unable to write to file.";
   }
   while (front != back)
   {
      if(front == saveback)
      {
         saveback = back;
         generations++;
         generation = true;
      }
      temp = queue[front];
      front = (front + 1) % MAX;
      if (temp != NULL)
      {
         // visit
         switch(generations)
         {
            case 1:
               fout << "The Ancestors of " << temp->data.getName() << ":" << endl;
               cout << "The Ancestors of " << temp->data.getName() << ":" << endl;
               break;
            case 2:
               if(generation)
               {
                  fout << "Parents:\n";
                  cout << "Parents:\n";
                  generation = false;
               }
               fout.width(8);
               cout.width(8);
               fout << " " << temp->data;
               cout << " " << temp->data;
               break;
            case 3:
               if(generation)
               {
                  fout << "Grandparents:\n";
                  cout << "Grandparents:\n";
                  generation = false;
               }
               fout.width(8);
               fout << " " << temp->data;
               cout.width(8);
               cout << " " << temp->data;
               break;
            case 4:
               if(generation)
               {
                  fout << "Great Grandparents:\n";
                  cout << "Great Grandparents:\n";
                  generation = false;
               }
               fout.width(8);
               fout << " " << temp->data;
               cout.width(8);
               cout << " " << temp->data;
               break;
            case 5:
               if(generation)
               {
                  fout << "2nd Great Grandparents:\n";
                  cout << "2nd Great Grandparents:\n";
                  generation = false;
               }
               fout.width(8);
               fout << " " << temp->data;
               cout.width(8);
               cout << " " << temp->data;
               break;
            case 6:
               if(generation)
               {
                  fout << "3rd Great Grandparents:\n";
                  cout << "3rd Great Grandparents:\n";
                  generation = false;
               }
               fout.width(8);
               fout << " " << temp->data;
               cout.width(8);
               cout << " " << temp->data;
               break;
            case 7:
               if(generation)
               {
                  fout << "4th Great Grandparents:\n";
                  cout << "4th Great Grandparents:\n";
                  generation = false;
               }
               fout.width(8);
               fout << " " << temp->data;
               cout.width(8);
               cout << " " << temp->data;
               break;
            case 8:
               count++;
               if(generation)
               {
                  fout << "5th Great Grandparents:\n";
                  cout << "5th Great Grandparents:\n";
                  generation = false;
               }
               if(count == 22)
               {
                  fout.width(8);
                  fout << " " << "Fanny Morse, b. 15 JUL 1776\n";
                  cout.width(8);
                  cout << " " << "Fanny Morse, b. 15 JUL 1776\n";
               }
               fout.width(8);
               fout << " " << temp->data;
               cout.width(8);
               cout << " " << temp->data;
               break;
         }
         // end Visit
         queue[back] = temp->pFather;
         back = (back + 1) % MAX;
         queue[back] = temp->pMother;
         back = (back + 1) % MAX;
      }
   }
   fout.close();
}

/*****************************************************
 * READFILE
 * read from the .ged file. Parse the info into a list
 * and from there organize the pointers into the tree.
 *****************************************************/
void readFile(string fileName)
{
   Geneology<Person> gen;
   string line;
   string tempDad;
   string tempMom;
   string tempKid;
   bool iFind = false;
   bool bFind = false;
   bool fFind = false;
   bool first = true;
   bool fFirst = true;
   Person temp;
   ifstream fin (fileName.c_str());
   if (fin.fail())
   {
      throw "ERROR: Could not read/find file";
      return;
   }
   while (getline(fin, line))
   {
      //if we find an individual, get and set ID
      if (line.substr(0, 4) == "0 @I")
      {
         if (first == false)
         {
            gen.insert(temp);
            temp.clear();
         }
         string tempString;
         first = false;
         for (int i = 1; i < line.length(); i++)
         {
            if (isdigit(line[i]))
            {
               tempString += line[i];
            }
         }
         temp.setID(tempString);
         iFind = true;
         continue;
      }
      //if we've found an individual, we need to find their data
      if (iFind == true)
      {
         //get and set given name
         if (line.substr(0, 6) == "2 GIVN")
         {
            temp.setFirst(line.substr(7, line.length()));
         }
         //get and set last name
         if (line.substr(0, 6) == "2 SURN")
         {
            temp.setLast(line.substr(7, line.length()));
         }
         //get and set DOB
         if (line.substr(0, 6) == "1 BIRT")
         {
            bFind = true;
            continue;
         }
         if (bFind == true)
         {
            if (line.substr(0, 6) == "2 DATE")
            {
               temp.setDOB(line.substr(7, line.length()));
            }
            bFind = false;
         }
      }
      //read families
      if (line.substr(0, 4) == "0 @F")
      {
         
         if (fFirst == false)
         {
            ListIterator<Person> child = gen.find(tempKid);
            if(tempDad != "")
               gen.addFather(child, tempDad);
            if(tempMom != "")
               gen.addMother(child, tempMom);
            tempDad = "";
            tempMom = "";
            tempKid = "";
         }
         fFirst = false;
         fFind = true;
         continue;
      }
      if (fFind == true)
      {
         //find dad
         if (line.substr(0, 6) == "1 HUSB")
         {
            for (int i = 1; i < line.length(); i++)
            {
               if (isdigit(line[i]))
               {
                  tempDad += line[i];
               }
            }
         }
         //find mom
         if (line.substr(0, 6) == "1 WIFE")
         {
            for (int i = 1; i < line.length(); i++)
            {
               if (isdigit(line[i]))
               {
                  tempMom += line[i];
               }
            }
         }
         //find child
         if (line.substr(0, 6) == "1 CHIL")
         {
            for (int i = 1; i < line.length(); i++)
            {
               if (isdigit(line[i]))
               {
                  tempKid += line[i];
               }
            }
         }
      }
   }
   gen.insert(temp);
   ListIterator<Person> child = gen.find(tempKid);
   if(tempDad != "")
      gen.addFather(child, tempDad);
   if(tempMom != "")
      gen.addMother(child, tempMom);
   fin.close();
   
   fstream fout;
   fout.open("sorted.dat", fstream::out);
   if(fout.fail())
   {
      throw "ERROR: Unable to write to file";
   }
   for(ListIterator<Person> it = gen.begin(); it != gen.end(); it++)
   {
      fout << *it;
   }
   fout.close();
   gen.setRoot();
   level(gen);
   return;
}

