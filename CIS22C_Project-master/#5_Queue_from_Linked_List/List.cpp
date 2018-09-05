/**
 
 * Howon Kim
 
 * CIS 22C
 
 * List.cpp
 
 */

#include <iostream>
#include <cstdlib>
#include "List.h"
using namespace std;

/**Constructors and Destructors*/

List::List()
{
    first = last = current = NULL;
    size = NULL;
    
}


List::List(const List &list): size(list.size)
{
    if(list.first == NULL)
    {
        first = last = current = NULL;
    }
    else
    {
        first = new Node(list.first->data);
        Nodeptr temp = new Node;
        temp = list.first;
        current = first;
        
        while(temp->nextnode != NULL)
        {
            
            current->nextnode = new Node;
            current = current->nextnode;
            temp = temp->nextnode;
            current->data = temp->data;
            
        }
        
        last = current;
        
    }
}


List::~List()
{
    current = first;
    Nodeptr temp;
    while(current != NULL)
    {
        temp = current->nextnode;
        
        delete current;
        
        current = temp;
        
    }
}


/**Manipulation Procedures*/

void List::insert_last(int data)
{
    if (size == 0)
    {
        first = new Node(data);
        last = first;
    }
    else
    {
        Nodeptr newNode = new Node(data);
        last -> nextnode = newNode;
        last = newNode;
    }
    
    size ++;
    
}


void List::insert_first(int data)
{
    if (size==0)
    {
        first = new Node(data);
        last = first;
        
    }
    else
    {
        Nodeptr newNode = new Node(data);
        newNode->nextnode = first;
        first = newNode;
    }
    
    size++;
    
}


void List::remove_first()
{
    if (size==0)
    {
        cout << "remove_first: List is empty. Cannot remove first element." << endl;
    }
    else if (size==1)
    {
        delete first;
        first = last = current = NULL;
        
        size = 0;
        
    }
    else
    {
        Nodeptr temp = first; 
        first = first->nextnode;
        delete temp;
        
        size--;
        
    }
}

/**Accessors*/

bool List::is_empty()
{
    return (size==0);
}


int List::get_first()
{
    if (is_empty())
    {
        cout << "get_first(): que is empty. No first element" << endl;
        exit(-1);
        
    }
    else
    {
        return first -> data;
    }
}




void List::print()
{
    current = first;
    while (current != NULL)
    {
        
        
        cout << current->data << " ";
        current = current->nextnode;
    }
    cout << endl;

    
}



int List::get_size()
{
    return size;
}



bool List::operator==(const List& list)
{
    if(size != list.size)
        return false;
    
    current = first;
    Nodeptr temp = list.first;
    
    while(current != NULL)
    {
        if(current->data != temp->data)
            return false;
        
        temp = temp->nextnode;
        current = current->nextnode;
    }
    return true;
}