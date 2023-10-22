#pragma once

#include <vector>
#include <string>

#include "IWeapon.h"

class ICharacter {
public:
	virtual ~ICharacter() = default;

	virtual std::string GetName() = 0;
	virtual int GetHealth() = 0;
	virtual int GetIntelligence() = 0;
	virtual int GetDexterity() = 0;
	virtual int GetStrength() = 0;
	virtual std::vector<IWeapon> GetWeaponOptions() = 0;

};
