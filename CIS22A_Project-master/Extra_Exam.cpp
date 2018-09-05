//
//  EXTRA TEST
//  Calculate the Net Pay
//  Enter the Work hours and Calculate the tax, gross pay and net pay
//
//  KimHowon_extra.cpp
//  MAC OS X 10.02 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/21/15.
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
    
    // DECLARE VARIABLES //
    // BASIC INFORMATION VARIABLES
    int num_employee=0;
    double num_hours=0;
    int num_dependents=0;
    
    // REGULAR PAY VARIABLES
    const double regular_rate=16.78;
    double regular_hours=0.0;
    double regular_pay=0.0;
    
    // OVERTIME PAY VARIABLES
    const double overtime_rate=1.5;
    double overtime_hours=0.0;
    double overtime_pay=0.0;
    
    // TOTAL PAY VARIABLE
    double pay_gross=0.0;
    double pay_net=0.0;
    
    // TAX RATE VARIABLES
    const double tax_FICA=0.06;
    const double tax_state=0.05;
    const double tax_federal300=0.10;
    const double tax_federal400=0.12;
    const double tax_federal500=0.15;
    const double tax_federalover=0.20;
    
    // TAX WITHHELD VARIABLES
    const double withheld_union=10;
    double withheld_insurance=0.0;
    double withheld_FICA=0.0;
    double withheld_state=0.0;
    double withheld_federal=0.0;
    
    
    // INPUT PROCESS //
    cout<<"Employee number: ";
    cin>>num_employee;
    cout<<endl;
    cout<<setw(28)<<left<<"Number of dependents:";
    cin>>num_dependents;
    cout<<setw(27)<<left<<"Number of hours worked:"<<right;
    cin>>num_hours;


    // CALCULATE PROCESS //
    // CALCULATE OVERTIME WORK HOURS AND REGULAR HOURS
    if(num_hours>40)
    {
        overtime_hours=num_hours-40;
        regular_hours=40;
    }
    else
    {
        regular_hours=num_hours;
    }
    
    // CALCULATE PAY
    regular_pay=regular_rate*regular_hours;
    overtime_pay=(regular_rate*overtime_hours)*overtime_rate;
    
    // CALCULATE GROSS PAY
    pay_gross=regular_pay+overtime_pay;
    
    // CALCULATE FICA TAX WITHHELD
    withheld_FICA=pay_gross*tax_FICA;
    
    // CALCULATE STATE TAX WITHHELD
    withheld_state=pay_gross*tax_state;
    
    // CALCULATE FEDERAL INCOME TAX WITHHELD IN SEVERAL STAGE
    if(pay_gross<=300)
    {
        withheld_federal=pay_gross*tax_federal300;
    }
    else if(pay_gross<=400)
    {
        withheld_federal=pay_gross*tax_federal400;
    }
    else if(pay_gross<=500)
    {
        withheld_federal=pay_gross*tax_federal500;
    }
    else
    {
        withheld_federal=pay_gross*tax_federalover;
    }
    
    // CALCULATE HEALTH INSURANCE PREMIUM WITHHELD
    if(num_dependents>=3)
    {
        withheld_insurance=35;
    }
    
    // CALCULATE NET PAY
    pay_net=pay_gross-(withheld_FICA+withheld_federal+withheld_state+withheld_union+withheld_insurance);
    
    
    // DISPLAY PROCESS //
    // DISPLAY REGULAR PAY
    cout<<setw(26)<<left<<"Regular pay rate:"<<right<<"$"<<regular_rate<<setw(5)<<"$"<<setw(8)<<regular_pay<<endl;
    // DISPLAY OVERTIME WORK (IF EXIST)
    if(overtime_hours!=0)
    {
        cout<<setw(27)<<left<<"Overtime hours worked:"<<right<<overtime_hours<<endl
            <<setw(28)<<left<<"With overtime premium:"<<right<<overtime_rate<<setw(5)<<"$"<<setw(8)<<overtime_pay<<endl;

    }
    
    // DISPLAY GROSS PAY
    cout<<setw(45)<<"---------"<<endl
        <<setw(32)<<left<<"Gross pay:"<<right<<setw(5)<<"$"<<setw(8)<<pay_gross<<endl;
    // DISPLAY FICA TAX WITHHELD
    cout<<endl
        <<setw(32)<<left<<"FICA tax withheld:"<<right<<setw(5)<<"$"<<setw(8)<<withheld_FICA<<endl;
    // DISPLAY FEDERAL INCOME TAX WITHHELD IN SEVERAL STAGE
    if(pay_gross<=300)
    {
        cout<<setw(27)<<left<<"Federal Income Tax withheld (10%):  "<<"$"<<right<<setw(8)<<withheld_federal<<endl;
    }
    else if(pay_gross<=400)
    {
        cout<<setw(27)<<left<<"Federal Income Tax withheld (12%):  "<<"$"<<right<<setw(8)<<withheld_federal<<endl;
    }
    else if(pay_gross<=500)
    {
        cout<<setw(27)<<left<<"Federal Income Tax withheld (15%):  "<<"$"<<right<<setw(8)<<withheld_federal<<endl;
    }
    else
    {
        cout<<setw(27)<<left<<"Federal Income Tax withheld (20%):  "<<"$"<<right<<setw(8)<<withheld_federal<<endl;
    }
    // DISPLAY STATE TAX WITHHELD
    cout<<setw(32)<<left<<"State Tax withheld:"<<right<<setw(5)<<"$"<<setw(8)<<withheld_state<<endl;
    // DISPLAY INSURANCE WITHHELD (IF EXIST)
    if(withheld_insurance!=0)
    {
        cout<<setw(27)<<left<<"Health Insurance Premium withheld:  "<<"$"<<right<<setw(8)<<withheld_insurance<<endl;
    }
    // DISPLAY UNION DUES WITHHELD
    cout<<setw(32)<<left<<"Union Dues withheld:"<<right<<setw(5)<<"$"<<setw(8)<<withheld_union<<endl
        <<setw(45)<<"---------"<<endl
    // DISPLAY NET PAY
        <<setw(32)<<left<<"Net Pay:"<<right<<setw(5)<<"$"<<setw(8)<<pay_net<<endl;

    return 0;
}
