#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Weapon.h"
#include "ICreature.h"
#include "UI.h"
#include "LootItem.h"

class PlayerCharacter : public ICreature {
private:
	std::string name_;
	int health_;
	int intelligence_;
	int dexterity_;
	int strength_;
	int maxHealth_;
	std::shared_ptr<Weapon> weapon_;
	int xp_;
	int level_;
	bool hasSwiftness_;
	bool isDead_;
	int healthPotions_;
	std::vector<std::shared_ptr<LootItem>> loot_;
	std::vector<std::shared_ptr<LootItem>> equiptItems_;
	int armourRating_;
	int evasionRating_;
	int accuracyRating_;
	int addedSpellDamage_;
	int addedPhysicalDamage_;
	int spellResistance_;
	int gold_;

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
		std::shared_ptr<Weapon> weapon
	);

	PlayerCharacter(const PlayerCharacter& other);


	std::string GetName() { return name_; }
	int GetHealth() { return health_; }
	int GetMaxHealth() { return maxHealth_; }
	int GetIntelligence() { return intelligence_; }
	int GetDexterity() { return dexterity_; }
	int GetStrength() { return strength_; }
	std::shared_ptr<Weapon> GetWeapon() { return weapon_; }
	int GetXP() { return xp_; }
	int GetLevel() { return level_; }
	int GetHealthPotions() { return healthPotions_; }
	bool GetHasSwiftness() { return hasSwiftness_; }
	bool GetIsDead() { return isDead_; }
	std::vector<std::shared_ptr<LootItem>> GetLoot() { return loot_; }
	std::vector<std::shared_ptr<LootItem>> GetEquiptItems() { return equiptItems_; }
	int GetArmourRating() { return armourRating_; }
	int GetAccuracyRating() { return evasionRating_; }
	int GetEvasionRating() { return evasionRating_; }
	int GetElementalResistance() { return evasionRating_; }
	int GetGold() { return gold_; }

	float CheckDamageReduction(int incomingDmg);
	bool CheckEvadeChance(int attackersAccuracy);
	bool CheckIfDead();
	void CheckHasSwiftness();

	void AddToInventory(std::shared_ptr<LootItem> newItem);
	bool TakeDamage(int damageTaken, int enemyAccuracy);
	void DrinkHealthPotion();
	void SetHealthPotions(int healthPotion);
	void AddToInventory(std::vector<std::shared_ptr<LootItem>> newItems);
	void SetEquiptItems(std::shared_ptr<LootItem> item);
	void RemoveFromInventory(std::shared_ptr<LootItem> item);
	void SetGold(int gold);
};
