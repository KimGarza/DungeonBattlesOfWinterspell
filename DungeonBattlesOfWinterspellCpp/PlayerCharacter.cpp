#include "PlayerCharacter.h"
#include <memory>

// Initial assigned attributes: 4, total assigned additional by player 10
// 1. Values passed into construc during playerCharacter creation. The ones xp, level, swift, dead is to be assigned in the assignment section without expecting them to come in
PlayerCharacter::PlayerCharacter() {}

PlayerCharacter::PlayerCharacter(
	std::string inName,
	int inHealth,
	int inIntelligence,
	int inDexterity,
	int inStrength,
	int maxHealth,
	bool hasSwiftness,
	std::shared_ptr<IWeapon> inWeapon
	// 2. Assigning the priv member variables we declared in header as the in[argValue] and assigning manual initial values to level, xp, etc...
	// In the constructor source, the colon : is used to initiate a member initializer list. It's used to initialize the member variables of a class with values provided to the constructor.
	// After the : is the assignment secition
) : name(inName), health(inHealth), intelligence(inIntelligence), dexterity(inDexterity), strength(inStrength), maxHealth(maxHealth),
hasSwiftness(hasSwiftness), weapon(inWeapon), xp(0), level(1), isDead(false), healthPotions(2), armour(0) {}

PlayerCharacter::PlayerCharacter(const PlayerCharacter& other) : name(other.name), health(other.health), intelligence(other.intelligence),
dexterity(other.dexterity), strength(other.strength), weapon(other.weapon),
xp(0), level(1), hasSwiftness(other.hasSwiftness), isDead(false) {}
	// Copy or clone other members if needed

bool PlayerCharacter::TakeDamage(int damageTaken) {
	health -= damageTaken;
	return CheckIfDead();
}

bool PlayerCharacter::CheckIfDead() {
	if (health < 1) {
		health = 0;
		isDead = true;
		return true;
	}
	return false;
}

void PlayerCharacter::DrinkHealthPotion() {

	if (health + 20 > maxHealth) {
		health = maxHealth;
	}
	else {
		health += 20;
	}

	healthPotions -= 1;
}

void PlayerCharacter::AddToInventory(std::vector<std::shared_ptr<LootItem>> newItems) {
	
	for (const auto& item : newItems) {
		if (item->GetItemType() != ItemType::HealthPotion) {
			loot.push_back(item);
		}
		else {
			healthPotions += 1;
		}
	}
}

void PlayerCharacter::RemoveFromInventory(std::shared_ptr<LootItem> item) {

	// first check if it is equipped
	auto checkEquipItem = std::find_if(equiptItems.begin(), equiptItems.end(), [item](const std::shared_ptr<LootItem>& invItem) {
		return invItem == item;
		});

	if (checkEquipItem != equiptItems.end()) {
		equiptItems.erase(checkEquipItem);
	}
	// then delete regardless
	auto checkInvItem = std::find_if(loot.begin(), loot.end(), [item](const std::shared_ptr<LootItem>& invItem) {
		return invItem == item;
		});

	if (checkInvItem != loot.end()) {
		loot.erase(checkInvItem);
	}
}

void PlayerCharacter::SetHealthPotions(int healthPotion) {
	healthPotions += healthPotion;
}

/// <summary>
/// Check if the particular pointer of incoming item already exists in player's equiptItems,
/// if so, it is equipt so player has chosen to unequipt i. Erase it from equiptItems, otherwise, equip it.
/// Subtract or add armour rating if any
/// </summary>
/// <param name="item"></param>
void PlayerCharacter::SetEquiptItems(std::shared_ptr<LootItem> item) {

	auto checkItem = std::find_if(equiptItems.begin(), equiptItems.end(), [item](const std::shared_ptr<LootItem>& invItem) {
		return invItem == item;
		});

	if (checkItem != equiptItems.end()) {
		armour -= item->GetArmourRating();
		equiptItems.erase(checkItem);
	}
	else {
		equiptItems.push_back(item);
		armour += item->GetArmourRating();
		//armour += item->GetElementalProtection();
		//armour += item->GetEvasionRating();
	}

}