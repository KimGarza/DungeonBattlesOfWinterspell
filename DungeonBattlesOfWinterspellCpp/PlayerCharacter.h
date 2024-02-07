#pragma once
#include <vector>
#include <memory>
#include <string>
#include "IWeapon.h"
#include "InvItem.h"
#include "ICreature.h"

class PlayerCharacter : public ICreature {
// 1. Private values make one for every property you want to describe/define your class
private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	int maxHealth;
	std::shared_ptr<IWeapon> weapon;
	int xp;
	int level;
	bool hasSwiftness;
	bool isDead;
	int healthPotions;

// 2. Preparing all values that will come through constructor ( we want xp, level, swift and dead to not be passed in we already know what these will be to start)
public:
	PlayerCharacter();

	PlayerCharacter( 
		std::string name,
		int health,
		int intelligence,
		int dexterity,
		int strength,
		int maxHealth,
		bool hasSwiftness,
		std::shared_ptr<IWeapon> weapon
		// 3. The reason these are not set here is bc they will be set with default values in source and managed within functions after
		/*int xp = 0, int level = 1, bool hasSwiftness = false, bool isDead = false*/
	);

	PlayerCharacter(const PlayerCharacter& other);


	std::string GetName() { return name; }
	int GetHealth() { return health; }
	int GetMaxHealth() { return maxHealth; }
	int GetIntelligence() { return intelligence; }
	int GetDexterity() { return dexterity; }
	int GetStrength() { return strength; }
	std::shared_ptr<IWeapon> GetWeapon() { return weapon; }
	int GetXP() { return xp; }
	int GetLevel() { return level; }
	int GetHealthPotions() { return healthPotions; }
	bool GetHasSwiftness() { return hasSwiftness; }
	bool GetIsDead() { return isDead; }

	bool TakeDamage(int damageTaken);
	bool CheckIfDead();
	void DrinkHealthPotion();
};
