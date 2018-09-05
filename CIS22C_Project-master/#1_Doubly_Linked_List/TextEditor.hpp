//
//  TextEditor.hpp
//  22C_KIM_HOWON_H2
//
//  Created by HOWON KIM on 10/8/15.
//  Copyright © 2015 HOWON KIM. All rights reserved.
//

#ifndef TextEditor_hpp
#define TextEditor_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


class TextEditor
{
private:
    // Declare a structure for the list
    struct dNode
    {
        string line;
        dNode *back;  // To point to the previous node
        dNode *fowd; // To point to the next node
    };
    
    dNode *head = 0;  // List head pointer
    int count; // Count of the Node
    
    
public:
    // Constructor
    TextEditor()
    {
        head = new dNode; count = 0;
        head->fowd = head;
        head->back = head; }
    
    // Destructor
    ~TextEditor();
    
    // Linked list operations
    void read();
    
    void append(string newLine);
    
    void print(int numline1, int numline2);
    void printFtoL() { return print(1, count); }
    void printLtoF() { return print(count, 1); }
    void printLineNumber() { cout << "Total Number of Lines : " << count << endl; }
    
    void remove(int numline1, int numline2);
    
    void insert(int numline, string text);
    
    void save() { return save("backup.txt");};
    void save(string filename);
    
    
    void help();
    void about();
};

#endif /* TextEditor_hpp */
