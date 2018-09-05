//
//  Lab 7.1 : Working with One-Dimensional Arrays
//  TeamP_lab71.cpp
//  Environment : MAC OS X 10.3 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 3/12/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    // DECLARE VARIABLES
    unsigned int seed=0;
    int random[10];
    int password=31337;
    int input=0;
    int input_pw[5];
    int calc=10000;
    int temp=0;
    int verify=0;

    // GENERATE RANDOM SEED
    seed=time(0);
    srand(seed);
    
    // DISPLAY THE PIN
    cout<<"PIN: 0 1 2 3 4 5 6 7 8 9"<<endl<<"NUM: ";
    
    // MAKE RANDOM NUMBER AND DISPLAY
    for(int o=0;o<10;o++)
    {
        random[o]=0+rand()%(9-0+1);
        cout<<random[o]<<" ";
    }

    // INPUT THE PASSWORD
    cout<<endl<<"Enter the password : ";
    cin>>input;
    
    // INPUT THE PASSWORD INTO THE ARRAY
    for(int i=0;i<5;i++)
    {
        // ALGORITHM FOR EXTRACT EACH NUMBER
        input_pw[i]=input/calc;
        input=input-(input_pw[i]*calc);

        calc/=10;
        
        /* VALIDATE INPUT ARRAY*/
        //cout<<input_pw[i]<<endl;
    }
    
    // RE-INITIALIZE
    calc=10000;
    
    // COMPARE THE PASSWORD
    for(int i=0;i<5;i++)
    {
        temp=password/calc;
        password=password-(temp*calc);
        
        // IF ONE NUMBER IS WRONG, TURN 1
        if(random[temp]!=input_pw[i])
        {
            verify=1;
        }
        calc/=10;
    }
    
    // DISPLAY PROCESS
    if(verify==0)
    {
        cout<<"Correct Password!"<<endl;
    }
    else
    {
        cout<<"Incorrect Password!"<<endl;
    }
    return 0;
}
