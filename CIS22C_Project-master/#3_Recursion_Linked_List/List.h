/**
 
 * Howon Kim
 
 * CIS 22C
 
 * List.h (Revision. Feb 5)
 
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
        
        /** define our own default constructor **/
        Node(): nextnode(NULL), previousnode(NULL){}
        Node(listitem data): nextnode(NULL), previousnode(NULL), data(data){}
    };
    
    typedef struct Node* Nodeptr;
    
    Nodeptr first;
    Nodeptr last;
    Nodeptr current; //the iterator
    
    int size;
    
    void reverse(Nodeptr node);
    //Helper function for the public printReverse() function.
    //Recursively prints the data in a List in reverse.
    
    
public:
    
    /**Constructors and Destructors*/
    
    List();
    //Default constructor; initializes and empty list
    //Postcondition: Initializes the nodes and empty list
    
    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: Frees memory allocated to the list
    
    List(const listitem &list);
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
    
    bool is_sorted();
    //Determines whether a list is sorted.
    
    
    bool off_end();
    //Determines if the iterator is off the end of the list
    
    
    int get_size();
    //Returns the length of the list
    
    
    int getIndex();
    //Indicates the index of the Node where the iterator is currently pointing
    //Nodes are numbered from 1 to size of the list
    //Pre: !off_end()
    
    

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
    
    
    void scrollToIndex(int index);
    //Moves the iterator to the node whose index is specified by the user
    //Pre: !empty()
    
    
    
    /**Additional List Operations*/
    
    void print();
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    
    bool operator==(const List& list);
    //Tests two lists to determine whether their contents are equal
    //Postcondition: returns true if lists are equal and false otherwise
    
    
    void printReverse();
    //Wrapper function that calls the reverse helper function to print a list in reverse
    //prints nothing if the List is empty
    
    
    int linear_search(listitem item);
    //Searchs the list, element by element, from the head of the List to the tail of the List
    //Returns the index of the element, if it is found in the List
    //Returns -1 if the element is not in the List
    //Pre: !empty()
    
    
    int binary_search(int low, int high, listitem item);
    //Recursively searchs the list by dividing the search space in half
    //Returns the index of the element, if it is found in the List
    //Returns -1 if the element is not in the List
    //Pre: !empty()
    //Pre: List is sorted (must test on a sorted list unless you do the E.C.)
    
    bool sorting();
    //Sort the List
    
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
List<listitem>::List(const listitem &list)
{
    Nodeptr move = first;
    Nodeptr move2 = list.first;
    
    while(move != NULL)
    {
        move2 = move;
        move = move->nextnode;
        move2 = move2->nextnode;
    }
    
    size = list.size;
}



/**Accessors*/

//**************************************************
// Get the first data of the node                  *
//**************************************************

template <class listitem>
listitem List<listitem>::get_first()
{
    if (is_empty()){
        cout << "get_first(): List is empty. No first element." << endl;
        exit(111);}
    else
        return first -> data;
}


//**************************************************
// Get the last data of the node                   *
//**************************************************

template <class listitem>
listitem List<listitem>::get_last()
{
    if (is_empty()){
        cout << "get_last(): List is empty. No last element." << endl;
        exit(111);}
    else
        return last -> data;
}


//**************************************************
// Returns the element pointed to by the iterator  *
//**************************************************

template <class listitem>
listitem List<listitem>::get_current()
{
    if (is_empty()){
        cout << "get_current() : List is empty. No current element." << endl;
        exit(111);}
    else if (off_end()){
        cout << "get_current() : Iterator is off the end of the List" << endl;
        exit(111);}
    else
        return current -> data;
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


//**************************************************
// Indicates the index of the Node where the       *
// iterator is currently pointing                  *
//**************************************************

template <class listitem>
int List<listitem>::getIndex()

{
    Nodeptr move = first;
    int current_index = 1;

    
    if(off_end()){
        cout << "getIndex() : Iterator is off the end of the List" << endl;
        return -1;
    }
    else
    {
        while(move!=current)
        {
            move = move -> nextnode;
            ++current_index;
        }
        
        return current_index;
    }
}




/**Manipulation Procedures*/

//**************************************************
// Move the iterator to the first data of the node *
//**************************************************

template <class listitem>
void List<listitem>::begin()
{
    if (is_empty())
        cout << "begin() : List is empty. There is no first Data." << endl;
    else
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
        cout << "insert_current(): List is empty. No current element." << endl;
    else if (off_end())
        cout << "insert_current() : Iterator is off the end of the List" << endl;
    
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
        cout << "remove_last(): List is empty. No first element." << endl;
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
        cout << "remove_first(): List is empty. No first element." << endl;
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
        --size;
        
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
        cout << "delete_current(): Current is NULL" << endl;
    else
    {
        //Remove First
        if(current == first)
            remove_first();
        
        //Remove_last
        else if(current == last)
            remove_last();
        
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
        cout << "scroll() : Node is empty" << endl;
    else if(off_end())
        cout << "scroll() : Current is NULL" << endl;
    else
        current = current -> nextnode;
}


//**************************************************
// Moves the iterator to the node whose index is   *
// specified by the user in the list               *
//**************************************************

template <class listitem>
void List<listitem>::scrollToIndex(int index)
{
    if (is_empty())
        cout << "scrollToIndex(int index) : List is empty" << endl;
    else if(index <= 0)
        cout << "scrollToIndex(int index) : Index is out of the range" << endl;
    else if(index > size)
        cout << "scrollToIndex(int index) : Index is out of the range" << endl;
    else
    {
        int current_index = 1;
        Nodeptr move = first;
        
        while (current_index != index)
        {
            move = move -> nextnode;
            ++current_index;
        }
        
        current = move;
    }
}


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
    
    Nodeptr move = first;
    Nodeptr move2 = list.first;
    
    while(move != NULL)
    {
        if(move->data != move2->data)
            return false;
        
        move2 = move2->nextnode;
        move = move->nextnode;
    }
    return true;
}


//**************************************************
// Print a list in reverse                         *
//**************************************************

template <class listitem>
void List<listitem>::reverse(Nodeptr node)
{
    if(node == first)
    {
        cout << node -> data;
        cout << endl;
    }
    else
    {
        cout << node -> data << " ";
        reverse(node->previousnode);
    }
    

}



template <class listitem>
void List<listitem>::printReverse()
{
    if(is_empty())
        cout << "printReverse() : List is empty" << endl;
    else
    {
        Nodeptr move = last;
        reverse(move);
    }
}




//***************************************************
// Searchs the list, element by element,            *
// from the head of the List to the tail of the List*
// Returns the index of the element,                *
// if it is found in the List                       *
//***************************************************

template <class listitem>
int List<listitem>::linear_search(listitem item)
{
    if(is_empty())
    {
        cout << "linear_search(listitem item) : List is empty" << endl;
        return -1;
    }
    
    else
    {
        Nodeptr move = first;
        int current_index = 1;
        
        while(move->data != item)
        {
            move = move -> nextnode;
            ++current_index;
            
            if(move==NULL)
                return -1;
        }
        
        return current_index;
    }
    
}


/*---------------------------------------------------------------------
 Sorting the list
 --------------------------------------------------------------------*/

template <class listitem>
bool List<listitem>::sorting()
{
    if(is_empty())
    {
        cout << "sorting() : List is empty" << endl;
        return false;
    }
    else
    {
        Nodeptr move = first;
        
        for (int i=0; i<size; ++i)
        {
            move = first;
            
            for (int j=0; j<size-i-1; ++j)
            {

                if (move->data > move->nextnode->data)
                {
                    int temp = move->data;
                    move->data = move->nextnode->data;
                    move->nextnode->data = temp;
                }
                move = move->nextnode;
            }
            
        }
    }
    
    cout << "The contents are : " << endl;
    print();
    
        return true;
    
}

/*---------------------------------------------------------------------
 Determines that list is sorted or not
 --------------------------------------------------------------------*/

template <class listitem>
bool List<listitem>::is_sorted()
{
    Nodeptr move = first;
    
    for (int i=1; i<size; ++i)
    {
        if (move->data > move->nextnode->data)
            return false;
        
        move = move->nextnode;
    }
    
    return true;
}


/*---------------------------------------------------------------------
 Recursively searchs the list by dividing the search space in half
 Returns the index of the element, if it is found in the List
 Returns -1 if the element is not in the List
 Pre: !empty()
 Pre: List is sorted
 --------------------------------------------------------------------*/

template <class listitem>
int List<listitem>::binary_search(int low, int high, listitem item)
{
    if(is_empty())
    {
        cout << "binary_search(int low, int high, listitem item) : List is empty" << endl;
        return -2;
    }
    else if(!is_sorted())
    {
        cout << "binary_search(int low, int high, listitem item) : List is not sorted" << endl;
        return -2;
    }
    
    else
    {
        int mid = (low+high)/2;
        scrollToIndex(mid);
        
        
        if(high < low)
            return -1;
        else if(current->data == item)
            return mid;
        else if(item < current->data)
            return binary_search(low, mid-1, item);
        else
            return binary_search(mid+1, high, item);
        
    }
    
}


#endif /* List_h */
