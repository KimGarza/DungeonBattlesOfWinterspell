#include "LootItem.h"

LootItem::LootItem(std::string name, 
	ItemType itemType,
	std::string description, 
	int worthInGold) : name(name), itemType(itemType), description(description), info(""), worthInGold(worthInGold), armourRating(0) {}

LootItem::LootItem(std::string name,
	ItemType itemType,
	std::string description,
	int worthInGold,
	int armourRating,
	int evasionRating) : name(name), itemType(itemType), description(description), info(""), worthInGold(worthInGold), armourRating(armourRating), evasionRating(evasionRating) {}

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
	int spellResistance) : name(name), itemType(itemType), description(description), info(""), worthInGold(worthInGold), armourRating(armourRating), evasionRating(evasionRating), 
	addedDex(addedDex), addedStr(addedStr), addedInt(addedInt), spellDamage(spellDamage), physDamage(physDamage), spellResistance(spellResistance) {}

void LootItem::SetArmourRating(int armourAdded) {
	armourRating += armourAdded;
}

void LootItem::SetInfo() {
	if (info == "") {
		info = "(Equipt)";
	}
	else {
		info = "";
	}
}

