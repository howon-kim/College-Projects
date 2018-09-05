//
//  NumDays.h
//  22B_KIM_HOWON_H7A
//
//  Created by HOWON KIM on 6/18/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Specification file for the NumDays Class
//  Store a value that represents a number of work hours and convert it to a number of days

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <stdio.h>

class NumDays
{
private:
    int hours; // To hold a number of hours
    
public:
    // Constructor
    NumDays()
    { hours = 0; }
    
    NumDays(int h)
    { hours = h; }
    
    NumDays(double d)
    { hours = d * 8.0; }
    
    // Mutator function
    void setHours(int i)
    { hours = i; }
    
    void setDays(double d)
    { hours = d * 8.0; }
    
    // Accessor function
    double getDays(void)
    { return hours/8.0; }
    
    int getHours(void)
    { return hours; }
    
    
    // Overloaded operator functions
    NumDays operator+(const NumDays &t); // Overloaded +
    NumDays operator-(const NumDays &t); // Overloaded -
    NumDays operator++(); // Prefix ++
    NumDays operator++(int); // Postfix ++
    NumDays operator--(); // Prefix --
    NumDays operator--(int); // Postfix --

    
    
};



#endif /* defined(___2B_KIM_HOWON_H7A__NumDays__) */
