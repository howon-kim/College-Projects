//
//  PersonData.cpp
//  22B_KIM_HOWON_H7C
//
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Implementation file for the PersonData Class

#include "PersonData.h"

//************************************************
// Default constructor                           *
//************************************************

PersonData::PersonData()
{
    lastName = "unknown";
    firstName = "unknown";
    address = "unknown";
    city = "unknown";
    state = "unknown";
    zip = "unknown";
    phone = "unknown";
}


//************************************************
// Constructor                                   *
//************************************************

PersonData::PersonData(string last, string first, string address, string city, string state, string zip, string phone)
{
    setLast(last);
    setFirst(first);
    setAddress(address);
    setCity(city);
    setState(state);
    setZip(zip);
    setPhone(phone);
}