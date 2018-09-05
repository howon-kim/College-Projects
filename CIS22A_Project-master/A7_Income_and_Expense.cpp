//
//  Assignment 7 : Company's income and expense amounts
//  KimHowon_a7.cpp
//  MAC OS X 10.2 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/20/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // DECLARE VARIABLES
    int item_income=0;
    int item_expense=0;
    int price_income=0;
    int price_expenses=0;
    int total_income=0;
    int total_expenses=0;
    int profit=0;
    
    // INPUT THE INCOME ITEMS
    cout<<"Enter the Income items : ";
    cin>>item_income;
    // Verifying process
    while(item_income<0)
    {
        cout<<"Enter the Income items in positive value : ";
        cin>>item_income;
    }
    
    // CALCULATE THE TOTAL INCOME
    for(int items=1;items<=item_income;items++)
    {
        
        cout<<"Enter the price of " <<items<<" item incomes : ";
        cin>>price_income;
        // If User input negative integers, it can be regard as expenses
        // Prevention of input the negative intergers
        while(price_income<0)
        {
            cout<<"Enter the price of " <<items<<" item incomes in positive integers : ";
            cin>>price_income;
        }
        total_income+=price_income;
    }
    
    // INPUT THE EXPENSE ITEMS
    cout<<"Enter the Expense items : ";
    cin>>item_expense;
    // Verifying process
    while(item_expense<0)
    {
        cout<<"Enter the Expense items in positive value : ";
        cin>>item_expense;
    }
    
    // CALCULATE THE TOTAL EXPENSES
    for(int items=1;items<=item_expense;items++)
    {
        cout<<"Enter the price of " <<items<<" item expenses : ";
        cin>>price_expenses;
        // If user input negative integers, it can show the wrong profit
        // Prevention of input the negative intergers
        while(price_expenses<0)
        {
            cout<<"Enter the price of " <<items<<" item expenses in positive integers : ";
            cin>>price_expenses;
        }
        total_expenses+=price_expenses;
    }
    
    // CALCULATE THE PROFIT
    total_expenses=(-total_expenses);
    profit=total_income+total_expenses;
    
    // DISPLAY PROCESS
    cout<<setw(20)<<left<<"TOTAL INCOME"<<setw(10)<<right<<total_income<<"$"<<endl
        <<setw(20)<<left<<"TOTAL EXPENSES"<<setw(10)<<right<<total_expenses<<"$"<<endl
        <<"==============================="<<endl
        <<setw(20)<<left<<"PROFIT(LOSS)"<<setw(10)<<right<<profit<<"$"<<endl;
    return 0;
}
