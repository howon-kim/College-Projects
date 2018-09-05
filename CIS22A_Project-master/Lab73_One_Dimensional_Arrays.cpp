//
//  Lab 7.3 : Working with One-Dimensional Arrays
//  TeamP_lab73.cpp
//  Environment : MAC OS X 10.3 (XCODE 6.2)
//
//  Created by HOWON KIM on 3/16/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // DECLARE ARRAYS
    const int TYPE_SALSA = 5;
    string name[TYPE_SALSA] = { "mild", "medium", "sweet", "hot", "zesty" };
    int sold[TYPE_SALSA];
    int total_sales = 0;
    string highest_selling = "";
    string lowest_selling = "";
    int highest_sales = 0;
    int lowest_sales = 0;
    
    // ENTER THE NUMBER OF JARS SOLD FOR EACH TYPE
    for (int num = 0; num < TYPE_SALSA; num++)
    {
        cout << "How many " << name[num] << " salsa sold in last month : ";
        cin >> sold[num];
        
        // INPUT VALIDATION
        while (sold[num] < 0)
        {
            cout << "Do not accept negative values for number of jars sold"<<endl
            << "How many " << name[num] << " salsa sold in this month : ";
            cin >> sold[num];
        }
    }
    
    // CALCULATE PROCESS
    // INITIALIZE VARIABLE
    highest_sales = sold[0];
    lowest_sales = sold[0];
    for (int num = 0; num < TYPE_SALSA; num++)
    {
        // CALCULATE PROCESS
        total_sales += sold[num];
        if (sold[num]>=highest_sales)
        {
            highest_sales = sold[num];
            highest_selling = name[num];
        }
        if (sold[num] <= lowest_sales)
        {
            lowest_sales = sold[num];
            lowest_selling = name[num];
        }
    }
    
    // DISPLAY PROCESS
    for (int num = 0; num < TYPE_SALSA; num++)
    {
        cout << name[num] << " Salsa sold : " << sold[num]<<endl;
    }
    cout<<endl<< "Total sales : " << total_sales<<endl
    << "Lowest selling product : " << lowest_selling<<endl
    << "Highest selling product : " << highest_selling<<endl;
    return 0;
}