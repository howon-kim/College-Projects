//
//  main.cpp
//  22C_KIM_HOWON_H2
//
//  Created by HOWON KIM on 10/8/15.
//  Copyright © 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "TextEditor.hpp"
using namespace std;

// Character Size
const int SIZE = 100;

//Function Prototype
void welcome();
void readFile(TextEditor &readLine); //
void printTotalLineNumber(TextEditor &printLineNumber);
void printAllLinesFtoL(TextEditor &printLine);
void printAllLinesLtoF(TextEditor &printLine);
void printSelectiveLines(TextEditor &printline, int lineNum, int lineNum2);
void removeSelectiveLines(TextEditor &removeLine, int lineNum, int lineNum2);
void saveFile(TextEditor &saveFile, string filename);
void insertLine(TextEditor &insertLine, int numLine, string insertText);
void help(TextEditor &help);
void about(TextEditor &about);
void quit(TextEditor &quit);
void goodbye();

int main(){
    
    // Class TextEditor
    TextEditor Data;
    
    // Char User's input
    char input[SIZE];
    
    // Processing the user's input data
    // Parse the data
    char *position = 0;
    char *position2 = 0;
    
    int lineNum = 0;    // Line number1
    int lineNum2 = 0;   // Line number 2
    string command =""; // Command
    string filename ="";    // Filename
    string insertText =""; // User's input text
    
    
    /* Program Start */
    // Welcome Screen
    welcome();
    
    /* Reading the Data from the input.txt file and save it to Doubly-Linked List */
    readFile(Data);
    
    /* Looping */
    while (command!= "q" && command!="Q"){
        
        // Read the User's Input
        cin.getline(input,SIZE);
        
        // Take it out the command from user's input
        command = input[0];
        

        if(command == "h" || command == "H" || command == "a" || command == "A" || command == "t" || command == "T" ||command == "f" || command == "F" || command == "b" || command == "B" || command == "q" || command == "Q" || command == "l" || command == "L" || command == "D" || command == "d" || command == "s" || command == "S" || command == "i" || command == "I"){
         
            if(command == "h" || command == "H" || command == "a" || command == "A" || command == "t" || command == "T" ||command == "f" || command == "F" || command == "b" || command == "B" || command == "q" || command == "Q"){
           
                if(input[1] == '\0'){
                    /* Display Instruction */
                    if(command == "h" || command == "H")
                    { help(Data); }
        
                    /* Display Developer's information */
                    if(command == "a" || command == "A")
                    { about(Data); }
        
                    /* Print the total number of lines */
                    if(command == "t" || command == "T")
                    { printTotalLineNumber(Data);}
        
                    /* Print all lines from first to last */
                    if(command == "f" || command == "F")
                    { printAllLinesFtoL(Data); }
        
                    /* Print all lines from last to first */
                    if(command == "b" || command == "B")
                    { printAllLinesLtoF(Data); }
        
                    /* Quit editing the file */
                    if(command == "q" || command == "Q")
                    { quit(Data); }
           
                } else cout << "Command Input Error : Press H for display instruction" << endl;
            }
        
            
            if(command == "l" || command == "L" || command == "D" || command == "d"){
                if(input[1]==' '){
                    // Take out the 1, 2 parsing information
                    position = strchr(input, ' ');
                    position2 = strchr(position+1,' ');
                }
            
                    if(position2!=NULL){ // Input validation
                        // Convert data to interger
                        lineNum = atoi(position);
                        lineNum2 = atoi(position2);
                    
                        /* Display specific range of lines */
                        if(command == "l" || command == "L")
                        { printSelectiveLines(Data, lineNum, lineNum2); }
                    
                        /* Delete Specific range of lines */
                        if(command == "d" || command == "D")
                        { removeSelectiveLines(Data, lineNum, lineNum2); }
                    
                    } else cout << "Command Input Error : Press H for display instruction" << endl;
            }
        
        
        
            /* Save the updated text to an output file */
            if(command == "s" || command == "S"){
                if(input[1]==' '){
                    position = strchr(input, ' ')+1;
                    filename = position;
                    saveFile(Data, filename);
                } else cout << "Command Input Error : Press H for display instruction" << endl;
            }
        
            /* Insert new line of text */
            if(command == "i" || command == "I"){
                if(input[1]==' '){
                    position = strchr(input, ' ');
                    position2 = strchr(position+1,' ');
                }
                if(position2!=NULL){
                    lineNum = atoi(position);
                    insertText = position2+1;
                    insertLine(Data, lineNum, insertText);
                } else cout << "Command Input Error : Press H for display instruction" << endl;
            }
            
        } else cout << "Command Input Error : Press H for display instruction" << endl;
        
    }
    
    
    /* Goodbye Screen */
    goodbye();
    
    return 0;
}

//*****************************************************************************
// Definition of function welcome
// This function displays the welcome screen
//*****************************************************************************

void welcome()
{
    cout << "Welcome to the Circularly Doubly-Linked Lists with sentinel node Project" << endl;
    
}


//*****************************************************************************
// Definition of function readFile
// This function read the input file
// Input Parameter : readLine
//*****************************************************************************

void readFile(TextEditor &readLine){
    
    readLine.read();
}


//*****************************************************************************
// Definition of function quit
// This function quit the program
// Input Parameter : quit
//*****************************************************************************

void quit(TextEditor &save)
{
    save.save();
}


//*****************************************************************************
// Definition of function help
// This function display the instructions
// Input Parameter : help
//*****************************************************************************

void help(TextEditor &help)
{
    help.help();
}


//*****************************************************************************
// Definition of function about
// This function display the developer's information
// Input Parameter : help
//*****************************************************************************

void about(TextEditor &about)
{
    about.about();
}



//*****************************************************************************
// Definition of function saveFile
// This function save the updated text to an output file
// Input Parameter :
// - saveFile
// - filename : user's input for filename
//*****************************************************************************

void saveFile(TextEditor &saveFile, string filename)
{
    saveFile.save(filename);
    return;
    
}

//*****************************************************************************
// Definition of function printTotalLineNumber
// This function display the total number of lines in the text
// Input Parameter : printLineNumber
//*****************************************************************************

void printTotalLineNumber(TextEditor &printLineNumber)
{
    printLineNumber.printLineNumber();
    return;
}


//*****************************************************************************
// Definition of function printAllLinesFtoL
// This function print all lines from first to last
// Input Parameter : printLine
//*****************************************************************************

void printAllLinesFtoL(TextEditor &printLine)
{
    printLine.printFtoL();
    return;
}

//*****************************************************************************
// Definition of function printAllLinesLtoF
// This function print all lines from last to first
// Input Parameter : printLine
//*****************************************************************************

void printAllLinesLtoF(TextEditor &printLine)
{
    printLine.printLtoF();
    return;
}

//*****************************************************************************
// Definition of function printSelectiveLines
// This function print selective lines
// Input Parameter : printLine, lineNum, lineNum2
//*****************************************************************************

void printSelectiveLines(TextEditor &printline, int lineNum, int lineNum2)
{
    printline.print(lineNum, lineNum2);
}


//*****************************************************************************
// Definition of function removeSelectiveLines
// This function remove selective lines
// Input Parameter : removeLine, lineNum, lineNum2
//*****************************************************************************

void removeSelectiveLines(TextEditor &removeLine, int lineNum, int lineNum2)
{
    removeLine.remove(lineNum, lineNum2);
}

//*****************************************************************************
// Definition of insertLine function
// This function insert new line
// Input Parameter : insertLine, numLine, insertText
//*****************************************************************************

void insertLine(TextEditor &insertLine, int numLine, string insertText)
{
    insertLine.insert(numLine, insertText);
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
    cout << "Thank you for using the the Program" << endl;
    cout << "IDE : XCODE 7.0.1 (Mac OS X 10.11)" << endl;
    cout << "Developer : Howon Kim" << endl;
}


/* OUTPUT
 Welcome to the Circularly Doubly-Linked Lists with sentinel node Project
 d 4 4
 f
 1 AAAAAAAAAAAAAAAA
 2 Charles Babbage 1837
 3 Ada Lovelace 1843
 4 George Boole 1847
 5 Kurt Gödel 1931
 6 John Atanasoff 	1943
 7 John von Neumann 1945
 8 Sergei Alekseyevich Lebedev 1951
 9 Grace Hopper 1952
 10 John Backus 1954
 11 Peter Naur 1960
 12 C.A.R. Hoare 1960
 13 DDDDDDDDDD
 14 EEEEEEEEE
 15 FFFFFF
 16 GGGGGGGGGGGGGGG
 17 Kristen Nygaard 1962
 18 Dennis Ritchie 1967
 19 Ken Thompson 1967
 20 Edsger Dijkstra 1968
 21 Donald Knuth 1968
 22 Niklaus Wirth 1970
 23 Sophie Wilson 1981
 24 Tim Berners-Lee 1989
 25 BBBBBBBBBBB
 d 1 1
 f
 1 Charles Babbage 1837
 2 Ada Lovelace 1843
 3 George Boole 1847
 4 Kurt Gödel 1931
 5 John Atanasoff 	1943
 6 John von Neumann 1945
 7 Sergei Alekseyevich Lebedev 1951
 8 Grace Hopper 1952
 9 John Backus 1954
 10 Peter Naur 1960
 11 C.A.R. Hoare 1960
 12 DDDDDDDDDD
 13 EEEEEEEEE
 14 FFFFFF
 15 GGGGGGGGGGGGGGG
 16 Kristen Nygaard 1962
 17 Dennis Ritchie 1967
 18 Ken Thompson 1967
 19 Edsger Dijkstra 1968
 20 Donald Knuth 1968
 21 Niklaus Wirth 1970
 22 Sophie Wilson 1981
 23 Tim Berners-Lee 1989
 24 BBBBBBBBBBB
 d 24 24
 f
 1 Charles Babbage 1837
 2 Ada Lovelace 1843
 3 George Boole 1847
 4 Kurt Gödel 1931
 5 John Atanasoff 	1943
 6 John von Neumann 1945
 7 Sergei Alekseyevich Lebedev 1951
 8 Grace Hopper 1952
 9 John Backus 1954
 10 Peter Naur 1960
 11 C.A.R. Hoare 1960
 12 DDDDDDDDDD
 13 EEEEEEEEE
 14 FFFFFF
 15 GGGGGGGGGGGGGGG
 16 Kristen Nygaard 1962
 17 Dennis Ritchie 1967
 18 Ken Thompson 1967
 19 Edsger Dijkstra 1968
 20 Donald Knuth 1968
 21 Niklaus Wirth 1970
 22 Sophie Wilson 1981
 23 Tim Berners-Lee 1989
 i 1 Blaise Pascal 1642
 f
 1 Blaise Pascal 1642
 2 Charles Babbage 1837
 3 Ada Lovelace 1843
 4 George Boole 1847
 5 Kurt Gödel 1931
 6 John Atanasoff 	1943
 7 John von Neumann 1945
 8 Sergei Alekseyevich Lebedev 1951
 9 Grace Hopper 1952
 10 John Backus 1954
 11 Peter Naur 1960
 12 C.A.R. Hoare 1960
 13 DDDDDDDDDD
 14 EEEEEEEEE
 15 FFFFFF
 16 GGGGGGGGGGGGGGG
 17 Kristen Nygaard 1962
 18 Dennis Ritchie 1967
 19 Ken Thompson 1967
 20 Edsger Dijkstra 1968
 21 Donald Knuth 1968
 22 Niklaus Wirth 1970
 23 Sophie Wilson 1981
 24 Tim Berners-Lee 1989
 i 25 Robert Cailliau 1989
 f
 1 Blaise Pascal 1642
 2 Charles Babbage 1837
 3 Ada Lovelace 1843
 4 George Boole 1847
 5 Kurt Gödel 1931
 6 John Atanasoff 	1943
 7 John von Neumann 1945
 8 Sergei Alekseyevich Lebedev 1951
 9 Grace Hopper 1952
 10 John Backus 1954
 11 Peter Naur 1960
 12 C.A.R. Hoare 1960
 13 DDDDDDDDDD
 14 EEEEEEEEE
 15 FFFFFF
 16 GGGGGGGGGGGGGGG
 17 Kristen Nygaard 1962
 18 Dennis Ritchie 1967
 19 Ken Thompson 1967
 20 Edsger Dijkstra 1968
 21 Donald Knuth 1968
 22 Niklaus Wirth 1970
 23 Sophie Wilson 1981
 24 Tim Berners-Lee 1989
 25 Robert Cailliau 1989
 i 6 Alan Turing 1936
 f
 1 Blaise Pascal 1642
 2 Charles Babbage 1837
 3 Ada Lovelace 1843
 4 George Boole 1847
 5 Kurt Gödel 1931
 6 Alan Turing 1936
 7 John Atanasoff 	1943
 8 John von Neumann 1945
 9 Sergei Alekseyevich Lebedev 1951
 10 Grace Hopper 1952
 11 John Backus 1954
 12 Peter Naur 1960
 13 C.A.R. Hoare 1960
 14 DDDDDDDDDD
 15 EEEEEEEEE
 16 FFFFFF
 17 GGGGGGGGGGGGGGG
 18 Kristen Nygaard 1962
 19 Dennis Ritchie 1967
 20 Ken Thompson 1967
 21 Edsger Dijkstra 1968
 22 Donald Knuth 1968
 23 Niklaus Wirth 1970
 24 Sophie Wilson 1981
 25 Tim Berners-Lee 1989
 26 Robert Cailliau 1989
 h
 >> Instruction <<
 T : Display the total number of lines in the text
 F : Print all lines from first to last (show the line numbers: 1, 2, 3, etc.)
 B : Print all lines from last to first (show the line numbers)
 I : Insert the new line of text to the selective line
 I(Line number)(Text)
 - I 3 This is the new line of text to be inserted
 - Insert a new line of text at position 3 in the list
 D : Delete selective lines
 D(Line number1)(Line number2)
 - D 3 7 : Delete lines 3 to 7 inclusive
 - D 7 3 : Delete lines 7 to 3 inclusive
 L : Show the selective lines and line numbers
 L(Line number1)(Line number2)
 - L 2 5 : List lines 2 to 5 inclusive
 - L 5 2 : List lines 5 to 2 inclusive, in reverse order
 S : Save the file
 S(Output file name)
 - S out.txt : Save the updated text to an output file
 H : Display instructions for T,F,B,I,L,D,S,H,A and Q
 A : About: Display information about the developer
 Q : Quit editing the file (save it to backup.txt)
 a
 >> About <<
 Developer : Howon Kim
 Class : CIS22C
 Professor : Delia Garbacea
 Quarter : 2015.Fall
 Date : Oct.2015
 College : De Anza College
 Program Based on Circularly Doubly-Linked List with Sentinel Node
 Tested on Xcode 7.0.1, Mac OS X 10.11 El Capitan
 s text.txt
 File was saved to text.txt
 d 1 10
 f
 1 John Backus 1954
 2 Peter Naur 1960
 3 C.A.R. Hoare 1960
 4 DDDDDDDDDD
 5 EEEEEEEEE
 6 FFFFFF
 7 GGGGGGGGGGGGGGG
 8 Kristen Nygaard 1962
 9 Dennis Ritchie 1967
 10 Ken Thompson 1967
 11 Edsger Dijkstra 1968
 12 Donald Knuth 1968
 13 Niklaus Wirth 1970
 14 Sophie Wilson 1981
 15 Tim Berners-Lee 1989
 16 Robert Cailliau 1989
 l 7 16
 7 GGGGGGGGGGGGGGG
 8 Kristen Nygaard 1962
 9 Dennis Ritchie 1967
 10 Ken Thompson 1967
 11 Edsger Dijkstra 1968
 12 Donald Knuth 1968
 13 Niklaus Wirth 1970
 14 Sophie Wilson 1981
 15 Tim Berners-Lee 1989
 16 Robert Cailliau 1989
 l 1 12
 1 John Backus 1954
 2 Peter Naur 1960
 3 C.A.R. Hoare 1960
 4 DDDDDDDDDD
 5 EEEEEEEEE
 6 FFFFFF
 7 GGGGGGGGGGGGGGG
 8 Kristen Nygaard 1962
 9 Dennis Ritchie 1967
 10 Ken Thompson 1967
 11 Edsger Dijkstra 1968
 12 Donald Knuth 1968
 l 8 3
 8 Kristen Nygaard 1962
 7 GGGGGGGGGGGGGGG
 6 FFFFFF
 5 EEEEEEEEE
 4 DDDDDDDDDD
 3 C.A.R. Hoare 1960
 l 10 2
 10 Ken Thompson 1967
 9 Dennis Ritchie 1967
 8 Kristen Nygaard 1962
 7 GGGGGGGGGGGGGGG
 6 FFFFFF
 5 EEEEEEEEE
 4 DDDDDDDDDD
 3 C.A.R. Hoare 1960
 2 Peter Naur 1960
 b
 16 Robert Cailliau 1989
 15 Tim Berners-Lee 1989
 14 Sophie Wilson 1981
 13 Niklaus Wirth 1970
 12 Donald Knuth 1968
 11 Edsger Dijkstra 1968
 10 Ken Thompson 1967
 9 Dennis Ritchie 1967
 8 Kristen Nygaard 1962
 7 GGGGGGGGGGGGGGG
 6 FFFFFF
 5 EEEEEEEEE
 4 DDDDDDDDDD
 3 C.A.R. Hoare 1960
 2 Peter Naur 1960
 1 John Backus 1954
 t
 Total Number of Lines : 16
 q
 File was saved to backup.txt
 Thank you for using the the Program
 IDE : XCODE 7.0.1 (Mac OS X 10.11)
 Developer : Howon Kim
 Program ended with exit code: 0
*/