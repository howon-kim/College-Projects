//
//  Lab 6.5 : Pass by reference
//  TeamP_Lab65.cpp
//  ENVIRONMENT : MAC OS X 10.3 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 3/10/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
using namespace std;

void inputOrderStockShippingCharges(int&, int&, double&);
void displayOrder (int, int, double=10.00);

int main()
{
    int num_order=0, num_stock=0;
    double charges_shipping =0.0;
    
    // INPUT PROCESS BY FUNCTION
    inputOrderStockShippingCharges(num_order, num_stock, charges_shipping);
    
    // DISPLAY PROCESS BY FUNCTION
    if(charges_shipping==0.0)
    {
        displayOrder(num_order, num_stock);
    }
    else
    {
        displayOrder(num_order, num_stock,charges_shipping);
    }
    return 0;
}

void inputOrderStockShippingCharges(int &order, int &stock, double &shipping)
{
    // FOR SELECT SPECIAL CHARGES
    char choice;
    
    // INPUT NUMBER OF SPOOLS ORDERED
    cout<<"Enter the number of spools ordered : ";
    cin>>order;
    
    // VALIDATION PROCESS
    while(order<1)
    {
        cout<<"Do not enter the number of spools ordered less than 1"<<endl
            <<"Retry to enter the number of spools ordered : ";
        cin>>order;
    }
    
    // INPUT THE NUMBER OF SPOOLS IN STOCK
    cout<<"Enter the number of spools in stock : ";
    cin>>stock;
    
    // VALIDATION PROCESS
    while(stock<0)
    {
        cout<<"Do not enter the number of spools in stock less than 0"<<endl
            <<"Retry to enter the number of spools in stock : ";
        cin>>stock;
    }
    
    // INPUT THE SPECIAL SHIPPING AND HANDLING CHARGES
    cout<<"If there are special charges, enter Y or y. If not, Press any key : ";
    cin>>choice;
    
    // IF THERE IS SPECIAL SHIPPING AND HANDLING CHARGES
    if (choice=='Y' || choice=='y')
    {
        cout<<"Enter the special charges per spool : ";
        cin>>shipping;
        
        // VALIDATION PROCESS
        while(shipping<0.01)
        {
            cout<<"Do not enter the special charges per spool less than 0.01"<<endl
                <<"Retry to enter the special charges per spool : ";
            cin>>shipping;
        }
    }

    return;
}
void displayOrder (int total_order, int total_stock, double total_shippingcharges)
{
    // DECLARE VARIABLES
    int spools_ready=0;
    int spools_backorder=0;
    int spools_subtotal=0;
    double spools_totalshippingcharges=0.0;
    double spools_totalorder=0.0;
    
    // CALCULATE PROCESS
    if(total_order>total_stock)
    {
        spools_ready=total_stock;
        spools_backorder=total_order-total_stock;
    }
    else
    {
        spools_ready=total_order;
        spools_backorder=total_order-total_stock;
    }
    
    spools_subtotal=spools_ready*100;
    spools_totalshippingcharges=spools_ready*total_shippingcharges;
    spools_totalorder=spools_subtotal+spools_totalshippingcharges;
    
    // DISPLAY RROCESS
    cout<<endl<<"The number of spools ready to ship from current stock : "<<spools_ready<<endl;
    if(spools_backorder>0)
    {
        cout<<"The number of spools on backorder : "<<spools_backorder<<endl;
    }
    cout<<"Subtotal of the portion ready to ship : "<<spools_subtotal<<endl;
    cout<<"Total shipping and handling charges on the portion ready to ship : "<<spools_totalshippingcharges<<endl;
    cout<<"Total of the order ready to ship : "<<spools_totalorder<<endl;
    
    return;
}