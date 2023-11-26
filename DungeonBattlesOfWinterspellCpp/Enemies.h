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


private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
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

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
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

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
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

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
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

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
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

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
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

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
};