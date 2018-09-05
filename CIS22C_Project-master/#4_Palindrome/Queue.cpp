//
//  Queue.cpp
//  Queue
//
//  Created by HOWON KIM on 1/13/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include "Queue.h"
using namespace std;


/********************************************************************************
 * Constructor & Destructor
 ********************************************************************************/

Queue::Queue():front(NULL),back(NULL),size(0){}

Queue::Queue(const Queue &queue):size(queue.size)
{
    {
        if(queue.front == NULL)
        {
            back = front = NULL;
        }
        
        else
        {
            front = new Node;
            front->data = queue.front->data;
            Nodeptr temp;
            temp = queue.front;
            Nodeptr qtemp = front; //create temporary iterator
            
            while(temp->nextnode != NULL)
            {
                
                qtemp->nextnode = new Node;
                qtemp = qtemp->nextnode;
                temp = temp->nextnode;
                qtemp->data = temp->data;
                
            }
            
            back = qtemp;
        }
    }
}

Queue::~Queue()
{
    Nodeptr temp = front;
    Nodeptr temp2 = front;
    while (temp != NULL)
    {
        temp = temp->nextnode;
        delete temp2;
        temp2 = temp;
    }
}


/********************************************************************************
 * removes an element from the front of the queue
 * precondition: the queue isn't empty
 * postcondition: an element has been removed from the front of the queue
 ********************************************************************************/

void Queue::dequeue(){
    if(is_empty())
    {
        cout << "dequeue() : size is 0" << endl;
        exit(-1);
    }
    else if(size ==1)
    {
        delete front;
        front = back =NULL;
        size = 0;
    }
    else
    {
        Nodeptr temp = front->nextnode;
        delete front;
        front = temp;
        size--;
    }
}


/********************************************************************************
 * adds an element to the back of the queue
 * postcondition: an element added to the back of the queue
 ********************************************************************************/

void Queue::enqueue(string data){
    
    Nodeptr newNode = new Node(data);
    
    if(is_empty())
    {
        back = newNode;
        front = back;
        size = 1;
    }
    else
    {
        back->nextnode = newNode;
        back = back->nextnode;
        size++;
    }
    
}

/********************************************************************************
 * returns the size of the queue
 ********************************************************************************/

int Queue::get_size(){
    return size;
}


/********************************************************************************
 * returns whether this queue is equal to another queue
 ********************************************************************************/

bool Queue::operator==(const Queue &queue){
    Node* temp1 = front;
    Node* temp2 = queue.front;
    
    int size1 = size;
    int size2 = queue.size;
    
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

/********************************************************************************
 * returns the element at the front of the queue
 * precondition: the queue is not empty
 ********************************************************************************/

string Queue::get_front(){
    if(is_empty())
    {
        cout << "get_front() : the queue is empty" << endl;
        exit(-1);
    }
    
    return front->data;
}



/********************************************************************************
 * prints the elements in the queue in a programmer-specified format to stdout
 ********************************************************************************/

void Queue::print()
{
    if(is_empty())
    {
        cout << "print() : Queue is empty" << endl;
        exit(-1);
    }
    
    Nodeptr temp;
    temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->nextnode;
    }
    cout << endl;
}

/********************************************************************************
 * returns whether the queue is empty
 ********************************************************************************/

bool Queue::is_empty()
{
    if(size == 0)
        return true;
    else
        return false;
}


// FOR TESTING
string Queue::get_back()
{
    if(is_empty())
    {
        cout << "get_back() : the queue is empty" << endl;
        exit(-1);
    }
    
    return back->data;
}

