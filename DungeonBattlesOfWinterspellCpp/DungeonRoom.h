#pragma once
#include "IEnemy.h"
#include "UI.h"
#include <vector>
#include <string>
#include <iostream>

class DungeonRoom
{
private:
	std::string name;
	std::string description;
	bool completed;
	int roomLevel;
	bool isLocked;
	int timesExplored;
	std::vector<std::shared_ptr<IEnemy>> enemyList;
	std::vector<std::shared_ptr<ICreature>> currentTurnOrder;

public:
	DungeonRoom(std::string name, std::string description, int roomLevel, bool isLocked, std::vector<std::shared_ptr<IEnemy>> enemieList);

	std::string GetName() { return name; }
	bool GetCompleted() { return completed; }
	bool GetRoomLevel() { return roomLevel; }
	bool GetIsLocked() { return isLocked; }
	int GetTimesExplored() { return timesExplored; }
	std::string GetDescription() { return description; }
	std::vector<std::shared_ptr<ICreature>> GetTurnOrder() { return currentTurnOrder; }
	std::vector<std::shared_ptr<IEnemy>> GetEnemies() { return enemyList; }

	void SetCompleted();
	void SetTimesExplored();
	void SetIsLocked(bool isLocked);
	void SetCurrentTurnOrder(std::vector<std::shared_ptr<ICreature>> turnOrder) {
		currentTurnOrder = turnOrder;
	}
};