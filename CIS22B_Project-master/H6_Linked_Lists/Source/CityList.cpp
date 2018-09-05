// Implementation file for the CityList class
#include <iostream>  // For cout  and NULL
#include <iomanip>
#include "CityList.h"
using namespace std;

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void CityList::displayList() const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      cout << setw(10) << nodePtr->data.state;
      cout << setw(10) << nodePtr->data.year;
      cout << setw(20) << nodePtr->data.city << endl;

      // Move to the next node.
      nodePtr = nodePtr->next;
   }
}
 

//**************************************************
// The insertNode function inserts a node with     *
// data copied to its data member.                 *
//**************************************************

void CityList::insertNode(Data dataIn)
{
   ListNode *newNode;             // A new node
   ListNode *nodePtr;             // To traverse the list
   ListNode *previousNode = NULL; // The previous node

   // Allocate a new node and store num there.
   newNode = new ListNode;

   newNode->data.state = dataIn.state;
   newNode->data.year = dataIn.year;
   newNode->data.city = dataIn.city;

   // If there are no nodes in the list
   // make newNode the first node
    
   if (!head)
   {
      head = newNode;
      newNode->next = NULL;
   }
   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to NULL.
      previousNode = NULL;

      // Skip all nodes whose value is less than num.
      while (nodePtr != NULL && nodePtr->data.city < dataIn.city)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == NULL)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise insert after the previous node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}

//**************************************************
// The searchList function searches for a node     *
// with city as its value. The node, if found, is  *
// print from the list.                            *
//**************************************************

void CityList::searchList(string city) const
{
    ListNode *nodePtr;  // To move through the list
    
    // Position nodePtr at the head of the list.
    nodePtr = head;
    
    // While nodePtr points to a node and
    // whose value member is not equal to city traverse
    // the list.
    while (nodePtr != NULL && nodePtr->data.city!=city)
    {
        // Move to the next node.
        nodePtr = nodePtr->next;
    }
    
    // Display the value in this node.
    if(nodePtr != NULL && nodePtr->data.city==city)
    {
        cout << endl << left << setw(10) << "State" << setw(10) << "Year" << setw(20) << "City" << endl;
        cout << setw(10) << "-----" << setw(10) << "-----" << setw(20) << "----------" << endl;
        cout << setw(10) << nodePtr->data.state;
        cout << setw(10) << nodePtr->data.year;
        cout << setw(20) << nodePtr->data.city << endl;
    }
    
    // Display error if there is no result in this node
    else
    {
        cout << "<" << city << ">" << " was not found" << endl;
    }
    
    
}
//**************************************************
// The deleteNode function searches for a node     *
// with city as its value. The node, if found, is  *
// deleted from the list and from memory.          *
//**************************************************

void CityList::deleteNode(string city)
{
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return;

   // Determine if the first node is the one.
   //if (head->value == num)
   if (head->data.city == city)
   {
      cout << endl << left << setw(10) << "State" << setw(10) << "Year" << setw(20) << "City" << endl;
      cout << setw(10) << "-----" << setw(10) << "-----" << setw(20) << "----------" << endl;
      cout << setw(10) << head->data.state;
      cout << setw(10) << head->data.year;
      cout << setw(20) << head->data.city << endl;
      cout << "** Delete the " << city << " **" << endl;
       
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
    
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to city.
      while (nodePtr != NULL && nodePtr->data.city != city)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list,
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         cout << endl << left << setw(10) << "State" << setw(10) << "Year" << setw(20) << "City" << endl;
         cout << setw(10) << "-----" << setw(10) << "-----" << setw(20) << "----------" << endl;
         cout << setw(10) << nodePtr->data.state;
         cout << setw(10) << nodePtr->data.year;
         cout << setw(20) << nodePtr->data.city << endl;
         cout << "** Delete the " << city << " **" << endl;

         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
       
       // Display error if there is no result in this node
      else
      {
          cout << "<" << city << ">" << " was not found" << endl;
      }
   }
}


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

CityList::~CityList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != NULL)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}
