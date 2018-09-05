//
//  Lab 5.3 : Working with the do while and for Looops
//  TeamP_lab53.cpp
//  MAC OS X 10.02 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/20/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // DECLARE VARIABLES
    int num_students=0;
    string name_student="";
    string name_front="";
    string name_end="";
    
    // ENTER THE NUMBER OF STUDENTS
    // DO ~ WHILE LOOP
    do
    {
        cout<<"Enter the Number of students between 1 to 25 : ";
        cin>>num_students;
    }while (num_students<1 || num_students>25);
    
    // ENTER THE NAME OF STUDENTS
    // INITIALIZE VARIABLES
    cout<<"Enter the Name of student : ";
    cin>>name_student;
    name_front=name_student;
    name_end=name_student;
    
    // CALCULATE PROCESS
    // ARRANGE THE STUDENTS
    for(int num=1;num<num_students;num++)
    {
        cout<<"Enter the Name of student : ";
        cin>>name_student;
        
        if(name_student<name_front)
        {
            name_front=name_student;
        }
        else if(name_student>name_end)
        {
            name_end=name_student;
        }
    }
    
    // OUTPUT PROCESS
    cout<<"Name who is front of the line is "<<name_front<<endl
        <<"Name who is end of the line is "<<name_end <<endl;
    
    return 0;
}
