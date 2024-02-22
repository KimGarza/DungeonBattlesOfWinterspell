#pragma once
#include <vector>
#include <string>
#include "Weapon.h"
#include "ICreature.h"

class Character : ICreature {
private:
	std::string name_;
	int health_;
	int intelligence_;
	int dexterity_;
	int strength_;
	std::vector<std::string> weaponOptions_;

public:
	Character(std::string name, int health, int intelligence, int dexterity,
		int strength, std::vector<std::string> weaponOptions);

	std::string GetName() { return name_; }
	int GetHealth() { return health_; }
	int GetIntelligence() { return intelligence_; }
	int GetDexterity() { return dexterity_; }
	int GetStrength() { return strength_; }
	std::vector<std::string> GetWeaponOptions() { return weaponOptions_; }

};