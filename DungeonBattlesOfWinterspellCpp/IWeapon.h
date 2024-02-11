#pragma once

#include <vector>
#include <string>

// Changed to not be abstr
class IWeapon { // Not true interface acts as one by class being abstract. This is b/c every method will be virtual

private:
	std::string name;
	bool isRanged;
	std::string primarySkillName;
	std::string primarySkillDescription;
	std::string secondarySkillName;
	std::string secondarySkillDescription;
	std::vector<int> primarySkillDamageRange;
	std::vector<int> secondarySkillDamageRange;

public:
	~IWeapon() = default;

	virtual std::string GetName() { return name; } //these 0s aren't like a number
	virtual bool GetIsRanged() { return isRanged; }
	virtual std::string GetPrimarySkillName() { return primarySkillName; }
	virtual std::string GetPrimarySkillDescription() { return primarySkillDescription; }
	virtual std::vector<int> GetPrimarySkillDamageRange() { return primarySkillDamageRange; }
	virtual std::string GetSecondarySkillName() { return secondarySkillName; }
	virtual std::string GetSecondarySkillDescription() { return secondarySkillDescription; }
	virtual std::vector<int> GetSecondarySkillDamageRange() { return secondarySkillDamageRange; }

	virtual int UseSkillPrimary() {
		return 0;
	};
	virtual int UseSkillSecondary() {
		return 0;
	}
};