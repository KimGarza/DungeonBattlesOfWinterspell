#pragma once

#include <vector>
#include <string>

#include "IWeapon.h"

class ICharacter {

private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	std::vector<std::string> weaponOptions;

public:
	virtual std::string GetName() const = 0;

	virtual int GetHealth() {
		return health;
	}

	virtual int GetIntelligence() const = 0;
	virtual int GetDexterity() const = 0;
	virtual int GetStrength() const = 0;

	virtual std::vector<std::string> GetWeaponOptions() const = 0;

	virtual ~ICharacter() {} // Virtual destructor
};
