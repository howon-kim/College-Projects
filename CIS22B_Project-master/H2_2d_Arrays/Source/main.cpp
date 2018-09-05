/**
 CIS 22B - Homework 2 : 2D Arrays
 Project: Friends
 
 Name: HOWON KIM
 IDE: XCODE 6.3.1 (MAC OS X 10.03)
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// !!!! DECLARE GLOBAL CONSTANT FOR SIZE OF ARRAY !!!! //
const int SIZE = 80;

// FUNCTION PROTOTYPE
void readFriendsData(string list_name[], int num_friends[][SIZE], int &num_current);
void displayTable(const string table_name[], const int table_friends[][SIZE], const int table_num);
void countFriends(const int count_friends[][SIZE], int count_numfriends[], const int count_num);
void displayList(const string list_name[], const int list_friends[][SIZE], const int list_numfriends[], const int list_num);
void displayGroup(const string group_name[], const int group_friends[][SIZE], const int group_num);


int main()
{
    cout << "<< START THE PROGRAM >>" << endl
    << ">> MADE BY : HOWON KIM" << endl
    << ">> IDE : XCODE 6.3.1 (MAC OS X 10.3)" << endl << endl;
    
    // Local Variable
    string name[SIZE] = {""}; // Students name
    int friends[SIZE][SIZE] = {0}; // Students friends
    int num_friends[SIZE] = {0}; // Number of friends for each student
    int number = 0; // Number of current students
    
    // readFriendsData Function
    readFriendsData(name, friends, number);
    
    // displayTable Function
    displayTable(name, friends, number);
    
    // countFriends Function
    countFriends(friends, num_friends, number);
    
    // displayList Function
    displayList(name, friends, num_friends, number);
    
    // displayGroup Function
    displayGroup(name, friends, number);
    
    // Finish the program
    cout << "<< Thank you for using my program! >>" << endl
    << ">> Developer : howonkim@me.com" << endl;
    return 0;
}

/****************************************************************************************
 
 * readFriendsData
 - This function read the data from text file and save data into the array and variable
 
 - Input Parameter
 - list_name[] : for save the list of name
 - num_friends[][] : for save the relations of friends
 - num_current : for save the current number of students
 
 - Output Parameter / Return value
 - Function does not return anything
 
 ****************************************************************************************/

void readFriendsData(string list_name[], int num_friends[][SIZE], int &num_current)
{
    cout << "<< readFriendsData FUNCTION STARTED >>" << endl;
    ifstream readFile;
    
    cout << ">> Open the 3club.txt file" << endl;
    readFile.open("/Users/HWKIM/Desktop/22B_KIM_HOWON_H2/22B_KIM_HOWON_H2/3club.txt");
    //!!!! FILE - OPEN VALIDATION !!!!//
    if(!readFile)
    {
        cout << "Can't open input file" << endl;
        exit(111);
    }
    
    cout << ">> Successfully opened the file!" << endl << endl;
    
    
    
    cout << ">> Read number of current students in the club" << endl;
    readFile>>num_current;
    /* Check the data */
    /*
     cout<<"num_current : "<<num_current<<endl;
     */
    
    //!!!! ARRAY SIZE VALIDATION !!!!//
    if(num_current>SIZE)
    {
        cout << "Number of data is too large to process, stop program" << endl;
        exit(10);
    }
    
    cout << ">> Successfully read number of current students!" << endl << endl;
    
    cout << ">> Read students name and save it into the list_name array" << endl;
    for(int i=0;i<num_current;i++)
    {
        readFile>>list_name[i];
    }
    /* Check the data */
    /*
     for(int i=0;i<num_current;i++)
     {
     cout<<list_name[i];
     cout<<endl;
     }
     */
    
    
    cout << ">> Successfully read students name and save it into the list_name array!" << endl << endl;
    
    cout << ">> Read number of friends and save it into the num_friends array" << endl;
    for(int r=0;r<num_current;r++)
    {
        for(int c=0;c<num_current;c++)
        {
            readFile>>num_friends[r][c];
        }
    }
    /* Check the data */
    /*
     for(int r=0;r<num_current;r++)
     {
     cout<<"row : "<<r<<endl;
     for(int c=0;c<num_current;c++)
     {
     cout<<"column: "<<c<<" = "<<num_friends[r][c]<<endl;
     }
     cout<<endl;
     }
     */
    cout << ">> Successfully read number of friends and save it into the num_friends array!" << endl << endl;
    
    readFile.close();
    cout << ">> Successfully closed the file" << endl;
    cout << "<< Successfully finished readFriendsData FUNCTION >>" << endl << endl;
    return;
}

/****************************************************************************************
 
 * displayTable function
 - This function prints out the friend table with the student name
 
 - Input Parameter
 - table_name[] : to access the student names
 - table_frieds[][] : to access the student relationships
 - table_num : size as the number of students in the club
 
 - Output Parameter / Return value
 - Function does not return anything
 
 ****************************************************************************************/

void displayTable(const string table_name[],const int table_friends[][SIZE],const int table_num)
{
    cout<< "<< displayTable FUNCTION STARTED >>" << endl;
    
    cout << "    | ";
    // Display name
    for(int i=0;i<table_num;i++)
    {
        cout << table_name[i];
        cout << " ";
    }
    
    // Second row (Display line)
    cout << endl << "---   ";
    for(int i=0;i<table_num;i++)
    {
        cout << "---";
        cout << " ";
    }
    cout << endl;
    
    // Display name and relationship between friends
    for(int r=0;r<table_num;r++)
    {
        cout << table_name[r];
        cout << " |  ";
        for(int c=0;c<table_num;c++)
        {
            cout << table_friends[r][c];
            cout << "   ";
        }
        cout << endl;
    }
    
    cout << "<< Successfully finished displayTable FUNCTION >>" << endl << endl;
    return;
}

/****************************************************************************************
 
 * countFriends
 - This function count the number of friends to each student
 
 - Input Parameter
 - count_friends[][] : access relationship of friends
 - count_numfriends[] : save total number of friends
 - count_num : access the total number of students
 
 - Output Parameter / Return value
 - Function does not return anything
 
 ****************************************************************************************/

void countFriends(const int count_friends[][SIZE], int count_numfriends[], const int count_num)
{
    cout << "<< countFriends FUNCTION STARTED >>" << endl;
    
    // Count current person's number of friends
    for(int r=0;r<count_num;r++)
    {
        for(int c=0;c<count_num;c++)
        {
            if(count_friends[r][c]==1)
            {
                count_numfriends[r]++;
            }
        }
    }
    
    // Validate data
    /*
     for(int i=0;i<count_num;i++)
     {
     cout<<count_numfriends[i]<<endl;
     }
     */
    
    cout << "<< Successfully finished countFriends FUNCTION >>" << endl << endl;
    return;
}

/****************************************************************************************
 
 * displayList
 - This function display the number of friends and list of the friends
 
 - Input Parameter
 - list_name[] : display the name of each student
 - list_friends[][] : access relationship of friends
 - list_numfriends[] : access number of friends of each student
 - list_num : access total number of students
 
 - Output Parameter / Return value
 - Function does not return anything
 
 ****************************************************************************************/

void displayList(const string list_name[],const int list_friends[][SIZE],const int list_numfriends[],const int list_num)
{
    cout << "<< displayList FUNCTION STARTED >>" << endl;
    
    // Variable for find the end of data
    int count=0;
    
    // Display current person's number of friends
    for(int r=0;r<list_num;r++)
    {
        // If someone have friends do this
        if(list_numfriends[r]>0)
        {
            // Display current person's name
            cout << list_name[r];
            
            // Display current person's number of friends
            cout << " ("
            << list_numfriends[r]
            << "): ";
            
            // Display current person's name of friends
            for(int c=0;c<list_num;c++)
            {
                if(list_friends[r][c]==1)
                {
                    cout << list_name[c];
                    count++;
                    
                    if(count==list_numfriends[r])
                    {
                        count=0;
                        cout << endl;
                        continue;
                    }
                    cout << ", ";
                }
            }
        }
    }
    cout << "<< Successfully finished displayList FUNCTION >>" << endl << endl;
    return ;
}

/****************************************************************************************
 
 * displayGroup
 - This function displays the relationship of friends by name
 
 - Input Parameter
 - group_name[] : display the name of each student's name
 - group_friends[][] : access the relationship of friends
 - group_num : access the total number of students
 
 - Output Parameter / Return value
 - Function does not return anything
 
 ****************************************************************************************/

void displayGroup(const string group_name[],const int group_friends[][SIZE],const int group_num)
{
    cout << "<< displayGroup FUNCTION STARTED >>" << endl;
    
    for(int r=0;r<group_num;r++)
    {
        int c=r+1; // variable for display opponent friend
        for(;c<group_num;c++)
        {
            if(group_friends[r][c]==1)
            {
                cout << group_name[r];
                cout << " - ";
                cout << group_name[c];
                cout << endl;
            }
        }
    }
    cout << "<< Successfully finished displayGroup FUNCTION >>" << endl << endl;
    return;
}

/** OUTPUT
 Last login: Mon Apr 20 16:46:25 on ttys001
 admin:~ HWKIM$ /Users/HWKIM/Library/Developer/Xcode/DerivedData/22B_KIM_HOWON_H2-eogyrlmcdctssyervrftiemsiaji/Build/Products/Debug/22B_KIM_HOWON_H2 ; exit;
 << START THE PROGRAM >>
 >> MADE BY : HOWON KIM
 >> IDE : XCODE 6.3.1 (MAC OS X 10.3)
 
 << readFriendsData FUNCTION STARTED >>
 >> Open the 3club.txt file
 >> Successfully opened the file!
 
 >> Read number of current students in the club
 >> Successfully read number of current students!
 
 >> Read students name and save it into the list_name array
 >> Successfully read students name and save it into the list_name array!
 
 >> Read number of friends and save it into the num_friends array
 >> Successfully read number of friends and save it into the num_friends array!
 
 >> Successfully closed the file
 << Successfully finished readFriendsData FUNCTION >>
 
 << displayTable FUNCTION STARTED >>
 | Ami Ann Ben Dan Ema Ira Guy Leo Luc Meg Sue Tom
 ---   --- --- --- --- --- --- --- --- --- --- --- ---
 Ami |  0   0   0   0   0   0   0   1   0   0   1   0
 Ann |  0   0   0   0   0   0   0   0   1   1   0   0
 Ben |  0   0   0   1   0   0   0   0   1   0   0   0
 Dan |  0   0   1   0   0   0   0   0   1   0   0   0
 Ema |  0   0   0   0   0   0   0   0   0   0   0   0
 Ira |  0   0   0   0   0   0   1   0   0   0   0   0
 Guy |  0   0   0   0   0   1   0   0   0   0   0   0
 Leo |  1   0   0   0   0   0   0   0   0   0   0   0
 Luc |  0   1   1   1   0   0   0   0   0   1   0   0
 Meg |  0   1   0   0   0   0   0   0   1   0   0   0
 Sue |  1   0   0   0   0   0   0   0   0   0   0   0
 Tom |  0   0   0   0   0   0   0   0   0   0   0   0
 << Successfully finished displayTable FUNCTION >>
 
 << countFriends FUNCTION STARTED >>
 << Successfully finished countFriends FUNCTION >>
 
 << displayList FUNCTION STARTED >>
 Ami (2) : Leo, Sue
 Ann (2) : Luc, Meg
 Ben (2) : Dan, Luc
 Dan (2) : Ben, Luc
 Ira (1) : Guy
 Guy (1) : Ira
 Leo (1) : Ami
 Luc (4) : Ann, Ben, Dan, Meg
 Meg (2) : Ann, Luc
 Sue (1) : Ami
 << Successfully finished displayList FUNCTION >>
 
 << displayGroup FUNCTION STARTED >>
 Ami - Leo
 Ami - Sue
 Ann - Luc
 Ann - Meg
 Ben - Dan
 Ben - Luc
 Dan - Luc
 Ira - Guy
 Luc - Meg
 << Successfully finished displayGroup FUNCTION >>
 
 << Thank you for using my program! >>
 >> Developer : howonkim@me.com
 logout
 
 [Process completed]
 **/
