//
//  Lab 6.6 : Overloaded Functions
//  TeamP_lab66.cpp
//  Environment : MAC OS X 10.03 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 3/10/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
using namespace std;

// Function prototypes
char inputChoice(char);
double calcTotalCharges(int, double, double, double);
double calcTotalCharges(double,double);


int main()
{
    // DECLARE VARIABLES
    char choice;
    int num_days=0;
    double dailyrate=0.0;
    double medicharges=0.0;
    double servicecharges=0.0;
    double totalcharges=0.0;
    
    // SELECTION PROCESS
    cout<<"If you are admitted as an in-patient, Enter 'I' or 'i'"<<endl
        <<"If you are admitted as an out-outpatient, Enter 'O' or 'o'"<<endl
        <<"Enter your choice : ";
    
    // INPUT CHOICE FUNCION
    choice=inputChoice(choice);
    
    // CACULATE AND INPUT PROCESS
    switch(choice)
    {
    // FOR IN-PATIENT
    case'I':
    case'i':
            // ENTER NUMBER OF DAYS SPENT IN THE HOSPITAL
            cout<<"Enter the number of days spent in the hospital : ";
            cin>>num_days;
            // VALIDATION PROCESS
            while(num_days<0)
            {
            cout<<"Enter the positive number : ";
            cin>>num_days;
            }
    
            // ENTER THE DAILY RATE
            cout<<"Enter the daily rate : ";
            cin>>dailyrate;
            // VALIDATION PROCESS
            while(dailyrate<0)
            {
            cout<<"Enter the positive number : ";
            cin>>dailyrate;
            }
    
            // ENTER THE HOSPITAL MEDICATION CHARGES
            cout<<"Enter the hospital medication charges : ";
            cin>>medicharges;
            // VALIDATION PROCESS
            while(medicharges<0)
            {
            cout<<"Enter the positive number : ";
            cin>>medicharges;
            }
    
            // ENTER THE CHARGES FOR HOSPITAL SERVICES (LAB TESTS, ETC)
            cout<<"Enter the charges for hospital services : ";
            cin>>servicecharges;
            // VALIDATION PROCESS
            while(servicecharges<0)
            {
                cout<<"Enter the positive number : ";
                cin>>servicecharges;
            }
            
            // CALCULATE AND DISPLAY PROCESS
            totalcharges=calcTotalCharges(num_days, dailyrate, medicharges, servicecharges);
            break;
            
    // FOR OUT-PATIENT
    case'O':
    case'o':
            // ENTER THE CHARGES FOR HOSPITAL SERVICES (LAB TESTS, ETC)
            cout<<"Enter the charges for hospital services : ";
            cin>>servicecharges;
            // VALIDATION PROCESS
            while(servicecharges<0)
            {
                cout<<"Enter the positive number : ";
                cin>>servicecharges;
            }
            
            // ENTER THE HOSPITAL MEDICATION CHARGES
            cout<<"Enter the hospital medication charges : ";
            cin>>medicharges;
            // VALIDATION PROCESS
            while(medicharges<0)
            {
                cout<<"Enter the positive number : ";
                cin>>medicharges;
            }
            
            // CALCULATE AND DISPLAY PROCESS
            totalcharges=calcTotalCharges(servicecharges, medicharges);
            break;
    }
    
    
    return 0;
}

char inputChoice(char fchoice)
{
    cin>>fchoice;
    while(fchoice!='I' && fchoice!='i' && fchoice!='O' && fchoice!='o')
    {
        cout<<"You entered wrong character"<<endl
            <<"If you are admitted as an in-patient, Enter 'I' or 'i'"<<endl
            <<"If you are admitted as an out-outpatient, Enter 'O' or 'o'"<<endl
            <<"Enter your choice : ";
        cin>>fchoice;
    }
    return fchoice;
}

double calcTotalCharges(int fdays, double frates, double fmedicharges, double fservicecharges)
{
    double ftotalcharges=0.0;
    ftotalcharges=(fdays*frates)+fmedicharges+fservicecharges;
    return ftotalcharges;
}

double calcTotalCharges(double fservicecharges, double fmedicharges)
{
    double ftotalcharges=0.0;
    ftotalcharges=fservicecharges+fmedicharges;
    return ftotalcharges;
}