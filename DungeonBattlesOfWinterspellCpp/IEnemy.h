#pragma once

#include <vector>
#include <string>

class IEnemy {
public:
	virtual ~IEnemy() = default;

	virtual std::string GetName() = 0; //these 0s aren't like a number
	virtual int GetHealth() = 0;
	virtual bool GetHasSwiftness() = 0;
	virtual std::string GetSkillName() = 0;
	virtual std::string GetSkillDescription() = 0;
	virtual int GetSkillDamage() = 0;
	virtual int GetMonsterLevel() = 0;

};
