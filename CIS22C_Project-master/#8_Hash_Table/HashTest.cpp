//
//  HashTest.cpp
//  Hash_Table
//
//  Created by HOWON KIM on 2/25/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "HashTable.h"
using namespace std;

void import(HashTable &hashdata);

int main(int argc, const char * argv[]) {
    
    HashTable data;
    import(data);
    
    data.printTable();
    cout << endl;
    
    /* Error List */
    data.printBucket(29);
    cout << data.findTitle("CISD111.64Z") << endl;
    data.removeItem("CISD111.01");
    data.findTitle("CISD111.01");
    cout << data.numItemsAtIndex(29) << endl; //0

    ///////////////
    
    cout << endl;
    cout << data.findTitle("CISD099.64Z") << endl; // Index 28
    
    
    data.removeItem("CISD002.01");
    data.removeItem("CISD002.01");

    data.printBucket(0);
    return 0;
}



/*---------------------------------------------------------------------
 Import Data
 --------------------------------------------------------------------*/

void import(HashTable &hashdata)
{
    int crn;
    string course;
    
    string title;
    bool status;
    string days;
    
    /**
    string time;
    
    int start;
    int end;
    
    string room;
    string campus;
    
    double units;
    
    string instructor;
    
    int seats_available;
    int waiting_available;
    int waiting_capacity;
    **/
    

    string temp;
    
    ifstream infile;
    infile.open("DBClass.txt");
    // For GCC : /Users/HWKIM/Documents/workspace/Hash_Table/src/DBClass.txt
    
    if(!infile)
    {
        cout << "File is not Exist" << endl;
        exit(111);
    }
    
    // Read CRN
    while(infile >> crn)
    {
        // Read Course
        infile >> course;
        infile >> temp;
        course.append(temp);
        
        // Read Title
        infile >> temp;
        while(temp != "Open" && temp != "Full")
        {
            title.append(temp);
            infile >> temp;

            if(temp != "Open" && temp != "Full")
                title.append(" ");
        }
        
        // Read Status
        if(temp == "Open")
            status = true;
        else
            status = false;
        
        // Read Days
        infile >> days;
        
        // Add Item in the hash table
        hashdata.addItem(crn, course, title, status, days);
        
        title = "";
    }
}

/** OUTPUT
 -------------------------------------------
 Index 0:
 Course: CISD002.01
 CRN: 428
 Title: CMPTRS & INTERNT IN SOCIETY
 Status: Open
 Days: MW
 Number Values at this Index: 14
 -------------------------------------------
 Index 1:
 Course: CISD022A08Y
 CRN: 43319
 Title: BEG PROG METHOD C++
 Status: Open
 Days: MTWTh
 Number Values at this Index: 5
 -------------------------------------------
 Index 2:
 Course: CISD022A09Y
 CRN: 44189
 Title: BEG PROG METHOD C++
 Status: Open
 Days: TTh
 Number Values at this Index: 4
 -------------------------------------------
 Index 3:
 Course: CISD003.01Y
 CRN: 429
 Title: BUSINESS INFO SYSTEMS
 Status: Open
 Days: MW
 Number Values at this Index: 2
 -------------------------------------------
 Index 4:
 Course: CISD003.02Y
 CRN: 41239
 Title: BUSINESS INFO SYSTEMS
 Status: Open
 Days: TTh
 Number Values at this Index: 6
 -------------------------------------------
 Index 5:
 Course: CISD003.03Y
 CRN: 44153
 Title: BUSINESS INFO SYSTEMS
 Status: Open
 Days: MW
 Number Values at this Index: 6
 -------------------------------------------
 Index 6:
 Course:
 CRN: 0
 Title:
 Status: Full
 Days:
 Number Values at this Index: 0
 -------------------------------------------
 Index 7:
 Course: CISD035B63Y
 CRN: 443
 Title: ADV JAVA PROGRAMMING
 Status: Open
 Days: MW
 Number Values at this Index: 2
 -------------------------------------------
 Index 8:
 Course: CISD035A64Z
 CRN: 441
 Title: JAVA PROGRAMMING
 Status: Open
 Days: TBA
 Number Values at this Index: 3
 -------------------------------------------
 Index 9:
 Course: CISD102.61Y
 CRN: 43529
 Title: ETHICAL HACKING
 Status: Open
 Days: Th
 Number Values at this Index: 4
 -------------------------------------------
 Index 10:
 Course: CISD064A64Z
 CRN: 44162
 Title: DATABASE MANAGEMENT SYSTEMS
 Status: Open
 Days: TBA
 Number Values at this Index: 2
 -------------------------------------------
 Index 11:
 Course: CISD064F61Y
 CRN: 43276
 Title: INTRO TO BIG DATA AND ANALYTIC
 Status: Open
 Days: T
 Number Values at this Index: 2
 -------------------------------------------
 Index 12:
 Course: CISD075A64Z
 CRN: 447
 Title: INTERNT CONC/TCP/IP PROT
 Status: Open
 Days: TBA
 Number Values at this Index: 1
 -------------------------------------------
 Index 13:
 Course: CISD003.64Z
 CRN: 41271
 Title: BUSINESS INFO SYSTEMS
 Status: Open
 Days: TBA
 Number Values at this Index: 3
 -------------------------------------------
 Index 14:
 Course: CISD003.65Z
 CRN: 43045
 Title: BUSINESS INFO SYSTEMS
 Status: Open
 Days: TBA
 Number Values at this Index: 6
 -------------------------------------------
 Index 15:
 Course: CISD004.65Z
 CRN: 43676
 Title: COMPUTER LITERACY
 Status: Open
 Days: TBA
 Number Values at this Index: 2
 -------------------------------------------
 Index 16:
 Course: CISD055.61Y
 CRN: 43316
 Title: IOS DEVELOPMENT
 Status: Open
 Days: MW
 Number Values at this Index: 2
 -------------------------------------------
 Index 17:
 Course: CISD029.61Y
 CRN: 42094
 Title: ADV C++ PROGRAMMING
 Status: Open
 Days: MW
 Number Values at this Index: 6
 -------------------------------------------
 Index 18:
 Course:
 CRN: 0
 Title:
 Status: Full
 Days:
 Number Values at this Index: 0
 -------------------------------------------
 Index 19:
 Course: CISD108.64Z
 CRN: 454
 Title: PC SECURITY BASICS
 Status: Open
 Days: TBA
 Number Values at this Index: 4
 -------------------------------------------
 Index 20:
 Course:
 CRN: 0
 Title:
 Status: Full
 Days:
 Number Values at this Index: 0
 -------------------------------------------
 Index 21:
 Course:
 CRN: 0
 Title:
 Status: Full
 Days:
 Number Values at this Index: 0
 -------------------------------------------
 Index 22:
 Course: CISD066.64Z
 CRN: 43321
 Title: INTRO DATA COM/NTWRKNG
 Status: Open
 Days: TBA
 Number Values at this Index: 1
 -------------------------------------------
 Index 23:
 Course: CISD022A01Y
 CRN: 42524
 Title: BEG PROG METHOD C++
 Status: Open
 Days: TTh
 Number Values at this Index: 2
 -------------------------------------------
 Index 24:
 Course: CISD022A02Y
 CRN: 42525
 Title: BEG PROG METHOD C++
 Status: Open
 Days: MW
 Number Values at this Index: 4
 -------------------------------------------
 Index 25:
 Course: CISD022A03Y
 CRN: 42526
 Title: BEG PROG METHOD C++
 Status: Open
 Days: MW
 Number Values at this Index: 8
 -------------------------------------------
 Index 26:
 Course: CISD022A04Y
 CRN: 42527
 Title: BEG PROG METHOD C++
 Status: Open
 Days: MW
 Number Values at this Index: 6
 -------------------------------------------
 Index 27:
 Course: CISD022A05Y
 CRN: 43046
 Title: BEG PROG METHOD C++
 Status: Open
 Days: TBA
 Number Values at this Index: 8
 -------------------------------------------
 Index 28:
 Course: CISD022A06Y
 CRN: 43059
 Title: BEG PROG METHOD C++
 Status: Open
 Days: TBA
 Number Values at this Index: 8
 
 printBucket : index is larger than Table Size
 findTitle : Course is not stored in the table
 -1
 removeItem : Course is not stored in the table
 findTitle : Course is not stored in the table
 0
 
 Title : OFFICE SOFTWARE APPLICATIONS
 28
 CISD002.01 is deleted from the table
 removeItem : Course is not stored in the table
 -------------------------------------------
 Index 0:
 Course: CISD018A02Y
 CRN: 435
 Title: INTRO TO UNIX/LINUX
 Status: Open
 Days: MW
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD018A02Y
 CRN: 435
 Title: INTRO TO UNIX/LINUX
 Status: Open
 Days: TBA
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD022A07Y
 CRN: 43277
 Title: BEG PROG METHOD C++
 Status: Open
 Days: MW
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD022A07Y
 CRN: 43277
 Title: BEG PROG METHOD C++
 Status: Open
 Days: TBA
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD022A61Y
 CRN: 42528
 Title: BEG PROG METHOD C++
 Status: Open
 Days: TTh
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD022A61Y
 CRN: 42528
 Title: BEG PROG METHOD C++
 Status: Open
 Days: TBA
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD022B06Y
 CRN: 43677
 Title: INTERMED PROG METHOD C++
 Status: Open
 Days: MW
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD022B06Y
 CRN: 43677
 Title: INTERMED PROG METHOD C++
 Status: Open
 Days: TBA
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD036A02Y
 CRN: 43651
 Title: INTRO TO COMP PROG USING JAVA
 Status: Open
 Days: TTh
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD036A02Y
 CRN: 43651
 Title: INTRO TO COMP PROG USING JAVA
 Status: Open
 Days: TBA
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD036B01Y
 CRN: 43840
 Title: INTERMED PROBLEM SOLVING JAVA
 Status: Open
 Days: TTh
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD036B01Y
 CRN: 43840
 Title: INTERMED PROBLEM SOLVING JAVA
 Status: Open
 Days: TBA
 Number Values at this Index: 13
 -------------------------------------------
 Index 0:
 Course: CISD095A55L
 CRN: 44055
 Title: PROJ MGMT - PRACTICUM
 Status: Open
 Days: S
 Number Values at this Index: 13
 Program ended with exit code: 0
**/