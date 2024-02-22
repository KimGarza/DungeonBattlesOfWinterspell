#pragma once
#include <vector>
#include <string>
#include "ICreature.h"

class Enemy : public ICreature {
private:
	std::string name_;
	int health_;
	bool hasSwiftness_;
	int accuracyRating_;
	int armour_;
	int evasionRating_;
	std::string skillName_;
	std::string skillDescription_;
	int skillDamage_;
	bool isDead_;

public:
	Enemy(std::string name, int health, bool hasSwiftness,
		int accuracyRating, int armour, int evasionRating,
		std::string skillName, std::string skillDescription,
		int skillDamage);

	std::string GetName() { return name_; }
	int GetHealth() { return health_; }
	bool GetHasSwiftness() { return hasSwiftness_; }
	bool GetAccuracyRating() { return accuracyRating_; }
	bool GetArmour() { return armour_; }
	bool GetEvasionRating() { return evasionRating_; }
	std::string GetSkillName() { return skillName_; }
	std::string GetSkillDescription() { return skillDescription_; }
	int GetSkillDamage() { return skillDamage_; }
	bool GetIsDead() { return isDead_; }
	void TakeDamage(int hitPoints);
	int AttackPlayer();
};