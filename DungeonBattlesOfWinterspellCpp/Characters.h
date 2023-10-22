#pragma once
#include <vector>

#include "ICharacter.h"
#include "IWeapon.h"

class WoodElf : public ICharacter {
public:
	WoodElf();

	std::string GetName() override { return name; }
	int GetHealth() override { return health; }
	int GetIntelligence() override { return intelligence; }
	int GetDexterity() override { return dexterity; }
	int GetStrength() override { return strength; }
	std::vector<IWeapon> GetWeaponOptions() override { return weaponOptions; }

private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	std::vector<IWeapon> weaponOptions;
};

// -------------------------------------------


class Dwarf : public ICharacter {
public:
	Dwarf();

	std::string GetName() override { return name; }
	int GetHealth() override { return health; }
	int GetIntelligence() override { return intelligence; }
	int GetDexterity() override { return dexterity; }
	int GetStrength() override { return strength; }
	std::vector<IWeapon> GetWeaponOptions() override { return weaponOptions; }

private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	std::vector<IWeapon> weaponOptions;
};

// -------------------------------------------


class Enchantress : public ICharacter {
public:
	Enchantress();

	std::string GetName() override { return name; }
	int GetHealth() override { return health; }
	int GetIntelligence() override { return intelligence; }
	int GetDexterity() override { return dexterity; }
	int GetStrength() override { return strength; }
	std::vector<IWeapon> GetWeaponOptions() override { return weaponOptions; }


private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	std::vector<IWeapon> weaponOptions;
};
