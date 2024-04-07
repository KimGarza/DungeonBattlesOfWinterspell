#include "PlayerCharacter.h"
#include "UI.h"
#include <memory>

PlayerCharacter::PlayerCharacter() {}

PlayerCharacter::PlayerCharacter(
	std::string inName,
	int inHealth,
	int inIntelligence,
	int inDexterity,
	int inStrength,
	int maxHealth,
	bool hasSwiftness,
	int armourRating,
	int evasionRating,
	std::shared_ptr<Weapon> inWeapon
) : name(inName), health(inHealth), intelligence(inIntelligence), dexterity(inDexterity), strength(inStrength), maxHealth(maxHealth),
hasSwiftness(hasSwiftness), armourRating(armourRating), evasionRating(evasionRating), weapon(inWeapon), xp(0), level(1), isDead(false), healthPotions(2), gold(0) {}

// don't remember writing this but perhaps related to default values somewhere??
PlayerCharacter::PlayerCharacter(const PlayerCharacter& other) : name(other.name), health(other.health), intelligence(other.intelligence),
dexterity(other.dexterity), strength(other.strength), weapon(other.weapon),
xp(0), level(1), hasSwiftness(other.hasSwiftness), armourRating(armourRating), evasionRating(evasionRating), isDead(false) {}
	// Copy or clone other members if needed

bool PlayerCharacter::TakeDamage(int damageTaken, int enemyAccuracy) {

	bool evades = CheckEvadeChance(enemyAccuracy);


	float dmgReduction = CheckDamageReduction(damageTaken);
	health -= (damageTaken - (damageTaken * dmgReduction));

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
		else if (item->GetName() == "Gold Coin") {
			gold += 1;
		}
		else {
			healthPotions += 1;
		}
	}
}

void PlayerCharacter::AddToInventory(std::shared_ptr<LootItem> newItem) {

	if (newItem->GetItemType() != ItemType::HealthPotion) {
		loot.push_back(newItem);
	}
	else {
		healthPotions += 1;
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

	// checking if exact item object is euipt, if yes, unequip it. Or else, equip it. Idk how to spell equipt.
	auto checkSamePtrItem = std::find_if(equiptItems.begin(), equiptItems.end(), [item](const std::shared_ptr<LootItem>& invItem) { // specifically if this item in memory is equipt already
		return invItem == item;
		});

	auto checkIfSameItem = std::find_if(equiptItems.begin(), equiptItems.end(), [item](const std::shared_ptr<LootItem>& invItem) { // if this item isn't physically equipt but is a duplicate of one that is
		return invItem->GetName() == item->GetName();
		});

	if (checkSamePtrItem != equiptItems.end()) {
		armourRating -= item->GetArmourRating();
		equiptItems.erase(checkSamePtrItem);

		if (item->GetName() == "Boots of Swiftness") {
			dexterity -= 4;
			CheckHasSwiftness();
		}

		item->SetInfo();
	}
	else if (checkIfSameItem != equiptItems.end()) {
		UI ui;
		ui.AlreadyEquiptItem();
	}
	else {
		equiptItems.push_back(item);
		armourRating += item->GetArmourRating();
		evasionRating += item->GetEvasionRating();
		
		if (item->GetName() == "Boots of Swiftness") {
			dexterity += 4; // rather than setting has swiftness to true in case player would have it even without boots
			hasSwiftness = true;
		}

		item->SetInfo();
		spellResistance += item->GetSpellResistance();
		addedSpellDamage += item->GetSpellDamage();
		addedPhysicalDamage += item->GetPhysicalDamage();
		intelligence += item->GetAddedInt();
		strength += item->GetAddedStr();
		dexterity += item->GetAddedDex(); /**/ CheckHasSwiftness();
	}
}

// formula inspired by path of exile's dmg reduction from armour in order to use experienced algorith for diminishing return
// on reduction rating, this is so that armour reduction can never block 100% of damage
float PlayerCharacter::CheckDamageReduction(int incomingDmg) {
	
	return armourRating / ((100 * incomingDmg) + armourRating);
}

bool PlayerCharacter::CheckEvadeChance(int attackersAccuracy) {
	return false;
	//float evasionChance = evasionRating + (attackersAccuracy * 4) / evasionRating;

	//std::random_device rd; // Obtain a random number from hardware
	//std::mt19937 eng(rd()); // Seed the generator
	//std::uniform_real_distribution<> distr(0.0, 1.0); // Define the range

	//double randomValue = distr(eng);

	//if (Random.value > evadeChance) { // Assuming Random.value returns a float between 0 and 1
	//	float dmgReduction = CheckDamageReduction(damageTaken);
	//	health -= (damageTaken - (damageTaken * dmgReduction));
	//}
	//else {
	//	// Attack was evaded, so no damage is taken
	//}
}

void PlayerCharacter::SetGold(int inGold) {
	gold += inGold;
}

void PlayerCharacter::CheckHasSwiftness() {
	if (dexterity >= 4) {
		hasSwiftness = true;
	}
	else {
		hasSwiftness = false;
	}
}