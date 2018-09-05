//
//  Polynomial.cpp
//  Polynomials
//
//  Created by HOWON KIM on 1/31/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include "Polynomial.h"
#include <iostream>
using namespace std;


/**Constructors and Destructors*/
//Default constructor; initializes an empty Polynomial
Polynomial::Polynomial(){}


//Destructor. Frees memory allocated to the list
Polynomial::~Polynomial(){}

//Polynomial::Polynomial(const Polynomial &polynomial);
//Copy constructor. Initializes the Polynomial to have the same elements as another Polynomial
Polynomial::Polynomial(const Polynomial &polynomial):poly(polynomial.poly){}



/*---------------------------------------------------------------------
 A helper function for evaluate.
 Evaluates a single term in the Polynomial by plugging in the value
 For example: If the term is 3.0x2 and the value is 5.0
 This function will return 75.0 since 3.0*5.0*5.0=75.0
 --------------------------------------------------------------------*/
double Polynomial::evaluateTerm(Term t, double value){
    
    double temp = 1.0;
    
    for(int i=1; i<=t.getExponent(); ++i)
        temp *= value;

    temp *= t.getCoefficient();
    
    return temp;
    
}




/*---------------------------------------------------------------------
 Evaluates the Polynomial by plugging in the value at all terms
 If the Polynomial is empty, returns 0.0.
 Calls the evaluateTerm function on each term in the Polynomial
 --------------------------------------------------------------------*/
double Polynomial::evaluate(double value){
    
    if(poly.is_empty())
    {
        cout << "evaluate(double value) : There is no data in the list" << endl;
        return 0;
    }
    else
    {
        double result = 0.0;
        for(int i =1 ; i<=poly.get_size(); ++i)
        {
            poly.scrollToIndex(i);
            result += evaluateTerm(poly.get_current(), value);
        }
        
        return result;
    }
}




/*---------------------------------------------------------------------
 inserts a single term into the polynomial
 --------------------------------------------------------------------*/

void Polynomial::insertTerm(int exponent, double coefficient){
    poly.insert_last(Term(coefficient,exponent));
}




/*---------------------------------------------------------------------
 Adds existing Polynomial to p, returning the result
 --------------------------------------------------------------------*/

Polynomial Polynomial::operator + (const Polynomial& p){
    
    
    Polynomial result = *new Polynomial;
    Polynomial temp1 = *this;
    Polynomial temp2 = p;
    
    
    if(temp1.poly.get_size() == -1)
        return Polynomial(temp2);
    else if(temp2.poly.get_size() == -1)
        return Polynomial(temp1);
    else if(temp1.poly.get_size() == -1 && temp2.poly.get_size() == -1)
        return Polynomial(result);
    else
    {
        if(temp1.poly.get_size() > temp2.poly.get_size())
        {
            for(int i =1; i<= temp1.poly.get_size(); i++)
            {
                temp1.poly.scrollToIndex(i);
                
                if(temp1.poly.get_current().getExponent() == temp2.poly.get_first().getExponent())
                {
                    for(int j =1; j <= temp2.poly.get_size(); j++)
                    {
                        temp2.poly.scrollToIndex(j);
                        result.insertTerm(temp2.poly.get_current().getExponent(), temp1.poly.get_current().getCoefficient() + temp2.poly.get_current().getCoefficient());
                        
                        
                        
                        if(j == temp2.poly.get_size())
                            return Polynomial(result);
                        
                        temp1.poly.scrollToIndex(++i);
                        
                        
                    }
                }
                result.insertTerm(temp1.poly.get_current().getExponent(), temp1.poly.get_current().getCoefficient());
            }
        }
        else if(temp1.poly.get_size() < temp2.poly.get_size())
        {
            for(int i=1; i<= temp2.poly.get_size(); i++)
            {
                temp2.poly.scrollToIndex(i);
                
                if(temp2.poly.get_current().getExponent() == temp1.poly.get_first().getExponent())
                {
                    for(int j=1; i<= temp1.poly.get_size(); j++)
                    {
                        temp1.poly.scrollToIndex(j);
                        result.insertTerm(temp1.poly.get_current().getExponent(), temp1.poly.get_current().getCoefficient() + temp2.poly.get_current().getCoefficient());
                        
                        if(j == temp1.poly.get_size())
                            return Polynomial(result);
                        
                        temp2.poly.scrollToIndex(++i);
                        
                    }
                }
                result.insertTerm(temp2.poly.get_current().getExponent(), temp2.poly.get_current().getCoefficient());
                
            }
        }
        else
        {
            for(int i = 1; i<= temp1.poly.get_size(); i++)
            {
                temp1.poly.scrollToIndex(i);
                temp2.poly.scrollToIndex(i);
                
                result.insertTerm(temp1.poly.get_current().getExponent(), temp1.poly.get_current().getCoefficient() + temp2.poly.get_current().getCoefficient());
            }
            
            return Polynomial(result);
        }
    }
    
    return Polynomial(result);
}


/*---------------------------------------------------------------------
 Multiplies existing Polynomial by p, returning the resulting Polynomial

 --------------------------------------------------------------------*/
Polynomial Polynomial::operator * (const Polynomial& p)
{
    
    Polynomial result = *new Polynomial;
    
    Polynomial temp1 = *this;
    Polynomial temp2 = p;
    
    int size = temp1.poly.get_first().getExponent() + temp2.poly.get_first().getExponent();
    
    double multi[size+1];
    
    // Array Initialize
    for(int a = 0; a<=size; a++)
        multi[a] = 0.0;
    
    
    for(int i = 1; i<=temp1.poly.get_size(); i++)
    {
        temp1.poly.scrollToIndex(i);
        
        for(int j = 1; j<=temp2.poly.get_size(); j++)
        {
            temp2.poly.scrollToIndex(j);
            
            multi[(temp1.poly.get_current().getExponent() + temp2.poly.get_current().getExponent())] += (temp1.poly.get_current().getCoefficient() * temp2.poly.get_current().getCoefficient());
        }
    }
    
    for(int k = 0; k<=size; k++)
        result.poly.insert_first(Term(multi[k], k));

 
    return Polynomial(result);
        
}


/*---------------------------------------------------------------------
 Prints the Polynomial to the console in the form of
 <coefficient1>x<exponent1> + <coefficient2>x<exponenent2> + ...
 For example: 2.5x4 + 3x3 + 0x2 + 8.1x1 +7.5x0
 --------------------------------------------------------------------*/

void Polynomial::print(){


    List<Term> temp = poly;

    if(temp.is_empty())
    {
        cout << "print() : There is no data in the list" << endl;
        return;
    }
    
    else
    {
        for (int i=1; i<=temp.get_size(); ++i)
        {
            temp.scrollToIndex(i);
            
            if(i==temp.get_size())
            {
                cout << temp.get_current().getCoefficient() << "x"
                << temp.get_current().getExponent();
            }
            else
            {
                cout << temp.get_current().getCoefficient() << "x"
                << temp.get_current().getExponent() << " + ";
            }
            
        }
    }
    cout << endl;

}
