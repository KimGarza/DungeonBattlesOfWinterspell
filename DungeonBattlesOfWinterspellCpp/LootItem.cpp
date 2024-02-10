#include "LootItem.h"

LootItem::LootItem(std::string name, 
	ItemType itemType,
	std::string description, 
	int worthInGold) : name(name), itemType(itemType), description(description), worthInGold(worthInGold), armourRating(0) {}

LootItem::LootItem(std::string name,
	ItemType itemType,
	std::string description,
	int worthInGold,
	int armourRating) : name(name), itemType(itemType), description(description), worthInGold(worthInGold), armourRating(armourRating) {}


void LootItem::SetArmourRating(int armourAdded) {
	armourRating += armourAdded;
}