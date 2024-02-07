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
	std::vector<std::shared_ptr<IEnemy>> enemyList;
	std::vector<std::shared_ptr<ICreature>> currentTurnOrder;

public:
	DungeonRoom(std::string name, std::string description, int roomLevel, std::vector<std::shared_ptr<IEnemy>> enemieList);

	std::string GetName() { return name; }
	bool GetCompleted() { return completed; }
	bool GetRoomLevel() { return roomLevel; }
	std::string GetDescription() { return description; }
	std::vector<std::shared_ptr<ICreature>> GetTurnOrder() { return currentTurnOrder; }
	std::vector<std::shared_ptr<IEnemy>> GetEnemies() { return enemyList; }

	void SetCompleted();
	void SetCurrentTurnOrder(std::vector<std::shared_ptr<ICreature>> turnOrder) {
		currentTurnOrder = turnOrder;
	}
};