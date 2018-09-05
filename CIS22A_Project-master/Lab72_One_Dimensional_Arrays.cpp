//
//  Lab 7.2 : Working with One-Dimensional Arrays
//  TeamP_lab72.cpp
//  ENVIRONMENT : MAC OS X 10.03 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 3/12/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

/* Write a program so that it asks the user for a percentage amount by which each price should be increased
 * The program then should increase each price in the array by that amount
 * For example, when the user enters the number 15, the program should increase each element's value by 15%
 * After increasing each price, the program should display the contents of the array.
 *
 * Use the following data stored in the array: 10.5, 25.5, 9.75, 6.0, 35.0, 100.4, 10.65, .56, 14.75, 4.78
 */

#include <iostream>
using namespace std;

int main()
{
    // DECLARE VARIABLES
    double percentage=0.0;
    double increment=0.0;
    double array[10]={10.5, 25.5, 9.75, 6.0, 35.0, 100.4, 10.65, .56, 14.75, 4.78};
    
    // INPUT PROCESS
    cout<<"Enter the percentage amount by which each price should be increased : ";
    cin>>percentage;
    
    // CALCULATE AND OUTPUT PROCESS
    for(int num=0;num<10;num++)
    {
        increment=array[num]*(percentage/100);
        array[num]+=increment;
        cout<<array[num]<<endl;
    }


    return 0;
}
