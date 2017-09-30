/*********************************************************************
 *** NAME        : Xiaozhu Jin									   ***
 *** CLASS       : CSc 346                                         ***
 *** ASSIGNMENT  : 6                                               ***
 *** DUE DATE    : 04/26/2017                                      ***
 *** INSTRUCTOR  : GAMRADT                                         ***
 *********************************************************************
 *** DESCRIPTION : This program will do the following tesks:       ***
 ***               1. Allow user to create a character class       ***
 ***               2. Allow user to set build of character         ***
 ***               3. If the user doesn't set any property, the    ***
 ***                  warrior class should display default value   ***
 ***               4. Display built character class to the screen  ***
 ********************************************************************/
#ifndef _WARRIOR_H
#define _WARRIOR_H
#include "Character.h"

namespace CharacterNS {

class Warrior : public Character {
	/********************************************************************
	 *** FUNCTION operator<<                                          ***
	 ********************************************************************
	 *** DESCRIPTION : used to display the warrior                    ***
	 *** INPUT ARGS  : sout, rightWarrior                             ***
	 *** OUTPUT ARGS : none                                           ***
	 *** IN/OUT ARGS : none                                           ***
	 *** RETURN      : none                                           ***
	 ********************************************************************/
	friend std::ostream & operator<<(std::ostream &, const Warrior &);
	public:
		enum WeaponType {AXE = 0, SWORD = 1};
		/********************************************************************
		 *** FUNCTION operator=                                           ***
		 ********************************************************************
		 *** DESCRIPTION : used to assign the warrior to another one      ***
		 *** INPUT ARGS  : sout, rightWarrior                             ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		Warrior & operator=(const Character &);
		/********************************************************************
		*** FUNCTION operator=                                           ***
		********************************************************************
		*** DESCRIPTION : used to assign the warrior to another one      ***
		*** INPUT ARGS  : sout, rightWarrior                             ***
		*** OUTPUT ARGS : none                                           ***
		*** IN/OUT ARGS : none                                           ***
		*** RETURN      : none                                           ***
		********************************************************************/
		Warrior & operator=(const Warrior &);
		/********************************************************************
		 *** FUNCTION Warrior                                             ***
		 ********************************************************************
		 *** DESCRIPTION : used to create default/overloaded constructor  ***
		 *** INPUT ARGS  : newName, newGender, newLifeForce, newWeapon    ***
		 ***			   and newResistance							  ***
		 *** OUTPUT ARGS : _name, _gender, _lifeForce, weapon, resistance ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		Warrior();
		Warrior(const std::string newName);
		Warrior(const std::string newName, const Gender newGender);
		Warrior(const std::string newName, const Gender newGender, const short int newLifeForce , const short int newResistance = 25, const WeaponType newWeapon = SWORD);
		/********************************************************************
		 *** FUNCTION Warrior                                             ***
		 ********************************************************************
		 *** DESCRIPTION : used to create copy constructor                ***
		 *** INPUT ARGS  : copiedCharacter                                ***
		 *** OUTPUT ARGS : Warrior                                        ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		Warrior(const Character &);
		/********************************************************************
		 *** FUNCTION Warrior                                             ***
		 ********************************************************************
		 *** DESCRIPTION : used to create copy constructor                ***
		 *** INPUT ARGS  : copiedWariror                                  ***
		 *** OUTPUT ARGS : Warrior                                        ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		Warrior(const Warrior &);
		/********************************************************************
		 *** FUNCTION ~Warrior                                            ***
		 ********************************************************************
		 *** DESCRIPTION : used to create destructor                      ***
		 *** INPUT ARGS  : none                                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		~Warrior();
		/********************************************************************
		 *** FUNCTION setWeapon                                           ***
		 ********************************************************************
		 *** DESCRIPTION : used to set weapon used by warrior             ***
		 *** INPUT ARGS  : newWeapon                                      ***
		 *** OUTPUT ARGS : Weapon                                         ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		inline void setWeapon(const WeaponType newWeapon = SWORD);
		/********************************************************************
		 *** FUNCTION getWeapon                                           ***
		 ********************************************************************
		 *** DESCRIPTION : used to get weapon for warrior                 ***
		 *** INPUT ARGS  : none                                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : Weapon                                         ***
		 ********************************************************************/
		inline WeaponType getWeapon() const;
		/********************************************************************
		 *** FUNCTION setResistance                                       ***
		 ********************************************************************
		 *** DESCRIPTION : used to set Resistance value for warrior       ***
		 *** INPUT ARGS  : newResistance                                  ***
		 *** OUTPUT ARGS : resistance                                     ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		inline void setResistance(const short int newResistance = 25);
		/********************************************************************
		 *** FUNCTION getResistance                                       ***
		 ********************************************************************
		 *** DESCRIPTION : used to get Life Force value for warrior       ***
		 *** INPUT ARGS  : none                                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : lifeforce                                      ***
		 ********************************************************************/
		inline short int getResistance() const;
	private:
		WeaponType weapon;
		short int resistance;
};

/********************************************************************
 *** FUNCTION setWeapon                                           ***
 ********************************************************************
 *** DESCRIPTION : used to set weapon used by warrior             ***
 *** INPUT ARGS  : newWeapon                                      ***
 *** OUTPUT ARGS : Weapon                                         ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
inline void Warrior::setWeapon(const Warrior::WeaponType newWeapon) {
	weapon = newWeapon;
	return;
}

/********************************************************************
*** FUNCTION getWeapon                                           ***
********************************************************************
*** DESCRIPTION : used to get weapon for warrior                 ***
*** INPUT ARGS  : none                                           ***
*** OUTPUT ARGS : none                                           ***
*** IN/OUT ARGS : none                                           ***
*** RETURN      : Weapon                                         ***
********************************************************************/
inline Warrior::WeaponType Warrior::getWeapon() const {
	return weapon;
}

/********************************************************************
 *** FUNCTION setResistance                                       ***
 ********************************************************************
 *** DESCRIPTION : used to set Resistance value for warrior       ***
 *** INPUT ARGS  : newResistance                                  ***
 *** OUTPUT ARGS : resistance                                     ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
inline void Warrior::setResistance(const short int newResistance) {
	resistance = newResistance;
	return;
}

/********************************************************************
 *** FUNCTION getResistance                                       ***
 ********************************************************************
 *** DESCRIPTION : used to get Life Force value for warrior       ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : lifeforce                                      ***
 ********************************************************************/
inline short int Warrior::getResistance() const {
	return resistance;
}
}
#endif
