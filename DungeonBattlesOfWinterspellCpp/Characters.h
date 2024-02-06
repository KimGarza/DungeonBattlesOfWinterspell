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
	bool hasSwiftness;
	std::vector<std::string> weaponOptions;

public:
	WoodElf();
	
	std::string GetName() const override {
		return name;
	}

	int GetHealth() { return health; }

	int GetIntelligence()  const override {
		return intelligence; 
	}

	int GetDexterity() const override {
		return dexterity; 
	}

	int GetStrength() const override {
		return strength; 
	}

	bool GetHasSwiftness() const override {
		return hasSwiftness;
	}

	std::vector<std::string> GetWeaponOptions() const override {
		return weaponOptions;
	}
};

// -------------------------------------------

class Dwarf : public ICharacter {

private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	bool hasSwiftness;
	std::vector<std::string> weaponOptions;

public:
	Dwarf();

	std::string GetName() const override {
		return name;
	}

	int GetHealth() { return health; }

	int GetIntelligence()  const override {
		return intelligence;
	}

	int GetDexterity() const override {
		return dexterity;
	}

	int GetStrength() const override {
		return strength;
	}

	bool GetHasSwiftness() const override {
		return hasSwiftness;
	}

	std::vector<std::string> GetWeaponOptions() const override {
		return weaponOptions;
	}
};

// -------------------------------------------

class Enchantress : public ICharacter {
private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	bool hasSwiftness;
	std::vector<std::string> weaponOptions;


public:
	Enchantress();

	std::string GetName() const override {
		return name;
	}

	int GetHealth() { return health; }

	int GetIntelligence()  const override {
		return intelligence;
	}

	int GetDexterity() const override {
		return dexterity;
	}

	int GetStrength() const override {
		return strength;
	}

	bool GetHasSwiftness() const override {
		return hasSwiftness;
	}

	std::vector<std::string> GetWeaponOptions() const override {
		return weaponOptions;
	}

};
