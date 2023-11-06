#pragma once

#include <vector>
#include <string>

// Changed to not be abstr
class IWeapon { // Not true interface acts as one by class being abstract. This is b/c every method will be virtual
public:
	~IWeapon() = default;

	std::string GetName() {}; //these 0s aren't like a number
	bool GetIsRanged() {};
	std::string GetPrimarySkillName() {};
	std::string GetPrimarySkillDescription() {};
	std::vector<int> GetPrimarySkillDamageRange() {};
	std::string GetSecondarySkillName() {};
	std::string GetSecondarySkillDescription() {};
	std::vector<int> GetSecondarySkillDamageRange() {};

	void UseSkillPrimary() {};
	void UseSkillSecondary() {};
};