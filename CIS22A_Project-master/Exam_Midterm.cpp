//
//  KimHowon_midterm.cpp
//  Midterm : Calculate the bank fees
//  Environment : MAC OS X 10.2 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/11/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    const double FEE_BASIC = 10; // Basic Fee
    const double FEE_20 = 0.10; // Check fee each for 0.10$ fewer than 20 checks
    const double FEE_40 = 0.08; // Check fee each for 0.08$ for 20~39 checks
    const double FEE_60 = 0.06; // Check fee each for 0.06$ for 40~59 checks
    const double FEE_61 = 0.04; // Check fee each for 0.04$ for 60 or more checks
    const double FEE_EXTRA = 15; // Balance of the account falls below 400$, extra 15$
    const int MIN_BALANCE = 400; // Below this balance, need to pay extra 15$
    
    double balance = 0.0;
    int check = 0;
    
    double amountfee = 0.0;
    double amountcharge = 0.0;
    // before any check fees are applied
    
    
// Ask beggining balance and the number of checks written
    cout << "Enter the following information about your checking account.\n"
         << "Beginning balance: $";
    cin >> balance;
    
    if(balance<0)
    {
        cout << "\nYour account is overdrawn!"<<endl;
    }
    else
    {
        cout << "Number of checks written: ";
        cin >> check;
        
        if(check<0)
        {
            cout << "\nNumber of checks must be zero or more." <<endl;
        }
        
            else
            {
                if(balance<MIN_BALANCE)
                {
                    cout << endl;
                    cout << setw(32) << left << "Balance" <<"$" << setw(8) << right << balance <<endl;
                    cout << setw(20) << "Number of checks written:  " << check << endl;
                    if(check<20)
                    {
                        cout << setw(32) << left <<"Check fee" << "$" << setw(8) << right << FEE_20 << endl;
                        amountfee = check * FEE_20;
                        cout << setw(32) << left << "Fee for written checks:" <<  "$" << setw(8) << right << amountfee << endl;
                        cout << setw(32) << left << "Extra Fee" << "$" << setw(8) << right << FEE_EXTRA <<endl;
                        cout << setw(32) << left <<"Monthly Fee" <<  "$" << setw(8) << right << FEE_BASIC << endl;
                        cout << setw(41) << "=========" << endl;
                        amountcharge = FEE_BASIC + FEE_EXTRA + amountfee;
                        cout << setw(32) << left <<"The bank fee for this month is" <<  "$" << setw(8) << right << amountcharge <<endl;
                    }
                    
                    else if(check<40)
                    {
                        cout << setw(32) << left <<"Check fee" << "$" << setw(8) << right << FEE_40 << endl;
                        amountfee = check * FEE_40;
                        cout << setw(32) << left << "Fee for written checks:" <<  "$" << setw(8) << right << amountfee << endl;
                        cout << setw(32) << left << "Extra Fee" << "$" << setw(8) << right << FEE_EXTRA <<endl;
                        cout << setw(32) << left <<"Monthly Fee" <<  "$" << setw(8) << right << FEE_BASIC << endl;
                        cout << setw(41) << "=========" << endl;
                        amountcharge = FEE_BASIC + FEE_EXTRA + amountfee;
                        cout << setw(32) << left <<"The bank fee for this month is" <<  "$" << setw(8) << right << amountcharge <<endl;
                    }
                    
                    else if(check<60)
                    {
                        cout << setw(32) << left <<"Check fee" << "$" << setw(8) << right << FEE_60 << endl;
                        amountfee = check * FEE_60;
                        cout << setw(32) << left << "Fee for written checks:" <<  "$" << setw(8) << right << amountfee << endl;
                        cout << setw(32) << left << "Extra Fee" << "$" << setw(8) << right << FEE_EXTRA <<endl;
                        cout << setw(32) << left <<"Monthly Fee" <<  "$" << setw(8) << right << FEE_BASIC << endl;
                        cout << setw(41) << "=========" << endl;
                        amountcharge = FEE_BASIC + FEE_EXTRA + amountfee;
                        cout << setw(32) << left <<"The bank fee for this month is" <<  "$" << setw(8) << right << amountcharge <<endl;
                    }
                    else if(check>=61)
                    {
                        cout << setw(32) << left <<"Check fee" << "$" << setw(8) << right << FEE_61 << endl;
                        amountfee = check * FEE_61;
                        cout << setw(32) << left << "Fee for written checks:" <<  "$" << setw(8) << right << amountfee << endl;
                        cout << setw(32) << left << "Extra Fee" << "$" << setw(8) << right << FEE_EXTRA <<endl;
                        cout << setw(32) << left <<"Monthly Fee" <<  "$" << setw(8) << right << FEE_BASIC << endl;
                        cout << setw(41) << "=========" << endl;
                        amountcharge = FEE_BASIC + FEE_EXTRA + amountfee;
                        cout << setw(32) << left <<"The bank fee for this month is" <<  "$" << setw(8) << right << amountcharge <<endl;
                    }
                }
                    else
                    {
                        if(check<20)
                        {
                            cout << setw(32) << left <<"Check fee" << "$" << setw(8) << right << FEE_20 << endl;
                            amountfee = check * FEE_20;
                            cout << setw(32) << left << "Fee for written checks:" <<  "$" << setw(8) << right << amountfee << endl;
                            cout << setw(32) << left <<"Monthly Fee" <<  "$" << setw(8) << right << FEE_BASIC << endl;
                            cout << setw(41) << "=========" << endl;
                            amountcharge = FEE_BASIC + amountfee;
                            cout << setw(32) << left <<"The bank fee for this month is" <<  "$" << setw(8) << right << amountcharge <<endl;
                        }
                    
                        else if(check<40)
                        {
                            cout << setw(32) << left <<"Check fee" << "$" << setw(8) << right << FEE_40 << endl;
                            amountfee = check * FEE_40;
                            cout << setw(32) << left << "Fee for written checks:" <<  "$" << setw(8) << right << amountfee << endl;
                            cout << setw(32) << left <<"Monthly Fee" <<  "$" << setw(8) << right << FEE_BASIC << endl;
                            cout << setw(41) << "=========" << endl;
                            amountcharge = FEE_BASIC + amountfee;
                            cout << setw(32) << left <<"The bank fee for this month is" <<  "$" << setw(8) << right << amountcharge <<endl;
                        }
                    
                        else if(check<60)
                        {
                            cout << setw(32) << left <<"Check fee" << "$" << setw(8) << right << FEE_60 << endl;
                            amountfee = check * FEE_60;
                            cout << setw(32) << left << "Fee for written checks:" <<  "$" << setw(8) << right << amountfee << endl;
                            cout << setw(32) << left <<"Monthly Fee" <<  "$" << setw(8) << right << FEE_BASIC << endl;
                            cout << setw(41) << "=========" << endl;
                            amountcharge = FEE_BASIC + amountfee;
                            cout << setw(32) << left <<"The bank fee for this month is" <<  "$" << setw(8) << right << amountcharge <<endl;
                        }
                        else if(check>=61)
                        {
                            cout << setw(32) << left <<"Check fee" << "$" << setw(8) << right << FEE_61 << endl;
                            amountfee = check * FEE_61;
                            cout << setw(32) << left << "Fee for written checks:" <<  "$" << setw(8) << right << amountfee << endl;
                            cout << setw(32) << left <<"Monthly Fee" <<  "$" << setw(8) << right << FEE_BASIC << endl;
                            cout << setw(41) << "=========" << endl;
                            amountcharge = FEE_BASIC + amountfee;
                            cout << setw(32) << left <<"The bank fee for this month is" <<  "$" << setw(8) << right << amountcharge <<endl;
                        }
                    }
                }
    
    }
    return 0;
}
