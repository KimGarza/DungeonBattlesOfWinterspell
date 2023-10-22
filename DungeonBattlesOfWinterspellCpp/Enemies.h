#include "IEnemy.h"

class Firespitter : public IEnemy {
public:
	Firespitter();

	std::string GetName() override { return name; }
	int GetHealth() override { return health; }
	bool GetHasSwiftness() override { return hasSwiftness; }
	std::string GetSkillName() override { return skillName; }
	std::string GetSkillDescription() override { return skillDescription; }
	int GetSkillDamage() override { return skillDamage; }
	int GetMonsterLevel() override { return monsterLevel; }

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	int monsterLevel;
};

// -------------------------------------------


class DungeonDweller : public IEnemy {
public:
	DungeonDweller();

	std::string GetName() override { return name; }
	int GetHealth() override { return health; }
	bool GetHasSwiftness() override { return hasSwiftness; }
	std::string GetSkillName() override { return skillName; }
	std::string GetSkillDescription() override { return skillDescription; }
	int GetSkillDamage() override { return skillDamage; }
	int GetMonsterLevel() override { return monsterLevel; }

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	int monsterLevel;
};

// -------------------------------------------


class Goblin : public IEnemy {
public:
	Goblin();

	std::string GetName() override { return name; }
	int GetHealth() override { return health; }
	bool GetHasSwiftness() override { return hasSwiftness; }
	std::string GetSkillName() override { return skillName; }
	std::string GetSkillDescription() override { return skillDescription; }
	int GetSkillDamage() override { return skillDamage; }
	int GetMonsterLevel() override { return monsterLevel; }

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	int monsterLevel;
};

// -------------------------------------------


class HauntingSpirit : public IEnemy {
public:
	HauntingSpirit();

	std::string GetName() override { return name; }
	int GetHealth() override { return health; }
	bool GetHasSwiftness() override { return hasSwiftness; }
	std::string GetSkillName() override { return skillName; }
	std::string GetSkillDescription() override { return skillDescription; }
	int GetSkillDamage() override { return skillDamage; }
	int GetMonsterLevel() override { return monsterLevel; }

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	int monsterLevel;
};

// -------------------------------------------


class Troll : public IEnemy {
public:
	Troll();

	std::string GetName() override { return name; }
	int GetHealth() override { return health; }
	bool GetHasSwiftness() override { return hasSwiftness; }
	std::string GetSkillName() override { return skillName; }
	std::string GetSkillDescription() override { return skillDescription; }
	int GetSkillDamage() override { return skillDamage; }
	int GetMonsterLevel() override { return monsterLevel; }

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	int monsterLevel;
};

// -------------------------------------------


class Skeleton : public IEnemy {
public:
	Skeleton();

	std::string GetName() override { return name; }
	int GetHealth() override { return health; }
	bool GetHasSwiftness() override { return hasSwiftness; }
	std::string GetSkillName() override { return skillName; }
	std::string GetSkillDescription() override { return skillDescription; }
	int GetSkillDamage() override { return skillDamage; }
	int GetMonsterLevel() override { return monsterLevel; }

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	int monsterLevel;
};

// -------------------------------------------


class UndeadWolf : public IEnemy {
public:
	UndeadWolf();

	std::string GetName() override { return name; }
	int GetHealth() override { return health; }
	bool GetHasSwiftness() override { return hasSwiftness; }
	std::string GetSkillName() override { return skillName; }
	std::string GetSkillDescription() override { return skillDescription; }
	int GetSkillDamage() override { return skillDamage; }
	int GetMonsterLevel() override { return monsterLevel; }

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	int monsterLevel;
};