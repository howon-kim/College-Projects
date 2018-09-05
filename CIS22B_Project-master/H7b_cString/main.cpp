//
//  22B_KIM_HOWON_H7B
//  Projects 1, 2, and 3, page 594
//
//  Demonstrate these functions in ONE program: ask the user to enter a string
//  then call the first function (Project 1), the second function (Project 2), and the third function (Project 3).
//
//  Created by HOWON KIM on 6/16/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Global section variable
const int SIZE = 101;

// Function Prototype
void welcome();
int stringLength (char * const slStringVal);
void backwardString (char * const bsStringVal, const int bsSize);
int wordCounter (char * const wcStringVal, const int wcSize);
void goodbye();


int main()
{
    char stringVal[SIZE]; // C-String variable
    int size = 0; // Actual size of C-String variable
    int numWord = 0; // Number of words
    
    welcome();
    
    cout << "Enter the string (Maximum characters : " << SIZE-1 << ") : ";
    cin.get(stringVal,SIZE);


    size = stringLength(stringVal);
    backwardString(stringVal, size);
    numWord = wordCounter(stringVal, size);

    goodbye();
    
    return 0;
}

//*****************************************************************************
// Definition of function welcome
// This function displays the welcome screen
// Input Parameter : none
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void welcome()
{
    cout << "Welcome to the C-String Project" << endl;
    cout << "______________________________________________" << endl << endl;
}


//*****************************************************************************
// Definition of function stringLength
// This function calculate the length of string
// Input Parameter
// - slStringVal : Access the C-String
// Output Parameter : none
// Return Value
// - actualSize : Save actual size of the string
//*****************************************************************************

int stringLength (char * const slStringVal)
{
    int actualSize = 0;
    
    cout << endl << "1. Calculate String Length" << endl;
    
    actualSize = strlen(slStringVal);
    
    cout << "String Length : " << actualSize << endl;
    cout << "___________________" << endl;

    return actualSize;
}


//*****************************************************************************
// Definition of function backwardString
// This function reverse the string
// Input Parameter
// - bsStringVal : Access the C-String
// - bsSize : Access the actual size of the string
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void backwardString (char * const bsStringVal, const int bsSize)
{
    cout << endl << "2. Reverse Display" << endl;
    
    for (int i = bsSize-1 ; i >= 0 ; i--)
    {
        cout << bsStringVal[i];
    }
    
    cout << endl << "___________________" << endl;
}


//*****************************************************************************
// Definition of function wordCounter
// This function counts the number of words
// Input Parameter
// - wcStringVal : Access the C-String
// - wcSize : Access the actual size of the string
// Output Parameter : none
// Return Value
// - numberWord : Save the number of words in the string
//*****************************************************************************

int wordCounter (char * const wcStringVal, const int wcSize)
{
    int numberWord = 0;
    int index = 0;

    cout << endl << "3. Count the words" << endl;
    
    while(index<wcSize)
    {
        if(isalnum(wcStringVal[index]) || ispunct(wcStringVal[index]))
        {
            while(isalnum(wcStringVal[index]) || ispunct(wcStringVal[index]))
            {
                index++;
            }
            
            numberWord++;
        }
        index++;
    }
    
    cout << "Number of Words : " << numberWord << endl;

    return numberWord;
}

//*****************************************************************************
// Definition of function goodbye
// This function displays the goodbye screen
// Input Parameter : none
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void goodbye()
{
    cout << endl << "______________________________________________" << endl << endl;
    cout << "Thank you for using the C-String Project" << endl;
    cout << "IDE : XCODE 6.3.2 (Mac OS X 10.04)" << endl;
    cout << "Developer : Howon Kim" << endl;
}

/* OUTPUT
 Welcome to the C-String Project
 ______________________________________________
 
 Enter the string (Maximum characters : 100) : My name is howon kim. Nice to meet you!
 
 1. Calculate String Length
 String Length : 39
 ___________________
 
 2. Reverse Display
 !uoy teem ot eciN .mik nowoh si eman yM
 ___________________
 
 3. Count the words
 Number of Words : 9
 
 ______________________________________________
 
 Thank you for using the C-String Project
 IDE : XCODE 6.3.2 (Mac OS X 10.04)
 Developer : Howon Kim

 */