//
//  main.cpp
//  22C_KIM_HOWON_HW3_EXTRA
//
//  Created by HOWON KIM on 10/22/15.
//  Copyright © 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include "Stack.h"
using namespace std;

// Function Prototype
void printList(Stack<int> *stack, int &count);

int main(int argc, const char * argv[]) {

    int number = 1;
    int count = 1;
    int top = 0;
    int fowd = 0;
    bool status = true;
    
    Stack<int> *stack = new Stack<int>;

    while(number!=0)
    {

        cout << "n = ";
        cin >> number;
        
        if(number <= 0)
            exit(111);
        
        
        // Make Stack
        for(int count = 1 ; count<=number ; count++)
            stack->push(1);
        
        
        // Loop Start
        while(status)
        {
            // Print List
            printList(stack, count);
            
            // Check Last Value
            if(stack->getCount()==1)
                status = false;
            
            // Pop up first, second top data
            stack->pop(top);
            stack->pop(fowd);
            
            --top; // decrement top data
            ++fowd; // increment next of top data
            
            
            if(top<fowd)
            {
                stack->push(top+fowd);
            }
            
            else if(top>=fowd)
            {
                stack->push(fowd);
                while(top-fowd>=fowd)
                {
                    stack->push(fowd);
                    top = top-fowd;
                }
                stack->push(top);
            }
        }
        
        // Initialize
        cout << endl;
        status = true;
        count = 1;
        stack->~Stack();
        stack = new Stack<int>;
    
    }
    
    return 0;
}

void printList(Stack<int> *stack, int &count)
{
    int data = 0;
    Stack<int> *temp = new Stack<int>;
    cout << count << ": ";
    
    do{
        stack->pop(data);
        temp->push(data);
    } while(stack->getCount()!=0);
    
    
    do{
        temp->pop(data);
        cout << data << " ";
        stack->push(data);
    } while(temp->getCount()!=0);
    
    cout << endl;

    ++count;

}