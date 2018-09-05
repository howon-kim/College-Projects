//
//  Extra Credit
//  KimHowon_extra.cpp
//  ENVIRONMENT : MAC OS X 10.3 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 3/12/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
using namespace std;

// FUNCTION PROTOTYPE
void getInput(int&, int&);
void calcBill(int&, double&, int, int);
void displayBill(int, double);

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // DECLARE VARIABLES
    int current=0;
    int previous=0;
    int used=0;
    double total_charge=0.0;
    
    while(current>=0)
    {
        // INPUT PROCESS
        getInput(current, previous);
        // CALCULATE PROCESS
        calcBill(used,total_charge,current,previous);
        
        // DISPLAY ERROR MESSAGE
        if(used<0)
        {
            cout<<"The current reading must be greater than or equal to the previous reading."<<endl;
        }
        else
        {
            // DISPLAY RESULT
            displayBill(used,total_charge);
        }
        
    }
    
    return 0;
}

// INPUT CURRENT READING AND PREVIOUS READING
void getInput(int &num_current, int &num_previous)
{
    // INPUT CURRENT READING
    cout<<endl<<"Current reading (negative number to end): ";
    cin>>num_current;
    
    // SENTINEL VALUE MAKES PROGRAM EXIT
    if(num_current<0)
    {
        exit(0);
    }
    
    // INPUT PREVIOUS READING
    cout<<"Previous reading: ";
    cin>>num_previous;
    
    // PREVIOUS READING INPUT VALIDATION
    while(num_previous<0)
    {
        cout<<"Do not enter the negative number. Try again : ";
        cin>>num_previous;
    }
    return;
}

// CALCULATE USED UNITS AND TOTAL CHARGE
void calcBill(int &num_used, double &num_total, int current_reading, int previous_reading)
{
    num_used=current_reading-previous_reading;
    num_total=num_used*0.11;
    
    return;
}

// DISPLAY USED UNITS AND TOTAL CHARGE
void displayBill(int used_unit, double charged_total)
{
    cout<<"Unit used: "<<used_unit<<endl
    <<"Total charge: $"<<charged_total<<endl;
    
    return;
}