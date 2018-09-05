//
//  Polynomial.h
//  Polynomials
//
//  Created by HOWON KIM on 1/31/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include "List.h"
#include "Term.h"
#include <iostream>
#include <cstddef> //for NULL
using namespace std;

class Polynomial
{
private:
    List<Term> poly;
    
    
public:
    /**Constructors and Destructors*/
    
    Polynomial();
    //Default constructor; initializes an empty Polynomial
    
    ~Polynomial();
    //Destructor. Frees memory allocated to the list
    
    Polynomial(const Polynomial &polynomial);
    //Copy constructor. Initializes the Polynomial to have the same elements as another Polynomial
    
    
    /**Manipulation Procedures*/
    
    void insertTerm(int exponent, double coefficient);
    //inserts a single term into the polynomial
    
    /**Additional Operations*/
    
    double evaluateTerm(Term t, double value);
    //A helper function for evaluate.
    //Evaluates a single term in the Polynomial by plugging in the value
    //For example: If the term is 3.0x2 and the value is 5.0
    //This function will return 75.0 since 3.0*5.0*5.0=75.0
    
    double evaluate(double value);
    //Evaluates the Polynomial by plugging in the value at all terms
    //If the Polynomial is empty, returns 0.0.
    //Calls the evaluateTerm function on each term in the Polynomial
    
    Polynomial operator + (const Polynomial& p);
    //Adds existing Polynomial to p, returning the result
    
    Polynomial operator * (const Polynomial& p);
    //Multiplies existing Polynomial by p, returning the resulting Polynomial
    //Worth 15 points extra credit
    
    void print();
    //Prints the Polynomial to the console in the form of
    //<coefficient1>x<exponent1> + <coefficient2>x<exponenent2> + ...
    //For example: 2.5x4 + 3x3 + 0x2 + 8.1x1 +7.5x0
    
    Polynomial derivative();

};

#endif /* POLYNOMIAL_H_ */