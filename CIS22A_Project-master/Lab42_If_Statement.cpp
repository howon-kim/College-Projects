//
// TeamP_Lab42.cpp
// Lab 4.2 : Working with if
// Environment : MAC OS X 10.02 (XCODE 6.1.1)
//
// Created by HOWON KIM on 2/2/15.
// Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    // DECLARE VARIABLES
    double amountPaid = 0.0;
    double amountOwed = 0.0;
    const double DOLLAR = 1.0;
    const double QUARTER = 0.25;
    const double DIME = 0.10;
    const double NICKEL = 0.05;
    const double PENNIE = 0.01;
    double amountChange = 0.0;
    int amountDollars = 0;
    int amountQuarters = 0;
    int amountDimes = 0;
    int amountNickels = 0;
    double amountPennies = 0.0;
    double currentOwed = 0.0;
    
    
    // INPUT PROCESS
    cout << "Please enter the amount paid: ";
    cin >> amountPaid;
    cout << "Please enter the amount owed: ";
    cin >> amountOwed;
    
    
    // CALCULATE PROCESS
    amountChange = amountPaid - amountOwed;
    amountDollars = amountChange / DOLLAR;
    amountQuarters = (amountChange - amountDollars) / QUARTER;
    amountDimes = (amountChange - amountDollars - amountQuarters*QUARTER)/ DIME;
    amountNickels = (amountChange - amountDollars - amountQuarters*QUARTER - amountDimes*DIME)/ NICKEL;
    amountPennies = (amountChange - amountDollars - amountQuarters*QUARTER - amountDimes*DIME - amountNickels*NICKEL)/ PENNIE;

    
    // OUTPUT PROCESS
    if (amountPaid >= amountOwed)
    {
        cout << "AMOUNT OF CHANGE : " << amountChange << endl;
        cout << amountDollars << " Dollars" << endl;
        cout << amountQuarters << " Quarters" << endl;
        cout << amountDimes << " Dimes" << endl;
        cout << amountNickels << " Nickels" << endl;
        cout << amountPennies << " Pennies" << endl;
    }
    else
    {
        currentOwed = (amountOwed - amountPaid);
        cout << "Customer need to pay more: " << currentOwed << endl;
        
    }
    return 0;
}