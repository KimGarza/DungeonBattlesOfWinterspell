#pragma once
#include <vector>
#include <string>
#include <random>
#include "Weapon.h"
#include "ICreature.h"

class Weapon {
private:
	std::string name;
	bool isRanged;
	std::string pSkillName;
	std::string pSkillDescription;
	std::vector<int> pSkillDamageRange;

	std::string sSkillName;
	std::string sSkillDescription;
	std::vector<int> sSkillDamageRange;

public:
	Weapon(std::string name, bool isRanged,
		std::string pSkillName, std::string pSkillDescription, std::vector<int> pSkillDamageRange, 
		std::string sSkillName, std::string sSkillDescription, std::vector<int> sSkillDamageRange);

	std::string GetName() { return name; }
	bool GetIsRanged() { return isRanged; }
	std::string GetPrimarySkillName() { return pSkillName; }
	std::string GetPrimarySkillDescription() { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange; }

	std::string GetSecondarySkillName() { return sSkillName; }
	std::string GetSecondarySkillDescription() { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange; }

	int UseSkillPrimary();
	int UseSkillSecondary();
};