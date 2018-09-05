//
//  Lab 6.1 : Function with No Parameters
//  TeamP_lab61.cpp
//  Environment : MAC OS X 10.03 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 3/4/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

/* Write a function named coinToss that simulates the tossing of a coin
 * When you call the function, it should generate a random number in the range of 1 through 2
 * If the random number is 1, the function should display heads
 * If the random number is 2, the function should display tails
 * Demonstrate the function in a program that asks the user how many times the coin should be tossed
 * and then simulates the tossing of the coin that number of times.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototype
void coinToss();

// MAIN FUNCTION
int main()
{
    
    // DECLARE VARIABLES
    unsigned int seed=0;
    int num_current=1;
    int num_toss=0;
    
    // SEED THE TIME
    seed=time(0);
    srand(seed);
    
    // INPUT PROCESS
    cout<<"How many times the coin should be tossed : ";
    cin>>num_toss;
    
    // CALCULATE PROCESS
    while(num_current<=num_toss)
    {
        coinToss();
        num_current++;
    }

    return 0;
}

// coinToss FUNCTION
void coinToss()
{
    int num_random=0;
    num_random=1+rand()%(2-1+1);
    
    if(num_random==1)
    {
        cout<<"Heads"<<endl;
    }
    else if(num_random==2)
    {
        cout<<"Tails"<<endl;
    }
    else
    {
        cout<<"Program Error"<<endl;
    }
    return;
}