//
//  Assignment 10 : Sales commission
//  KimHowon_a10.cpp
//  Environment : MAC OS X 10.3 (XCODE 6.2)
//
//  Created by HOWON KIM on 3/13/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
using namespace std;


// FUNTION PROTOTYPE
double getAmountSoldBySalesPeson ();
void calculateCommission (double, double&, double);
void displayCommission (double);
void calculateTotalCommission (double, double&);


int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
 
    // DECLARE VARIABLES
    double amount_sold=0.0;
    double commission=0.0;
    double total_commission=0.0;
   
    // CALCULATE PROCESS
    while(amount_sold!=-99)
    {
        amount_sold=getAmountSoldBySalesPeson();
    if(amount_sold==-99)
        {
        cout<<"Total commission : "<<total_commission<<endl;
        }
    else
        {
        calculateCommission(amount_sold, commission, .10);
        displayCommission(commission);
        calculateTotalCommission(commission, total_commission);
        cout<<"To finish entering the sales amount, enter -99"<<endl;
        }
    }
    
    
    return 0;
}

// GET AMOUNT SOLD FUNCTION
double getAmountSoldBySalesPeson(void)
{
    double famount_sold=0.0;
    cout<<"Enter the amonut sold by a salesperson : ";
    cin>>famount_sold;
    return famount_sold;
}

// CALCULATE COMMISSION FUNCTION
void calculateCommission (double total_sold, double &fcommission, double commission_rate)
{
    fcommission=total_sold*commission_rate;
    return;
}

// DISPLAY EACH SALESPERSON'S COMMISSION FUNCTION
void displayCommission (double display_commission)
{
    cout<<"This person's commission : "<<display_commission<<endl;
    return;
}

// CALCULATE TOTAL COMMISISON FUNCTION
void calculateTotalCommission (double calc_commission, double &calc_total_commission)
{
    calc_total_commission+=calc_commission;
    return;
}