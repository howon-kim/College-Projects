//
//  Homework6.cpp
//  22B_KIM_HOWON_H6 : Linked Lists
//
//  Created by HOWON KIM on 6/8/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "CityList.h"
using namespace std;

void welcome();
void readCityData(CityList *readList);
void printCityData(CityList *printList);
void searchCityData(CityList *searchList);
void deleteCityData(CityList *deleteList);
void goodbye();


int main()
{
    CityList list;

    // WELCOME FUNCTION
    welcome();

    // A. Read data from a text file
    readCityData(&list);
    
    // B. Print the list
    printCityData(&list);
    
    // C. Seach Function
    searchCityData(&list);

    // D. Delete Function
    deleteCityData(&list);
    
    // EXTRA. Check the Result (Inactive)
    // list.displayList();
    
    // GOODBYE FUNCTION
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
    cout << "Welcome to the Linked Lists Project" << endl;
    cout << "___________________________________" << endl << endl;
}


//*****************************************************************************
// Definition of function readCityData
// This function save the city list from the file to the linked list
// Input Parameter : none
// Output Parameter
// - readList : Linked list for save the city list
// Return Value : none
//*****************************************************************************

void readCityData(CityList *readList)
{
    cout << endl << "A. Read City Data" << endl;
    cout << "___________________" << endl;
    
    Data import;

    ifstream infile;
    infile.open("/Users/HWKIM/Library/Mobile Documents/com~apple~CloudDocs/College/Programming/CIS22B/22B_KIM_HOWON_H6/22B_KIM_HOWON_H6/cities.txt");
    
    while(!infile)
    {
        cout << "FILE OPEN ERROR" << endl;
        exit(111);
    }
    
    
    while(infile>>import.state)
    {
        //infile >> import.state;
        
        infile >> import.year;
        infile.ignore();
        getline(infile, import.city);
        
        // DEBUG //
        /*
         cout << import.state;
         cout << import.year;
         cout << import.city;
         cout << endl;
         */
        readList->insertNode(import);
        
    }

    infile.close();
    
    cout << endl << "Complete to read data" << endl;
    cout << "___________________" << endl;

}


//*****************************************************************************
// Definition of function printCityData
// This function displays the city list
// Input Parameter
// - printList : Access the City Data
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void printCityData(CityList * printList)
{
    cout << endl << endl << "B. Print City Data" << endl;
    cout << "___________________" << endl << endl;
    
    cout << left << setw(10) << "State" << setw(10) << "Year" << setw(20) << "City" << endl;
    cout << setw(10) << "-----" << setw(10) << "-----" << setw(20) << "----------" << endl;
    printList->displayList();
    
    cout << "___________________" << endl;
}


//*****************************************************************************
// Definition of function searchCityData
// This function search the city from the city data
// Input Parameter
// - searchList : Access the City Data
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void searchCityData(CityList * searchList)
{
    string searchCity;

    cout << endl << "C. Search City Data" << endl;
    cout << "___________________" << endl;
    
    while(searchCity!="QUIT")
    {
        cout << endl << "Enter the city for search (QUIT for stop searching) : ";
        getline(cin,searchCity);
        
        if(searchCity!="QUIT")
        {
            searchList->searchList(searchCity);
        }
        

    }
        cout << "___________________" << endl;
}

//*****************************************************************************
// Definition of function deleteCityData
// This function delete the city from the city data
// Input Parameter : none
// Output Parameter
// - deleteList : Access the City Data
// Return Value : none
//*****************************************************************************


void deleteCityData(CityList * deleteList)
{
    string searchCity;
    
    cout << endl << endl << "D. Delete City Data" << endl;
    cout << "___________________" << endl;
    
    while(searchCity!="QUIT")
    {
        cout << endl << "Enter the city for delete (QUIT for stop searching) : ";
        getline(cin,searchCity);
        
        if(searchCity!="QUIT")
        {
            deleteList->deleteNode(searchCity);
        }
    }
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
    cout << endl << endl << "______________________________________________" << endl << endl;
    cout << "Thank you for using the Linked Lists Project" << endl;
    cout << "IDE : XCODE 6.3.2 (Mac OS X 10.04)" << endl;
    cout << "Developer : Howon Kim" << endl;
}


/* OUTPUT 
 Last login: Wed Jun 10 23:17:33 on ttys000
 admin:~ HWKIM$ /Users/HWKIM/Library/Developer/Xcode/DerivedData/22B_KIM_HOWON_H6-dvdyutphimoqmieihojarkvsbozb/Build/Products/Debug/22B_KIM_HOWON_H6 ; exit;
 Welcome to the Linked Lists Project
 ___________________________________
 
 
 A. Read City Data
 ___________________
 
 Complete to read data
 ___________________
 
 
 B. Print City Data
 ___________________
 
 State     Year      City
 -----     -----     ----------
 MD        1797      Baltimore
 MA        1822      Boston
 IL        1837      Chicago
 OH        1834      Columbus
 TX        1856      Dallas
 MI        1815      Detroit
 TX        1837      Huston
 IN        1832      Indianapolis
 FL        1822      Jacksonville
 CA        1850      Los Angeles
 TN        1826      Memphis
 WI        1846      Milwaukee
 NY        1898      New York
 PA        1701      Philadelphia
 AZ        1881      Phoenix
 TX        1837      San Antonio
 CA        1850      San Diego
 CA        1850      San Francisco
 CA        1850      San Jose
 DC        1788      Washington
 ___________________
 
 C. Search City Data
 ___________________
 
 Enter the city for search (QUIT for stop searching) : Baltimore
 
 State     Year      City
 -----     -----     ----------
 MD        1797      Baltimore
 
 Enter the city for search (QUIT for stop searching) : Washington
 
 State     Year      City
 -----     -----     ----------
 DC        1788      Washington
 
 Enter the city for search (QUIT for stop searching) : Memphis
 
 State     Year      City
 -----     -----     ----------
 TN        1826      Memphis
 
 Enter the city for search (QUIT for stop searching) : Cupertino
 <Cupertino> was not found
 
 Enter the city for search (QUIT for stop searching) : QUIT
 ___________________
 
 
 D. Delete City Data
 ___________________
 
 Enter the city for delete (QUIT for stop searching) : Baltimore
 
 State     Year      City
 -----     -----     ----------
 MD        1797      Baltimore
 ** Delete the Baltimore**
 
 Enter the city for delete (QUIT for stop searching) : Baltimore
 <Baltimore> was not found
 
 Enter the city for delete (QUIT for stop searching) : Washington
 
 State     Year      City
 -----     -----     ----------
 DC        1788      Washington
 ** Delete the Washington**
 
 Enter the city for delete (QUIT for stop searching) : Washington
 <Washington> was not found
 
 Enter the city for delete (QUIT for stop searching) : Cupertino
 <Cupertino> was not found
 
 Enter the city for delete (QUIT for stop searching) : QUIT
 
 
 ______________________________________________
 
 Thank you for using the Linked Lists Project
 IDE : XCODE 6.3.2 (Mac OS X 10.04)
 Developer : Howon Kim
 logout
 
 [Process completed]
 
*/