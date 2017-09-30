/********************************************************************
 *** NAME : Xiaozhu Jin                                           ***
 *** CLASS : CSc 346                                              ***
 *** ASSIGNMENT : 5                                               ***
 *** DUE DATE : 04/10/2017                                        ***
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
 *** FUNCTION operatpr=                                           ***
 ********************************************************************
 *** DESCRIPTION : used to copy contents from anouter fraction    ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Fraction::operator=(const Fraction &rightFraction){
    if(this != &rightFraction) {
        setNumerator(rightFraction.getNumerator());
        setDenominator(rightFraction.getDenominator());
    }
    return *this;
}
    
/********************************************************************
 *** FUNCTION operator+                                           ***
 ********************************************************************
 *** DESCRIPTION : used to add fraction to anouter fraction       ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction Fraction::operator+(const Fraction &rightFraction){
    Fraction temp;
    temp.setNumerator(getNumerator() * rightFraction.getDenominator() + rightFraction.getNumerator() * getDenominator());
    temp.setDenominator(getDenominator() * rightFraction.getDenominator());
    return temp;
}
    
/********************************************************************
 *** FUNCTION operator*                                           ***
 ********************************************************************
 *** DESCRIPTION : used to multiply fraction to anouter fraction  ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Fraction::operator*( const Fraction &rightFraction ) {
    setNumerator(getNumerator() * rightFraction.getNumerator());
    setDenominator(getDenominator() * rightFraction.getDenominator());
    reduce();
    return *this;
}
    
/********************************************************************
 *** FUNCTION operator++                                          ***
 ********************************************************************
 *** DESCRIPTION : used to add 1 to the fraction                  ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Fraction::operator++() {
    setNumerator(getNumerator() + getDenominator());
    return *this;
}
    
/********************************************************************
 *** FUNCTION operator++                                          ***
 ********************************************************************
 *** DESCRIPTION : used to add 1 to the fraction                  ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction Fraction::operator++( const int ) {
    Fraction temp(*this);
    ++(*this);
    return temp;
}

/********************************************************************
 *** FUNCTION operator-                                           ***
 ********************************************************************
 *** DESCRIPTION : used to negate the invoking fraction           ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction Fraction::operator-() {
    Fraction temp(*this);
    temp.setNumerator(-getNumerator());
    return temp;
}
    
/********************************************************************
 *** FUNCTION operator int                                        ***
 ********************************************************************
 *** DESCRIPTION : used to convert the fraction to integer        ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction::operator int() const {
    return (getNumerator()/static_cast<int>(getDenominator()));
}
    
/********************************************************************
 *** FUNCTION operator float                                      ***
 ********************************************************************
 *** DESCRIPTION : used to convert the fraction to float          ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction::operator float() const{
    return (getNumerator()/static_cast<float>(getDenominator()));
}
    
/********************************************************************
 *** FUNCTION operator bool                                       ***
 ********************************************************************
 *** DESCRIPTION : used to convert the fraction to bool           ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : *this                                          ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction::operator bool() const{
    bool test;
    if(getNumerator() == 0) {
        test = false;
        } else {
            test = true;
        }
    return test;
}

/********************************************************************
 *** FUNCTION operator-                                            ***
 ********************************************************************
 *** DESCRIPTION : used to subtract fraction from anouter fraction***
 *** INPUT ARGS  : leftFraction, rightFraction                    ***
 *** OUTPUT ARGS : leftFraction                                   ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction operator-(const Fraction &leftFraction, const Fraction &rightFraction) {
    Fraction temp(rightFraction);
    temp = -temp;
    temp = temp + leftFraction;
    return temp;
}

/********************************************************************
 *** FUNCTION operator/                                           ***
 ********************************************************************
 *** DESCRIPTION : used to divide fraction from anouter fraction  ***
 *** INPUT ARGS  : leftFraction, rightFraction                    ***
 *** OUTPUT ARGS : leftFraction                                   ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction operator/( const Fraction &leftFraction, const Fraction &rightFraction ) {
    Fraction temp(rightFraction);
    temp = !temp;
    temp = temp * leftFraction;
    return temp;
}
    
/********************************************************************
 *** FUNCTION decrement                                           ***
 ********************************************************************
 *** DESCRIPTION : used to subtract fraction by 1                 ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : rightFraction                                  ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & operator--(Fraction &rightFraction) {
    Fraction temp(-1,1);
    rightFraction = temp + rightFraction;
    return rightFraction;
}

/********************************************************************
 *** FUNCTION decrement                                           ***
 ********************************************************************
 *** DESCRIPTION : used to subtract fraction by 1                 ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : rightFraction                                  ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction  operator--(Fraction &leftFraction, const int ) {
    Fraction temp(leftFraction);
    --temp;
    return temp;
}
    
/********************************************************************
 *** FUNCTION operator!                                           ***
 ********************************************************************
 *** DESCRIPTION : used to invert the fraction                    ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : rightFraction                                  ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction operator!(Fraction &rightFraction) {
    Fraction temp(rightFraction);
    if(!bool(temp)) {
        temp(rightFraction.getDenominator(), rightFraction.getNumerator());
    } else {
        std::cout << "Cannot invert the fraction since the numerator is 0" << std::endl;
    }
    return temp;
}
    
/********************************************************************
 *** FUNCTION operator==                                          ***
 ********************************************************************
 *** DESCRIPTION : used to test whether two fraction are equal    ***
 *** INPUT ARGS  : leftFraction, rightFraction                    ***
 *** OUTPUT ARGS : true/false                                     ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
bool operator==(const Fraction &leftFraction, const Fraction &rightFraction) {
    bool test;
    if(float(leftFraction) == float(rightFraction)) {
        test = true;
    } else {
        test = false;
    }
    return test;
}
    
/********************************************************************
 *** FUNCTION operator<                                           ***
 ********************************************************************
 *** DESCRIPTION : used to test whether left fraction are less    ***
 ***               than the right fraction                        ***
 *** INPUT ARGS  : leftFraction, rightFraction                    ***
 *** OUTPUT ARGS : true/false                                     ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
bool operator<(const Fraction &leftFraction, const Fraction &rightFraction) {
    bool test;
    if(float(leftFraction) < float(rightFraction)) {
        test = true;
    } else {
        test = false;
    }
    return test;
}
    
/********************************************************************
 *** FUNCTION operator>                                           ***
 ********************************************************************
 *** DESCRIPTION : used to test whether left fraction are larger  ***
 ***               than the right fraction                        ***
 *** INPUT ARGS  : leftFraction, rightFraction                    ***
 *** OUTPUT ARGS : true/false                                     ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
bool operator>(const Fraction &leftFraction, const Fraction &rightFraction) {
    bool test;
    if(float(leftFraction) < float(rightFraction)) {
        test = true;
    } else {
        test = false;
    }
    return test;
}

/********************************************************************
 *** FUNCTION operator<<                                          ***
 ********************************************************************
 *** DESCRIPTION : used to display the fraction                   ***
 *** INPUT ARGS  : sout, rightFraction                            ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
std::ostream & operator<<(std::ostream &sout, const Fraction &rightFraction) {
    Fraction temp(rightFraction.getNumerator(), rightFraction.getDenominator());
    if(temp.getNumerator() < 0)
    {
        temp = -temp;
        return sout << "-" << temp.getNumerator() / temp.getDenominator()
                    << " " << temp.getNumerator() % temp.getDenominator()
                    << "/" << temp.getDenominator() << std::endl;
    }
    else
    {
        return sout << temp.getNumerator() / temp.getDenominator()
                    << " " << temp.getNumerator() % temp.getDenominator()
                    << "/" << temp.getDenominator() << std::endl;
    }

}
    
/********************************************************************
 *** FUNCTION operator>>                                          ***
 ********************************************************************
 *** DESCRIPTION : used to read numerator and denominator         ***
 *** INPUT ARGS  : sin, rightFraction                             ***
 *** OUTPUT ARGS : sin                                            ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
std::istream & operator>>(std::istream &sin, Fraction &rightFraction) {
    sin >> rightFraction.numerator >> rightFraction.denominator;
    return sin;
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
    
}