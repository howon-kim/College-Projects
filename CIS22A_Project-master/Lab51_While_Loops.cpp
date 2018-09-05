//
//  Lab 5.1 Working with the while loop
//  TeamP_lab51.cpp
//  Mac OS X 10.02 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/19/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    // DECLARE VARIABLES
    int num_user=0;
    int num_random=0;
    int num_attempt=1;
    unsigned int seed=0;
    
    // GENERATE RANDOM NUMBER
    seed = time(0);
    srand(seed);
    num_random = 100 + rand()%(999-100+1);
    
    // Random number verifier
    // cout<<num_random;
    
    // INPUT PROCESS
    cout<<"Enter the number\n";
    cin>>num_user;
    
    // LOOP PROCESS
    while(num_user!=num_random)
    {
        if(num_user>num_random)
        {
            cout << "Too high, try again\n";
        }
        else
        {
            cout << "Too low, try again\n";
        }
        cin>>num_user;
        num_attempt++;
        
        // User attempt verifier
        // cout<<num_attempt;
    }
    
    // OUTPUT PROCESS
    cout<<"User's total attempt : "<<num_attempt<<endl;
    return 0;
}
