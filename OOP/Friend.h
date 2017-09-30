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

#ifndef FRIEND_H
#define FRIEND_H

#include "Fraction.h"

namespace FractionNS
{

class Friend {
    public:
    /********************************************************************
     *** FUNCTION ~Friend                                             ***
     ********************************************************************
     *** DESCRIPTION : used to create destructor                      ***
     *** INPUT ARGS  : none                                           ***
     *** OUTPUT ARGS : none                                           ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        ~Friend();
    /********************************************************************
     *** FUNCTION subtract                                            ***
     ********************************************************************
     *** DESCRIPTION : used to subtract fraction from anouter fraction***
     *** INPUT ARGS  : leftFraction, rightFraction                    ***
     *** OUTPUT ARGS : leftFraction                                   ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        static Fraction & subtract(Fraction &leftFraction, const Fraction &rightFraction);
    /********************************************************************
     *** FUNCTION divied                                              ***
     ********************************************************************
     *** DESCRIPTION : used to divide fraction from anouter fraction  ***
     *** INPUT ARGS  : leftFraction, rightFraction                    ***
     *** OUTPUT ARGS : leftFraction                                   ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        static Fraction & divide(Fraction &leftFraction, const Fraction &rightFraction);
    /********************************************************************
     *** FUNCTION decrement                                           ***
     ********************************************************************
     *** DESCRIPTION : used to subtract fraction by 1                 ***
     *** INPUT ARGS  : rightFraction                                  ***
     *** OUTPUT ARGS : rightFraction                                  ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        static Fraction & decrement(Fraction &rightFraction);
    /********************************************************************
     *** FUNCTION invert                                              ***
     ********************************************************************
     *** DESCRIPTION : used to invert the fraction                    ***
     *** INPUT ARGS  : rightFraction                                  ***
     *** OUTPUT ARGS : rightFraction                                  ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        static Fraction & invert(Fraction &rightFraction);
    /********************************************************************
     *** FUNCTION toBool                                              ***
     ********************************************************************
     *** DESCRIPTION : used to converts the passed in fraction to bool***
     *** INPUT ARGS  : rightFraction                                  ***
     *** OUTPUT ARGS : rightFraction                                  ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        static bool toBool(const Fraction &rightFraction);
    
    private:

        Friend();
        Friend( const Friend &copiedFriend );
};
    
}


#endif /* Friend_h */
