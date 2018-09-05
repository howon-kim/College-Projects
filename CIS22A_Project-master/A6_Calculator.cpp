//
//  KimHowon_a6.cpp
//  Aassignment 6 : Calculator
//  Environment : MAC OS X 10.2 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 2/14/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    char letter;
    int num1=0;
    int num2=0;
    int result=0;

    // Program will need to get a letter
    cout<<"What do you want to Calculate\n"
        <<"A(a) : Addition\n"
        <<"S(s) : Subtraction\n"
        <<"M(m) : Multiplication\n"
        <<"D(d) : Division\n"
        <<"Choose one letter : ";
    cin >> letter;
    
    
    switch(letter)
    {
        // Calculate and display the sum of both integers
        case'A':
        case'a':cout<<"Addition Calculation\n"
                    <<"Enter the First number : ";
                cin>>num1;
                cout<<"Enter the Second number : ";
                cin>>num2;
                result = num1+num2;
                cout<<num1<<"+"<<num2<<"="<<result<<endl;
            break;
        
        // Calculate and display the the difference between both integers
        case'S':
        case's':cout<<"Subtraction Calculation\n"
                    <<"Enter the First number : ";
                cin>>num1;
                cout<<"Enter the Second number : ";
                cin>>num2;
            // Subtract the smaller number from the larger one
                if(num1>num2)
                {
                    result = num1-num2;
                    cout<<num1<<"-"<<num2<<"="<<result<<endl;
                }
                else
                {
                    result = num2-num1;
                    cout<<num2<<"-"<<num1<<"="<<result<<endl;
                }
            break;
        
        // Calculate and display the product of both integers
        case'M':
        case'm':cout<<"Multipication Calculation\n"
                    <<"Enter the First number : ";
                cin>>num1;
                cout<<"Enter the Second number : ";
                cin>>num2;
                result = num1*num2;
                cout<<num1<<"*"<<num2<<"="<<result<<endl;
            break;
           
        // Divide both integers
        case'D':
        case'd':cout<<"Division Calculation\n"
                    <<"Enter the Fist number : ";
                cin>>num1;
                cout<<"Enter the Second number : ";
                cin>>num2;
            // Diviging the larger number by the smaller one
                if(num1>num2)
                {
                    result = num1/num2;
                    cout<<num1<<"/"<<num2<<"="<<result<<endl;
                }
                else
                {
                    result = num2/num1;
                    cout<<num2<<"/"<<num1<<"="<<result<<endl;
                }
            break;
        
        // Display an appropriate error message before the program ends
        default:cout<<"Enter the valid letter from the menu\n";
    }
    
    return 0;
}
