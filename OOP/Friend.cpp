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
#include "Friend.h"

namespace FractionNS
{
/********************************************************************
 *** FUNCTION Friend                                              ***
 ********************************************************************
 *** DESCRIPTION : used to create default/overloaded constructor  ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Friend::Friend() {
    return;
}
    
/********************************************************************
 *** FUNCTION Friend                                              ***
 ********************************************************************
 *** DESCRIPTION : used to create copy constructor                ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Friend::Friend( const Friend &copiedFriend){
    return;
}

/********************************************************************
 *** FUNCTION ~Friend                                             ***
 ********************************************************************
 *** DESCRIPTION : used to create destructor                      ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Friend::~Friend() {
    return;
}

/********************************************************************
 *** FUNCTION subtract                                            ***
 ********************************************************************
 *** DESCRIPTION : used to subtract fraction from anouter fraction***
 *** INPUT ARGS  : leftFraction, rightFraction                    ***
 *** OUTPUT ARGS : leftFraction                                   ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Friend::subtract( Fraction &leftFraction, const Fraction &rightFraction ) {
    Fraction temp(rightFraction.getNumerator(), rightFraction.getDenominator());
    temp.negate();
    leftFraction.add(temp);
    return leftFraction;
}

/********************************************************************
 *** FUNCTION divied                                              ***
 ********************************************************************
 *** DESCRIPTION : used to divide fraction from anouter fraction  ***
 *** INPUT ARGS  : leftFraction, rightFraction                    ***
 *** OUTPUT ARGS : leftFraction                                   ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Friend::divide( Fraction &leftFraction, const Fraction &rightFraction ) {
    if(leftFraction.getDenominator() != 0 && rightFraction.getDenominator() != 0) {
        Fraction temp(rightFraction.getNumerator(), rightFraction.getDenominator());
        Friend::invert(temp);
        leftFraction.multiply(temp);
    } else {
        std::cout<< "Error. One of the denominators is 0. divide operation is failed" << std::endl;
    }
    return leftFraction;
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
Fraction & Friend::decrement( Fraction &rightFraction ) {
    Fraction temp(-1,1);
    rightFraction.add(temp);
    return rightFraction;
}

/********************************************************************
 *** FUNCTION invert                                              ***
 ********************************************************************
 *** DESCRIPTION : used to invert the fraction                    ***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : rightFraction                                  ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Fraction & Friend::invert( Fraction &rightFraction ) {
    Fraction temp;
    if(rightFraction.getNumerator() != 0) {
        temp.setNumerator(rightFraction.getNumerator());
        temp.setDenominator(rightFraction.getDenominator());
        if(temp.getNumerator() < 0) {
            temp.negate();
            rightFraction.setNumerator(temp.getDenominator());
            rightFraction.setDenominator(temp.getNumerator());
            rightFraction.negate();
        } else {
            rightFraction.setNumerator(temp.getDenominator());
            rightFraction.setDenominator(temp.getNumerator());
        }
    } else {
        std::cout << "Cannot invert the fraction since the numerator is 0" << std::endl;
    }
    return rightFraction;
}

/********************************************************************
 *** FUNCTION toBool                                              ***
 ********************************************************************
 *** DESCRIPTION : used to converts the passed in fraction to bool***
 *** INPUT ARGS  : rightFraction                                  ***
 *** OUTPUT ARGS : rightFraction                                  ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
bool Friend::toBool( const Fraction &rightFraction ) {
    bool isValid;
    if(rightFraction.getNumerator() == 0){
        isValid = false;
    } else {
        isValid = true;
    }
    return isValid;
}
    
}