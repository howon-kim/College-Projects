//
//  Lab 5.4 : Working with the for Loops
//  TeamP_lab54.cpp
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
    int num_First=0;
    int num_Second=0;
    int num_Sum=0;
    //string error="First number must not be greater than Second number\nRetry to enter the First number and Second number\nEnter the Fisrt number:";
    
    // INPUT PROCESS
    cout << "Enter the First number : ";
    cin>>num_First;
    cout << "Enter the Second number : ";
    cin>>num_Second;
    
    // VERIFICATION PROCESS
    while(num_First>num_Second)
    {
        cout<<"First number must not be greater than Second number"<<endl
            <<"Retry to enter the First number and Second number"<<endl
            << "Enter the First number : ";
        cin>>num_First;
        cout << "Enter the Second number : ";
        cin>>num_Second;
    }
    // LOOP CALCULATION
    for(;num_First<=num_Second;num_First++)
    {
        if(num_First%2==0)
        {
            num_Sum+=num_First;
        }
    }
    // OUTPUT PROCESS
    cout<<"Sum of the even integers : "<<num_Sum<< endl;
    return 0;
}
