//
//  Lab 5.2 : Working with the while loop
//  TeamP_lab52.cpp
//  MAC OS X 10.02 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/19/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    // DECLARE VARIABLES
    int num_user=0;
    int num_smallest=0;
    int num_largest=0;
    
    // INPUT PROCESS
    cout<<"Enter the number : ";
    cin>>num_user;
    
    // INITIALIZE THE VARIABLES
    num_smallest=num_user;
    num_largest=num_user;
    
    // LOOP PROCESS
    while(num_user!=-99)
    {
        if(num_user>num_largest)
        {
            num_largest=num_user;
        }
        else if(num_user<num_smallest)
        {
            num_smallest=num_user;
        }
        cout<<"Enter the number : ";
        cin>>num_user;
    }
    
    // OUTPUT PROCESS
    cout<<"Largest number : "<<num_largest<<endl;
    cout<<"Smallest number : "<<num_smallest<<endl;
    return 0;
}
