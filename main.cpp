#include "Character.h"
#include "Warrior.h"
#include <iostream>
#include <string>

int main() {
	using namespace CharacterNS;
	Character newCharacter(Character::WARRIOR, "Aragon", Character::MALE, 300);
	Warrior newWarrior(newCharacter.getName(), newCharacter.getGender(), newCharacter.getLifeForce());

	std::cout << newWarrior << std::endl;
	

	
	


	return 0;
}