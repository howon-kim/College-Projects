
#ifndef Q_H_
#define Q_H_

#include "List.h"
#include <iostream>
#include <cstddef>
#include <cstdlib>


using namespace std;

class Q
{
public:
    /**constructors and destructors*/
    
    Q();
    //initializes an empty queue
    //postcondition: an empty queue
    
    Q(const Q &queue);
    //initializes queue to have same elements as another queue
    //postcondition: a copy of queue
    
    ~Q();
    //frees memory allocated to the queue
    //postcondition: memory for queue has been freed
    
    /**manipulation procedures*/
    
    void dequeue();
    //removes an element from the front of the queue
    //precondition: the queue isn't empty
    //postcondition: an element has been removed from the front of the queue
    
    void enqueue(int data);
    //adds an element to the back of the queue
    //postcondition: an element added to the back of the queue
    
    /**accessors*/
    
    bool operator==(const Q &queue);
    //returns whether this queue is equal to another queue
    
    int get_front();
    //returns the element at the front of the queue
    //precondition: the queue is not empty
    
    int get_size();
    //returns the size of the queue
    
    /**additional queue operations*/
    void print();
    //prints the elements in the queue in a programmer-specified format to stdout
    
    
private:
    List queue; //calls the List default constructor
    
    
};

#endif /* Q_H_ */


