//
//  Die.cpp
//  22B_KIM_HOWON_H5
//
//  Created by HOWON KIM on 6/2/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Implementatoin file for the DIE Class
//  DIE Class is roll the 2 dice and returns the added value of 2 dice

#include "Die.h"
#include <cstdlib> // For rand and srand
#include <ctime> // For the time function
#include <iostream>
using namespace std;




//********************************************************************
// The roll member function simulates the rolling of two dice
//********************************************************************

void Die::roll()
{
    // Get the system time
    unsigned seed = time(0);
    
    // Seed the random number generator
    srand(seed);

    
    // Constant for the minumum die value
    const int MIN_VALUE = 1; // minimum die value
    
    // Get a random value for the die
    dice1 = (rand() % (6 - MIN_VALUE + 1)) + MIN_VALUE;
    dice2 = (rand() % (6 - MIN_VALUE + 1)) + MIN_VALUE;

}


//********************************************************************
// The calcTotal member function adds the number of two dice
// and return the total value
//********************************************************************

int Die::calTotal()
{
// FUNCTINO INLINE
    return dice1 + dice2;
}