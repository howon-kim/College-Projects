//
//  HashTable.cpp
//  Hash_Table
//
//  Created by HOWON KIM on 2/25/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include "HashTable.h"

/*---------------------------------------------------------------------
 Constructor
 --------------------------------------------------------------------*/

HashTable::HashTable()
{
    for(int i = 0; i< TABLE_SIZE; i++)
        Table[i] = new Node;
}


/*---------------------------------------------------------------------
 Destructor
 --------------------------------------------------------------------*/

HashTable::~HashTable()
{
    for(int i = 0 ; i< TABLE_SIZE; i++)
    {
        Nodeptr remove = Table[i];
        while(remove != NULL)
        {
            Nodeptr move2 = remove -> next;
            delete remove;
            remove = move2;
        }
        
        Table[i] = NULL;
    }
}


/*---------------------------------------------------------------------
 Hash Function
 --------------------------------------------------------------------*/

int HashTable::hash(string key)
{
    int index, sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    index = sum % TABLE_SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
    return index;
}

/*---------------------------------------------------------------------
 Inserts a new item into the table
 Calls the hash function on the key title to determine the correct bucket
 --------------------------------------------------------------------*/

void HashTable::addItem(int crn, string course, string title, bool status, string days)
{
    //Nodeptr temp(crn,course,title,status,days);
    Nodeptr temp = new Node;
    
    temp -> crn = crn;
    temp -> course = course;
    temp -> title = title;
    temp -> status = status;
    temp -> days = days;
    
    int index = hash(course);
    
    if(Table[index]->course == "")
        Table[index] = temp;
    else
    {
        Nodeptr move = Table[index];
        
        while(move -> next != NULL)
            move = move -> next;
        
        move -> next = temp;
    }
}

/*---------------------------------------------------------------------
 Prints the first item of each bucket
 Includes the number of items stored at that bucket
 --------------------------------------------------------------------*/

void HashTable::printTable()
{    
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "-------------------------------------------" << endl;
        cout << "Index " << i << ":" << endl
             << "Course: " << Table[i] -> course << endl
             << "CRN: " << Table[i] -> crn << endl
             << "Title: " << Table[i] -> title << endl;
        
        if(Table[i]->status == 1)
            cout << "Status: Open" << endl;
        else
            cout << "Status: Full" << endl;
        
        cout << "Days: " << Table[i] -> days << endl;
        cout << "Number Values at this Index: " << numItemsAtIndex(i) << endl;
    }
}


/*---------------------------------------------------------------------
 Helper function to printTable
 Counts the number of items in each bucket
 --------------------------------------------------------------------*/

int HashTable::numItemsAtIndex(int index)
{
    int count = 0;
    Nodeptr temp = Table[index];
    
    if(temp->course == "")
        return count;
    
    while(temp != NULL)
    {
        count ++;
        temp = temp->next;
    }
    
    return count;
    
}


/*---------------------------------------------------------------------
 Prints all items stored at a particular bucket
 --------------------------------------------------------------------*/

void HashTable::printBucket(int index)
{
    
    if(index >= TABLE_SIZE)
    {
        cout << "printBucket : index is larger than Table Size" << endl;
        return;
    }
    
    Nodeptr move = Table[index];

    if (move->course == "")
        cout << "printBucket : No data" << endl;
    else
    {
        while(move != NULL)
        {
            cout << "-------------------------------------------" << endl;
            cout << "Index " << index << ":" << endl;

            cout << "Course: " << move -> course << endl
            << "CRN: " << move -> crn << endl
            << "Title: " << move -> title << endl;
            
            if(move->status == 1)
                cout << "Status: Open" << endl;
            else
                cout << "Status: Full" << endl;
            
            cout << "Days: " << move -> days << endl;
            cout << "Number Values at this Index: " << numItemsAtIndex(index) << endl;
            
            move = move->next;
        }
    }
}

/*---------------------------------------------------------------------
 Searches for an title in the table using the key
 Returns the index under which the title is stored
 returns -1 if the title is not found
 --------------------------------------------------------------------*/

int HashTable::findTitle(string course)
{
    int key = hash(course);
    
    Nodeptr move = Table[key];
    
    while (move != NULL)
    {
        if (move -> course == course)
        {
            cout << "Title : " << move -> title << endl;
            return key;
        }
        move = move -> next;
    }
    
    cout << "findTitle : Course is not stored in the table" << endl;
    return -1;
    
    
}

/*---------------------------------------------------------------------
 Removes the item with the given key
 --------------------------------------------------------------------*/

void HashTable::removeItem(string course)
{
    int key = hash(course);
    
    Nodeptr move = Table[key];
    Nodeptr move2 = Table[key];
    
    if (move->course == course)
    {
        Table[key] = move->next;
        delete move;
        cout << course << " is deleted from the table" << endl;
        return;
    }
    
    else
    {
        move = move -> next;
        while(move != NULL)
            
        {
            if(move -> course == course)
            {
                move2 -> next = move -> next;
                delete move;
                cout << course << " is deleted from the table" << endl;
                return;
            }
            move = move -> next;
            move2 = move2 -> next;
        }
    }
    
    cout << "removeItem : Course is not stored in the table" << endl;
}

