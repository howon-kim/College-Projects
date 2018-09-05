//
//  Lab 6.2 : Function with Parameters
//  TeamP_lab62.cpp
//  Environment : MAC OS X 10.03 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 3/4/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//


#include <iostream>
using namespace std;

void calculateCompletionTime(int, int);
int main()
{
    // DECLARE VARIABLES
    int current_hours=0;
    int current_minutes=0;
    int waiting_hours=0;
    int waiting_minutes=0;
    int completion_hours=0;
    int completion_minutes=0;
    char choice;
    
    // INPUT PROCESS (CURRENT TIME)
    cout<<"Compute completion time from current time and waiting period"<<endl
    <<"Current time:"<<endl
    <<"Enter 24 hour time in the format HH:MM"<<endl;
    cin>>current_hours;
    cin.ignore();
    cin>>current_minutes;
    
    // INPUT PROCESS (WAITING TIME)
    cout<<"Waiting time:"<<endl
    <<"Enter 24 hour time in the format HH:MM"<<endl;
    cin>>waiting_hours;
    cin.ignore();
    cin>>waiting_minutes;
    
    // CALCULATE PROCESS
    cout<<"Completion time is in the day following the start time"<<endl
    <<"Completion Time in 24 hour format:"<<endl;
    
    completion_hours=current_hours+waiting_hours;
    completion_minutes=current_minutes+waiting_minutes;
    calculateCompletionTime(completion_hours, completion_minutes);
    
    // ASK TO CONTINUE THE PROGRAM
    cout<<endl<<endl<<endl<<"Enter Y or y to continue, any other halts"<<endl<<endl;
    cin>>choice;
    
    // CONTINUE PROGRAM PROCESS
    while(choice=='y' || choice=='Y')
    {
        cout<<"Current time:"<<endl
        <<"Enter 24 hour time in the format HH:MM"<<endl;
        cin>>current_hours;
        cin.ignore();
        cin>>current_minutes;
        
        cout<<"Waiting time:"<<endl
        <<"Enter 24 hour time in the format HH:MM"<<endl;
        cin>>waiting_hours;
        cin.ignore();
        cin>>waiting_minutes;
        
        cout<<"Completion Time in 24 hour format:"<<endl;
        
        completion_hours=current_hours+waiting_hours;
        completion_minutes=current_minutes+waiting_minutes;
        calculateCompletionTime(completion_hours, completion_minutes);
        
        cout<<endl<<endl<<endl<<"Enter Y or y to continue, any other halts"<<endl<<endl;
        cin>>choice;
        
    }
    return 0;
}

// CALCULATE COMPLETION TIME PROCESS
void calculateCompletionTime(int hours, int minutes)
{
    if(minutes>=60)
    {
        minutes-=60;
        hours++;
    }
    if(hours>=24)
    {
        hours-=24;
    }
    cout<<hours<<":"<<minutes;
    return;
}
