//
//  NewtonsMethod_cpp
//  NewtonsMethod
//
//  Created by HOWON KIM on 3/08/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Polynomial.h"
using namespace std;

Polynomial *inputNumber();
void displayFunction (Polynomial, Polynomial);
double newtonsMethod (Polynomial, Polynomial);
void displayResult (const double);

int main(int argc, const char * argv[]) {
    
    char choice;
    double result;
    

    while(choice!='N' && choice!='n')
    {
        
        Polynomial poly1;
        poly1 = *inputNumber();
        
        Polynomial poly2 = poly1.derivative();
        
        
        displayFunction(poly1, poly2);
        result = newtonsMethod(poly1, poly2);
        
        displayResult(result);
        while(result == -1111)
        {
            result = newtonsMethod(poly1, poly2);
            displayResult(result);
        }
        
        cout << "Do you want to continue? (Y/N) : ";
        cin >> choice;
    }

}

/*---------------------------------------------------------------------
 Input the number of exponent and coefficient
 --------------------------------------------------------------------*/

Polynomial *inputNumber()
{
    Polynomial *temp;
    
    int exponent;
    double coefficient;
    
    cout << "Enter the highest exponent : ";
    cin >> exponent;
    
    while(exponent <= -1)
    {
        cout << "Re-Enter the highest exponent : ";
        cin >> exponent;
    }
    
    for(; exponent>=0; exponent--)
    {
        cout << "X^" << exponent << " :";
        cin >> coefficient;
        
        
        temp->insertTerm(exponent, coefficient);
    }
    
    return temp;
}



/*---------------------------------------------------------------------
 Display the function and derivative
 --------------------------------------------------------------------*/

void displayFunction(Polynomial function, Polynomial derivative)
{
    cout << left << fixed << setprecision(3) << setw(2) << "F" << "(x) : "; function.print();
    cout << left << fixed << setprecision(3) << setw(2) << "F'" << "(x) : "; derivative.print();
}


/*---------------------------------------------------------------------
 Newton's Method
 If answer is not calculate in 500 times, it regarded as infinte loop.
 --------------------------------------------------------------------*/

double newtonsMethod(Polynomial function, Polynomial derivative)
{
    double input;
    double temp = 0;
    double result = -1;
    int index = 0;
    
    cout << endl << "Enter the number of test : ";
    cin >> input;
    
    cout << "------------------------------------------------------------" << endl;
    
    while (temp != result)
    {
        temp = result;
        result = input - function.evaluate(input)/derivative.evaluate(input);
        cout << fixed << setprecision(10) << setw(10) << result << " = " << right << setw(10) << input << " - (" << function.evaluate(input) << "/" << derivative.evaluate(input) <<")" << endl;
        input = result;
        index++;
        
        if(function.evaluate(input) == 0)
            return result;
        
        if(index == 500)
            return -1111;
    }
    return result;
}

/*---------------------------------------------------------------------
 display the Result
 --------------------------------------------------------------------*/

void displayResult(const double result)
{
    cout << "------------------------------------------------------------" << endl;
    
    if(result == -1111)
    {
        cout << "This is infinite loop. Enter the another number to test" << endl;
        cout << "------------------------------------------------------------" << endl;
        return;
    }
    
    cout << fixed << setprecision(10) << "Result : " << result << endl;
    cout << "------------------------------------------------------------" << endl;

}

