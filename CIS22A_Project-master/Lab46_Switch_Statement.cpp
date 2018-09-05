//
//  TeamP_lab46
//  Lab 4.6 : The Switch Statement
//  Development Environment : MAC OS X 10.02 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/9/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

//  Write a Program that calculates a customer's monthly bill
#include <iostream>
using namespace std;
int main()
{
    char package;
    const double PRICE_A = 9.95;
    const double ADDPRICE_A = 2.00;
    const int GIVENHOUR_A = 10;
    const double PRICE_B = 14.95;
    const double ADDPRICE_B = 1.00;
    const int GIVENHOUR_B = 20;
    const double PRICE_C = 19.95;
    const int MAX_HOUR = 744;
    int hour = 0;
    double bill = 0.0;
    
    
// Ask which package the customer has purchased
// User only selects package A, B or C (capital character)
    cout << "A. Package A\n"
         << "B. Package B\n"
         << "C. Package C\n";
    
    cout << "Choose the package : ";
    cin >> package;
    

// CALCULATE PROCESS
    switch (package)
    {
    case 'A':
     cout << "How many hours were used : ";
     cin >> hour;
        if(hour<=GIVENHOUR_A)
        {
            bill = PRICE_A;
            cout << "Your total amount is " << bill << "$" << endl;
        }
        else if(hour<=MAX_HOUR)
        {
            bill = PRICE_A + (ADDPRICE_A * (hour-GIVENHOUR_A));
            cout << "Your total amount is "<< bill << "$" << endl;
        }
        else
        {
            cout << "The number of hours used in a month cannot exceed 744" << endl;
        }
    break;
    
    case 'B':
        cout << "How many hours were used : ";
        cin >> hour;
        if(hour<=GIVENHOUR_B)
        {
            bill = PRICE_B;
            cout << "Your total amount is " << bill << "$" << endl;
        }
        else if(hour<=MAX_HOUR)
        {
            bill = PRICE_B + (ADDPRICE_B * (hour-GIVENHOUR_B));
            cout << "Your total amount is "<< bill << "$" << endl;
        }
        else
        {
            cout << "The number of hours used in a month cannot exceed 744" << endl;
        }
    break;
            
    case 'C':
        cout << "How many hours were used : ";
        cin >> hour;
        if(hour<=MAX_HOUR)
        {
            bill = PRICE_C;
            cout << "Your total amount is "<< bill << "$" << endl;
        }
        else
        {
            cout << "The number of hours used in a month cannot exceed 744" << endl;
        }
    break;
            
    default :
    cout << "You chosen the package " << package << endl
         << "You need to choose the package within A or B or C" << endl;
    }
    
    return 0;
}
