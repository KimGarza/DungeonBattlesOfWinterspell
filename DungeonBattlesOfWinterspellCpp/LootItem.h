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
	double worthInGold;
	int armourRating;

public:
	LootItem(std::string name, ItemType itemType, std::string description, int worthInGold);
	LootItem(std::string name, ItemType itemType, std::string description, int worthInGold, int armourRating);

	std::string GetName() { return name; }
	ItemType GetItemType() { return itemType; }
	std::string GetDescription() { return description; }
	std::string GetInfo() { return info; }
	double GetWorthInGold() { return worthInGold; }
	double GetArmourRating() { return armourRating; }

	void SetArmourRating(int armourAdded);
	void SetInfo();

};

