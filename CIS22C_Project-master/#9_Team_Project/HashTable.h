/*------------------------------------------------------------------------------------------
 
 File Name: HashTable.h
 
 CIS 22C: Course Project: De Anza Courses
 Group #1
 Name: Maryna Kapurova
 
 Program purpose and function: organizing information from an input file into hashtable
 for the purpose of fast retrieval of the information: O(1) or O(n/k) runtime
 
 Program inputs: 
 Input File: DBClass.txt
 Program ourputs:
 Information retrieved from the hashtable
 
 Variables used: crn
------------------------------------------------------------------------------------------*/

#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <string>
#include <iostream>
#include <cstdlib>
#include "Class.h"
using namespace std;

template <class hashdata>
class HashTable {
private:
    
    struct Node
    {
        hashdata data;
        
        Node* next;
        Node(): next(NULL){}
        Node(hashdata data): next(NULL), data(data){}
    };
    
    
    typedef struct Node* Nodeptr;
    
    static const int TABLE_SIZE = 31;
    Nodeptr Table[TABLE_SIZE];
    
    
public:
    HashTable();
    
    ~HashTable();
    
    HashTable(const HashTable &table);
    // Copy Constructor
    // Creates a deep copy
    
    int hash(string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //the ASCII values of each character % the table size
    
    void addItem(hashdata data);
    //inserts a new item into the table
    //calls the hash function on the key title to determine the correct bucket
    
    void removeItem(hashdata CRN);
    //removes the item with the given key
    
    void printTable() const;
    //prints the first item of each bucket
    //includes the number of items stored at that bucket
    
    void printBucket(int index);
    //Prints all items stored at a particular bucket
    
    int findCRN(hashdata CRN);
    //Searches for an title in the table using the key
    //Returns the index under which the title is stored
    //returns -1 if the title is not found
    
    
    /* Inactive Funtion */
    //int numItemsAtIndex(int index);
    //Helper function to printTable
    //Counts the number of items in each bucket
};

/*---------------------------------------------------------------------
 Constructor
 --------------------------------------------------------------------*/
template <class hashdata>
HashTable<hashdata>::HashTable()
{
    for(int i = 0; i< TABLE_SIZE; i++)
        Table[i] = new Node();
}

/*---------------------------------------------------------------------
 Destructor
 --------------------------------------------------------------------*/
template <class hashdata>
HashTable<hashdata>::~HashTable()
{
    for(int i = 0 ; i< TABLE_SIZE; i++)
    {
        Nodeptr remove = Table[i];
        
        if(Table[i] == NULL)
        {}
        else
        {
            while(remove != NULL)
            {
                Nodeptr move2 = remove -> next;
                delete remove;
                remove = move2;
            }
            
            Table[i] = NULL;
        }
    }
}

/*---------------------------------------------------------------------
 Copy Constructor
 Creates a deep copy
 --------------------------------------------------------------------*/
template <class hashdata>
HashTable<hashdata>::HashTable(const HashTable &table)
{
    Nodeptr temp;
    for(int i = 0; i< table.TABLE_SIZE; i++)
    {
        Table[i] = new Node;
        temp = table.Table[i];
        if(table.Table[i]->data.getCRN() != "")
        {
            while(temp != NULL)
            {
                addItem(temp->data);
                temp = temp->next;
            }
        }
    }
}

/*---------------------------------------------------------------------
 Hash Function
 returns the hash value for the given key
 uses pseudorandom (prime numbers) for efficient distribution
 Input: key (value)
 Output: index#/bucket#
 --------------------------------------------------------------------*/

template <class hashdata>
int HashTable<hashdata>::hash(string key)
{
    int a = 17;
    int b = 7;
    int temp = 0;
    int index = 0;
    
    for(int i = 0; i < key.length(); i++)
        temp += key[i];
    
    index = (a * temp +b) % TABLE_SIZE; // pseudorandom
 
    return index;
    

}

/*---------------------------------------------------------------------
 addItem
 Inserts a new item into the table
 Calls the hash function on the key title to determine the correct bucket
 Input: data (new item)
 Output: data inserted at the bucket
 --------------------------------------------------------------------*/

template <class hashdata>
void HashTable<hashdata>::addItem(hashdata data)
{
    Nodeptr temp = new Node;
    
    temp->data = data;
    
    int index = hash(data.getCRN());
    
    if(Table[index]->data.getCRN() == "")
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
 printTable
 Prints the first item of each bucket
 Includes the number of items stored at that bucket
 Input: -
 Output: the first item of each bucket printed, including the number of items stored at that bucket
 --------------------------------------------------------------------*/
template <class hashdata>
void HashTable<hashdata>::printTable() const
{
    int count = 0;
    
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "-------------------------------------------" << endl;
        cout << "Index " << i << ":" << endl;
        Nodeptr move = Table[i];
        
        if(move == NULL)
            cout << "bucket is null" << endl;
        
        if (move->data.getCRN() == "")
            cout << "printBucket : No data" << endl;
        
        else
        {
            while(move != NULL)
            {
                move->data.print();
                move = move->next;
                count ++;
            }
        }
    }
    cout << "-------------------------------------------" << endl;
    cout << "Total : " << count << endl;

}

/*---------------------------------------------------------------------
 numItemsAtIndex
 Helper function to printTable
 Counts the number of items in each bucket
 Input: index#/bucket#
 Output: number of items stored at index/bucket
 --------------------------------------------------------------------*/
/*
 template <class hashdata>
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
 */

/*---------------------------------------------------------------------
 printBucket
 Prints all items stored at a particular bucket
 Input: index#/bucket#
 Output: all items stored at the index/bucket
 --------------------------------------------------------------------*/
template <class hashdata>
void HashTable<hashdata>::printBucket(int index)
{
    
    if(index >= TABLE_SIZE)
    {
        cout << "printBucket : index is larger than Table Size" << endl;
        return;
    }
    
    Nodeptr move = Table[index];
    
    if (move->data.getCRN() == "")
        cout << "printBucket : No data" << endl;
    else
    {
        cout << "-------------------------------------------" << endl;
        cout << "Index " << index << ":" << endl;
        
        while(move != NULL)
        {
            move->data.print();
            move = move->next;
        }
    }
}

/*---------------------------------------------------------------------
 findCRN
 Searches for an title in the table using the key
 Returns the index under which the title is stored
 returns -1 if the title is not found
 Input: CRN#
 Output: index#/bucket# or -1 (not found)
 --------------------------------------------------------------------*/

template <class hashdata>
int HashTable<hashdata>::findCRN(hashdata CRN)
{
    int key = hash(CRN.getCRN());
    
    Nodeptr move = Table[key];
    
    while (move != NULL)
    {
        if (move -> data.getCRN() == CRN.getCRN())
        {
            move->data.displayCategory();
            move->data.print();
            return key;
        }
        move = move -> next;
        
        if(move == NULL)
        {
            cout << "findCRN : CRN is not stored in the table" << endl;
            return -1;
        }
    }
    cout << "findCRN : CRN is not stored in the table" << endl;
    return -1;
}


/*---------------------------------------------------------------------
 removeItem
 Removes the item with the given key
 Input: CRN#
 Output: removed item; size--
 --------------------------------------------------------------------*/

template <class hashdata>
void HashTable<hashdata>::removeItem(hashdata CRN)
{
    int key = hash(CRN.getCRN());
    Nodeptr move = Table[key];
    Nodeptr move2 = Table[key];
    if (move->data.getCRN() == CRN.getCRN())
    {
        Table[key] = move->next;
        delete move;
        cout << CRN.getCRN() << " is deleted from the table" << endl;
        return;
    }
    else
    {
        move = move -> next;
        while(move != NULL)
        {
            if(move->data.getCRN() == CRN.getCRN())
            {
                move2 -> next = move -> next;
                delete move;
                cout << CRN.getCRN() << " is deleted from the table" << endl;
                return;
            }
            move = move -> next;
            move2 = move2 -> next;
        }
    }
    cout << "removeItem : Course is not stored in the table" << endl;
}

#endif /* HASHTABLE_H_ */