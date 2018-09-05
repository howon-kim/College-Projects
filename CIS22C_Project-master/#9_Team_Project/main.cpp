/*------------------------------------------------------------------------------------------
 
 File Name: main.cpp
 
 CIS 22C: Course Project: De Anza Courses
 Group #1
 Name: Howon Kim
 
 Description:
 This is a Class Searching program for Computer Science Department in De Anza.
 Users can see the entire list of classes with its details
 such as CRN number, course name, professor's name, room number and availability.
 
 Based on CRN number, users can narrow down their choice and come up with one class
 that they only want to see
 or
 they can use course numbers to check entire course's information
 
 Also, this program provides few statistic values for
 about professor, course and availiability
 
 ------------------------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "HashTable.h"
#include "BST.h"
#include "Class.h"
using namespace std;

/* Function Prototype */
void welcome();
void showMenu();
bool preReadFile(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
bool readFile(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
void addNewData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
void addData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN, Class input);
void deleteData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
void listData(BST<Class> &CRN ,  BST<Class> &Course,   HashTable<Class> &H_CRN);
void searchData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
void statistics(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
bool writeFile(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN);
void goodbye();


int main()
{
    char choice;
    welcome();
    BST<Class> CRN;
    BST<Class> COURSE;
    HashTable<Class> H_CRN;
    preReadFile(CRN,COURSE,H_CRN);


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


/*---------------------------------------------------------------------
 Welcome Function
 --------------------------------------------------------------------*/

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


/*---------------------------------------------------------------------
 Goodbye Function
 --------------------------------------------------------------------*/

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


/*---------------------------------------------------------------------
 Menu Display
 --------------------------------------------------------------------*/

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
 
 Input
 - Binary Search Tree : CRN
 - Binary Search Tree : Course
 - Hash Table : H_CRN
 
 Output
 - Boolean
 --------------------------------------------------------------------*/

bool writeFile(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN)
{
    ofstream outfile;
    char choice;
    string fileName;
    
    while(choice != 'N' && choice != 'n')
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
            cout << "Do you want to continue? (Y/N) : ";
            cin >> choice;
            
            
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
            cout << "Do you want to continue? (Y/N) : ";
            cin >> choice;

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
            cout << "Do you want to continue? (Y/N) : ";
            cin >> choice;
            

        }
        else if(choice == '4')
            choice = 'n';
        
        outfile.close();

    }
    return true;
}


/*---------------------------------------------------------------------
 Add new data to both binary search tree and hashtable
 
 Input
 - Binary Search Tree : CRN
 - Binary Search Tree : Course
 - Hash Table : H_CRN
 
 Output
 - none
 --------------------------------------------------------------------*/

void addNewData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN)
{
    char choice;

    while(choice != 'N' && choice != 'n')
    {
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
            cout << "| Enter the another CRN (5digits) : ";
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
        
        
        cout << "Do you want to continue? (Y/N) : ";
        cin >> choice;

    }
}

/*---------------------------------------------------------------------
 Statistics
 
 Input
 - Binary Search Tree : CRN
 - Binary Search Tree : Course
 - Hash Table : H_CRN
 
 Output
 - none
 --------------------------------------------------------------------*/

void statistics(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN)
{
    char choice;
    string input;
    Class temp;
    
    while(choice != 'N' && choice != 'n')
    {

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
            cout << "Do you want to continue? (Y/N) : ";
            cin >> choice;
        }
        
        else if(choice == '2')
        {
            cout << "Enter the name of instructor : ";
            cin >> input;
            temp.setInstructor(input);
            CRN.countInstructor(temp);
            
            cout << "Do you want to continue? (Y/N) : ";
            cin >> choice;

        }
        else if(choice == '3')
        {
            cout << "Enter the Course name : ";
            cin >> input;
            temp.setCourse(input);
            CRN.countCourse(temp);
            
            cout << "Do you want to continue? (Y/N) : ";
            cin >> choice;
            

        }
        else if(choice == '4')
            choice = 'n';
    
    }
}


/*---------------------------------------------------------------------
 List data from BST, HashTable
 
 Input
 - Binary Search Tree : CRN
 - Binary Search Tree : Course
 - Hash Table : H_CRN
 
 Output
 - none
 --------------------------------------------------------------------*/

void listData( BST<Class> &CRN ,  BST<Class> &Course,   HashTable<Class> &H_CRN)
{
    char choice;
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
            
            cout << "Do you want to continue? (Y/N) : ";
            cin >> choice;
        }
        else if(choice == '2')
        {
            cout << "+------------------------------------------------+" << endl;
            cout << "| Binary Search Tree by Course                   |" << endl;
            cout << "+================================================+" << endl;
            Course.inOrderPrint();
            
            cout << "Do you want to continue? (Y/N) : ";
            cin >> choice;
        }
        
        else if(choice == '3')
            choice = 'N';
        
    }
}


/*---------------------------------------------------------------------
 Search data from the BST, HashTable
 
 Input
 - Binary Search Tree : CRN
 - Binary Search Tree : Course
 - Hash Table : H_CRN
 
 Output
 - none
 --------------------------------------------------------------------*/
void searchData(BST<Class> &CRN, BST<Class> &Course,  HashTable<Class> &H_CRN)
{
    char choice;
    string input;
    Class temp;

    while(choice != 'N' && choice != 'n')
    {

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
            
            cout << "Do you want to continue? (Y/N) : ";
            cin >> choice;
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

            cout << "Do you want to continue? (Y/N) : ";
            cin >> choice;

        }
        else if(choice == '3')
            choice = 'n';
    }
    

}


/*---------------------------------------------------------------------
 Write data from textfile to BST and Hashtable (Preloaded)
 
 Input
 - Binary Search Tree : CRN
 - Binary Search Tree : Course
 - Hash Table : H_CRN
 
 Output
 - Boolean
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
    
    
    /* File Input Process */
    ifstream infile;

    infile.open("DBClass.txt");
    
    while(!infile)
    {
        cout << "File does not exist";
        exit(111);
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
    
    cout << "Read file is succeed..." << endl;
    return true;
}


/*---------------------------------------------------------------------
 Write data from textfile to BST and Hashtable
 
 Input
 - Binary Search Tree : CRN
 - Binary Search Tree : Course
 - Hash Table : H_CRN
 
 Output
 - Boolean
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
        cout << "Enter the filename again : ";
        cin >> fileName;
        
        infile.open(fileName);
        
        if(!infile)
        {
            cout << "File does not exist. Do you want to continue? (Y/N) : ";
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
 Add class data to the BST and Hashtable
 
 Input
 - Binary Search Tree : CRN
 - Binary Search Tree : Course
 - Hash Table : H_CRN
 - Class object : input
 
 Output
 - none
 --------------------------------------------------------------------*/

void addData(BST<Class> &CRN, BST<Class> &Course, HashTable<Class> &H_CRN, Class input)
{
    CRN.addCRN(input);
    Course.addCourse(input);
    H_CRN.addItem(input);
}


/*---------------------------------------------------------------------
 Delete data from the BST and Hashtable
 
 Input
 - Binary Search Tree : CRN
 - Binary Search Tree : Course
 - Hash Table : H_CRN
 
 Output
 - none
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
            CRN.removeCRN(temp);
            Course.removeCourse(temp);
            H_CRN.removeItem(temp);
            cout << input << " is deleted from the BST" << endl << endl;
        }
        
        else
            cout << input << " not founded" << endl << endl;
    
        
        cout << "Do you want to continue? (Y/N) : ";
        cin >> choice;
        
        if(choice == 'N' || choice == 'n')
            return;
        
    }
}
