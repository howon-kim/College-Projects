//
//  PersonData.h
//  22B_KIM_HOWON_H7C
//
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Specification file for the PersonData Class


#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <stdio.h>
#include <string>
using namespace std;

class PersonData
{
protected:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    
public:
    // Constructor
    PersonData();
    PersonData(string last, string first, string address, string city, string state, string zip, string phone);

    
    // Mutator function
    void setLast (string last)
    { lastName = last; }
    
    void setFirst (string first)
    { firstName = first; }
    
    void setAddress (string address1)
    { address = address1; }
    
    void setCity (string city1)
    { city = city1; }
    
    void setState (string state1)
    { state = state1; }
    
    void setZip (string zip1)
    { zip = zip1; }
    
    void setPhone (string phone1)
    { phone = phone1; }
    
    // Accessor function
    string getLast () const
    { return lastName; }
    
    string getFirst () const
    { return firstName; }
    
    string getAddress () const
    { return address; }
    
    string getCity () const
    { return city; }
    
    string getState () const
    { return state; }
    
    string getZip () const
    { return zip; }
    
    string getPhone () const
    { return phone; }
    
};

#endif /* defined(PERSONDATA_H) */
