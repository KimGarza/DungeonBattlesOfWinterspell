#pragma once
#include <vector>
#include <string>
#include "IWeapon.h"
#include "ICreature.h"

class ICharacter {

private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	bool hasSwiftness;
	int armourRating;
	std::vector<std::string> weaponOptions;

public:
	virtual std::string GetName() const = 0;

	virtual int GetHealth() { // If I remove the return on this to make it a pure virtual function I get error that the Characters cannot instanitate pure virutal funciton
		return health;
	}

	virtual int GetIntelligence() const = 0;
	virtual int GetDexterity() const = 0;
	virtual int GetStrength() const = 0;
	virtual int GetArmourRating() const = 0;

	virtual bool GetHasSwiftness() const = 0;

	virtual std::vector<std::string> GetWeaponOptions() const = 0;

	virtual void SetHasSwiftness(bool hasSwiftness) = 0;

	virtual ~ICharacter() {} // Virtual destructor
};
