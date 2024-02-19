#pragma once
#include <vector>
#include "IWeapon.h"
#include "ICreature.h"

class Character : ICreature {
private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	bool hasSwiftness;
	int armourRating;
	int evasionRating;
	std::vector<std::string> weaponOptions;

public:
	Character(std::string name, int health, int intelligence, int dexterity,
		int strength, int armourRating, int evasionRating, std::vector<std::string> weaponOptions);

	std::string GetName() { return name; }
	int GetHealth() { return health; }
	int GetIntelligence() { return intelligence; }
	int GetDexterity() { return dexterity; }
	int GetStrength() {	return strength; }
	bool GetHasSwiftness() { return hasSwiftness;}
	int GetArmourRating() { return armourRating; }
	int GetEvasionRating() { return evasionRating;}
	std::vector<std::string> GetWeaponOptions() { return weaponOptions;	}
};