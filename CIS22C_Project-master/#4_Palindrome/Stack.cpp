//
//  Stack.cpp
//  Stack
//
//  Created by HOWON KIM on 1/20/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include "Stack.h"
#include <cstdlib>
#include <iostream>
using namespace std;

/********************************************************************************
 * Constructor & Destructor
 ********************************************************************************/

Stack::Stack(): size(0), top(NULL){};

Stack::~Stack()
{
    Nodeptr current = new Node;
    Nodeptr next = new Node;
    
    current = top;
    
    while(current != NULL)
    {
        next = current -> nextnode;
        delete current;
        current = next;
    }
}

Stack::Stack(const Stack &stack):size(stack.size)
{

    if(stack.top == NULL)
    {
        top = NULL;
    }
    
    else
    {
        top = stack.top;
        Nodeptr temp1 = top -> nextnode;
        Nodeptr temp2 = stack.top -> nextnode;
        
        while(temp2 != NULL)
        {
            temp1 = temp2;
            temp1 = temp1 -> nextnode;
            temp2 = temp2 -> nextnode;
        }
    }
}


/********************************************************************************
 * removes an element from the top of the stack
 * postcondition: an element has been removed from the top of the stack
 ********************************************************************************/

void Stack::pop()
{
    if (top == NULL)
    {
        cout << "pop() : stack is empty" << endl;
        exit(-1);
    }
    else if (size == 1)
    {
        delete top;
        top = NULL;
        size = 0;
    }
    else
    {
        Nodeptr temp = new Node;
        temp = top -> nextnode;
        
        delete top;
        top = temp;
        
        size --;
    }
}

/********************************************************************************
 * adds an element to the top of the stack
 * postcondition: an element added to the top of the stack
 ********************************************************************************/

void Stack::push(string content)
{
    Nodeptr newNode = new Node;
    newNode -> data = content;
    
    if(top==NULL)
    {
        top = newNode;
        size = 1;
    }
    else
    {
        newNode -> nextnode = top;
        top = newNode;
        ++size;
    }
}



/**accessors*/

/********************************************************************************
 * returns the element at the top of the stack
 * precondition: the stack is not empty
 ********************************************************************************/

string Stack::get_top()
{
    if(top==NULL)
    {
        cout << "get_top() : Stack is empty" << endl;
        exit(-1);
    }
    else
        return top -> data;
}



/********************************************************************************
 * returns the size of the stack
 ********************************************************************************/

int Stack::get_size()
{
    return size;
}

        


/**additional stack operations*/

/********************************************************************************
 * prints the elements in the stack in a programmer-specified format to stdout
 ********************************************************************************/

void Stack::print()
{
    if(top==NULL)
    {
        cout << "print() : Stack is empty" << endl;
        exit(-1);
    }
    else
    {
        Nodeptr temp = top;
        
        while(temp!=NULL)
        {
            cout << temp -> data << " ";
            temp = temp -> nextnode;
        }
        
        cout << endl;
    }
}


/********************************************************************************
 * returns whether this stack is equal to another stack
 ********************************************************************************/

bool Stack::operator==(const Stack &stack){
    Nodeptr temp1 = top;
    Nodeptr temp2 = stack.top;
    
    int size1 = size;
    int size2 = stack.size;
    
    if(temp1 == NULL && temp2 == NULL)
    {
        return true;
    }
    else if(temp1 == NULL || temp2 == NULL)
    {
        return false;
    }
    else if (size1 != size2)
    {
        return false;
    }
    else
    {
        while(temp1 != NULL)
        {
            if(temp1->data != temp2->data)
            {
                return false;
            }
            temp1 = temp1 -> nextnode;
            temp2 = temp2 -> nextnode;
        }
        return true;
    }
    
}



