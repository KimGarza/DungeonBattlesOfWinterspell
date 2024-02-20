#pragma once
#include "Enemy.h"
#include "LootItem.h"
#include "UI.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

class DungeonRoom
{
private:
	std::string name;
	std::string description;
	bool completed;
	int roomLevel;
	bool isLocked;
	int timesExplored;
	std::vector<std::shared_ptr<Enemy>> enemyList;
	std::vector<std::shared_ptr<ICreature>> currentTurnOrder;
	std::vector<std::shared_ptr<LootItem>> loot;

public:
	DungeonRoom(std::string name, 
		std::string description, 
		int roomLevel, bool isLocked, 
		std::vector<std::shared_ptr<Enemy>> enemieList, 
		std::vector<std::shared_ptr<LootItem>> loot);

	std::string GetName() { return name; }
	bool GetCompleted() { return completed; }
	bool GetRoomLevel() { return roomLevel; }
	bool GetIsLocked() { return isLocked; }
	int GetTimesExplored() { return timesExplored; }
	std::string GetDescription() { return description; }
	std::vector<std::shared_ptr<ICreature>> GetTurnOrder() { return currentTurnOrder; }
	std::vector<std::shared_ptr<Enemy>> GetEnemy() { return enemyList; }
	std::vector<std::shared_ptr<LootItem>> GetLoot() { return loot; }


	void SetCompleted();
	void SetTimesExplored();
	void SetIsLocked(bool isLocked);
	void SetCurrentTurnOrder(std::vector<std::shared_ptr<ICreature>> turnOrder) {
		currentTurnOrder = turnOrder;
	}
	void SetLoot();

};