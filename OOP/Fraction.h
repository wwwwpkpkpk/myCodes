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

#ifndef FRACTION_H
#define FRACTION_H

namespace FractionNS
{
class Fraction{
    public:
    /********************************************************************
     *** FUNCTION Fraction                                            ***
     ********************************************************************
     *** DESCRIPTION : used to create default/overloaded constructor  ***
     *** INPUT ARGS  : numerator, denominator                         ***
     *** OUTPUT ARGS : numerator, denominator                         ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        Fraction(const int = 0, const unsigned int = 1);
    /********************************************************************
     *** FUNCTION Fraction                                            ***
     ********************************************************************
     *** DESCRIPTION : used to create copy constructor                ***
     *** INPUT ARGS  : copiedFraction                                 ***
     *** OUTPUT ARGS : Fraction                                       ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        Fraction(const Fraction & );
    /********************************************************************
     *** FUNCTION ~Fraction                                           ***
     ********************************************************************
     *** DESCRIPTION : used to create destructor                      ***
     *** INPUT ARGS  : none                                           ***
     *** OUTPUT ARGS : none                                           ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        ~Fraction();
    /********************************************************************
     *** FUNCTION getNumerator                                        ***
     ********************************************************************
     *** DESCRIPTION : used to get numerator value for fraction       ***
     *** INPUT ARGS  : none                                           ***
     *** OUTPUT ARGS : none                                           ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        inline int getNumerator() const;
    /********************************************************************
     *** FUNCTION setNumerator                                        ***
     ********************************************************************
     *** DESCRIPTION : used to set numerator value for fraction       ***
     *** INPUT ARGS  : newNumerator                                   ***
     *** OUTPUT ARGS : numerator                                      ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        inline void setNumerator( const int newNumerator = 0 );
    /********************************************************************
     *** FUNCTION getDenominator                                      ***
     ********************************************************************
     *** DESCRIPTION : used to get denominator value for fraction     ***
     *** INPUT ARGS  : none                                           ***
     *** OUTPUT ARGS : none                                           ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        inline unsigned int getDenominator() const;
    /********************************************************************
     *** FUNCTION setDenominator                                      ***
     ********************************************************************
     *** DESCRIPTION : used to set denominator value for fraction     ***
     *** INPUT ARGS  : newDenominator                                 ***
     *** OUTPUT ARGS : denominator                                    ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        inline void setDenominator( const unsigned int newDenominator  = 1 );
    /********************************************************************
     *** FUNCTION copy                                                ***
     ********************************************************************
     *** DESCRIPTION : used to copy contents from anouter fraction    ***
     *** INPUT ARGS  : rightFraction                                  ***
     *** OUTPUT ARGS : *this                                          ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        Fraction & copy( const Fraction &rightFraction );
    /********************************************************************
     *** FUNCTION add                                                 ***
     ********************************************************************
     *** DESCRIPTION : used to add fraction to anouter fraction       ***
     *** INPUT ARGS  : rightFraction                                  ***
     *** OUTPUT ARGS : *this                                          ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        Fraction & add( const Fraction &rightFraction );
    /********************************************************************
     *** FUNCTION multiply                                            ***
     ********************************************************************
     *** DESCRIPTION : used to multiply fraction to anouter fraction  ***
     *** INPUT ARGS  : rightFraction                                  ***
     *** OUTPUT ARGS : *this                                          ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        Fraction & multiply( const Fraction &rightFraction );
    /********************************************************************
     *** FUNCTION increment                                           ***
     ********************************************************************
     *** DESCRIPTION : used to add 1 to the fraction                  ***
     *** INPUT ARGS  : none                                           ***
     *** OUTPUT ARGS : *this                                          ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        Fraction & increment();
    /********************************************************************
     *** FUNCTION negate                                              ***
     ********************************************************************
     *** DESCRIPTION : used to negate the invoking fraction           ***
     *** INPUT ARGS  : none                                           ***
     *** OUTPUT ARGS : *this                                          ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        Fraction & negate();
    /********************************************************************
     *** FUNCTION compare                                             ***
     ********************************************************************
     *** DESCRIPTION : used to compare with invoking fraction         ***
     *** INPUT ARGS  : rightFraction                                  ***
     *** OUTPUT ARGS : *this                                          ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        int compare( const Fraction &rightFraction );
    /********************************************************************
     *** FUNCTION toInt                                               ***
     ********************************************************************
     *** DESCRIPTION : used to convert the fraction to integer        ***
     *** INPUT ARGS  : none                                           ***
     *** OUTPUT ARGS : *this                                          ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        int toInt() const;
    /********************************************************************
     *** FUNCTION toFloat                                             ***
     ********************************************************************
     *** DESCRIPTION : used to convert the fraction to float          ***
     *** INPUT ARGS  : none                                           ***
     *** OUTPUT ARGS : *this                                          ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        float toFloat() const;
    /********************************************************************
     *** FUNCTION view                                                ***
     ********************************************************************
     *** DESCRIPTION : used to disaply the fraction to screen         ***
     *** INPUT ARGS  : none                                           ***
     *** OUTPUT ARGS : none                                           ***
     *** IN/OUT ARGS : none                                           ***
     *** RETURN      : none                                           ***
     ********************************************************************/
        void view() const;
    
    private:
        int numerator;
        unsigned int denominator;
        void reduce();
        unsigned int gcd( const unsigned int first, const unsigned int second );
};

/********************************************************************
 *** FUNCTION getNumerator                                        ***
 ********************************************************************
 *** DESCRIPTION : used to get numerator value for fraction       ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
inline int Fraction::getNumerator() const {
    return numerator;
}

/********************************************************************
 *** FUNCTION setNumerator                                        ***
 ********************************************************************
 *** DESCRIPTION : used to set numerator value for fraction       ***
 *** INPUT ARGS  : newNumerator                                   ***
 *** OUTPUT ARGS : numerator                                      ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
/*inline*/ void Fraction::setNumerator( int newNumerator ) {
    numerator = newNumerator;
    return;
}

/********************************************************************
 *** FUNCTION getDenominator                                      ***
 ********************************************************************
 *** DESCRIPTION : used to get denominator value for fraction     ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
inline unsigned int Fraction::getDenominator() const {
    return denominator;
}

/********************************************************************
 *** FUNCTION setDenominator                                      ***
 ********************************************************************
 *** DESCRIPTION : used to set denominator value for fraction     ***
 *** INPUT ARGS  : newDenominator                                 ***
 *** OUTPUT ARGS : denominator                                    ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
/*inline*/ void Fraction::setDenominator( unsigned int newDenominator ) {
    if(newDenominator != 0) {
        denominator = newDenominator;
    } else {
        std::cout << "The denominator cannot be 0" << std::endl;
    }
    
    return;
}
    
}
#endif /* Fraction_h */
