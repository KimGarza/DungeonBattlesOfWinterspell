#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Weapon.h"
#include "..\Helper\UI.h"
#include "ICreature.h"
#include "LootItem.h"

class PlayerCharacter : public ICreature {
private:
	std::string name;
	int health;
	int intelligence;
	int dexterity;
	int strength;
	int maxHealth;
	std::shared_ptr<Weapon> weapon;
	int xp;
	int level;
	bool hasSwiftness;
	bool isDead;
	int healthPotions;
	std::vector<std::shared_ptr<LootItem>> loot;
	std::vector<std::shared_ptr<LootItem>> equiptItems;
	int armourRating;
	int evasionRating;
	int accuracyRating;
	int addedSpellDamage;
	int addedPhysicalDamage;
	int spellResistance;
	int gold;

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
		int armourRating,
		int evasionRating,
		std::shared_ptr<Weapon> weapon
	);

	PlayerCharacter(const PlayerCharacter& other);


	std::string GetName() { return name; }
	int GetHealth() { return health; }
	int GetMaxHealth() { return maxHealth; }
	int GetIntelligence() { return intelligence; }
	int GetDexterity() { return dexterity; }
	int GetStrength() { return strength; }
	std::shared_ptr<Weapon> GetWeapon() { return weapon; }
	int GetXP() { return xp; }
	int GetLevel() { return level; }
	int GetHealthPotions() { return healthPotions; }
	bool GetHasSwiftness() { return hasSwiftness; }
	bool GetIsDead() { return isDead; }
	std::vector<std::shared_ptr<LootItem>> GetLoot() { return loot; }
	std::vector<std::shared_ptr<LootItem>> GetEquiptItems() { return equiptItems; }
	void AddToInventory(std::shared_ptr<LootItem> newItem);
	int GetArmourRating() { return armourRating; }
	int GetAccuracyRating() { return evasionRating; }
	int GetEvasionRating() { return evasionRating; }
	int GetElementalResistance() { return evasionRating; }
	int GetGold() { return gold; }

	float CheckDamageReduction(int incomingDmg);
	bool CheckEvadeChance(int attackersAccuracy);

	bool TakeDamage(int damageTaken, int enemyAccuracy);
	bool CheckIfDead();
	void DrinkHealthPotion();
	void SetHealthPotions(int healthPotion);
	void AddToInventory(std::vector<std::shared_ptr<LootItem>> newItems);
	void SetEquiptItems(std::shared_ptr<LootItem> item);
	void RemoveFromInventory(std::shared_ptr<LootItem> item);
	void SetGold(int gold);
	void CheckHasSwiftness();
};
