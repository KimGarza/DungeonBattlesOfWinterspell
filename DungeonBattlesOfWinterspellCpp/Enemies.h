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
	bool GetIsDead() override { return isDead; }
	void TakeDamage(int hitPoints) override;
	int AttackPlayer() override;


private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	bool isDead;
	UI ui;
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
	bool GetIsDead() override { return isDead; }
	void TakeDamage(int hitPoints);
	int AttackPlayer();

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	bool isDead;
	UI ui;
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
	bool GetIsDead() override { return isDead; }
	void TakeDamage(int hitPoints);
	int AttackPlayer();

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	bool isDead;
	UI ui;
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
	bool GetIsDead() override { return isDead; }
	void TakeDamage(int hitPoints);
	int AttackPlayer();

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	bool isDead;
	UI ui;
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
	bool GetIsDead() override { return isDead; }
	void TakeDamage(int hitPoints);
	int AttackPlayer();

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	bool isDead;
	UI ui;
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
	bool GetIsDead() override { return isDead; }
	void TakeDamage(int hitPoints);
	int AttackPlayer();

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	bool isDead;
	UI ui;
};

// -------------------------------------------


class UndeadWolf : public IEnemy {
public:
	UndeadWolf();

	std::string GetName() { return name; }
	int GetHealth() override { return health; }
	bool GetHasSwiftness() override { return hasSwiftness; }
	std::string GetSkillName() override { return skillName; }
	std::string GetSkillDescription() override { return skillDescription; }
	int GetSkillDamage() override { return skillDamage; }
	bool GetIsDead() override { return isDead; }
	void TakeDamage(int hitPoints);
	int AttackPlayer();


private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	bool isDead;
	UI ui;
};