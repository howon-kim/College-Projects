//
//  TextEditor.cpp
//  22C_KIM_HOWON_H2
//
//  Created by HOWON KIM on 10/8/15.
//  Copyright © 2015 HOWON KIM. All rights reserved.
//

#include "TextEditor.hpp"
#include <iostream>
#include <fstream>
using namespace std;

//**************************************************
// read function read the data from input file     *
// stored the data to each linked list node        *
//**************************************************

void TextEditor::read(){
    
    // Variable to read data
    string import;
    
    ifstream infile;
    infile.open("/Users/HWKIM/Documents/22C_KIM_HOWON_H2/22C_KIM_HOWON_H2/input.txt");
    
    // File Validation
    if(!infile)
    {
        cout << "File Error" << endl;
        exit(111);
    }
    
    // Import data to linked list
    while(getline(infile,import))
    {
        append(import);
        
    }
    
    infile.close();
}

//**************************************************
// help displays the instructions                  *
//**************************************************

void TextEditor::help()
{
    cout<< "    >> Instruction <<" << endl
    << "    T : Display the total number of lines in the text" << endl
    << "    F : Print all lines from first to last (show the line numbers: 1, 2, 3, etc.)" << endl
    << "    B : Print all lines from last to first (show the line numbers)" << endl
    << "    I : Insert the new line of text to the selective line" << endl
    << "        I(Line number)(Text)" << endl
    << "        - I 3 This is the new line of text to be inserted" << endl
    << "        - Insert a new line of text at position 3 in the list" << endl
    << "    D : Delete selective lines" << endl
    << "        D(Line number1)(Line number2)" << endl
    << "        - D 3 7 : Delete lines 3 to 7 inclusive" << endl
    << "        - D 7 3 : Delete lines 7 to 3 inclusive" << endl
    << "    L : Show the selective lines and line numbers" << endl
    << "        L(Line number1)(Line number2)" << endl
    << "        - L 2 5 : List lines 2 to 5 inclusive" << endl
    << "        - L 5 2 : List lines 5 to 2 inclusive, in reverse order" << endl
    << "    S : Save the file" << endl
    << "        S(Output file name)" << endl
    << "        - S out.txt : Save the updated text to an output file" << endl
    << "    H : Display instructions for T,F,B,I,L,D,S,H,A and Q" << endl
    << "    A : About: Display information about the developer" << endl
    << "    Q : Quit editing the file (save it to backup.txt)" << endl;
}

//**************************************************
// about displays the information about developer  *
//**************************************************

void TextEditor::about()
{
    cout<< "    >> About <<" << endl
    << "    Developer : Howon Kim" << endl
    << "    Class : CIS22C" << endl
    << "    Professor : Delia Garbacea" << endl
    << "    Quarter : 2015.Fall" << endl
    << "    Date : Oct.2015" << endl
    << "    College : De Anza College" << endl
    << "    Program Based on Circularly Doubly-Linked List with Sentinel Node" << endl
    << "    Tested on Xcode 7.0.1, Mac OS X 10.11 El Capitan" << endl;
}


//**************************************************
// append function appends a node containing the   *
// value pased into line, to the end of the list.  *
//**************************************************

void TextEditor::append(string newLine)
{
    dNode *newNode; // To point to a new node
    
    // Allocate a new node and store string there
    newNode = new dNode();
    newNode->line = newLine;
    
    newNode->back = head->back;
    newNode->fowd = head;
    
    head->back->fowd = newNode;
    head->back = newNode;
    
    ++count;
    
}

//**************************************************
// The insert function inserts a node with         *
// data copied to its data member                  *
//**************************************************

void TextEditor::insert(int numline, string text)
{
    // Current Location
    int currentCount = 1;

    // Allocate new node and save text
    dNode *newNode = new dNode;
    newNode->line = text;
    
    dNode *previousNode = head;
    dNode *currentNode = head->fowd;
    
    // If there is no data in the linked list
    if (count==0)
    {
        while(count<numline)
        {
            dNode *emptyNode = new dNode;
            emptyNode->back = head->back;
            emptyNode->fowd = head;
            
            head->back->fowd = emptyNode;
            head->back = emptyNode;
            
            currentNode = emptyNode;

            ++count;
        }

        
        newNode->back = currentNode->back;
        newNode->fowd = head;
        head->back = newNode;
        currentNode->back->fowd=newNode;
        delete currentNode;
    }

    
    else
    {
        // If new line is in the range of exist data
        if(numline<=count)
        {
            // Move to the destination
            while(currentCount<numline)
            {
                currentNode = currentNode->fowd;
                previousNode = previousNode->fowd;
                currentCount++;
            }
    
    // 0 is regard as 1
            
            previousNode->fowd = newNode;
            newNode->back = previousNode;
            currentNode->back = newNode;
            newNode->fowd = currentNode;
            count ++;
        }
        
        // If new line is out of the range of exist data
        else if(numline>count)
        {
            // move to end of the data
            while(currentCount<count)
            {
                currentNode = currentNode->fowd;
                currentCount++;
            }
            
            // Create new data with empty line
            while (numline>currentCount) {
                currentNode->fowd = new dNode;
                currentNode->fowd->back = currentNode;
                currentNode->fowd->fowd = head;
                head->back= currentNode->fowd;

                currentNode = currentNode->fowd;
                currentCount++;
            }

            // Insert user's data to the destination
            newNode->back = currentNode->back;
            newNode->fowd = head;
            head->back = newNode;
            currentNode->back->fowd=newNode;
            delete currentNode;
            
            
            count = numline;

        }
    }
}


//**************************************************
// save function saves the data to the file        *
// value in the nodes saved to the user's filename *
//**************************************************

void TextEditor::save(string filename)
{
    // If there is no data, exit the function
    if(head->fowd == head){
      cout << "No Data to Save" << endl;
    }
    
    else {
        dNode *pCurrent = head->fowd;
    
        ofstream outfile;
        outfile.open(filename);
    
        // File validation
        if(!outfile)
        {
            cout << "File Error" << endl;
            exit(111);
        }
    
        // Output the data
        while(pCurrent != head)
        {
            outfile << pCurrent->line << endl;
            pCurrent = pCurrent->fowd;
        }
    
        outfile.close();
        
        cout << "File was saved to " << filename << endl;
    }
}

//**************************************************
// print displays the specific range of value      *
// that user entered                               *
// which stored in each node of the linked list    *
//**************************************************

void TextEditor::print(int numline1, int numline2)
{
    // Current location
    int currentCount = 1;
    dNode *pCurrent = head->fowd;
    
    // If there is no Data, exit function
    if(pCurrent==head || count==0){
        cout << "No Data" << endl;
        return ;
    }

    // Range Criteria
    if (numline2>count || numline1>count || numline1<=0 || numline2<=0){
        cout << "Invalid Number" << endl;
        return ;
    }
    
    // Case 1 : numline1 <= numline2
    if(numline1<=numline2){
        
        while(currentCount<numline1)
        {
            pCurrent = pCurrent->fowd;
            ++currentCount;
        }
        while(currentCount<=numline2)
        {
            cout << currentCount << " " << pCurrent->line << endl;
            pCurrent = pCurrent->fowd;
            ++currentCount;
        }
    }
    
    // Case 2 : numline1 > numline2
    else if(numline1>numline2)
    {
        while(currentCount<numline1)
        {
            pCurrent = pCurrent->fowd;
            ++currentCount;
        }
        while(currentCount>=numline2)
        {
            cout << currentCount << " " << pCurrent->line << endl;
            pCurrent = pCurrent->back;
            --currentCount;
        }
    }
    
}

//**************************************************
// The remove function searches for the nodes      *
// with selective range. The node, if found, is    *
// deleted from the list and from memory.          *
//**************************************************

void TextEditor::remove(int numline1, int numline2)
{
    int currentCount = 1;
    int tempNum = 0;
    
    // If there is no data, exit function
    if(head->fowd==head || count == 0){
        cout << "No Data" << endl;
        return ;
    }
    
    // Range Criteria
    if (numline2>count || numline1>count || numline1<=0 || numline2<=0){
        cout << "Invalid Number" << endl;
        return ;
    }
    
    dNode *pCurrent = head;
    dNode *temp = head->fowd;
    
    // If numline1 is bigger than numline 2, swap it
    if(numline1>numline2)
    {
        tempNum = numline2;
        numline2 = numline1;
        numline1 = tempNum;
    }
    
    // Go to the first data location to delete
    while(numline1>currentCount)
    {
        pCurrent = pCurrent->fowd;
        temp = temp->fowd;
        currentCount++;
    }
    
    dNode *remove = temp;
    // Start to delete until numline 2
    while(numline2>=currentCount)
    {
        temp = temp->fowd;
        delete remove;
        remove = temp;
        currentCount++;
    }
    
    pCurrent->fowd = temp;
    temp->back = pCurrent;
    
    // Count Revalidate Function
    count = count - (numline2 - numline1 + 1);
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

TextEditor::~TextEditor()
{
    dNode *nodePtr;   // To traverse the list
    dNode *remove; // remove the node
    
    // Position nodePtr after the head
    nodePtr = head->fowd;
    remove = head->fowd;
    
    // While nodePtr is not at the end of the list
    while (nodePtr != head)
    {
        // Point to the next node.
        nodePtr = nodePtr->fowd;
        
        // Delete the current node.
        delete remove;
        
        // Copy current location to remove node
        remove = nodePtr;
        
       
        
       

    }
}
