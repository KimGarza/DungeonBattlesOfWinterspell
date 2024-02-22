#include "Weapon.h"
#include <random>

Weapon::Weapon(std::string name, bool isRanged,
	std::string pSkillName, std::string pSkillDescription, std::vector<int> pSkillDamageRange,
	std::string sSkillName, std::string sSkillDescription, std::vector<int> sSkillDamageRange)
	: name(name), isRanged(isRanged), 
	pSkillName(pSkillName), pSkillDescription(pSkillDescription), pSkillDamageRange(pSkillDamageRange), 
	sSkillName(sSkillName), sSkillDescription(sSkillDescription), sSkillDamageRange(sSkillDamageRange) {}

int Weapon::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange[0]; /**/ int max = pSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int Weapon::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange[0]; /**/ int max = sSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}