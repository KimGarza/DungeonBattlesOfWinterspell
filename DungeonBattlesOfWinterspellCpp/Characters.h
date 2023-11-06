#pragma once
#include <vector>
#include "ICharacter.h"
#include "IWeapon.h"

class WoodElf : public ICharacter {

private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	std::vector<std::string> weaponOptions;

public:
	WoodElf();

	std::string GetName() { return name; }
	int GetHealth() override { return health; }
	int GetIntelligence() { return intelligence; }
	int GetDexterity() { return dexterity; }
	int GetStrength() { return strength; }
	std::vector<std::string> GetWeaponOptions() { return weaponOptions; }
};

// -------------------------------------------

class Dwarf : public ICharacter {

private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	std::vector<std::string> weaponOptions;

public:
	Dwarf();

	std::string GetName() { return name; }
	int GetHealth() override { return health; }
	int GetIntelligence() { return intelligence; }
	int GetDexterity() { return dexterity; }
	int GetStrength() { return strength; }
	std::vector<std::string> GetWeaponOptions() { return weaponOptions; }
};

// -------------------------------------------

class Enchantress : public ICharacter {
private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	std::vector<std::string> weaponOptions;


public:
	Enchantress();

	std::string GetName() { return name; }
	int GetHealth() override  { return health; }
	int GetIntelligence() { return intelligence; }
	int GetDexterity() { return dexterity; }
	int GetStrength() { return strength; }
	std::vector<std::string> GetWeaponOptions() { return weaponOptions; }

};
