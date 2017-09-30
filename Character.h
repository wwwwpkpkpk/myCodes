/********************************************************************
 *** NAME        : Xiaozhu Jin									  ***
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
#ifndef _CHARACTER_H
#define _CHARACTER_H
#include <iostream>

namespace CharacterNS {


class Character {
		/********************************************************************
		 *** FUNCTION operator<<                                          ***
		 ********************************************************************
		 *** DESCRIPTION : used to display the character                  ***
		 *** INPUT ARGS  : sout, rightCharacter                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		friend std::ostream & operator<<(std::ostream &, const Character & );

	public:
		enum Class { HUNTER = 0, WARRIOR = 1, WIZARD = 2 };
		enum Gender { MALE = 0, FEMALE = 1 };
		/********************************************************************
		 *** FUNCTION Character                                           ***
		 ********************************************************************
		 *** DESCRIPTION : used to create default/overloaded constructor  ***
		 *** INPUT ARGS  : newClass, newName, newGender, newLifeForce     ***
		 *** OUTPUT ARGS : _class, _name, _gender, _lifeForce             ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		Character(const Class newClass = HUNTER, const std::string newName = "Frodo", const Gender newGender = MALE, const short int newLifeForce = 150);
		/********************************************************************
		 *** FUNCTION Character                                           ***
		 ********************************************************************
		 *** DESCRIPTION : used to create copy constructor                ***
		 *** INPUT ARGS  : copiedCharacter                                ***
		 *** OUTPUT ARGS : Character                                      ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		Character( const Character & );
		/********************************************************************
		 *** FUNCTION ~Character                                          ***
		 ********************************************************************
		 *** DESCRIPTION : used to create destructor                      ***
		 *** INPUT ARGS  : none                                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		~Character();
		/********************************************************************
		 *** FUNCTION operator=                                           ***
		 ********************************************************************
		 *** DESCRIPTION : used to assign the character to another one    ***
		 *** INPUT ARGS  : sout, rightCharacter                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		Character & operator=(const Character &);
		/********************************************************************
		 *** FUNCTION setLifeForce                                        ***
		 ********************************************************************
		 *** DESCRIPTION : used to set Life Force value for Character     ***
		 *** INPUT ARGS  : newLifeForce                                   ***
		 *** OUTPUT ARGS : lifeforce                                      ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		inline void setLifeForce(const short int newLifeForce = 150);
		/********************************************************************
		 *** FUNCTION getLifeForce                                        ***
	 	 ********************************************************************
	 	 *** DESCRIPTION : used to get Life Force value for Character     ***
		 *** INPUT ARGS  : none                                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : lifeforce                                      ***
		 ********************************************************************/
		inline short int getLifeForce() const;
		/********************************************************************
		 *** FUNCTION setClass                                            ***
		 ********************************************************************
		 *** DESCRIPTION : used to set class for Character                ***
		 *** INPUT ARGS  : newClass						                  ***
		 *** OUTPUT ARGS : class						                  ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		inline void setClass(const Class newClass = HUNTER);
		/********************************************************************
		 *** FUNCTION getClass	                                          ***
		 ********************************************************************
		 *** DESCRIPTION : used to get class for Character			      ***
		 *** INPUT ARGS  : none                                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : class                                          ***
		 ********************************************************************/
		inline Class getClass() const;
		/********************************************************************
		 *** FUNCTION setName                                             ***
		 ********************************************************************
		 *** DESCRIPTION : used to set name for Character                 ***
		 *** INPUT ARGS  : newName						                  ***
		 *** OUTPUT ARGS : name							                  ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		inline void setName(const std::string newName = "Frodo");
		/********************************************************************
		 *** FUNCTION getName	                                          ***
		 ********************************************************************
		 *** DESCRIPTION : used to get name for Character			      ***
		 *** INPUT ARGS  : none                                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : name                                           ***
		 ********************************************************************/
		inline std::string getName() const;
		/********************************************************************
		 *** FUNCTION setGenderMale	                                      ***
		 ********************************************************************
		 *** DESCRIPTION : used to set Character's gender to male         ***
		 *** INPUT ARGS  : none                                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : none                                           ***
		 ********************************************************************/
		inline void setGender(const Gender newGender = MALE);
		
		/********************************************************************
		 *** FUNCTION isGenderFemale                                      ***
		 ********************************************************************
		 *** DESCRIPTION : used to check whether the character's gender is***
		 ***               female                                         ***
		 *** INPUT ARGS  : none                                           ***
		 *** OUTPUT ARGS : none                                           ***
		 *** IN/OUT ARGS : none                                           ***
		 *** RETURN      : Gender                                         ***
		 ********************************************************************/
		inline Gender getGender() const;

	private:
		Class _class;
		Gender _gender;
		std::string _name;
		short int _lifeForce;
};

/********************************************************************
 *** FUNCTION setLifeForce                                        ***
 ********************************************************************
 *** DESCRIPTION : used to set Life Force value for Character     ***
 *** INPUT ARGS  : newLifeForce                                   ***
 *** OUTPUT ARGS : lifeforce                                      ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
inline void Character::setLifeForce(const short int newLifeForce) {
	_lifeForce = newLifeForce;
	return;
}

/********************************************************************
 *** FUNCTION getLifeForce                                        ***
 ********************************************************************
 *** DESCRIPTION : used to get Life Force value for Character     ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : lifeforce                                      ***
 ********************************************************************/
inline short int Character::getLifeForce() const {
	return _lifeForce;
}

/********************************************************************
 *** FUNCTION setClass                                            ***
 ********************************************************************
 *** DESCRIPTION : used to set class for Character                ***
 *** INPUT ARGS  : newClass						                  ***
 *** OUTPUT ARGS : class						                  ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
inline void Character::setClass(const Class newClass) {
	_class = newClass;
	return;
}

/********************************************************************
 *** FUNCTION getClass	                                          ***
 ********************************************************************
 *** DESCRIPTION : used to get class for Character			      ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : class                                          ***
 ********************************************************************/
inline Character::Class Character::getClass() const {
	return _class;
}

/********************************************************************
 *** FUNCTION setName                                             ***
 ********************************************************************
 *** DESCRIPTION : used to set name for Character                 ***
 *** INPUT ARGS  : newName						                  ***
 *** OUTPUT ARGS : name							                  ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
inline void Character::setName(const std::string newName) {
	_name = newName;
	return;
}

/********************************************************************
 *** FUNCTION getName	                                          ***
 ********************************************************************
 *** DESCRIPTION : used to get name for Character			      ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : name                                           ***
 ********************************************************************/
inline std::string Character::getName() const {
	return _name;
}

/********************************************************************
 *** FUNCTION setGenderMale	                                      ***
 ********************************************************************
 *** DESCRIPTION : used to set Character's gender to male         ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : none                                           ***
 ********************************************************************/
inline void Character::setGender(const Gender newGender) {
	_gender = newGender;
	return;
}


/********************************************************************
 *** FUNCTION isGenderFemale                                      ***
 ********************************************************************
 *** DESCRIPTION : used to check whether the character's gender is***
 ***               female                                         ***
 *** INPUT ARGS  : none                                           ***
 *** OUTPUT ARGS : none                                           ***
 *** IN/OUT ARGS : none                                           ***
 *** RETURN      : Gender                                         ***
 ********************************************************************/
inline Character::Gender Character::getGender() const {
	return _gender;
}
}
#endif