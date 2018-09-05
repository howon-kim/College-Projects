//
//  Palindrome.cpp
//
//  Created by HOWON KIM on 1/20/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "Queue.h"
#include "Stack.h"
using namespace std;


// Function Prototype
char *convertStringtoChar(string text);
bool compareString (Stack &stack, Queue &queue);
void displayResult (bool check, string text);
void insertNumberstoStackandQueue (char *convert, string text, Stack &stack, Queue &queue);

int main(int argc, const char * argv[]) {
    
    Stack stack;
    Queue queue;
    string text;
    char *convert;
    bool check;
    
    
    // File Open
    ifstream infile;
    infile.open("palindrome.txt");
    
    // File Validation
    if(!infile)
    {
        cout << "file open error" << endl;
        exit(111);
    }
    

    // Read Line
    while (getline(infile, text))
    {
        // Convert String to Character
        convert = convertStringtoChar(text);

        // Insert Characters to Stack and Queue
        insertNumberstoStackandQueue(convert, text, stack, queue);
        
        // Compare the String
        check = compareString(stack, queue);
        
        // Display the Result
        displayResult(check, text);
        
        check = true;
    }
    

    return 0;
}


void insertNumberstoStackandQueue (char *convert, string text, Stack &stack, Queue &queue)
{
    string input;
    for(int i = 0; i<text.length(); i++)
    {
        if(convert[i] != ' ')
        {
            input = tolower(convert[i]);
            stack.push(input);
            queue.enqueue(input);
        }
    }
}


void displayResult (bool check, string text)
{
    if(check == true)
        cout << text << " is a palindrome" << endl;
    else
        cout << text << " isn't a palindrome" << endl;
}



bool compareString (Stack &stack, Queue &queue)
{
    bool status = true;
    
    while(!queue.is_empty())
    {
        if(stack.get_top() != queue.get_front())
            status = false;
        
        stack.pop();
        queue.dequeue();
    }
    return status;
}


char *convertStringtoChar (string text)
{
    char *process = new char [text.length() + 1];
    strcpy(process, text.c_str());
    
    return process;
}