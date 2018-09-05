//
//  Main.cpp
//  Main Function
//
//  Created by HOWON KIM on 2/25/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "HashTable.h"
#include "BST.h"
#include "Class.h"
using namespace std;

void welcome(); // Welcome function
void showMenu(); // Menu function

bool preReadFile(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
bool readFile(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
void addNewData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
void addData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN, Class input);
void deleteData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
void listData(BST<Class> CRN ,  BST<Class> Course,   HashTable<Class> H_CRN);
void searchData(BST<Class> CRN, BST<Class> Course, HashTable<Class> H_CRN);
void statistics(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
bool writeFile(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
void goodbye(); // Goodbye function

int main()
{
    char choice; // User's choice
    welcome(); // execute welcome function

    BST<Class> CRN; // Object for CRN reader for BST
    BST<Class> COURSE; // object for Course reader for BST
    
    HashTable<Class> H_CRN; // Object for CRN for hash table
    preReadFile(CRN,COURSE,H_CRN); // Execute function for reading a file


    while (1)
    {
        cout << "Enter the menu (H: Help) : ";
        cin >> choice;
        
        
        if(choice == 'R' || choice == 'r')
            readFile(CRN, COURSE, H_CRN);
        else if(choice == 'A' || choice == 'a')
            addNewData(CRN, COURSE, H_CRN);
        else if(choice == 'L' || choice == 'l')
            listData(CRN, COURSE, H_CRN);
        else if(choice == 'F' || choice == 'f')
            searchData(CRN, COURSE, H_CRN);
        else if(choice == 'S' || choice == 's')
            statistics(CRN, COURSE, H_CRN);
        else if(choice == 'D' || choice == 'd')
            deleteData(CRN, COURSE, H_CRN);
        else if(choice == 'W' || choice == 'w')
            writeFile(CRN, COURSE, H_CRN);
        else if(choice == 'H' || choice == 'h')
            showMenu();
        else if(choice == 'X' || choice == 'x')
        {
            goodbye();
            return 0;
        }
        else
            cout << "Incorrect Input. ";
    }
    
}



void welcome()
{
    cout << "% " << "*  **   **   " << "**   **   **" << "   **   **   **   *" << " % " << endl;
    cout << "| " << " *    *    * " << "   *    *   " << " *    *    *    *  " << " | " << endl;
    
    cout << "   " << "                                               " << "   " << endl;
    cout << "☆ " << "   De Anza College Class Database System    "  << " ☆ " << endl;
    cout << "   " << "                                               " << "   " << endl;
    
    cout << "| " << " *    *    * " << "   *    *   " << " *    *    *    *  " << " | " << endl;
    cout << "% " << "*  **   **   " << "**   **   **" << "   **   **   **   *" << " % " << endl << endl;
}

void goodbye()
{
    cout << endl;
    cout << "★ " << "*  **   **   " << "**   **   **" << "   **   **   **   *" << " ★ " << endl;
    cout << "∥  " << " *    *    * " << "   *    *   " << " *    *    *    *  " << "∥ " << endl;
    
    cout << "   " << "                                               " << "   " << endl;
    cout << "§ " << "            Thank You, Goodbye!             "  << " § " << endl;
    cout << "   " << "                                               " << "   " << endl;
    
    cout << "∥  " << " *    *    * " << "   *    *   " << " *    *    *    *  " << "∥ " << endl;
    cout << "★ " << "*  **   **   " << "**   **   **" << "   **   **   **   *" << " ★ " << endl;
}

void showMenu()
{
    cout << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "| Help                                                                            |" << endl;
    cout << "+=================================================================================+" << endl;
    cout << "| A |  Add new individual data from the input                                     |" << endl;
    cout << "| L |  List data by CRN or Course                                                 |" << endl;
    cout << "| F |  Search the Data by CRN or Course                                           |" << endl;
    cout << "| D |  Delete Data by CRN                                                         |" << endl;
    cout << "| R |  Read data from the text file                                               |" << endl;
    cout << "| W |  Write data to the text file                                                |" << endl;
    cout << "| S |  Statistics from the data                                                   |" << endl;
    cout << "| X |  Exit Program                                                               |" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    
}


/*---------------------------------------------------------------------
 Write data from BST, HashTable into the text file
 --------------------------------------------------------------------*/

bool writeFile(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN)
{
    ofstream outfile;
    char choice;
    string fileName;
    
    while(1)
    {
        cout << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "| Write File                                     |" << endl;
        cout << "+================================================+" << endl;
        cout << "| 1 |  Write file sorted by CRN                  |" << endl;
        cout << "| 2 |  Write file sorted by Course               |" << endl;
        cout << "| 3 |  Write file based on HashTable             |" << endl;
        cout << "| 4 |  Go to the previous menu                   |" << endl;
        cout << "+------------------------------------------------+" << endl;
        
        cout << "Enter : ";
        cin >> choice;
        
        while(choice != '1' && choice != '2' && choice != '3' && choice != '4')
        {
            cout << "Incorrect Input, Please Enter the Menu Again : ";
            cin >> choice;
        }
        
        cout << endl;
        
        if(choice == '1')
        {
            cout << "Enter the filename : ";
            cin >> fileName;
            
            outfile.open(fileName);
            
            streambuf *coutbuf = cout.rdbuf(); // Save old buf
            cout.rdbuf(outfile.rdbuf());
            
            CRN.inOrderPrint();
            
            cout.rdbuf(coutbuf); // Reset to standard output again
            
            cout <<"Successfully Saved the file to " << fileName << endl;
            cout << "Do you want to continue? (N : Go to Previous Menu) :";
            cin >> choice;
            
            if(choice == 'N' || choice == 'n')
                return true;
            
            
        }
        else if(choice == '2')
        {
            cout << "Enter the filename : ";
            cin >> fileName;
            
            outfile.open(fileName);
            
            streambuf *coutbuf = cout.rdbuf(); // Save old buf
            cout.rdbuf(outfile.rdbuf());
            
            Course.inOrderPrint();
            
            cout.rdbuf(coutbuf); // Reset to standard output again

            cout <<"Successfully Saved the file to " << fileName << endl;
            cout << "Do you want to continue? (N : Go to Previous Menu) :";
            cin >> choice;
            
            if(choice == 'N' || choice == 'n')
                return true;
        }
        
        else if(choice == '3')
        {
            cout << "Enter the filename : ";
            cin >> fileName;
            
            outfile.open(fileName);
            
            streambuf *coutbuf = cout.rdbuf(); // Save old buf
            cout.rdbuf(outfile.rdbuf());
            
            H_CRN.printTable();
            
            cout.rdbuf(coutbuf); // Reset to standard output again

            cout <<"Successfully Saved the file to " << fileName << endl;
            cout << "Do you want to continue? (N : Go to Previous Menu) :";
            cin >> choice;
            
            if(choice == 'N' || choice == 'n')
                return true;
        }
        else if(choice == '4')
            return true;
    }
    return true;
}
    

void addNewData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN)
{
    while(1)
    {
        char choice;
        Class input;
        
        string ncrn;
        string nsubject;
        string ncourse;
        string nsection;
        string ntitle;
        string nstatus;
        string ndays;
        string ntime;
        string nroom;
        string ncampus;
        double nunits;
        string ninstructor;
        int nseats_available;
        int nwaiting_available;
        int nwaiting_capacity;
        
        cout << "+------------------------------------------------+" << endl;
        cout << "| Add New Data                                   |" << endl;
        cout << "+================================================+" << endl;

        cout << "| Enter the CRN (5digits) : ";
        cin >> ncrn;
        input.setCRN(ncrn);
        
        while(CRN.findCRN(input))
        {
            cout << input.getCRN() << " is already exist " << endl;
            cout << "| Enter the CRN (5digits) : ";
            cin >> ncrn;
            input.setCRN(ncrn);
        }
        
        cout << "| Enter the Subject : ";
        cin >> nsubject;
        input.setSubject(nsubject);
        
        cout << "| Enter the Course : ";
        cin >> ncourse;
        input.setCourse(ncourse);
        
        cin.ignore();
        if(Course.findCourse(input))
        {
            cout << "Same Course is exist. We show you some data" << endl;
            
            cout << "| Enter the Section : ";
            cin >> nsection;
            input.setSection(nsection);
            
            cin.ignore();
            cout << "| Enter the Title : ";
            getline(cin, ntitle);
            input.setTitle(ntitle);
        }
        else
        {
            cout << "| Enter the Section : ";
            cin >> nsection;
            input.setSection(nsection);
            
            cout << "Enter the Title : ";
            getline(cin, ntitle);
            input.setTitle(ntitle);
            
        }
        
        cout << "Status is automatically set up to Open" << endl;
        input.setStatus("Open");
        
        cout << "| Enter the Days : ";
        cin >> ndays;
        input.setDays(ndays);
        
        cout <<"| Enter the Time (xx:xxAM-xx:xxPM) : ";
        cin >> ntime;
        input.setTime(ntime);
        
        cout << "| Enter the Room : ";
        cin >> nroom;
        input.setRoom(nroom);
        
        cout << "Campus is automatically set up to DA" << endl;
        input.setCampus("DA");
        
        cout << "| Enter the Units : ";
        cin >> nunits;
        input.setUnits(nunits);
        
        cout << "| Enter the Instructor : ";
        cin >> ninstructor;
        input.setInstructor(ninstructor);
        
        cout << "| Enter the Available seats : ";
        cin >> nseats_available;
        input.setSeats_available(nseats_available);
        

        
        cout << "| Enter the Available waiting capacity : ";
        cin >> nwaiting_capacity;
        input.setWaiting_capacity(nwaiting_capacity);
        
        cout << "Waiting list availablity is automatically set up to " << nwaiting_capacity << endl;
        input.setWaiting_available(nwaiting_capacity);


            CRN.addCRN(input);
            Course.addCourse(input);
            H_CRN.addItem(input);
        
        
        cout << "Do you want to continue? (N : Go to Previous Menu) :";
        cin >> choice;
        
        if(choice == 'N' || choice == 'n')
            return;
    }
}



void statistics(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN)
{
    while(1)
    {
        char choice;
        string input;
        Class temp;
        
        cout << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "| Statistics                                     |" << endl;
        cout << "+================================================+" << endl;
        cout << "| 1 |  Current Class Status                      |" << endl;
        cout << "| 2 |  Instructor Statistics                     |" << endl;
        cout << "| 3 |  Course Statistics                         |" << endl;
        cout << "| 4 |  Go to the previous menu                   |" << endl;
        cout << "+------------------------------------------------+" << endl;
        
        cout << "Enter : ";
        cin >> choice;
        
        while(choice != '1' && choice != '2' && choice != '3' && choice != '4')
        {
            cout << "Incorrect Input, Please Enter the Menu Again : ";
            cin >> choice;
        }
        
        
        if(choice == '1')
        {
            CRN.countStatus();
            cout << "Do you want to continue? (N : Go to Previous Menu) :";
            cin >> choice;
            
            if(choice == 'N' || choice == 'n')
                return;
        }
        
        else if(choice == '2')
        {
            cout << "Enter the name of instructor : ";
            cin >> input;
            temp.setInstructor(input);
            CRN.countInstructor(temp);
            
            cout << "Do you want to continue? (N : Go to Previous Menu) :";
            cin >> choice;
            
            if(choice == 'N' || choice == 'n')
                return;

        }
        else if(choice == '3')
        {
            cout << "Enter the Course name : ";
            cin >> input;
            temp.setCourse(input);
            CRN.countCourse(temp);
            
            cout << "Do you want to continue? (N : Go to Previous Menu) :";
            cin >> choice;
            
            if(choice == 'N' || choice == 'n')
                return;
        }
        else if(choice == '4')
            return;
        
        
        
    }
}

/*---------------------------------------------------------------------
 List data from BST, HashTable
 --------------------------------------------------------------------*/

void listData( BST<Class> CRN ,  BST<Class> Course,   HashTable<Class> H_CRN)
{
    char choice;
    // TEMP for print category
    Class temp;
    while(choice != 'N' && choice != 'n')
    {

        cout << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "| List Data                                      |" << endl;
        cout << "+================================================+" << endl;
        cout << "| 1 |  List data by sorted CRN                   |" << endl;
        cout << "| 2 |  List data by sorted Course                |" << endl;
        cout << "| 3 |  Go to the previous menu                   |" << endl;
        cout << "+------------------------------------------------+" << endl;
        
        cout << "Enter : ";
        cin >> choice;
        
        while(choice != '1' && choice != '2' && choice != '3')
        {
            cout << "Incorrect Input, Please Enter the Menu Again : ";
            cin >> choice;
        }

        
        if(choice == '1')
        {
            cout << "+------------------------------------------------+" << endl;
            cout << "| Binary Search Tree by CRN                      |" << endl;
            cout << "+================================================+" << endl;
            temp.displayCategory();
            CRN.inOrderPrint();

            cout << "+------------------------------------------------+" << endl;
            cout << "| Hash Table by CRN                              |" << endl;
            cout << "+================================================+" << endl;
            H_CRN.printTable();
            
            cout << "Do you want to continue? (N : Go to Previous Menu) :";
            cin >> choice;
            
          //  if(choice == 'N' || choice == 'n')
           //     return;
            
        }
        else if(choice == '2')
        {
            cout << "+------------------------------------------------+" << endl;
            cout << "| Binary Search Tree by Course                   |" << endl;
            cout << "+================================================+" << endl;
            Course.inOrderPrint();
            
            cout << "Do you want to continue? (N : Go to Previous Menu) :";
            cin >> choice;
            
          //  if(choice == 'N' || choice == 'n')
           //     return;
        }
        else if(choice == '3')
            choice = 'N';
        
    }
}

void searchData(BST<Class> CRN, BST<Class> Course,  HashTable<Class> H_CRN)
{

    while(1)
    {
        char choice;
        string input;
        Class temp;
        
        cout << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "| Search Data                                    |" << endl;
        cout << "+================================================+" << endl;
        cout << "| 1 |  Search the CRN                            |" << endl;
        cout << "| 2 |  Search the Course                         |" << endl;
        cout << "| 3 |  Go to the previous menu                   |" << endl;
        cout << "+------------------------------------------------+" << endl;
        
        cout << "Enter : ";
        cin >> choice;
        
        while(choice != '1' && choice != '2' && choice != '3')
        {
            cout << "Incorrect Input, Please Enter the Menu Again : ";
            cin >> choice;
        }
        
        if(choice == '1')
        {
            cout << "Enter the CRN : ";
            cin >> input;
            temp.setCRN(input);
            
            cout << "+------------------------------------------------+" << endl;
            cout << "| Result from the BST (CRN)                      |" << endl;
            cout << "+================================================+" << endl;
            CRN.findCRN(temp);

            cout << "+------------------------------------------------+" << endl;
            cout << "| Result from the HashTable (CRN)                |" << endl;
            cout << "+================================================+" << endl;
            H_CRN.findCRN(temp);
            
            cout << "Do you want to continue? (N : Go to Previous Menu) :";
            cin >> choice;
            
            if(choice == 'N' || choice == 'n')
                return;
        }
        
        else if(choice == '2')
        {
            cout << "Enter the Course : ";
            cin >> input;
            temp.setCourse(input);
            
            cout << "+------------------------------------------------+" << endl;
            cout << "| Result from the BST (Course)                   |" << endl;
            cout << "+================================================+" << endl;
            Course.findCourse(temp);

            cout << "Do you want to continue? (N : Go to Previous Menu) :";
            cin >> choice;
            
            if(choice == 'N' || choice == 'n')
                return;
        }
        else if(choice == '3')
            return;

    }
    

}


/*---------------------------------------------------------------------
 Pre-Read File Function
 --------------------------------------------------------------------*/

bool preReadFile(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN)
{
    string crn; // Primary
    string subject;
    string course; // Secondly
    string section;
    
    string title;
    string status;
    string days;
    string time;
    string room;
    string campus;
    double units;
    string instructor;
    int seats_available;
    int waiting_available;
    int waiting_capacity;
    
    string fileName;
    char choice;
    
    /* File Input Process */
    ifstream infile;
    
    cout << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "| Read File                                      |" << endl;
    cout << "+================================================+" << endl;
    
   // cout << "Enter the filename: ";
   // cin >> fileName;
    infile.open("DBClass.txt");
    
    
    while(!infile)
    {
        cout << "File does not exist";
        return false;
    }
    
    
    while(infile >> crn)
    {
        infile>>subject;
        infile>>course;
        infile>>section;
        infile.ignore();
        getline(infile,title,'\t');
        infile >> status;
        infile >> days;
        infile>>time;
        infile >> room;
        infile >> campus;
        infile >> units;
        infile.ignore();
        getline(infile, instructor, '\t');
        infile >> seats_available;
        infile >> waiting_available;
        infile >> waiting_capacity;
        
        Class input(crn, subject, course, section, title, status, days, time, room, campus, units, instructor, seats_available, waiting_available, waiting_capacity);
        addData(CRN, Course, H_CRN, input);
    }
    
    cout << "Read file is succeed" << endl;
    return true;
}


/*---------------------------------------------------------------------
 Read File Function
 --------------------------------------------------------------------*/

bool readFile(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN)
{
    string crn; // Primary
    string subject;
    string course; // Secondly
    string section;
    
    string title;
    string status;
    string days;
    string time;
    string room;
    string campus;
    double units;
    string instructor;
    int seats_available;
    int waiting_available;
    int waiting_capacity;
    
    string fileName;
    char choice;
    
    /* File Input Process */
    ifstream infile;
    
    cout << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "| Read File                                      |" << endl;
    cout << "+================================================+" << endl;
    
    cout << "Enter the filename: ";
    cin >> fileName;
    infile.open(fileName);

    
    while(!infile)
    {
        cout << "File does not exist. Enter the filename again : ";
        cin >> fileName;
        
        infile.open(fileName);
        
        if(!infile)
        {
            cout << "If you want to go to previous menu, enter N : ";
            cin >> choice;
            
            if(choice == 'N' || choice == 'n')
                return false;
        }
        
    }
    
    
    while(infile >> crn)
    {
        infile>>subject;
        infile>>course;
        infile>>section;
        infile.ignore();
        getline(infile,title,'\t');
        infile >> status;
        infile >> days;
        infile>>time;
        infile >> room;
        infile >> campus;
        infile >> units;
        infile.ignore();
        getline(infile, instructor, '\t');
        infile >> seats_available;
        infile >> waiting_available;
        infile >> waiting_capacity;
        
        Class input(crn, subject, course, section, title, status, days, time, room, campus, units, instructor, seats_available, waiting_available, waiting_capacity);
        addData(CRN, Course, H_CRN, input);
    }
    
    cout << "Read file from " << fileName << " is succeed" << endl;
    return true;
}

/*---------------------------------------------------------------------
 Add Data Function
 --------------------------------------------------------------------*/

void addData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN, Class input)
{
    CRN.addCRN(input);
    Course.addCourse(input);
    H_CRN.addItem(input);
}


/*---------------------------------------------------------------------
 Delete Data Function
 --------------------------------------------------------------------*/

void deleteData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN)
{
    cout << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "| Delete Data                                    |" << endl;
    cout << "+================================================+" << endl;
    
    char choice;
    string input;
    Class temp;
    
    while(1)
    {
        cout << "Enter the CRN : ";
        cin >> input;
        
        temp.setCRN(input);
        
        
        if(CRN.findCRN(temp))
        {
            //temp.displayCategory();
            CRN.removeCRN(temp);
            Course.removeCourse(temp);
            H_CRN.removeItem(temp);
            cout << input << " is deleted from the BST" << endl << endl;
        }
        
        else
            cout << input << " not founded" << endl << endl;
    
        
        cout << "Do you want to continue? (N : Go to previous Menu) : ";
        cin >> choice;
        
        if(choice == 'N' || choice == 'n')
            return;
        
    }
}
