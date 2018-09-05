//
//  NumDays.cpp
//  22B_KIM_HOWON_H7A
//
//  Created by HOWON KIM on 6/18/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Implementation file for the NumDays Class
//  Store a value that represents a number of work hours and convert it to a number of days

#include "NumDays.h"

//**********************************************
// Overloaded binary + operator.               *
//**********************************************

NumDays NumDays::operator+ (const NumDays &t)
{
    NumDays total;
    total.hours = hours + t.hours;
    return total;
}


//**********************************************
// Overloaded binary - operator.               *
//**********************************************

NumDays NumDays::operator- (const NumDays &t)
{
    NumDays total;
    if(hours >= t.hours)
    {
        total.hours = hours - t.hours;
    }
    else
    {
        total.hours = t.hours - hours;
    }
    return total;
}


//*************************************************************
// Overloaded prefix ++ operator. Causes the hours member to  *
// be incremented. Returns the incremented object.            *
//*************************************************************

NumDays NumDays::operator++()
{
    ++hours;
    return *this;
}


//***************************************************************
// Overloaded postfix ++ operator. Causes the hours member to   *
// be incremented. Returns the value of the object before the   *
// increment.                                                   *
//***************************************************************

NumDays NumDays::operator++(int)
{
    NumDays temp(hours);
    
    hours++;
    return temp;
}


//*************************************************************
// Overloaded prefix -- operator. Causes the hours member to  *
// be decremented. Returns the decremented object.            *
//*************************************************************

NumDays NumDays::operator--()
{
    --hours;
    return *this;
}


//***************************************************************
// Overloaded postfix -- operator. Causes the hours member to   *
// be decremented. Returns the value of the object before the   *
// decrement.                                                   *
//***************************************************************

NumDays NumDays::operator--(int)
{
    NumDays temp(hours);
    
    hours--;
    return temp;
}