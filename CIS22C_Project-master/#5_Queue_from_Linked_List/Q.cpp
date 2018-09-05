//
//  Q.cpp
//  Queue
//
//  Created by HOWON KIM on 1/13/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include "Q.h"
using namespace std;


Q::Q(){}

Q::Q(const Q &q):queue(q.queue){}

Q::~Q(){}


/**manipulation procedures*/

/*****************************************************************************
 * removes an element from the front of the queue
 * precondition: the queue isn't empty
 * postcondition: an element has been removed from the front of the queue
 *****************************************************************************/

 
void Q::dequeue()
{
    queue.remove_first();
    
}



/*****************************************************************************
 * adds an element to the back of the queue
 * postcondition: an element added to the back of the queue
 *****************************************************************************/

void Q::enqueue(int data)
{
    queue.insert_last(data);
}




/**accessors*/

/*****************************************************************************
 * returns whether this queue is equal to another queue
 *****************************************************************************/

bool Q::operator==(const Q &copyque)
{
    if(queue == copyque.queue)
        return true;
    else
        return false;
    
}

/*****************************************************************************
 * returns the element at the front of the queue
 ****************************************************************************/


int Q::get_front()
{
    return queue.get_first();
}


/*****************************************************************************
 * returns the size of the queue
 * precondition: the queue is not empty
 *****************************************************************************/

int Q::get_size()
{
    return queue.get_size();
    
}



/**additional queue operations*/

void Q::print()
{
    queue.print();
}

