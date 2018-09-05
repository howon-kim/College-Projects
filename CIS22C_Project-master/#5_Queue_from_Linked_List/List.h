/**
 
 * Howon Kim
 
 * CIS 22C
 
 * List.h
 
 */

#ifndef LIST_H
#define LIST_H
#include <cstddef>
#include <cstdlib>


class List
{
    
private:
    struct Node
    {
        int data;
        Node* nextnode;
        
        Node(): nextnode(NULL){} //define our own default constructor
        Node(int data): nextnode(NULL), data(data){}
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
    //Postcondition: List should be empty
    
    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: list should be empty and left we head and the tail which compiler takes care of
    
    List(const List &list);
    //Copy construcor. Initializes list to have the same elements as another list
    //Postcondition:
    
    /**Accessors*/
    
    int get_last();
    //Returns the last element in the list
    //Precondition:
    
    
    int get_current();
    //Returns the element pointed to by the iterator
    //Precondition:
    
    
    bool is_empty();
    //Determines whether a list is empty.
    
    int get_first();
    //Returns the first element in the list
    //Precondition:
    
    bool off_end();
    //Determines if the iterator is off the end of the list
    
    
    int get_size();
    //Returns the length of the list
    
    
    /**Manipulation Procedures*/
    
    void begin();
    //Moves the iterator to point to the first element in the list
    //If the list is empty, the iterator remains NULL
    //Postcondition:
    
    
    void insert_current(int data);
    //Inserts a new element into the list in the position after the iterator
    //Precondition: there has to be a data
    //Postcondition: it has to point the one that next to the current
    
    void remove_last();
    //Removes the value of the last element in the list
    //Precondition:
    //Postcondition:
    
    void remove_first();
    //Removes the value of the first element in the list
    //Precondition:
    //Postcondition:
    
    void insert_last(int data);
    //Inserts a new element at the end of the list
    //If the list is empty, the new element becomes both head and tail
    //Postcondition:it has to point the Null
    
    void insert_first(int data);
    //Inserts a new element at the front of the list
    //If the list is empty, the new element becomes both head and tail
    //Postcondition: has to get the address from the head and point it
    
    
    void delete_current();
    //Removes the element after the element pointed at by the iterator
    //Precondition:
    //Postcondition:
    
    void scroll();
    //Moves the iterator forward by one element in the list
    //Has no effect if the iterator is offend or the list is empty
    //Postcondition:
    
    
    /**Additional List Operations*/
    
    void print();
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    
    bool operator == (const List& list);
    
    
};



#endif /* List_h */
