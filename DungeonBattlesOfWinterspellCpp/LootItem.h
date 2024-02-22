#pragma once
#include <string>
#include "ItemTypes.h"

class LootItem
{
private:
	std::string name_;
	ItemType itemType_;
	std::string description_;
	std::string info_; // whether it is equipt or not
	int worthInGold_;
	int armourRating_;
	int evasionRating_;
	int spellDamage_;
	int physDamage_;
	int addedDex_;
	int addedStr_;
	int addedInt_;
	float spellResistance_;


public:
	LootItem(std::string name, ItemType itemType, std::string description, int worthInGold);
	LootItem(std::string name, ItemType itemType, std::string description, int worthInGold, int armourRating, int evasionRating);
	LootItem(std::string name, ItemType itemType, std::string description, int worthInGold, int armourRating, int evasionRating, 
		int addedDex, int addedStr, int addedInt, int spellDamage, int physDamage, int spellResistance);

	std::string GetName() { return name_; }
	ItemType GetItemType() { return itemType_; }
	std::string GetDescription() { return description_; }
	std::string GetInfo() { return info_; }
	int GetWorthInGold() { return worthInGold_; }
	int GetArmourRating() { return armourRating_; }
	int GetEvasionRating() { return evasionRating_; }
	int GetSpellDamage() { return spellDamage_; }
	int GetPhysDamage() { return physDamage_; }
	int GetAddedDex() { return addedDex_; }
	int GetAddedStr() { return addedStr_; }
	int GetAddedInt() { return addedInt_; }
	float GetSpellResistance() { return spellResistance_;  }
	int GetPhysicalDamage() { return physDamage_;  }

	void SetArmourRating(int armourAdded);
	void SetInfo();
};

