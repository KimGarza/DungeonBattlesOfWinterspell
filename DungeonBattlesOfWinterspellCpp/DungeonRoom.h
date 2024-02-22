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
	std::string name_;
	std::string description_;
	bool completed_;
	int roomLevel_;
	bool isLocked_;
	int timesExplored_;
	std::vector<std::shared_ptr<Enemy>> enemyList_;
	std::vector<std::shared_ptr<ICreature>> currentTurnOrder_;
	std::vector<std::shared_ptr<LootItem>> loot_;

public:
	DungeonRoom(std::string name, 
		std::string description, 
		int roomLevel, bool isLocked, 
		std::vector<std::shared_ptr<Enemy>> enemieList, 
		std::vector<std::shared_ptr<LootItem>> loot);

	std::string GetName() { return name_; }
	std::string GetDescription() { return description_; }
	bool GetCompleted() { return completed_; }
	bool GetRoomLevel() { return roomLevel_; }
	bool GetIsLocked() { return isLocked_; }
	int GetTimesExplored() { return timesExplored_; }
	std::vector<std::shared_ptr<ICreature>> GetTurnOrder() { return currentTurnOrder_; }
	std::vector<std::shared_ptr<Enemy>> GetEnemy() { return enemyList_; }
	std::vector<std::shared_ptr<LootItem>> GetLoot() { return loot_; }


	void SetCompleted();
	void SetTimesExplored();
	void SetIsLocked(bool isLocked);
	void SetCurrentTurnOrder(std::vector<std::shared_ptr<ICreature>> turnOrder) {
		currentTurnOrder_ = turnOrder;
	}
	void SetLoot();

};