/********************************************************************
 *** NAME : Xiaozhu Jin                                           ***
 *** CLASS : CSc 346                                              ***
 *** ASSIGNMENT : 4                                               ***
 *** DUE DATE : 03/28/2017                                        ***
 *** INSTRUCTOR : GAMRADT                                         ***
 ********************************************************************
 *** DESCRIPTION : This program will do the following tasks:      ***
 ***               1. Allow user to performe mathematical         ***
 ***                  operations in fractions                     ***
 ***               2. Allow user to increment/decrement the       ***
 ***                  fraction                                    ***
 ***               3. Allow user to invert the fraction           ***
 ***               4. Allow user to get get gcd of fraction       ***
 ***               4. Display implemented fraction to the screen  ***
 ********************************************************************/

#include <iostream>
#include "Fraction.h"
namespace FractionNS {
/********************************************************************
 *** FUNCTION Fraction                                            ***
 ********************************************************************
 *** DESCRIPTION : used to create default/overloaded constructor  ***
 *** INPUT ARGS  : numerator, denominator                         ***
 *** OUTPUT ARGS : numerator, denominator                         ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction::Fraction( const int newNumerator, const unsigned newDenominator) {
    setNumerator(newNumerator);
    if(newDenominator != 0) {
        setDenominator(newDenominator);
    }else {
        std::cout << "Invalid Fraction. Denomnator will be set to default(1)" << std::endl;
        setDenominator(1);
    }
    
}
    
/********************************************************************
 *** FUNCTION Fraction                                            ***
 ********************************************************************
 *** DESCRIPTION : used to create copy constructor                ***
 *** INPUT ARGS  : copiedFraction                                 ***
 *** OUTPUT ARGS : Fraction                                       ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction::Fraction( const Fraction &copiedFraction ) {
    setNumerator(copiedFraction.getNumerator());
    setDenominator(copiedFraction.getDenominator());
}
    
/********************************************************************
 *** FUNCTION ~Fraction                                           ***
 ********************************************************************
 *** DESCRIPTION : used to create destructor                      ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction::~Fraction() {
    
}
    
/********************************************************************
 *** FUNCTION copy                                                ***
 ********************************************************************
 *** DESCRIPTION : used to copy contents from anouter fraction    ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Fraction::copy( const Fraction &rightFraction ) {
    setNumerator(rightFraction.getNumerator());
    setDenominator(rightFraction.getDenominator());
    return *this;
}

/********************************************************************
 *** FUNCTION add                                                 ***
 ********************************************************************
 *** DESCRIPTION : used to add fraction to anouter fraction       ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Fraction::add( const Fraction &rightFraction ) {
    setNumerator(getNumerator() * rightFraction.getDenominator() + rightFraction.getNumerator() * getDenominator());
    setDenominator(getDenominator() * rightFraction.getDenominator());
    reduce();
    return *this;
}

/********************************************************************
 *** FUNCTION multiply                                            ***
 ********************************************************************
 *** DESCRIPTION : used to multiply fraction to anouter fraction  ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Fraction::multiply( const Fraction &rightFraction ) {
    setNumerator(getNumerator() * rightFraction.getNumerator());
    setDenominator(getDenominator() * rightFraction.getDenominator());
    reduce();
    return *this;
}

/********************************************************************
 *** FUNCTION increment                                           ***
 ********************************************************************
 *** DESCRIPTION : used to add 1 to the fraction                  ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Fraction::increment() {
    Fraction temp(1,1);
    add(temp);
    return *this;
}
 
/********************************************************************
 *** FUNCTION negate                                              ***
 ********************************************************************
 *** DESCRIPTION : used to negate the invoking fraction           ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Fraction::negate() {
    setNumerator( -getNumerator() );
    return *this;
}

/********************************************************************
 *** FUNCTION compare                                             ***
 ********************************************************************
 *** DESCRIPTION : used to compare with invoking fraction         ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
int Fraction::compare(const Fraction &rightFraction) {
    int result;
    if(toFloat() < rightFraction.toFloat()) {
        result = -1;
    } else if (toFloat() > rightFraction.toFloat()) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/********************************************************************
 *** FUNCTION toInt                                               ***
 ********************************************************************
 *** DESCRIPTION : used to convert the fraction to integer        ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
int Fraction::toInt() const{
    return getNumerator()/static_cast<int>(getDenominator());
}

/********************************************************************
 *** FUNCTION toFloat                                             ***
 ********************************************************************
 *** DESCRIPTION : used to convert the fraction to float          ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
float Fraction::toFloat() const{
    return getNumerator()/static_cast<float>(getDenominator());
}

/********************************************************************
 *** FUNCTION reduce                                              ***
 ********************************************************************
 *** DESCRIPTION : used to simplify the fraction                  ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
void Fraction::reduce() {
    int gcdReduce;
    gcdReduce = gcd(getNumerator(), getDenominator());
    setNumerator(getNumerator() / gcdReduce);
    setDenominator(getDenominator() / gcdReduce);
}

/********************************************************************
 *** FUNCTION gcd                                                 ***
 ********************************************************************
 *** DESCRIPTION : used to get gcd of numerator and denominator   ***
 *** INPUT ARGS  : first, second                                  ***
 *** OUTPUT ARGS : temp1                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
unsigned int Fraction::gcd(const unsigned int first, const unsigned int second) {
    int temp1 = first, temp2 = second;
    int swaptemp = 0;
    if(temp1 < 0) {
        temp1 = temp1 * -1;
    }
    if(temp1 < temp2) {
        swaptemp = temp1;
        temp1 = temp2;
        temp2 = swaptemp;
    }
    while(temp2 > 0) {
        swaptemp = temp1 % temp2;
        temp1 = temp2;
        temp2 = swaptemp;
    }
    return temp1;
}

/********************************************************************
 *** FUNCTION view                                                ***
 ********************************************************************
 *** DESCRIPTION : used to disaply the fraction to screen         ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
void Fraction::view() const{
    Fraction temp(getNumerator(), getDenominator());
        
    if(temp.getNumerator() < 0)
    {
        temp.negate();
        std::cout << "-" << temp.getNumerator() / temp.getDenominator()
                  << " " << temp.getNumerator() % temp.getDenominator()
                  << "/" << temp.getDenominator() << std::endl;
    }
    else
    {
        std::cout << temp.getNumerator() / temp.getDenominator()
                  << " " << temp.getNumerator() % temp.getDenominator()
                  << "/" << temp.getDenominator() << std::endl;
    }
    
}
}