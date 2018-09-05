//
//  Die.h
//  22B_KIM_HOWON_H5
//
//  Created by HOWON KIM on 6/2/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Specification file for the DIE Class
//  DIE Class is roll the 2 dice and returns the added value of 2 dice

#ifndef DIE_H
#define DIE_H

#include <stdio.h>

class Die
{
private:
    int dice1; // First die
    int dice2; // Second die
    
public:
    void roll(); // Roll the die
    int calTotal(); // Adds the value of dice and return total number
    
};

#endif /* defined(DIE_H) */
