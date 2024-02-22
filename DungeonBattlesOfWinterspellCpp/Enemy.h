#pragma once
#include <vector>
#include <string>
#include "ICreature.h"

class Enemy : public ICreature {
private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	bool isDead;

public:
	Enemy(std::string name, int health, bool hasSwiftness,
		std::string skillName, std::string skillDescription,
		int skillDamage);

	std::string GetName() { return name; }
	int GetHealth() { return health; }
	bool GetHasSwiftness() { return hasSwiftness; }
	std::string GetSkillName() { return skillName; }
	std::string GetSkillDescription() { return skillDescription; }
	int GetSkillDamage() { return skillDamage; }
	bool GetIsDead() { return isDead; }
	void TakeDamage(int hitPoints);
	int AttackPlayer();
};