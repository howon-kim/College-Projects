//
//  CList.h
//  Circular_Linked_List
//
//  Created by HOWON KIM on 1/25/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//


#ifndef CList_h
#define CList_h
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>
using namespace std;

template <class listitem>
class List
{
    
private:
    
    struct Node
    {
        listitem data;
        Node* nextnode;
        
        Node(): nextnode(NULL){} //define our own default constructor
        Node(listitem newdata): data(newdata), nextnode(NULL){}
    };
    
    
    
    typedef struct Node* Nodeptr;
    
    
    Nodeptr first;
    Nodeptr last;
    Nodeptr current; //the iterator
    
    int size;
    
    
    
public:
    
    /**Constructors and Destructors*/
    
    List();
    //Default constructor; initializes and empty list
    //Postcondition: the linked list is created; its data is 0, first, last and current are NULL
    
    //~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: Memory for the list is deallocated
    
    
    /**Accessors*/
    
    bool is_empty();
    //Determines whether a list is empty.
    
    listitem get_first();
    //Returns the first element in the list
    //Precondition: the list cannot be empty
    
    bool off_end();
    //Determines if the iterator is off the end of the list
    
    int get_size();
    //Returns the length of the list
    
    /**Manipulation Procedures*/
    
    void begin();
    //Moves the iterator to point to the first element in the list
    //If the list is empty, the iterator remains NULL
    //Postcondition: the iterator will be pointing to the first element in the list
    
    
    void remove_first();
    //Removes the value of the first element in the list
    //Precondition: size != 0
    //Postcondition: the first element is removed from the list
    
    void remove_last();
    //Removes the value of the last element in the list
    //Precondition: size != 0
    //Postcondition: the last element is removed from the list
    
    void insert_first(listitem data);
    //Inserts a new element as the firstt of the list
    //If the list is empty, the new element becomes both first and last
    //Postcondition: the new element is inserted at the first of the list
    
    void insert_last(listitem data);
    //Inserts a new element as the last of the list
    //If the list is empty, the new element becomes both first and last
    //Postcondition: the new element is inserted at the last of the list
    
    
    
    void scroll();
    //Moves the iterator forward by one element in the list
    //Has no effect if the iterator is offend or the list is empty
    //Postcondition: the iterator is moved forward by one node in the list
    
    
    /**Additional List Operations*/
    
    
    void print();
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    
};
/**Constructor and Destructor*/
template <class listitem>
List<listitem>::List(): first(NULL), last(NULL), current(NULL), size(0) {}


//Add destructor here

/**Access Functions*/
template <class listitem>
listitem List<listitem>::get_first()
{
    if (size != 0)
        return first->data;
    else {
        cout << "get_first(): List is empty" << endl;
        exit(-1);
    }
}


template <class listitem>
int List<listitem>::get_size()
{
    return size;
}

/**Manipulation Procedures*/

template <class listitem>
void List<listitem>::scroll()
{
    if (current!=NULL)
        current = current->nextnode;
    cout << "scroll(): Current is off end" << endl;
}

template <class listitem>
void List<listitem>::begin()
{
    current = first;
}

//Add remove_first and insert_first here
template <class listitem>
void List<listitem>::insert_first(listitem data)
{
    Nodeptr newFirst = new Node(data);
    if (size == 0)
    {
        first = last = newFirst;
        
        last->nextnode = first;
        
    }
    else
    {
        newFirst->nextnode = first;
        last->nextnode = newFirst;
        first = newFirst;
    }
    size++;
}

template <class listitem>
void List<listitem>::remove_first()
{
    if (size == 0)
    {
        
        cout << "remove_first(): List is empty" << endl;
        
        return;
        
        
    }
    
    else if (size == 1)
        
    {
        
        last->nextnode = NULL;
        
        first = last = NULL;
        
    }
    
    else
    {
        Nodeptr temp = first;
        first = first->nextnode;
        last->nextnode = first;
        delete temp;
    }
    size--;
}


//Add remove_last and insert_last here
template <class listitem>
void List<listitem>::insert_last(listitem data)
{
    Nodeptr newLast = new Node(data);
    if (size == 0)
    {
        first = last = newLast;
        
        last->nextnode = first;
        
    }
    else
    {
        newLast->nextnode = first;
        last->nextnode = newLast;
        last = newLast;
    }
    size++;
}

template <class listitem>
void List<listitem>::remove_last()
{
    if (size == 0)
    {
        
        cout << "remove_last(): List is empty" << endl;
        
        return;
        
        
    }
    
    else if (size == 1)
        
    {
        
        last->nextnode = NULL;
        
        first = last = NULL;
        
    }
    
    else
    {
        Nodeptr temp = first;
        while(temp -> nextnode != last)
            temp = temp -> nextnode;
        temp->nextnode = first;
        delete last;
        last = temp;
    }
    
    size--;
}


/**Additional List Operations*/

template <class listitem>
void List<listitem>::print()
{
    if(size == 0)
    {
        cout << " ";
    }
    else
    {
        current = first;
        //cout << current->data;
        while (current!= last) //changed NULL to last
        {
            cout << current->data << " ";
            current = current->nextnode;
        }
        cout << current->data << endl; //print last data separately from loop
    }
}

#endif /* CList_h */
