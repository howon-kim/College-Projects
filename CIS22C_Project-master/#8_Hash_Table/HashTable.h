//
//  HashTable.h
//  Hash_Table
//
//  Created by HOWON KIM on 2/25/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class HashTable {
    
public:
    HashTable();
    
    ~HashTable();
    
    int hash(string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //the ASCII values of each character % the table size
    
    void addItem(int crn, string course, string title, bool status, string days);
    //inserts a new item into the table
    //calls the hash function on the key title to determine the correct bucket
    
    void removeItem(string course);
    //removes the item with the given key
    
    int numItemsAtIndex(int index);
    //Helper function to printTable
    //Counts the number of items in each bucket
    
    void printTable();
    //prints the first item of each bucket
    //includes the number of items stored at that bucket
    
    void printBucket(int index);
    //Prints all items stored at a particular bucket
    
    int findTitle(string course);
    //Searches for an title in the table using the key
    //Returns the index under which the title is stored
    //returns -1 if the title is not found
    
private:
    
    struct Node
    {
        int crn;
        string course;
        
        string title;
        bool status;
        string days;
        
        /** File I/O Operation Needed
        string time;
        
        int start;
        int end;
        
        string room;
        string campus;
        
        double units;
        
        string instructor;
        
        int seats_available;
        int waiting_available;
        int waiting_capacity;
         **/
        
        
        Node* next;
        Node(): crn(0), course(""), title(""), status(0), days(""), next(NULL){};
        //time(""), start(0), end(0), room(""), campus(""), units(0.0), instructor(""), seats_available(0), waiting_available(0), waiting_capacity(0)
        
        Node(int ncrn, string ncourse, string ntitle, bool nstatus, string ndays): crn(ncrn), course(ncourse), title(ntitle), status(nstatus), days(ndays),next(NULL){};
       
        //Node(int ncrn, string ncourse, string ntitle, bool nstatus, string ndays, string ntime, int nstart, int nend, string nroom, string ncampus, double nunits, string ninstructor, int nseats_available, int nwaiting_available, int nwaiting_capacity): crn(ncrn), course(ncourse), title(ntitle), status(nstatus), days(ndays), time(ntime), start(nstart), end(nend), room(nroom), campus(ncampus), units(nunits), instructor(ninstructor), seats_available(nseats_available), waiting_available(nwaiting_available), waiting_capacity(nwaiting_capacity),next(NULL) {}
        
    };
    
    
    typedef struct Node* Nodeptr;

    static const int TABLE_SIZE = 29;
    Nodeptr Table[TABLE_SIZE];
    
};

#endif /* HASHTABLE_H_ */
