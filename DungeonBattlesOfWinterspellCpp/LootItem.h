#pragma once
#include <string>
#include "ItemTypes.h"

class LootItem
{
private:
	std::string name;
	ItemType itemType;
	std::string description;
	std::string info; // whether it is equipt or not
	int worthInGold;
	int armourRating;
	int evasionRating;
	int spellDamage;
	int physDamage;
	int addedDex;
	int addedStr;
	int addedInt;


public:
	LootItem(std::string name, ItemType itemType, std::string description, int worthInGold);
	LootItem(std::string name, ItemType itemType, std::string description, int worthInGold, int armourRating, int evasionRating);
	LootItem(std::string name, ItemType itemType, std::string description, int worthInGold, int armourRating, int evasionRating, int addedDex, int addedStr, int addedInt, int spellDamage, int physDamage);

	std::string GetName() { return name; }
	ItemType GetItemType() { return itemType; }
	std::string GetDescription() { return description; }
	std::string GetInfo() { return info; }
	int GetWorthInGold() { return worthInGold; }
	int GetArmourRating() { return armourRating; }
	int GetEvasionRating() { return evasionRating; }
	int GetSpellDamage() { return spellDamage; }
	int GetPhysDamage() { return physDamage; }
	int GetAddedDex() { return addedDex; }
	int GetAddedStr() { return addedStr; }
	int GetAddedInt() { return addedInt; }

	void SetArmourRating(int armourAdded);
	void SetInfo();

};

