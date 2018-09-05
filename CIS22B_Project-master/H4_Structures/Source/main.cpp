//
//  Homework4 : Arrays and Structures
//  22B_KIM_HOWON_H4
//  Project : Best Colleges
//
//  Created by HOWON KIM on 5/11/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Declare Structure
struct College
{
    int rank;
    string name;
    int found;
    string site;
    double gradTransRate;
    double fRetentionRate;
    int lCost;
    int hCost;
    int students;
};

// Function Prototype
void welcome();
College *readCollegeInfo(int &rsize);
void displayDataManager (const College *list, const int dmsize);
void printList (const College *list, const int plsecond);
void printCollege (const College *list, int point);
void searchManager (const College *list, int smsize);
int binarySearch(const College *list, int numElems, int value);
void goodbye();



int main()
{
    // Declare Variables
    int size = 0; // number of colleges
    int choice = -1; // for menu
    
    // Declare Pointer
    College *list = nullptr;
    
    // Welcome Function
    welcome();

    // Read College Information
    list = readCollegeInfo(size);

    // Menu Start
    while(choice!=0)
    {
        cout << "===== WELCOME TO THE COLLEGE FINDER =====" << endl
        << "      0. End Program" << endl
        << "      1. Display Data Manager" <<endl
        << "      2. Search Manager" << endl << endl
        << "      Enter the number : ";
        cin >> choice;
        
        switch(choice)
        {
            case 0 : break;
            case 1 : displayDataManager(list,size); break;
            case 2 : searchManager(list, size); break;
            default : cout << "      Incorrect number!" << endl << endl;

        }
    }
    
    // Release the memory
    delete [] list;
    
    // Finish the program
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

void welcome ()
{
    cout << "***** WELCOME TO HOWONKIM'S PROGRAM *****" << endl;
    return ;
}


//*****************************************************************************
// Definition of function readCollegeInfo
// This function read integers from scores.txt file
// Input Parameter : none
// Output Parameter : rsize : size as the number of the colleges
// Return Value : info : return address of the dynamically allocated arrays
//*****************************************************************************

College *readCollegeInfo(int &rsize)
{
    // Declare pointer
    College *info = nullptr;
    
    cout << "----- READCOLLEGEINFO FUNCTION -----" << endl;
    ifstream infile;
    infile.open("/Users/HWKIM/Desktop/22B_KIM_HOWON_H4/22B_KIM_HOWON_H4/CA_BestColleges.txt");
    
    if(!infile)
    {
        cout << ">>      Can't open the file" << endl;
        exit(111);
    }
    cout << "      Succeed to open CA_BestColleges.txt" << endl;
    
    // Read number of colleges
    infile >> rsize;
    
    // Create dynamically allocate arrays
    info = new College[rsize];
    
    // Read college info
    for(int i=0; i<rsize; i++)
    {
        infile >> info[i].rank;
        infile.ignore();
        getline(infile, info[i].name);
        infile >> info[i].found;
        infile.ignore();
        getline(infile, info[i].site);
        infile >> info[i].gradTransRate;
        infile >> info[i].fRetentionRate;
        infile >> info[i].lCost;
        infile >> info[i].hCost;
        infile >> info[i].students;
    }
    

    
    // Close the file
    infile.close();
    
    cout << "----- FINISH READCOLLEGEINFO FUNCTION -----" << endl;

    return info;
}

//*****************************************************************************
// Definition of function printCollege
// This function prints the fields of College structure
// Input Parameter
// - list : access the colleges
// - point : location for display colleges
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void printCollege (const College *list, int point)
{
    cout << endl << "----- PRINTCOLLEGE FUNCTION -----" << endl;
    cout << "Rank: " << list[point].rank << endl;
    cout << "School Name: " << list[point].name << endl;
    cout << "Year Founded: " << list[point].found << endl;
    cout << "Website: " << list[point].site << endl;
    cout << fixed << showpoint << setprecision(1)
         << "Graduation and Transfer Rate: " << list[point].gradTransRate << "%" << endl;
    cout << fixed << showpoint << setprecision(1)
         << "First Year Retention Rate: " << list[point].fRetentionRate << "%" << endl;
    cout << "Cost of Attendance: $" << list[point].lCost << " - $"
         << list[point].hCost << endl;
    cout << "Number of Students: approx. " << list[point].students << endl << endl;
    cout << "----- FINISH PRINTCOLLEGE FUNCTION -----" << endl;

}

//*****************************************************************************
// Definition of function printList
// This function display the certain range of colleges
// Input Parameter
// - list : access the colleges (location : first order to display college)
// - plsecond : number for display colleges
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void printList (const College *list, const int plsecond)
{
    cout << endl << "----- PRINTLIST FUNCTION -----" << endl;

    for(int i=0; i < plsecond; i++)
    {
        printCollege(list, i);
    }

    
    cout << endl << "----- FINISH PRINTLIST FUNCTION -----" << endl;

    return ;
}

//***************************************************************************************************
// Definition of function displayDataManager
// This function display the certain range of colleges by execute printList, printCollege functions
// Input Parameter
// - list : access the colleges
// - dmsize : number of the colleges
// Output Parameter : none
// Return Value : none
//***************************************************************************************************

void displayDataManager (const College *list, const int dmsize)
{
    cout << endl << "===== WELCOME TO DISPLAY DATA MANAGER =====" <<endl;
    
    int first = -1, second = -1;
    
    while(first != 0 || second != 0)
    {
        cout << "      Enter two numbers for display consecutive schools" << endl
             << "      (Range : 0 ~ 14)" << endl
             << "      (For finish the function enter 0 0)" << endl << endl
             << "      Enter the number : ";
        
        cin >> first >> second;
        cout << endl;

        if (first >= 0 && (first + second) <= dmsize) // 15 Colleges
        {
            printList(&list[first],second);
            
        }
    }
    
    cout << endl << "===== FINISH DISPLAY DATA MANAGER =====" <<endl;

    return;
}


//*****************************************************************************
// Definition of function searchManager
// This function display the colleges that match the founded year that user entered by execute binarySearch, printCollege function
// Input Parameter
// - list : access the colleges
// - smsize : number of the colleges
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void searchManager (const College *list, int smsize)
{
    cout << endl << "===== WELCOME TO SEARCH MANAGER =====" <<endl;

    // Local Variables
    int year = 0;
    int result = 0;
    int temp = 0; // for save the original value of result
    
    while (1)
    {
        cout << "      Enter the founded year to find the matching college" << endl
             << "      (For finish the function enter 0)" << endl << endl
             << "      Enter the number : ";
        cin >> year;

        if(year == 0)
        {
            cout << "      Year is 0. Finish the function";
            cout << endl << "===== FINISH SEARCH MANAGER =====" << endl << endl;
            return;
        }
        
        result = binarySearch(list, smsize, year);
        
        if(result == -1)
        {
            cout << "      Not found" << endl << endl;
        }
        
        else
        {
            printCollege(list, result);
            temp = result;
        
            while(list[result-1].found == year)
            {
                result--;
                printCollege(list, result);
            
            }
           
            result = temp; // return original value
    
            while(list[result+1].found == year)
            {
                result++;
                printCollege(list, result);
            }
        }
    }
    return ;
}

//***************************************************************
// Definition of binarySearch function                          *
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of numElems        *
// elements, is searched for the number stored in value. If the *
// number is found, its array subscript is returned. Otherwise, *
// -1 is returned indicating the value was not in the array.    *
//***************************************************************

int binarySearch(const College *list, int numElems, int value)
{
    cout << endl << "===== WELCOME TO BINARYSEARCH =====" <<endl;

    int first = 0,			 // First array element
    last = numElems - 1, // Last array element
    middle,				 // Midpoint of search
    position = -1;		 // Position of search value
    bool found = false;		 // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;  // Calculate midpoint
        if (list[middle].found == value)	  // If value is found at mid
        {
            found = true;
            position = middle;
        }
        
        else if (list[middle].found > value) // If value is in lower half
            last = middle - 1;
        
        else
            first = middle + 1;			// If value is in upper half
    }
    
    cout << endl << "===== FINISH BINARYSEARCH =====" <<endl;

    return position;
}


//*****************************************************************************
// Definition of function goodbye
// This function display the farewell message
// Input Parameter : none
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void goodbye()
{
    cout << "***** THANK YOU FOR USING MY PROGRAM *****" << endl
         << "***** IDE : XCODE *****" << endl;
    return;
}

/* OUTPUT
 Last login: Wed May 20 21:05:08 on ttys005
 admin:~ HWKIM$ /Users/HWKIM/Library/Developer/Xcode/DerivedData/22B_KIM_HOWON_H4-dddgmzxziedfxuaumugosgrbudcz/Build/Products/Debug/22B_KIM_HOWON_H4 ; exit;
 ***** WELCOME TO HOWONKIM'S PROGRAM *****
 ----- READCOLLEGEINFO FUNCTION -----
 Succeed to open CA_BestColleges.txt
 ----- FINISH READCOLLEGEINFO FUNCTION -----
 ===== WELCOME TO THE COLLEGE FINDER =====
 0. End Program
 1. Display Data Manager
 2. Search Manager
 
 Enter the number : 1
 
 ===== WELCOME TO DISPLAY DATA MANAGER =====
 Enter two numbers for display consecutive schools
 (Range : 0 ~ 14)
 (For finish the function enter 0 0)
 
 Enter the number : 13 2
 
 Enter two numbers for display consecutive schools
 (Range : 0 ~ 14)
 (For finish the function enter 0 0)
 
 Enter the number : 13 1
 
 
 ----- PRINTLIST FUNCTION -----
 
 ----- PRINTCOLLEGE FUNCTION -----
 Rank: 13
 School Name: Lake Tahoe Community College
 Year Founded: 1975
 Website: http://www.ltcc.edu
 Graduation and Transfer Rate: 48.0%
 First Year Retention Rate: 82.8%
 Cost of Attendance: $14199 - $19620
 Number of Students: approx. 3000
 
 ----- FINISH PRINTCOLLEGE FUNCTION -----
 
 ----- PRINTCOLLEGE FUNCTION -----
 Rank: 9
 School Name: Irvine Valley College
 Year Founded: 1985
 Website: http://www.ivc.edu
 Graduation and Transfer Rate: 51.1%
 First Year Retention Rate: 90.3%
 Cost of Attendance: $14415 - $20577
 Number of Students: approx. 14384
 
 ----- FINISH PRINTCOLLEGE FUNCTION -----
 
 ----- FINISH PRINTLIST FUNCTION -----
 Enter two numbers for display consecutive schools
 (Range : 0 ~ 14)
 (For finish the function enter 0 0)
 
 Enter the number : 0 0
 
 
 ----- PRINTLIST FUNCTION -----
 
 ----- PRINTCOLLEGE FUNCTION -----
 Rank: 3
 School Name: Santa Barbara City College
 Year Founded: 1909
 Website: http://www.sbcc.edu
 Graduation and Transfer Rate: 53.8%
 First Year Retention Rate: 83.4%
 Cost of Attendance: $11882 - $18524
 Number of Students: approx. 30687
 
 ----- FINISH PRINTCOLLEGE FUNCTION -----
 
 ----- FINISH PRINTLIST FUNCTION -----
 
 ===== FINISH DISPLAY DATA MANAGER =====
 ===== WELCOME TO THE COLLEGE FINDER =====
 0. End Program
 1. Display Data Manager
 2. Search Manager
 
 Enter the number : 2
 
 ===== WELCOME TO SEARCH MANAGER =====
 Enter the founded year to find the matching college
 (For finish the function enter 0)
 
 Enter the number : 1933
 
 ===== WELCOME TO BINARYSEARCH =====
 
 ===== FINISH BINARYSEARCH =====
 Not found
 
 Enter the founded year to find the matching college
 (For finish the function enter 0)
 
 Enter the number : 1947
 
 ===== WELCOME TO BINARYSEARCH =====
 
 ===== FINISH BINARYSEARCH =====
 
 ----- PRINTCOLLEGE FUNCTION -----
 Rank: 15
 School Name: Palo Verde College
 Year Founded: 1947
 Website: http://www.paloverde.edu
 Graduation and Transfer Rate: 31.2%
 First Year Retention Rate: 82.7%
 Cost of Attendance: $14266 - $18266
 Number of Students: approx. 3898
 
 ----- FINISH PRINTCOLLEGE FUNCTION -----
 
 ----- PRINTCOLLEGE FUNCTION -----
 Rank: 2
 School Name: Orange Coast College
 Year Founded: 1947
 Website: http://www.orangecoastcollege.edu
 Graduation and Transfer Rate: 54.2%
 First Year Retention Rate: 91.2%
 Cost of Attendance: $20244 - $26346
 Number of Students: approx. 25000
 
 ----- FINISH PRINTCOLLEGE FUNCTION -----
 Enter the founded year to find the matching college
 (For finish the function enter 0)
 
 Enter the number : 0

 Year is 0. Finish the function
 ===== FINISH SEARCH MANAGER =====
 
 ===== WELCOME TO THE COLLEGE FINDER =====
 0. End Program
 1. Display Data Manager
 2. Search Manager
 
 Enter the number : 3
 Incorrect number!
 
 ===== WELCOME TO THE COLLEGE FINDER =====
 0. End Program
 1. Display Data Manager
 2. Search Manager
 
 Enter the number : 0
 ***** THANK YOU FOR USING MY PROGRAM *****
 ***** IDE : XCODE *****
 logout
 
 [Process completed]
 

*/