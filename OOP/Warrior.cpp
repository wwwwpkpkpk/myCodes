/*********************************************************************
 *** NAME        : Xiaozhu Jin	 								   ***
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
#include "Warrior.h"
#include <string>
#include <iostream>

namespace CharacterNS {
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

Warrior::Warrior() : Character(WARRIOR), resistance(25), weapon(SWORD) {
	return;
}

Warrior::Warrior(const std::string newName) : Character(WARRIOR,newName), resistance(25), weapon(SWORD) {
	return;
}

Warrior::Warrior(const std::string newName, const Character::Gender newGender) : Character(WARRIOR,newName,newGender), resistance(25), weapon(SWORD) {
	return;
}

Warrior::Warrior(const std::string newName, const Character::Gender newGender, const short int newLifeForce, const short int newResistance, const Warrior::WeaponType newWeapon) : Character(WARRIOR, newName, newGender, newLifeForce), resistance(newResistance), weapon(newWeapon) {
	return;
}

/********************************************************************
 *** FUNCTION Warrior                                             ***
 ********************************************************************
 *** DESCRIPTION : used to create copy constructor                ***
 *** INPUT ARGS  : copiedCharacter                                ***
 *** OUTPUT ARGS : Warrior                                        ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Warrior::Warrior(const Character &copiedCharacter) : Character(copiedCharacter), resistance(25), weapon() {
	return;
}

/********************************************************************
 *** FUNCTION Warrior                                             ***
 ********************************************************************
 *** DESCRIPTION : used to create copy constructor                ***
 *** INPUT ARGS  : copiedWariror                                  ***
 *** OUTPUT ARGS : Warrior                                        ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Warrior::Warrior(const Warrior & copiedWarrior) : Character(copiedWarrior), resistance(copiedWarrior.getResistance()), weapon(copiedWarrior.getWeapon()) {
	return;
}

/********************************************************************
 *** FUNCTION ~Warrior                                            ***
 ********************************************************************
 *** DESCRIPTION : used to create destructor                      ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Warrior::~Warrior() {
	std::cout << "Warrior Class has been destoryed" << std::endl;
}

/********************************************************************
 *** FUNCTION operator<<                                          ***
 ********************************************************************
 *** DESCRIPTION : used to display the warrior                    ***
 *** INPUT ARGS  : sout, rightWarrior                             ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
std::ostream & operator<<(std::ostream &sout, const Warrior &rightWarrior) {
	std::string WarriorGender;
	if (rightWarrior.getGender() == Character::MALE) {
		WarriorGender = "Male";
	}
	else {
		WarriorGender = "Female";
	}
	switch (rightWarrior.getClass()) {
		case 0: {
			return sout << "Class: Hunter" << std::endl
						<< "Name: " << rightWarrior.getName() << std::endl
						<< "Gender: " << WarriorGender << std::endl
						<< "Life Force: " << rightWarrior.getLifeForce() << std::endl;

			break;
		}
		case 1: {
			if(rightWarrior.getWeapon() == Warrior::AXE) {
				return sout << "Class: Warrior" << std::endl
							<< "Name: " << rightWarrior.getName() << std::endl
							<< "Gender: " << WarriorGender << std::endl
							<< "LifeForce: " << rightWarrior.getLifeForce() << std::endl
							<< "Resistance: " << rightWarrior.getResistance() << std::endl
							<< "Weapon: Axe" << std::endl;
			} else {
				return sout << "Class: Warrior" << std::endl
							<< "Name: " << rightWarrior.getName() << std::endl
							<< "Gender: " << WarriorGender << std::endl
							<< "LifeForce: " << rightWarrior.getLifeForce() << std::endl
							<< "Resistance: " << rightWarrior.getResistance() << std::endl
							<< "Weapon: Sword" << std::endl;
			}
			break;
		}
		default: {
			return sout << "Class: Wizard" << std::endl
						<< "Name: " << rightWarrior.getName() << std::endl
						<< "Gender: " << WarriorGender << std::endl
						<< "Life Force: " << rightWarrior.getLifeForce() << std::endl;
			break;
		}
	}
}

/********************************************************************
*** FUNCTION operator=                                           ***
********************************************************************
*** DESCRIPTION : used to assign the warrior to another one      ***
*** INPUT ARGS  : sout, rightWarrior                             ***
*** OUTPUT ARGS : none                                           ***
*** IN/OUT ARGS : none                                           ***
*** RETURN      : none                                           ***
********************************************************************/
Warrior &Warrior::operator=(const Character &rightCharacter) {
	if (rightCharacter.getClass() == WARRIOR) {
		Character::operator=(rightCharacter);
	}
	return *this;
}

/********************************************************************
 *** FUNCTION operator=                                           ***
 ********************************************************************
 *** DESCRIPTION : used to assign the warrior to another one      ***
 *** INPUT ARGS  : sout, rightWarrior                             ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Warrior &Warrior::operator=(const Warrior &rightWarrior) {
	if (rightWarrior.getClass() == WARRIOR && this != &rightWarrior) {
		Character::operator=(rightWarrior);
		setResistance(rightWarrior.getResistance());
		setWeapon(rightWarrior.getWeapon());
	}
	return *this;
}
}
