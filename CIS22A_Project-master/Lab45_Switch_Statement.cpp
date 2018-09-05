//
//  TeamP_lab45.cpp
//  Lab 4.5 : The Switch Statement
//  Development Environmnet : MAC OS X 10.02 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/9/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // DECLARE VARIABLES
    int typeMedium =0;
    double distance = 0.0;
    const int SPEED_AIR = 1100;
    const int SPEED_WATER = 4900;
    const int SPEED_STEEL = 16400;
    double time = 0.0;
    
    // DISPLAY A MENU (Allowing user to select air, water, or steel)
    cout << "1. Calculate the time in the air condition\n"
         << "2. Calculate the time in the water condition\n"
         << "3. Calculate the time in the steel condition\n";
    
    cout << "Your choice : ";
    cin >> typeMedium;
    
    // INPUT, CALCLATE, OUTPUT PROCESS
    switch (typeMedium)
    {
        case 1:
            cout<<"Enter the distance a sound wave will travel in the air condition\n";
            cin>>distance;
            if(distance>=0)
            {
                time = distance/SPEED_AIR;
                cout << "Amount of time it will take to " << distance << " feet is about " <<  setprecision(4) << fixed << time << "seconds\n";
            }
            else
            {
                cout << "Do not enter the distance less than 0\n";
            }
            break;
        
        case 2:
            cout<<"Enter the distance a sound wave will travel in the water condition\n";
            cin>>distance;
            if(distance>=0)
            {
                time = distance/SPEED_WATER;
                cout << "Amount of time it will take to " << distance << " feet is about " <<  setprecision(4) << fixed << time << "seconds\n";
            }
            else
            {
                cout << "Do not enter the distance less than 0\n";
            }
            break;
            
        case 3:
            cout<<"Enter the distance a sound wave will travel in the steel condition\n";
            cin>>distance;
            if(distance>=0)
            {
                time = distance/SPEED_STEEL;
                cout << "Amount of time it will take to " << distance << " feet is about " <<  setprecision(4) << fixed << time << "seconds\n";
            }
            else
            {
                cout << "Do not enter the distance less than 0\n";
            }
            break;
            
        default:
            cout <<"Select one of the available choice from the menu\n";
            break;
    }
    
    return 0;
}
