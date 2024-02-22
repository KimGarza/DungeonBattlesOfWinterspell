#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() {}

PlayerCharacter::PlayerCharacter(
	std::string inName,
	int inHealth,
	int inIntelligence,
	int inDexterity,
	int inStrength,
	int maxHealth_,
	bool hasSwiftness_,
	std::shared_ptr<Weapon> inWeapon
) : name_(inName), health_(inHealth), intelligence_(inIntelligence), dexterity_(inDexterity), strength_(inStrength), maxHealth_(maxHealth_),
hasSwiftness_(hasSwiftness_), armourRating_(0), evasionRating_(0), weapon_(inWeapon), xp_(0), level_(1), isDead_(false), healthPotions_(2), gold_(0) {}

// don't remember writing this but perhaps related to default values somewhere??
PlayerCharacter::PlayerCharacter(const PlayerCharacter& other) : name_(other.name_), health_(other.health_), intelligence_(other.intelligence_),
dexterity_(other.dexterity_), strength_(other.strength_), weapon_(other.weapon_),
xp_(0), level_(1), hasSwiftness_(other.hasSwiftness_), armourRating_(0), evasionRating_(0), isDead_(false) {}
// copy or clone other members if needed

bool PlayerCharacter::TakeDamage(int damageTaken, int enemyAccuracy) {

	bool evades = CheckEvadeChance(enemyAccuracy);

	float dmgReduction = CheckDamageReduction(damageTaken);
	health_ -= (damageTaken - (damageTaken * dmgReduction));

	return CheckIfDead();
}

bool PlayerCharacter::CheckIfDead() {
	if (health_ < 1) {
		health_ = 0;
		isDead_ = true;
		return true;
	}
	return false;
}

void PlayerCharacter::DrinkHealthPotion() {

	if (health_ + 20 > maxHealth_) {
		health_ = maxHealth_;
	}
	else {
		health_ += 20;
	}

	healthPotions_ -= 1;
}

void PlayerCharacter::AddToInventory(std::vector<std::shared_ptr<LootItem>> newItems) {
	
	for (const auto& item : newItems) {
		if (item->GetItemType() != ItemType::HealthPotion) {
			loot_.push_back(item);
		}
		else if (item->GetName() == "Gold Coin") {
			gold_ += 1;
		}
		else {
			healthPotions_ += 1;
		}
	}
}

void PlayerCharacter::AddToInventory(std::shared_ptr<LootItem> newItem) {

	if (newItem->GetItemType() != ItemType::HealthPotion) {
		loot_.push_back(newItem);
	}
	else {
		healthPotions_ += 1;
	}
}

void PlayerCharacter::RemoveFromInventory(std::shared_ptr<LootItem> item) {

	// first check if it is equipped
	auto checkEquipItem = std::find_if(equiptItems_.begin(), equiptItems_.end(), [item](const std::shared_ptr<LootItem>& invItem) {
		return invItem == item;
		});

	if (checkEquipItem != equiptItems_.end()) {
		equiptItems_.erase(checkEquipItem);
	}
	// then delete regardless
	auto checkInvItem = std::find_if(loot_.begin(), loot_.end(), [item](const std::shared_ptr<LootItem>& invItem) {
		return invItem == item;
		});

	if (checkInvItem != loot_.end()) {
		loot_.erase(checkInvItem);
	}
}

void PlayerCharacter::SetHealthPotions(int health_Potion) {
	healthPotions_ += health_Potion;
}

/// <summary>
/// Check if the particular pointer of incoming item already exists in player's equiptItems,
/// if so, it is equipt so player has chosen to unequipt i. Erase it from equiptItems, otherwise, equip it.
/// Subtract or add armour rating if any
/// </summary>
/// <param name_="item"></param>
void PlayerCharacter::SetEquiptItems(std::shared_ptr<LootItem> item) {

	// checking if exact item object is euipt, if yes, unequip it. Or else, equip it. Idk how to spell equipt.
	auto checkSamePtrItem = std::find_if(equiptItems_.begin(), equiptItems_.end(), [item](const std::shared_ptr<LootItem>& invItem) { // specifically if this item in memory is equipt already
		return invItem == item;
		});

	auto checkIfSameItem = std::find_if(equiptItems_.begin(), equiptItems_.end(), [item](const std::shared_ptr<LootItem>& invItem) { // if this item isn't physically equipt but is a duplicate of one that is
		return invItem->GetName() == item->GetName();
		});

	if (checkSamePtrItem != equiptItems_.end()) {
		armourRating_ -= item->GetArmourRating();
		equiptItems_.erase(checkSamePtrItem);

		if (item->GetName() == "Boots of Swiftness") {
			dexterity_ -= 4;
			CheckHasSwiftness();
		}

		item->SetInfo();
	}
	else if (checkIfSameItem != equiptItems_.end()) {
		UI ui;
		ui.AlreadyEquiptItem();
	}
	else {
		equiptItems_.push_back(item);
		armourRating_ += item->GetArmourRating();
		evasionRating_ += item->GetEvasionRating();
		
		if (item->GetName() == "Boots of Swiftness") {
			dexterity_ += 4; // rather than setting has swiftness to true in case player would have it even without boots
			hasSwiftness_ = true;
		}

		item->SetInfo();
		spellResistance_ += item->GetSpellResistance();
		addedSpellDamage_ += item->GetSpellDamage();
		addedPhysicalDamage_ += item->GetPhysicalDamage();
		intelligence_ += item->GetAddedInt();
		strength_ += item->GetAddedStr();
		dexterity_ += item->GetAddedDex(); /**/ CheckHasSwiftness();
	}
}

// formula inspired by path of exile's dmg reduction from armour in order to use experienced algorith for diminishing return
// on reduction rating, this is so that armour reduction can never block 100% of damage
float PlayerCharacter::CheckDamageReduction(int incomingDmg) {
	
	return armourRating_ / ((100 * incomingDmg) + armourRating_);
}

bool PlayerCharacter::CheckEvadeChance(int attackersAccuracy) {
	return false;
	//float evasionChance = evasionRating_ + (attackersAccuracy * 4) / evasionRating_;

	//std::random_device rd; // Obtain a random number from hardware
	//std::mt19937 eng(rd()); // Seed the generator
	//std::uniform_real_distribution<> distr(0.0, 1.0); // Define the range

	//double randomValue = distr(eng);

	//if (Random.value > evadeChance) { // Assuming Random.value returns a float between 0 and 1
	//	float dmgReduction = CheckDamageReduction(damageTaken);
	//	health_ -= (damageTaken - (damageTaken * dmgReduction));
	//}
	//else {
	//	// Attack was evaded, so no damage is taken
	//}
}

void PlayerCharacter::SetGold(int inGold) {
	gold_ += inGold;
}

void PlayerCharacter::CheckHasSwiftness() {
	if (dexterity_ >= 4) {
		hasSwiftness_ = true;
	}
	else {
		hasSwiftness_ = false;
	}
}