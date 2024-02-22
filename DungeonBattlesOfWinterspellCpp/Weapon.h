#pragma once
#include <vector>
#include <string>
#include <random>
#include "Weapon.h"
#include "ICreature.h"

class Weapon {
private:
	std::string name_;
	bool isRanged_;
	std::string pSkillName_;
	std::string pSkillDescription_;
	std::vector<int> pSkillDamageRange_;

	std::string sSkillName_;
	std::string sSkillDescription_;
	std::vector<int> sSkillDamageRange_;

public:
	Weapon(std::string name, bool isRanged,
		std::string pSkillName, std::string pSkillDescription, std::vector<int> pSkillDamageRange, 
		std::string sSkillName, std::string sSkillDescription, std::vector<int> sSkillDamageRange);

	std::string GetName() { return name_; }
	bool GetIsRanged() { return isRanged_; }
	std::string GetPrimarySkillName() { return pSkillName_; }
	std::string GetPrimarySkillDescription() { return pSkillDescription_; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange_; }

	std::string GetSecondarySkillName() { return sSkillName_; }
	std::string GetSecondarySkillDescription() { return sSkillDescription_; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange_; }

	int UseSkillPrimary();
	int UseSkillSecondary();
};