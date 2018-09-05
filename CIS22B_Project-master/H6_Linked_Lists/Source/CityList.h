// Specification file for the CityList class
#ifndef CITYLIST_H
#define CITYLIST_H
#include <iostream>
using namespace std;

struct Data
{
    string state;
    int year;
    string city;
    // other fields could be added here
};

class CityList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      //double value;           // The value in this node
       Data data;
       ListNode *next;  // To point to the next node
   };

   ListNode *head;            // List head pointer

public:
    
   // Constructor
   CityList()
      { head = NULL; }

   // Destructor
   ~CityList();

   // Linked list operations
   void insertNode(Data);   //void insertNode(double);
   void deleteNode(string);
   void searchList(string) const;
   void displayList() const;

};

#endif
