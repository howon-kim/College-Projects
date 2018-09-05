/**
 
 * Howon Kim
 
 * CIS 22C
 
 * List.h
 
 */

#ifndef List_h
#define List_h
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

template <class listitem>
class List
{
    
private:
    struct Node
    {
        listitem data;
        Node* nextnode;
        Node* previousnode;
        
        Node(): nextnode(NULL), previousnode(NULL){} //define our own default constructor
        Node(listitem data): nextnode(NULL), previousnode(NULL), data(data){}
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
    //Postcondition: Initializes the nodes and empty list
    
    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: Frees memory allocated to the list
    
    List(const List &list);
    //Copy construcor. Initializes list to have the same elements as another list
    //Postcondition: Initializes list to have the same elements as another list
    
    /**Accessors*/
    
    listitem get_first();
    //Returns the first element in the list
    //Precondition: Node's size is must not be 0
    
    listitem get_last();
    //Returns the last element in the list
    //Precondition: Node's size is must not be 0
    
    
    listitem get_current();
    //Returns the element pointed to by the iterator
    //Precondition: Node's size is must not be 0 and iterator is pointing the data
    
    
    bool is_empty();
    //Determines whether a list is empty.
    
    
    bool off_end();
    //Determines if the iterator is off the end of the list
    
    
    int get_size();
    //Returns the length of the list
    
    
    /**Manipulation Procedures*/
    
    void begin();
    //Moves the iterator to point to the first element in the list
    //If the list is empty, the iterator remains NULL
    //Postcondition: Moves the iterator to point to the first elemment in the list
    
    
    void insert_current(listitem data);
    //Inserts a new element into the list in the position after the iterator
    //Precondition: Node's size is must not be 0
    //Postcondition: Insert new data into the list after the iterator
    
    void remove_last();
    //Removes the value of the last element in the list
    //Precondition: Node's size is must not be 0
    //Postcondition: Remove the last data in the list
    
    void remove_first();
    //Removes the value of the first element in the list
    //Precondition: Node's size is must not be 0
    //Postcondition: Remove the first data
    
    void insert_last(listitem data);
    //Inserts a new element at the end of the list
    //If the list is empty, the new element becomes both head and tail
    //Postcondition: Insert the new data at the end of the list
    
    void insert_first(listitem data);
    //Inserts a new element at the front of the list
    //If the list is empty, the new element becomes both head and tail
    //Postcondition: Insert the new data at the front of the list
    
    
    void delete_current();
    //removes the element currently pointed to by the iterator
    //Precondition: Node's size is must not be 0
    //Postcondition: Remove the data currently pointed to by the iterator
    
    void scroll();
    //Moves the iterator forward by one element in the list
    //Has no effect if the iterator is offend or the list is empty
    //Postcondition: Iterator is pointing the next element from current iterator
    
    
    /**Additional List Operations*/
    
    void print();
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    
    bool operator==(const List& list);
    //Tests two lists to determine whether their contents are equal
    //Postcondition: returns true if lists are equal and false otherwise
    
};



/**Constructors and Destructors*/


//**************************************************
// Constructor                                     *
// Initialize the fields inside the list class     *
//**************************************************

template <class listitem>
List<listitem>::List(): size(0), first(NULL), last(NULL), current(NULL){};


//**************************************************
// Destructor                                      *
// Free object's resources                         *
//**************************************************

template <class listitem>
List<listitem>::~List()
{
    Nodeptr current = first;
    Nodeptr next = first;
    while (current != NULL)
    {
        next = current->nextnode;
        delete current;
        current = next;
    }
}


//**************************************************
// Copy Constructor                                *
// Initializes list to have the same               *
// elements as another list                        *
//**************************************************


template <class listitem>
List<listitem>::List(const List &list)
// List<listitem>::List(const listitem &list) // Destructor Error !!!

{
    if(list.first == NULL)
    {
        first = last = current = NULL;
        size = 0;
    }
    
    else
    {
        
        first = new Node(list.first -> data);
        Nodeptr move = first;
        Nodeptr move2 = list.first;
        
        
        while(move2 -> nextnode != NULL)
        {
            move -> nextnode = new Node;
            move = move -> nextnode;
            move2 = move2->nextnode;
            move -> data = move2 -> data;
        }
        
        last = move;
        size = list.size;
    }
}




/**Accessors*/

//**************************************************
// Get the first data of the node                  *
//**************************************************

template <class listitem>
listitem List<listitem>::get_first()
{
    if (is_empty())
    {
        cout << "get_first(): List is empty. No first element." << endl;
        exit(-1);
    }
    else
    {
        return first -> data;
    }
}


//**************************************************
// Get the last data of the node                   *
//**************************************************

template <class listitem>
listitem List<listitem>::get_last()
{
    if (is_empty())
    {
        cout << "get_last(): List is empty. No last element." << endl;
        exit(-1);
    }
    else
    {
        return last -> data;
    }
}


//**************************************************
// Returns the element pointed to by the iterator  *
//**************************************************

template <class listitem>
listitem List<listitem>::get_current()
{
    if (is_empty())
    {
        cout << "get_current() : List is empty. No current element." << endl;
        exit(-1);
    }
    else if(off_end())
    {
        cout << "get_current() : Iterator is off the end of the List" << endl;
        exit(-1);
    }
    else
    {
        return current -> data;
    }
}


//**************************************************
// It check the node is empty or not               *
// If the list is empty it returns true, else false*
//**************************************************

template <class listitem>
bool List<listitem>::is_empty()
{
    if (size == 0)
        return 1;
    else
        return 0;
}



//**************************************************
// It check the current pointer is null or not     *
//**************************************************

template <class listitem>
bool List<listitem>::off_end()
{
    if (current == NULL)
        return 1;
    else
        return 0;
}



//**************************************************
// Return the length of the list                   *
//**************************************************

template <class listitem>
int List<listitem>::get_size()
{
    int size = 0;
    Nodeptr move = first;
    
    while(move != NULL)
    {
        move = move->nextnode;
        size++;
        
    }
    
    return size;
}


/**Manipulation Procedures*/



//**************************************************
// Move the iterator to the first data of the node *
//**************************************************

template <class listitem>
void List<listitem>::begin()
{
    if (is_empty())
    {
        cout << "begin() : List is empty. There is no first Data." << endl;
        exit(-1);
    }
    
    current = first;
}



//**************************************************
// Inserts a new element into the list in the      *
// position after the iterator                     *
//**************************************************

template <class listitem>
void List<listitem>::insert_current(listitem data)
{
    Nodeptr newNode = new Node(data);
    
    if (is_empty())
    {
        cout << "insert_current(): List is empty. No current element." << endl;
        exit(-1);
    }
    else if (off_end())
    {
        cout << "insert_current(): Current is Null" << endl;
        exit(-1);
    }
    
    // EDGE CASE : IF CURRENT IS END OF THE LIST
    else if (current == last)
    {
        current -> nextnode = newNode;
        newNode -> previousnode = current;
        newNode -> nextnode = NULL;
        last = newNode;
    }
    else
    {
        newNode -> nextnode = current -> nextnode;
        current -> nextnode -> previousnode = newNode;
        current -> nextnode = newNode;
        newNode -> previousnode = current;
        
        
    }
    
    size++;
    
}


//**************************************************
// Remove the last data of the node                *
//**************************************************

template <class listitem>
void List<listitem>::remove_last()
{
    if (is_empty())
    {
        cout << "remove_last(): List is empty. No first element." << endl;
        exit(-1);
    }
    else if(size == 1)
    {
        first = last = NULL;
        size = 0;
    }
    else
    {
        Nodeptr temp = last->previousnode;
        delete last;
        
        last = temp;
        last -> nextnode = NULL;
        
        --size;
    }
    
}


//**************************************************
// Remove the first data of the node               *
//**************************************************

template <class listitem>
void List<listitem>::remove_first()
{
    if (is_empty())
    {
        cout << "remove_first(): List is empty. No first element." << endl;
        exit(-1);
    }
    else if(size == 1)
    {
        first = last = NULL;
        size = 0;
    }
    else
    {
        Nodeptr temp = first->nextnode;
        delete first;
        
        
        first = temp;
        first->previousnode = NULL;
        size--;
        
    }
    
}


//**************************************************
// Add a new Node to the very end of the list      *
//**************************************************

template <class listitem>
void List<listitem>::insert_last(listitem data)
{
    if (is_empty())
    {
        Nodeptr newNode = new Node(data);
        first = last = newNode;
    }
    
    else
    {
        Nodeptr newNode = new Node(data);
        last -> nextnode = newNode;
        newNode -> previousnode = last;
        last = newNode;
    }
    
    size++;
}



//**************************************************
// Add a new Node to the very front of the list    *
//**************************************************

template <class listitem>
void List<listitem>::insert_first(listitem data)
{
    if (is_empty())
    {
        Nodeptr newNode = new Node(data);
        first = last = newNode;
    }
    
    else
    {
        Nodeptr newNode = new Node(data);
        newNode->nextnode = first;
        first -> previousnode = newNode;
        first = newNode;
    }
    
    size++;
    
}

//**************************************************
// removes the element currently pointed to by the *
// iterator                                        *
//**************************************************

template <class listitem>
void List<listitem>::delete_current()
{
    if (off_end())
    {
        cout << "delete_current(): Current is NULL" << endl;
        exit(-1);
    }
    else
    {
        //Remove First
        if(current == first)
        {
            remove_first();
        }
        
        //Remove_last
        else if(current == last)
        {
            remove_last();
        }
        
        else
        {
            Nodeptr temp1 = current -> previousnode;
            Nodeptr temp2 = current -> nextnode;
            
            temp1 -> nextnode = temp2;
            temp2 -> previousnode = temp1;
            
            delete current;
            current = NULL; //VERY IMPORTANT
        }
        
    }
    
    size--;
}


//**************************************************
// Moves the iterator forward by one element       *
// in the list                                     *
//**************************************************


template <class listitem>
void List<listitem>::scroll()
{
    if(is_empty())
    {
        cout << "scroll() : Node is empty" << endl;
        exit(-1);
    }
    else if(off_end())
    {
        cout << "scroll() : Current is NULL" << endl;
        exit(-1);
    }
    else
        current = current -> nextnode;
}



/**Additional List Operations*/


//**************************************************
// Display the list of the nodes                   *
//**************************************************

template <class listitem>
void List<listitem>::print()
{
    Nodeptr move = first;
    while (move != NULL)
    {
        cout << move->data << " " ;
        move = move -> nextnode;
        
    }
    cout << endl;
}




//**************************************************
// Tests two lists to determine whether            *
// their contents are equal                        *
//**************************************************

template <class listitem>
bool List<listitem>::operator==(const List& list)
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

#endif /* List_h */
