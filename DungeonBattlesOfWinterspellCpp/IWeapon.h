#pragma once

#include <vector>
#include <string>

// Changed to not be abstr
class IWeapon { // Not true interface acts as one by class being abstract. This is b/c every method will be virtual
public:
	~IWeapon() = default;

	std::string GetName() { return "Default Weapon"; } //these 0s aren't like a number
	virtual bool GetIsRanged() { return false; }
	virtual std::string GetPrimarySkillName() { return "Default Skill"; }
	virtual std::string GetPrimarySkillDescription() { return "Default Description"; }
	virtual std::vector<int> GetPrimarySkillDamageAttack() { return { 0, 0 }; }
	virtual std::string GetSecondarySkillName() { return "Default Skill"; }
	virtual std::string GetSecondarySkillDescription() { return "Default Description"; }
	virtual std::vector<int> GetSecondarySkillDamageRange() { return { 0, 0 }; }

	virtual int UseSkillPrimary() { return 0; }
	virtual int UseSkillSecondary() { return 0; }
};