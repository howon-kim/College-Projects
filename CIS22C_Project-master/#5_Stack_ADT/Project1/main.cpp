//
//  main.cpp
//  22C_KIM_HOWON_H3
//
//  Created by HOWON KIM on 10/20/15.
//  Copyright © 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Stack.h"
using namespace std;

const int SIZE = 4;

// Function Prototype
void process(Stack<int> *stack, string filename);
void displayItem(Stack<int> *stack);
void popItem(Stack<int> *stack);


int main(int argc, const char * argv[]) {
    
    // Make New Stack
    Stack<int> *stack = new Stack<int>;
    string file[SIZE] = {"numbers1.txt", "numbers2.txt", "numbers3.txt", "QUIT"};
    
    
    for (int count = 0 ; count < SIZE ; count++)
    {
        if (file[count] == "QUIT")
        {
            cout << "Test Finished" << endl;
            return 0;
        }
        
        /* PROCESS DATA */
        process(stack, file[count]);
        
        /* DELETE STACK */
        delete stack;
        stack = new Stack<int>;
    }
}

//*****************************************************************************
// Definition of function process
// This function open the input file and process the numbers from the file
// Input /Output Parameter : stack
// Input Parameter : filename
// Return Value : none
//*****************************************************************************
void process(Stack<int> *stack, string filename)
{
    int data = 0;
    int item = 0;
    bool status;
    
    /* OPEN FILE PROCESS */
    ifstream infile;
    infile.open(filename);
    
    if(!infile){
        cout << "File Error : Can not open the file" << endl;
        return ;
    }
    
    else
    {
        cout << ">> Start \"" << filename << "\" File <<" << endl ;
        
        /* PROCESSING FILE */
        while (infile>>data)
        {
            cout << "Read " << data << ", ";
            if(data==0)
            {
                cout << "The stack has " << stack->getCount() << " numbers" << endl;
            }
            
            if(data==1)
            {
                status = stack->getTop(item);
                if(status)
                {
                    cout << "Display the element at the top of the stack: " << item << endl;
                }
                else
                {
                    cout << "This is Empty Stack" << endl;
                }
                
            }
            
            if(data>1)
            {
                status = stack->push(data);
                if(status)
                {
                    cout << "Push " << data << endl;
                }
                else
                {
                    cout << "Push Error " << endl;
                }
            }
            
            if(data<0)
            {
                data = abs(data);
                
                if(data>stack->getCount())
                {
                    cout << "The stack has " << stack->getCount() << " items which is less than " << data << " items" << endl;
                }
                else
                {
                    cout << "Pop and print " << data << " numbers : ";
                    
                    for (; data>=1 ; data--)
                    {
                        popItem(stack);
                    }
                    cout << endl;
                }
            }
        }
        
        
        if(stack->isEmpty())
            cout << "END OF FILE, Empty stack";
        else
        {
            cout << "END OF FILE, Display the stack from top to bottom : ";
            displayItem(stack);
        }
        
        /* CLOSE FILE PROCESS */
        infile.close();
        cout << endl << ">> Finish \"" << filename << "\" File <<" << endl << endl;
    }
    
    
    return ;
}


//*****************************************************************************
// Definition of function displayItem
// This function display the elements in the stack
// Input /Output Parameter : stack
// Return Value : none
//*****************************************************************************
void displayItem(Stack<int> *stack)
{
    Stack<int> *temp = new Stack<int>;
    int top = 0;
    for(int count = stack->getCount(); count>=1 ; count--)
    {
        temp->push(stack->pop(top));
        cout << top << " ";
    }
    
    for(int count = temp->getCount(); count>=1 ; count--)
    {
        stack->push(temp->pop(top));
    }
    
    return;
    
}

//*****************************************************************************
// Definition of function popItem
// This function pop the item from the stack
// Input /Output Parameter : stack
// Return Value : none
//*****************************************************************************
void popItem(Stack<int> *stack)
{
    bool status;
    int dataOut = 0;
    
    // Pop the Item
    status = stack->pop(dataOut);
    
    
    if (status)
    {
        cout << dataOut << " " ;
    }
    else
        cout << "*** Empty stack! ***";
}


/* OUTPUT
 >> Start "numbers1.txt" File <<
 Read 10, Push 10
 Read 20, Push 20
 Read 30, Push 30
 Read 1, Display the element at the top of the stack: 30
 Read 40, Push 40
 Read 0, The stack has 4 numbers
 Read 50, Push 50
 Read -2, Pop and print 2 numbers : 50 40
 Read 15, Push 15
 Read 25, Push 25
 Read -3, Pop and print 3 numbers : 25 15 30
 Read 60, Push 60
 Read 70, Push 70
 END OF FILE, Display the stack from top to bottom : 70 60 20 10
 >> Finish "numbers1.txt" File <<
 
 >> Start "numbers2.txt" File <<
 Read 10, Push 10
 Read 20, Push 20
 Read 30, Push 30
 Read -6, The stack has 3 items which is less than 6 items
 Read 40, Push 40
 Read 50, Push 50
 Read -5, Pop and print 5 numbers : 50 40 30 20 10
 END OF FILE, Empty stack
 >> Finish "numbers2.txt" File <<
 
 >> Start "numbers3.txt" File <<
 Read 15, Push 15
 Read 25, Push 25
 Read 35, Push 35
 Read 45, Push 45
 Read 0, The stack has 4 numbers
 Read 1, Display the element at the top of the stack: 45
 Read 0, The stack has 4 numbers
 Read 55, Push 55
 Read 65, Push 65
 Read 75, Push 75
 Read 0, The stack has 7 numbers
 Read 1, Display the element at the top of the stack: 75
 Read 0, The stack has 7 numbers
 Read -50, The stack has 7 items which is less than 50 items
 Read 0, The stack has 7 numbers
 Read 1, Display the element at the top of the stack: 75
 Read 0, The stack has 7 numbers
 Read -5, Pop and print 5 numbers : 75 65 55 45 35
 Read 10, Push 10
 Read 40, Push 40
 Read 50, Push 50
 Read 60, Push 60
 Read 70, Push 70
 Read 80, Push 80
 Read 90, Push 90
 Read 0, The stack has 9 numbers
 Read 1, Display the element at the top of the stack: 90
 Read 0, The stack has 9 numbers
 Read -3, Pop and print 3 numbers : 90 80 70
 Read 13, Push 13
 Read 23, Push 23
 Read 33, Push 33
 Read 43, Push 43
 Read 54, Push 54
 Read -5, Pop and print 5 numbers : 54 43 33 23 13
 Read 0, The stack has 6 numbers
 Read 1, Display the element at the top of the stack: 60
 Read 0, The stack has 6 numbers
 Read 17, Push 17
 Read 27, Push 27
 Read 7, Push 7
 Read 47, Push 47
 Read 57, Push 57
 Read 67, Push 67
 Read 77, Push 77
 Read 87, Push 87
 Read 97, Push 97
 Read 19, Push 19
 Read 29, Push 29
 Read 39, Push 39
 Read 49, Push 49
 Read 59, Push 59
 Read 69, Push 69
 Read 79, Push 79
 Read 89, Push 89
 Read 99, Push 99
 Read 0, The stack has 24 numbers
 Read 1, Display the element at the top of the stack: 99
 Read -6, Pop and print 6 numbers : 99 89 79 69 59 49
 Read 0, The stack has 18 numbers
 Read 1, Display the element at the top of the stack: 39
 Read 14, Push 14
 Read 24, Push 24
 Read 34, Push 34
 Read 44, Push 44
 Read 0, The stack has 22 numbers
 Read -150, The stack has 22 items which is less than 150 items
 Read 54, Push 54
 Read 64, Push 64
 Read 0, The stack has 24 numbers
 END OF FILE, Display the stack from top to bottom : 64 54 44 34 24 14 39 29 19 97 87 77 67 57 47 7 27 17 60 50 40 10 25 15
 >> Finish "numbers3.txt" File <<
 
 Test Finished
 Program ended with exit code: 0
 */

