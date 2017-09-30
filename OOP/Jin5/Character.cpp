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
#include <iostream>
#include <string>
#include "Character.h"

namespace CharacterNS {
/********************************************************************
 *** FUNCTION Character                                           ***
 ********************************************************************
 *** DESCRIPTION : used to create default/overloaded constructor  ***
 *** INPUT ARGS  : newClass, newName, newGender, newLifeForce     ***
 *** OUTPUT ARGS : _class, _name, _gender, _lifeForce             ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Character::Character(Class newClass, std::string newName, Gender newGender, short int newLifeForce) : _class(newClass), _name(newName), _gender(newGender), _lifeForce(newLifeForce)  {
	return;
}

/********************************************************************
 *** FUNCTION Character                                           ***
 ********************************************************************
 *** DESCRIPTION : used to create copy constructor                ***
 *** INPUT ARGS  : copiedCharacter                                ***
 *** OUTPUT ARGS : Character                                      ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Character::Character(const Character &copiedCharacter) : _class(copiedCharacter.getClass()), _name(copiedCharacter.getName()), _gender(copiedCharacter.getGender()), _lifeForce(copiedCharacter.getLifeForce()) {
	return;
}

/********************************************************************
 *** FUNCTION ~Character                                          ***
 ********************************************************************
 *** DESCRIPTION : used to create destructor                      ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Character::~Character() {
	std::cout << "The character class has been destoryed" << std::endl;
}

/********************************************************************
 *** FUNCTION operator<<                                          ***
 ********************************************************************
 *** DESCRIPTION : used to display the character                  ***
 *** INPUT ARGS  : sout, rightCharacter                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
std::ostream & operator<<(std::ostream &sout, const Character &rightCharacter) {
	std::string strGender;
	if (rightCharacter.getGender() == Character::MALE) {
		strGender = "Male";
	}else {
		strGender = "Female";
	}
	switch (rightCharacter.getClass()) {
	case Character::WARRIOR:
			return sout << "Class: Warrior" << std::endl
						<< "Name: " << rightCharacter.getName() << std::endl
						<< "Gender: " << strGender << std::endl
						<< "Life Force: " << rightCharacter.getLifeForce() << std::endl;
			break;
		case Character::WIZARD:
			return sout << "Class: Wizard" << std::endl
						<< "Name: " << rightCharacter.getName() << std::endl
						<< "Gender: " << strGender << std::endl
						<< "Life Force: " << rightCharacter.getLifeForce() << std::endl;
			break;
		default :
			return sout << "Class: Hunter" << std::endl
						<< "Name: " << rightCharacter.getName() << std::endl
						<< "Gender: " << strGender << std::endl
						<< "Life Force: " << rightCharacter.getLifeForce() << std::endl;
			break;
	}
}

/********************************************************************
 *** FUNCTION operator=                                           ***
 ********************************************************************
 *** DESCRIPTION : used to assign the character to another one    ***
 *** INPUT ARGS  : sout, rightCharacter                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
Character &Character::operator=(const Character &rightCharacter) {
	if (this != &rightCharacter) {
		setLifeForce(rightCharacter.getLifeForce());
		setClass(rightCharacter.getClass());
		setName(rightCharacter.getName());
		setGender(rightCharacter.getGender());
	}
	return *this;
}

}
