#pragma once

#include <string>

class IWeapon // Not true interface acts as one by class being abstract. This is b/c every method will be virtual
{
private:

	std::string name;
	bool isRanged;
	std::string primarySkillName; // single target, more damage
	std::string secondarySkillName; // AOE 

public:

	// deconstruction
	virtual ~IWeapon();

	// getters/setters
	std::string GetName() const;
	bool GetIsRanged() const;
	std::string GetPrimarySkillName() const;
	std::string GetSecondarySkillName() const;

	// attack functions
	virtual void UseSkillPrimary() = 0; // = 0 means pure virtual function
	virtual void UseSkillSecondary() = 0;
};



