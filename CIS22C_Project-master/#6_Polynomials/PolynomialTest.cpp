//
//  PolynomialTest.cpp
//  Polynomials
//
//  Created by HOWON KIM on 1/31/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Polynomial.h"
using namespace std;

int main(int argc, const char * argv[]) {
 
    cout << fixed << setprecision(1);
    
    Polynomial temp1;
    Polynomial temp2;
    
    
    // ERROR LIST //
    temp1.print(); // print() : There is no data in the list
    temp1.evaluate(2.0); // evaluate(double value) : There is no data in the list
    temp2.print(); // // print() : There is no data in the list
    
    // EDGE CASE TEST //
    Polynomial add1 = temp1 + temp2;
    add1.print(); // print() : There is no data in the list

    temp1.insertTerm(0, 11);
    Polynomial add2;
    add2 = temp1 + temp2;
    add2.print(); //11.0x0
    
    Polynomial add3 = temp2 + temp1;
    add3.print(); // 11.0x0

    
    
    // TEST //
    
    cout << "Should be 11.0 : " << temp1.evaluate(2) << endl;
    
    Polynomial temp3;
    temp3.insertTerm(3, 3);
    temp3.insertTerm(2, 3);
    temp3.insertTerm(1, 3);
    temp3.insertTerm(0, 3);
    
    temp3.print(); // 3.0x3 + 3.0x2 + 3.0x1 + 3.0x0

    cout << "Should be 120.0 : " << temp3.evaluate(3) << endl;
    
    Polynomial add4 = temp3 + temp1;
    add4.print(); // 3.0x3 + 3.0x2 + 3.0x1 + 14.0x0

    cout << "Should be 131.0 : " << add4.evaluate(3) << endl << endl;
    
    
    
    // Given Test Code //
    
    Polynomial poly;
    poly.insertTerm(4, 3.5);
    poly.insertTerm(3, 2.1);
    poly.insertTerm(2, 6.5);
    poly.insertTerm(1, 5.5);
    poly.insertTerm(0, 1);
    cout << "Printing P1. \nShould be 3.5x4 + 2.1x3 + 6.5x2 + 5.5x1 + 1x0: \n";
    poly.print();
    cout << endl << endl;
    Polynomial poly2;
    poly2.insertTerm(2, 3.3);
    poly2.insertTerm(1, 9.0);
    poly2.insertTerm(0,3.4);
    cout << "Printing P2. \nShould be 3.3x2 + 9.0x1 + 3.4x0\n";
    poly2.print();
    cout << endl << endl;
    Polynomial p_add = poly + poly2;
    cout << "Printing P3 = P1 + P2. \nShould be 3.5x4 + 2.1x3 + 9.8x2 + 14.5x1 + 4.4x0\n";
    p_add.print();
    cout << endl << endl;
    Polynomial p4;
    p4.insertTerm(5, 2.3);
    p4.insertTerm(4, 0);
    p4.insertTerm(3, 8.9);
    p4.insertTerm(2, 6.5);
    p4.insertTerm(1, 1.6);
    p4.insertTerm(0, 9.6);
    cout << "Printing P4. \nShould be 2.3x5 + 0x4 + 8.9x3 + 6.5x2 + 1.6x1 +9.6x0\n";
    p4.print();
    cout << endl << endl;
    Polynomial p5;
    p5.insertTerm(3, 3.1);
    p5.insertTerm(2, 3.1);
    p5.insertTerm(1, 3.1);
    p5.insertTerm(0, 3.1);
    cout << "Printing P5. \nShould be 3.1x3 + 3.1x2 + 3.1x1 + 3.1x0\n";
    p5.print();
    cout << endl << endl;
    Polynomial p6 = p4 + p5;
    cout << "Printing P6 = P4 + P5. \nShould be 2.3x5 + 0x4 + 12.0x3 + 9.6x2 + 4.7x1 + 12.7x0\n";
    p6.print();
    cout << endl << endl;
    Polynomial p7(p5);
    cout << "Printing copy of P5. \nShould be 3.1x3 + 3.1x2 + 3.1x1 + 3.1x0\n";
    p7.print();
    cout << endl << endl;
    cout << "Evaluating p2 at 2.0. Should print 34.6: " << fixed << setprecision(1) << poly2.evaluate(2) << endl << endl;

    // Finish to Test the Given Code //
    
    

    // Multiplication Test

    cout << ">>Multiplication Test" << fixed << setprecision(2) << endl;

    Polynomial multi1 = poly * poly2;
    cout << "+Should be : 11.55x6 + 38.43x5 + 52.25x4 + 83.79x3 + 74.90x2 + 27.70x1 + 3.40x0" << endl;
    multi1.print();
    
    Polynomial multi2 = temp3 * add4;
    cout << "+Should be : 9.00x6 + 18.00x5 + 27.00x4 + 69.00x3 + 60.00x2 + 51.00x1 + 42.00x0" << endl;
    multi2.print();
    
    Polynomial mtemp1;
    Polynomial mtemp2;
    mtemp2.insertTerm(0, 5.5);
    
    mtemp1.insertTerm(1, 5);
    mtemp1.insertTerm(0, 3);
    
    Polynomial multi4 = mtemp2 * mtemp1;
    cout << "+Should be : 27.50x1 + 16.50x0" << endl;
    multi4.print();

    

}



/** OUTPUT
 
 print() : There is no data in the list
 evaluate(double value) : There is no data in the list
 print() : There is no data in the list
 print() : There is no data in the list
 11.0x0
 11.0x0
 Should be 11.0 : 11.0
 3.0x3 + 3.0x2 + 3.0x1 + 3.0x0
 Should be 120.0 : 120.0
 3.0x3 + 3.0x2 + 3.0x1 + 14.0x0
 Should be 131.0 : 131.0
 
 Printing P1.
 Should be 3.5x4 + 2.1x3 + 6.5x2 + 5.5x1 + 1x0:
 3.5x4 + 2.1x3 + 6.5x2 + 5.5x1 + 1.0x0
 
 
 Printing P2.
 Should be 3.3x2 + 9.0x1 + 3.4x0
 3.3x2 + 9.0x1 + 3.4x0
 
 
 Printing P3 = P1 + P2.
 Should be 3.5x4 + 2.1x3 + 9.8x2 + 14.5x1 + 4.4x0
 3.5x4 + 2.1x3 + 9.8x2 + 14.5x1 + 4.4x0
 
 
 Printing P4.
 Should be 2.3x5 + 0x4 + 8.9x3 + 6.5x2 + 1.6x1 +9.6x0
 2.3x5 + 0.0x4 + 8.9x3 + 6.5x2 + 1.6x1 + 9.6x0
 
 
 Printing P5.
 Should be 3.1x3 + 3.1x2 + 3.1x1 + 3.1x0
 3.1x3 + 3.1x2 + 3.1x1 + 3.1x0
 
 
 Printing P6 = P4 + P5.
 Should be 2.3x5 + 0x4 + 12.0x3 + 9.6x2 + 4.7x1 + 12.7x0
 2.3x5 + 0.0x4 + 12.0x3 + 9.6x2 + 4.7x1 + 12.7x0
 
 
 Printing copy of P5.
 Should be 3.1x3 + 3.1x2 + 3.1x1 + 3.1x0
 3.1x3 + 3.1x2 + 3.1x1 + 3.1x0
 
 
 Evaluating p2 at 2.0. Should print 34.6: 34.6
 
 >>Multiplication Test
 +Should be : 11.55x6 + 38.43x5 + 52.25x4 + 83.79x3 + 74.90x2 + 27.70x1 + 3.40x0
 11.55x6 + 38.43x5 + 52.25x4 + 83.79x3 + 74.90x2 + 27.70x1 + 3.40x0
 +Should be : 9.00x6 + 18.00x5 + 27.00x4 + 69.00x3 + 60.00x2 + 51.00x1 + 42.00x0
 9.00x6 + 18.00x5 + 27.00x4 + 69.00x3 + 60.00x2 + 51.00x1 + 42.00x0
 +Should be : 27.50x1 + 16.50x0
 27.50x1 + 16.50x0
 Program ended with exit code: 0
 
 **/