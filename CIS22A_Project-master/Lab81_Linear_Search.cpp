//
//  Lab 8.1 : Working with the Linear Search
//  TeamP_lab81.cpp
//  Environment : MAC OS X 10.3 (XCODE 6.2)
//
//  Created by HOWON KIM on 3/18/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Using STL Vector

#include <iostream>
#include <vector>
using namespace std;

// Function Prototype
int searchAccount(vector<int> faccount,int fsearch);

int main()
{
    // DECLARE VECTOR VARIABLE
    vector<int> account;
    
    // DECLARE VARIABLES FOR SEARCH
    int search=0;
    int result=0;
    
    // INPUT PROCESS
    account.push_back(5658845);
    account.push_back(4520125);
    account.push_back(7895122);
    account.push_back(8777541);
    account.push_back(8451277);
    account.push_back(1302850);
    account.push_back(8080152);
    account.push_back(4562555);
    account.push_back(5552012);
    account.push_back(5050552);
    account.push_back(7825877);
    account.push_back(1250255);
    account.push_back(1005231);
    account.push_back(6545231);
    account.push_back(3852085);
    account.push_back(7576651);
    account.push_back(7881200);
    account.push_back(4581002);
    
    /* Amount of Account Number
     * cout<<account.size();
     */
    
    // ENTER CHARGE ACCOUNT NUMBER
    cout<<"Enter the charge account number : ";
    cin>>search;

    // Search the vector
    result=searchAccount(account, search);
    
    // If searchAccount return -1, then search was not found
    if(result==-1)
    {
        cout<<"Number is invalid"<<endl;
    }
    // Otherwise result contains the subscript of the search in the vector
    else
    {
        cout<<"Number is valid"<<endl;
        cout<<search<<" is in the #"<<result+1<<endl;
    }
    
    return 0;
    
}

int searchAccount(vector<int> faccount,int fsearch)
{
    int index=0; // Used as a subscript to search vector
    int position=-1; // To record position of search value
    bool found = false; // Flag to indicate if the value was found
    int size=faccount.size(); // Size of Vector of account
    
    while(index<size && !found)
    {
        if(faccount[index]==fsearch) // If the value is found
        {
            found=true; // Set the flag
            position=index; // Record the value's subscript
        }
        index++; // Go to the next element
    }
    return position; // Return the position, or -1
}
