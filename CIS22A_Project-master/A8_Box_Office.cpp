//
//  Assignment 8 : Box Office
//  KimHowon_a8.cpp
//
//  Created by HOWON KIM on 2/27/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // DECLARE VARIABLES
    double salary_original=0.0;
    double salary=0.0;
    double raise=0.0;
    int year=1;
    double rate=0.0;
    int raise_rate=0;
    
    // INPUT PROCESS
    cout<<"Salary (negative number or 0 to end): ";
    cin>>salary;
    
    // SAVE THE ORIGINAL VALUE
    salary_original=salary;
    
    // CALCULATE PROCESS
    while(salary>0) // Sentinel value validation
    {
        rate=0.03; // Raise rate for calculation
        raise_rate=3; // Raise rate for display
        
        while(rate<0.07) // Calculate 3%~6% raise rates
        {
            cout<<"Raise rate: "<<raise_rate<<"%"<<endl; // Display Raise rate
            while(year<=3) // Calculate raises and display
            {
                raise=salary*rate; // Calculate raises
                cout<<"Year "<<year<<":  Raise: $"<<raise<<endl; // Display raises
                salary+=raise;
                year++; // Go on to the next year
            }
            rate+=0.01; // Adding 0.01 to the Actual value of raise rates
            raise_rate+=1; // Adding 1 to the Raise rates
            year=1; // Adding 1 to the Number of years
            salary=salary_original; // Recover original salary
            cout<<endl;
        }
        // Repeat until user enter the sentinel value
        cout<<"Salary (negative number or 0 to end): ";
        cin>>salary;
        salary_original=salary;
    }
    
    return 0;
}

