#include "..\..\Headers\Actors\Character.h"

Character::Character(std::string name, int health, int intelligence, int dexterity,
	int strength, int armourRating, int evasionRating, std::vector<std::string> weaponOptions)
	: name(name), health(health), intelligence(intelligence), dexterity(dexterity),
	strength(strength), armourRating(armourRating), evasionRating(evasionRating), weaponOptions(weaponOptions) {}