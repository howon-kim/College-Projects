//
//  CustomerData.h
//  22B_KIM_HOWON_H7C
//
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Specification file for the CustomerData Class


#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include <stdio.h>
#include "PersonData.h"

class CustomerData: public PersonData
{
private:
    int customerNumber;
    bool mailingList;
    
public:
    // Constructor
    CustomerData();
    CustomerData(string last, string first, string address, string city, string state, string zip, string phone, int num, bool list);
    
    // Mutator function
    void setCustomerNumber (int num)
    { customerNumber = num; }
    
    void setMailingList (bool list)
    {
        if(list == true)
        {
            mailingList = true;
        }
    }
    
    // Accessor function
    int getCustomerNumber () const
    { return customerNumber; }
    
    bool getMailingList () const
    { return mailingList; }

};

#endif /* defined(CUSTOMERDATA_H) */
