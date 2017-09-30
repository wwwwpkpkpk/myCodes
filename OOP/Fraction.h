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

#ifndef FRACTION_H
#define FRACTION_H

namespace FractionNS
{
class Fraction{
        /********************************************************************
         *** FUNCTION operator-                                           ***
         ********************************************************************
         *** DESCRIPTION : used to subtract fraction from anouter fraction***
         *** INPUT ARGS  : leftFraction, rightFraction                    ***
         *** OUTPUT ARGS : leftFraction                                   ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        friend Fraction operator-(const Fraction &, const Fraction &);
        /********************************************************************
         *** FUNCTION operator/                                           ***
         ********************************************************************
         *** DESCRIPTION : used to divide fraction from anouter fraction  ***
         *** INPUT ARGS  : leftFraction, rightFraction                    ***
         *** OUTPUT ARGS : leftFraction                                   ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        friend Fraction operator/( const Fraction &, const Fraction &);
        /********************************************************************
         *** FUNCTION operator--                                          ***
         ********************************************************************
         *** DESCRIPTION : used to subtract fraction by 1                 ***
         *** INPUT ARGS  : rightFraction                                  ***
         *** OUTPUT ARGS : rightFraction                                  ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        friend Fraction & operator--(Fraction &);
        /********************************************************************
         *** FUNCTION operator--                                          ***
         ********************************************************************
         *** DESCRIPTION : used to subtract fraction by 1                 ***
         *** INPUT ARGS  : rightFraction                                  ***
         *** OUTPUT ARGS : rightFraction                                  ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        friend Fraction operator--(Fraction &, const int );
        /********************************************************************
         *** FUNCTION operator!                                           ***
         ********************************************************************
         *** DESCRIPTION : used to invert the fraction                    ***
         *** INPUT ARGS  : rightFraction                                  ***
         *** OUTPUT ARGS : rightFraction                                  ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        friend Fraction operator!(Fraction &rightFraction);
        /********************************************************************
         *** FUNCTION operator==                                          ***
         ********************************************************************
         *** DESCRIPTION : used to test whether two fraction are equal    ***
         *** INPUT ARGS  : leftFraction, rightFraction                    ***
         *** OUTPUT ARGS : true/false                                     ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        friend bool operator==(const Fraction &, const Fraction &);
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
        friend bool operator<(const Fraction &, const Fraction &);
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
        friend bool operator>(const Fraction &, const Fraction &);
        /********************************************************************
         *** FUNCTION operator<<                                          ***
         ********************************************************************
         *** DESCRIPTION : used to display the fraction                   ***
         *** INPUT ARGS  : sout, rightFraction                            ***
         *** OUTPUT ARGS : none                                           ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        friend std::ostream & operator<<(std::ostream &, const Fraction &);
        /********************************************************************
         *** FUNCTION operator>>                                          ***
         ********************************************************************
         *** DESCRIPTION : used to read numerator and denominator         ***
         *** INPUT ARGS  : sin, rightFraction                             ***
         *** OUTPUT ARGS : sin                                            ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        friend std::istream & operator>>(std::istream &, Fraction &);
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
        inline void setDenominator( const unsigned int newDenominator = 1 );
        /********************************************************************
         *** FUNCTION operatpr=                                           ***
         ********************************************************************
         *** DESCRIPTION : used to copy contents from anouter fraction    ***
         *** INPUT ARGS  : rightFraction                                  ***
         *** OUTPUT ARGS : *this                                          ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        Fraction & operator=( const Fraction &rightFraction );
        /********************************************************************
         *** FUNCTION operator+                                           ***
         ********************************************************************
         *** DESCRIPTION : used to add fraction to anouter fraction       ***
         *** INPUT ARGS  : rightFraction                                  ***
         *** OUTPUT ARGS : *this                                          ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        Fraction operator+( const Fraction &rightFraction );
        /********************************************************************
         *** FUNCTION operator*                                           ***
         ********************************************************************
         *** DESCRIPTION : used to multiply fraction to anouter fraction  ***
         *** INPUT ARGS  : rightFraction                                  ***
         *** OUTPUT ARGS : *this                                          ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        Fraction & operator*( const Fraction &rightFraction );
        /********************************************************************
         *** FUNCTION operator++                                          ***
         ********************************************************************
         *** DESCRIPTION : used to add 1 to the fraction                  ***
         *** INPUT ARGS  : none                                           ***
         *** OUTPUT ARGS : *this                                          ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        Fraction & operator++();
        /********************************************************************
         *** FUNCTION operator++                                          ***
         ********************************************************************
         *** DESCRIPTION : used to add 1 to the fraction                  ***
         *** INPUT ARGS  : none                                           ***
         *** OUTPUT ARGS : *this                                          ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        Fraction operator++( const int );
        /********************************************************************
         *** FUNCTION operator-                                           ***
         ********************************************************************
         *** DESCRIPTION : used to negate the invoking fraction           ***
         *** INPUT ARGS  : none                                           ***
         *** OUTPUT ARGS : *this                                          ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        Fraction operator-();
        /********************************************************************
         *** FUNCTION operator int                                        ***
         ********************************************************************
         *** DESCRIPTION : used to convert the fraction to integer        ***
         *** INPUT ARGS  : none                                           ***
         *** OUTPUT ARGS : *this                                          ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        operator int() const;
        /********************************************************************
         *** FUNCTION operator float                                      ***
         ********************************************************************
         *** DESCRIPTION : used to convert the fraction to float          ***
         *** INPUT ARGS  : none                                           ***
         *** OUTPUT ARGS : *this                                          ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        operator float() const;
        /********************************************************************
         *** FUNCTION operator bool                                       ***
         ********************************************************************
         *** DESCRIPTION : used to convert the fraction to bool           ***
         *** INPUT ARGS  : none                                           ***
         *** OUTPUT ARGS : *this                                          ***
         *** IN/OUT ARGS : none                                           ***
         *** RETURN      : none                                           ***
         ********************************************************************/
        operator bool() const;
        
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
