#pragma once

#include <vector>
#include <string>

class IWeapon { // Not true interface acts as one by class being abstract. This is b/c every method will be virtual
public:
	virtual ~IWeapon() = default;

	virtual std::string GetName() = 0; //these 0s aren't like a number
	virtual bool GetIsRanged() = 0;
	virtual std::string GetPrimarySkillName() = 0;
	virtual std::string GetPrimarySkillDescription() = 0;
	virtual std::vector<int> GetPrimarySkillDamageRange() = 0;
	virtual std::string GetSecondarySkillName() = 0;
	virtual std::string GetSecondarySkillDescription() = 0;
	virtual std::vector<int> GetSecondarySkillDamageRange() = 0;

	virtual void UseSkillPrimary() = 0;
	virtual void UseSkillSecondary() = 0;
};