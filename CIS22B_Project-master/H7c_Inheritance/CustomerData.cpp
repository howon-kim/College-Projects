//
//  CustomerData.cpp
//  22B_KIM_HOWON_H7C
//
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Implementation file for the CustomerData Class


#include "CustomerData.h"

//************************************************
// Default constructor                           *
//************************************************

CustomerData::CustomerData():PersonData()
{
    customerNumber = 0;
    mailingList = false;
}


//************************************************
// Constructor                                   *
//************************************************

CustomerData::CustomerData(string last, string first, string address, string city, string state, string zip, string phone, int num, bool list):PersonData(last,first,address,city,state,zip,phone)
{
    setCustomerNumber(num);
    setMailingList(list);
}