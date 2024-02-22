#include "LootItem.h"

LootItem::LootItem(std::string name, 
	ItemType itemType,
	std::string description, 
	int worthInGold) : name_(name), itemType_(itemType), description_(description), info_(""), 
	worthInGold_(worthInGold) {}

LootItem::LootItem(std::string name,
	ItemType itemType,
	std::string description,
	int worthInGold,
	int armourRating,
	int evasionRating) : name_(name), itemType_(itemType), description_(description), info_(""),
	worthInGold_(worthInGold), armourRating_(0), evasionRating_(evasionRating) {}

LootItem::LootItem(std::string name,
	ItemType itemType,
	std::string description,
	int worthInGold,
	int armourRating,
	int evasionRating,
	int addedDex,
	int addedStr,
	int addedInt,
	int spellDamage,
	int physDamage,
	int spellResistance) : name_(name), itemType_(itemType), description_(description), info_(""),
	worthInGold_(worthInGold), armourRating_(0), evasionRating_(evasionRating),
	addedDex_(addedDex), addedStr_(addedStr), addedInt_(addedInt), spellDamage_(spellDamage), 
	physDamage_(physDamage), spellResistance_(spellResistance) {}

void LootItem::SetArmourRating(int armourAdded) {
	armourRating_ += armourAdded;
}

void LootItem::SetInfo() {
	if (info_ == "") {
		info_ = "(Equipt)";
	}
	else {
		info_ = "";
	}
}

