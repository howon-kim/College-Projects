//
//  Lab 5.6 : Working with while and nested for Loops
//  TeamP_lab56.cpp
//  ENVIRONMENT : MAC OS X 10.02 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/24/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int num_years=0;
    double num_rainfall=0;
    int total_months=0;
    double total_rainfall=0.0;
    double ave_rainfall=0.0;
    
    int current_year=1;
    int current_month=1;

    cout<<"Enter the number of years : ";
    cin>>num_years;
        
    while(num_years<1)
    {
        cout<<"Do not accept a number less than 1 for the number of years"<<endl
            <<"Retry to enter the number of years : ";
        cin>>num_years;
    }
    
    for(;current_year<=num_years;current_year++)
    {
        cout<<"Enter the "<<current_year<<" years rainfall"<<endl;
        for(;current_month<=12;current_month++)
        {
            cout<<"Enter the inches of rainfall in "<<current_month<<" month : ";
            cin>>num_rainfall;
            
            while(num_rainfall<0)
            {
                cout<<"Do not accept negative numbers for the monthly rainfall"<<endl
                    <<"Retry to enter the inches of rainfall for "<<current_month<<" month : ";
                cin>>num_rainfall;
            }
            total_rainfall+=num_rainfall;
        }
        current_month=1;
    }
    
    total_months=num_years*12;
    ave_rainfall=num_rainfall/total_months;
    
    // DISPLAY PROCESS
    cout<<"During "<<total_months<<"There was "<<total_rainfall<<" inches rainfall"<<endl
        <<"Average rainfall per "<<total_months<<"is about "<<ave_rainfall<<" inches"<<endl;
    return 0;
}
