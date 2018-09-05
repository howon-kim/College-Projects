//
//  22B_KIM_HOWON_H7A
//  NumDays Class
//
//  The class’s purpose is to store a value that represents a number of work hours and convert it to a number of days
//
//  Created by HOWON KIM on 6/16/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include "NumDays.h"
using namespace std;

int main()
{
    NumDays a(8);
    NumDays b(10);
    NumDays c; // Initialize to 0
    
    
    // Operator Overloading +
    cout << "Demonstrating binary + operator.\n";
    c = a+b; // 18hours
    cout << "c: " << c.getDays() << " days" << endl; // 2.25
    
    
    // Operator Overloading -
    cout << "\nDemonstrating binary - operator.\n";
    a = b-c; // 10-18 = |-8|
    cout << "a: " << a.getDays() << " days" << endl << endl; // 1.00
    
    
    // Operator Overloading prefix++
    cout << "Demonstrating prefix ++ operator.\n";
    for (int count = 0; count < 12; count++)
    {
        a = ++b;
        cout << "a: " << a.getDays() << " days " ;
        cout << "\tb: " << b.getDays() << " days  " <<endl;
    }
    
    // Operator Overloading postfix++
    cout << "\nDemonstrating postfix ++ operator.\n";
    for (int count = 0; count < 12; count++)
    {
        a = b++;
        cout << "a: " << a.getDays() << " days ";
        cout << "\tb: " << b.getDays() << " days  "<<endl;
    }
    
    // Operator Overloading prefix--
    cout << "\nDemonstrating prefix -- operator.\n";
    for (int count = 0; count < 12; count++)
    {
        a = --b;
        cout << "a: " << a.getDays() << " days " ;
        cout << "\tb: " << b.getDays() << " days  " <<endl;
    }
    
    // Operator Overloading postfix--
    cout << "\nDemonstrating postfix -- operator.\n";
    for (int count = 0; count < 12; count++)
    {
        a = b--;
        cout << "a: " << a.getDays() << " days ";
        cout << "\tb: " << b.getDays() << " days  "<<endl;
    }

    return 0;
}

/* OUTPUT
 Demonstrating binary + operator.
 c: 2.25 days
 
 Demonstrating binary - operator.
 a: 1 days
 
 Demonstrating prefix ++ operator.
 a: 1.375 days 	b: 1.375 days
 a: 1.5 days 	b: 1.5 days
 a: 1.625 days 	b: 1.625 days
 a: 1.75 days 	b: 1.75 days
 a: 1.875 days 	b: 1.875 days
 a: 2 days 	b: 2 days
 a: 2.125 days 	b: 2.125 days
 a: 2.25 days 	b: 2.25 days
 a: 2.375 days 	b: 2.375 days
 a: 2.5 days 	b: 2.5 days
 a: 2.625 days 	b: 2.625 days
 a: 2.75 days 	b: 2.75 days
 
 Demonstrating postfix ++ operator.
 a: 2.75 days 	b: 2.875 days
 a: 2.875 days 	b: 3 days
 a: 3 days 	b: 3.125 days
 a: 3.125 days 	b: 3.25 days
 a: 3.25 days 	b: 3.375 days
 a: 3.375 days 	b: 3.5 days
 a: 3.5 days 	b: 3.625 days
 a: 3.625 days 	b: 3.75 days
 a: 3.75 days 	b: 3.875 days
 a: 3.875 days 	b: 4 days
 a: 4 days 	b: 4.125 days
 a: 4.125 days 	b: 4.25 days
 
 Demonstrating prefix -- operator.
 a: 4.125 days 	b: 4.125 days
 a: 4 days 	b: 4 days
 a: 3.875 days 	b: 3.875 days
 a: 3.75 days 	b: 3.75 days
 a: 3.625 days 	b: 3.625 days
 a: 3.5 days 	b: 3.5 days
 a: 3.375 days 	b: 3.375 days
 a: 3.25 days 	b: 3.25 days
 a: 3.125 days 	b: 3.125 days
 a: 3 days 	b: 3 days
 a: 2.875 days 	b: 2.875 days
 a: 2.75 days 	b: 2.75 days
 
 Demonstrating postfix -- operator.
 a: 2.75 days 	b: 2.625 days
 a: 2.625 days 	b: 2.5 days
 a: 2.5 days 	b: 2.375 days
 a: 2.375 days 	b: 2.25 days
 a: 2.25 days 	b: 2.125 days
 a: 2.125 days 	b: 2 days
 a: 2 days 	b: 1.875 days
 a: 1.875 days 	b: 1.75 days
 a: 1.75 days 	b: 1.625 days
 a: 1.625 days 	b: 1.5 days
 a: 1.5 days 	b: 1.375 days
 a: 1.375 days 	b: 1.25 days  
*/
