//
//  Lab 6.4 : Function with Return
//  TeamP_lab64.cpp
//  ENVIRONMENT : MAC OS X 10.3 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 3/7/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

/*  Write a program that calculates the average number of days a company's employees are absent. The program should have the following functions:

◦	A function called by main that asks the user for the number of employees in the company. This value should be returned as an int. (The function accepts no arguments.)
◦	A function called by main that accepts one argument: the number of employees in the company. The function should ask the user to enter the number of days each employee missed during the past year. The total of these days should be returned as an int.
◦	A function called by main that takes two arguments: the number of employees in the company and the total number of days absent for all employees during the year. The function should return, as a double, the average number of days absent. (This function does not perform screen output and does not ask the user for input.)

    Input Validation: Do not accept a number less than 1 for the number of employees.Do not accept a negative number for the days any employee missed.
 */



#include <iostream>
using namespace std;

int inputNumberOfEmployees();
int inputNumberOfAbsent(int);
double calAverageNumberOfAbsent(int,int);

int main()
{
    int num_Employees=0;
    int num_Absent=0;
    double num_AvgAbsent=0.0;
    num_Employees=inputNumberOfEmployees();
    num_Absent=inputNumberOfAbsent(num_Employees);
    num_AvgAbsent=calAverageNumberOfAbsent(num_Employees,num_Absent);
    
    
    return 0;
}

int inputNumberOfEmployees()
{
    int fnum_Employees=0;
    cout<<"Input the Number Of Employees : ";
    cin>>fnum_Employees;
    
    while(fnum_Employees<1)
    {
        cout<<"Input the Number Of Employees greater than 0 : ";
        cin>>fnum_Employees;
    }
    
    return fnum_Employees;
}

int inputNumberOfAbsent(int total_Employees)
{
    int current_Absent=0;
    int fnum_Absent=0;
    for(int current_Employee=1;current_Employee<=total_Employees;current_Employee++)
    {
        cout<<"Enter "<<current_Employee<<" Employee's absent days : ";
        cin>>current_Absent;
        while(current_Absent<0)
        {
            cout<<"Input the "<<current_Employee<<" Employee's Absent days by positive number : ";
            cin>>current_Absent;
        }
        fnum_Absent+=current_Absent;
    }
    return fnum_Absent;
}

double calAverageNumberOfAbsent(int totalnum_Employees, int totalnum_Absent)
{
    return static_cast<double>(totalnum_Absent)/static_cast<double>(totalnum_Employees);
}