#include "Character.h"

Character::Character(std::string name, int health, int intelligence, int dexterity,
	int strength, std::vector<std::string> weaponOptions)
	: name_(name), health_(health), intelligence_(intelligence), dexterity_(dexterity),
	strength_(strength), weaponOptions_(weaponOptions) {}