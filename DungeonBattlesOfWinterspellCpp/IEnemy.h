#pragma once
#include <vector>
#include <string>
#include "ICreature.h"

class IEnemy : public ICreature {

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;

public:
	virtual std::string GetName() = 0; //these 0s aren't like a number

	virtual int GetHealth() {
		return health;
	}

	virtual bool GetHasSwiftness() = 0;
	virtual std::string GetSkillName() = 0;
	virtual std::string GetSkillDescription() = 0;
	virtual int GetSkillDamage() = 0;

	bool IsPlayableCharacter() const override { return false; } // inherited from ICreature

	virtual ~IEnemy() = default;
};
