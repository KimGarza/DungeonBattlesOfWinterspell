#pragma once

#include <vector>
#include <string>

#include "IWeapon.h"

class ICharacter {
public:
	std::string GetName();
	virtual int GetHealth();
	int GetIntelligence();
	int GetDexterity();
	int GetStrength();
	std::vector<std::string> GetWeaponOptions();

	virtual ~ICharacter() {} // Virtual destructor
};
