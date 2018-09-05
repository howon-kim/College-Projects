//
//  Lab 6.3 : Function with Return
//  TeamP_lab63.cpp
//  Environment : MAC OS X 10.3 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 3/4/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

// FUNCTION PROTOTYPE
double inputPriceOfPaint();
int inputNumberOfRooms();
int inputAreaOfWallSpace(int);

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // DECLARE VARIABLES
    double price_paint=0.0;
    int num_rooms=0;
    int num_squarefeet=0;
    
    int gallons_paint=0;
    double hours_labor=0.0;
    double total_paintcost=0.0;
    double total_laborcost=0.0;
    double total_charges=0.0;
    
    const double BASIC_WALLSPACE=415.0;
    const double BASIC_LABORHOUR=8.0;
    const double BASIC_LABORCHARGES=18.00;
    
    // INPUT PRICE OF PAINT BY FUNCTION
    price_paint=inputPriceOfPaint();
    
    // INPUT NUMBER OF ROOMS BY FUNCTION
    num_rooms=inputNumberOfRooms();
    
    // CALCULATE AREA OF WALL SPACE IN SQUARE FEET
    num_squarefeet=inputAreaOfWallSpace(num_rooms);
    
    // CALCULATE PROCESS
    gallons_paint=1+(num_squarefeet/BASIC_WALLSPACE);
    hours_labor=static_cast<double>(num_squarefeet)/(BASIC_WALLSPACE/BASIC_LABORHOUR);
    total_paintcost=gallons_paint*price_paint;
    total_laborcost=hours_labor*BASIC_LABORCHARGES;
    total_charges=total_paintcost+total_laborcost;
    
    // DISPLAY PROCESS
    cout<<endl<<"ESTIMATED CHARGES"<<endl
        <<"------------------"<<endl<<endl
        <<setw(16)<<left<<"Gallons of paint"<<":  "<<gallons_paint<<endl
        <<setw(16)<<left<<"Hours of labor"<<":  "<<hours_labor<<endl
        <<setw(16)<<left<<"Price per gallon"<<": $"<<price_paint<<endl
        <<setw(16)<<left<<"Paint cost:"<<"  $"<<total_paintcost<<endl
        <<setw(16)<<left<<"Total labor:"<<"  $"<<total_laborcost<<endl
        <<setw(16)<<left<<"Total charges:"<<"  $"<<total_charges<<endl;
    return 0;
    
}

// INPUT PRICE OF PAINT
double inputPriceOfPaint()
{
    double fprice_paint=0.0;
    cout<<"Enter the price of the paint, per gallon: ";
    cin>>fprice_paint;
    
    // INPUT VALIDATION : LESS THAN $10.00
    while(fprice_paint<10.00)
    {
        cout<<"Do not enter the price of paint less than $10.00"<<endl
            <<"Retry to enter the price of the paint, per gallon: ";
        cin>>fprice_paint;
    }
    
    return fprice_paint;
}

// INPUT NUMBER OF ROOMS
int inputNumberOfRooms()
{
    int fnum_rooms=0;
    cout<<"Enter the number of rooms to be painted: ";
    cin>>fnum_rooms;
    
    // INPUT VALIDATION : LESS THAN 1
    while(fnum_rooms<1)
    {
        cout<<"Do not enter the number of rooms less than 1"<<endl
            <<"Retry to enter the number of rooms to be painted: ";
        cin>>fnum_rooms;
    }
    return fnum_rooms;
}

// INPUT AREA OF WALL SPACE
int inputAreaOfWallSpace(int total_rooms)
{
    int current_wallspace=0;
    int total_wallspace=0;
    
    // INPUT AREA OF WALL SPACE FOR EACH ROOM
    for(int current_room=1;current_room<=total_rooms;current_room++)
    {
        cout<<"Room "<<current_room<<": Enter the area of wall space in square feet: ";
        cin>>current_wallspace;
        
        // INPUT VALIDAATION : NOT NEGATIVE VALUE
        while(current_wallspace<0)
        {
            cout<<"Do not enter the negative value for square footage of wall space"<<endl
                <<"Room "<<current_room<<": Enter the area of wall space in square feet: ";
            cin>>current_wallspace;

        }
        // CALCULATE TOTAL AREA OF WALL SPACE
        total_wallspace+=current_wallspace;
    }
    return total_wallspace;
}