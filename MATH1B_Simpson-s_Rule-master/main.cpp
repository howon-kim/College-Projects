//
//  Simpson's Rule
//
//  Created by HOWON KIM
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Polynomial.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    Polynomial equation;
    int exponent = 0;
    double coefficient = 0;
    
    int n = 0;
    double a = 0;
    double b = 0;
    int count = 0;
    double dx = 0;
    double area = 0;
    
    cout << "===== ENTER THE FUNCTION =====" << endl << endl;
    cout << "Enter the highest exponent : ";
    cin >> exponent;
    
    while(exponent <= -1)
    {
        cout << "Re-Enter the highest exponent : ";
        cin >> exponent;
    }
    
    for(; exponent>=0; exponent--)
    {
        cout << "Enter the coefficient of X^" << exponent << " : ";
        cin >> coefficient;
        
        
        equation.insertTerm(exponent, coefficient);
    }
    

    cout << endl << endl << "===== SIMPSON'S METHOD CALCULATION START =====" << endl << endl;
    cout << "Enter the 'n' (even number) : ";
    cin >> n;
    
    while(n%2 == 1){
        cout << "Enter the n (Even number) : ";
        cin >> n;
    }
    
    
    cout << "Enter the upper limit : ";
    cin >> b;
    
    cout << "Enter the lower limit : ";
    cin >> a;
    
    while(a>=b){
        
        cout << "Enter the upper limit : ";
        cin >> b;
        
        cout << "Enter the lower limit : ";
        cin >> a;
    }
    
    
    cout << endl << endl << "===== SIMPSON'S METHOD CALCULATION PROCESSING =====" << endl << endl;

    dx = (b-a) / n;
    cout << "dx = " << dx << endl;
    
    
    for(double i = a ; i <= b + 0.001 ; i += dx){
        cout << setw(5) << left << "x = " << setw(5) << left << i << setw(5) << "| ";
        if(i == a){
            cout << setw(4) << left << "y = " << setw(8) << left << equation.evaluate(i) << endl;
            area += equation.evaluate(i);
        }
        else if(i >= b - 0.001){
            cout << setw(4) << left << "y = " << setw(8) << left << equation.evaluate(i) << endl;
            area += equation.evaluate(i);
        }
        else if(count %2 == 1){
            cout << setw(4) << left <<  "y = 4 * " << setw(8) << left << equation.evaluate(i) << "  =  " << equation.evaluate(i) * 4 << endl;
            area += equation.evaluate(i) * 4;
        }
        else if(count %2 == 0){
            cout << setw(4) << left << "y = 2 * " << setw(8) << left << equation.evaluate(i) <<  "  =  " << equation.evaluate(i) * 2 << endl;
            area += equation.evaluate(i) * 2;
        }
        else{
            cout << "error " << endl;
        }
        
        count++;

        
    }
    
    cout << endl << endl << "===== SIMPSON'S METHOD CALCULATION RESULT =====" << endl << endl;

    area *= (dx/3);
    cout << "The result of this integration is " <<  area << endl << endl;
        
        
}






