#include "Weapon.h"

Weapon::Weapon(std::string name, bool isRanged,
	std::string pSkillName, std::string pSkillDescription, std::vector<int> pSkillDamageRange,
	std::string sSkillName, std::string sSkillDescription, std::vector<int> sSkillDamageRange)
	: name_(name), isRanged_(isRanged),
	pSkillName_(pSkillName), pSkillDescription_(pSkillDescription), pSkillDamageRange_(pSkillDamageRange),
	sSkillName_(sSkillName), sSkillDescription_(sSkillDescription), sSkillDamageRange_(sSkillDamageRange) {}

int Weapon::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange_[0]; /**/ int max = pSkillDamageRange_[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int Weapon::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange_[0]; /**/ int max = sSkillDamageRange_[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}