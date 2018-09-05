//
//  Lab 5.5 : Working with the nested for while Loops
//  TeamP_lab55.cpp
//  Environment : MAC OS X 10.02 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/23/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    
    // DECLARE VARIABLES
    int num_floor=0;
    int num_room=0;
    int num_occupied=0;
    
    int total_room=0;
    int total_occupied=0;
    int total_unoccupied=0;
    double per_occupied=0;
    
    // INPUT PROCESS
    cout<<"Enter the number of floors hotel has : ";
    cin>>num_floor;
    
    // INPUT VALIDATION
    while(num_floor<1)
    {
        cout<<"Number of floor must not be less than 1"<<endl;
        cout<<"Retry to enter the number of floors : ";
        cin>>num_floor;
    }
    
    // INPUT PROCESS
    for(int floor=1;floor<=num_floor;floor++)
    {
        if(floor==13)
        {
            continue;
        }
        
        cout<<"Enter the number of rooms on the "<<floor<<" Floor : ";
        cin>>num_room;
        while(num_room<10)
        {
            cout<<"Number of rooms must not be less than 10"<<endl;
            cout<<"Retry to enter the number of rooms on the "<<floor<<" Floor : ";
            cin>>num_room;
        }
        
        cout<<"Enter the number of rooms are occupied : ";
        cin>>num_occupied;
        while(num_occupied>num_room || num_occupied<0)
        {
            cout<<"Occupied rooms must be less than or eqaul to Number of rooms and must be positive number"<<endl;
            cout<<"Retry to enter the number of rooms are occupied : ";
            cin>>num_occupied;
        }
        
        total_room+=num_room;
        total_occupied+=num_occupied;
        
    }
    
    // CALCULATE PROCESS
    total_unoccupied = total_room - total_occupied;
    per_occupied = (static_cast<double>(total_occupied)/static_cast<double>(total_room))*100;
    
    
    // DISPLAY PROCESS
    cout<<setw(30)<<left<<"TOTAL ROOMS"<<right<<setw(10)<<total_room<<endl;
    cout<<"========================================="<<endl;
    cout<<setw(30)<<left<<"OCCUPIED ROOMS"<<right<<setw(10)<<total_occupied<<endl;
    cout<<setw(30)<<left<<"UNOCCUPIED ROOMS"<<right<<setw(10)<<total_unoccupied<<endl;
    cout<<"========================================="<<endl;
    cout<<setw(30)<<left<<"PERCENTAGE OF ROOMS OCCUPIED"<<fixed<<setprecision(1)<<setw(9)<<right<<per_occupied<<"%"<<endl;
    return 0;
}