#pragma once
#include "IEnemy.h"
#include "UI.h"
#include <vector>
#include <string>
#include <iostream>

class DungeonRoom
{
private:
	UI ui;
	std::string name;
	bool completed;
	std::string description;
	std::vector<std::shared_ptr<IEnemy>> enemyList;
	std::vector<std::shared_ptr<ICreature>> currentTurnOrder;

public:
	DungeonRoom(std::string name, std::vector<std::shared_ptr<IEnemy>> enemieList);

	std::string GetName() { return name; }
	bool GetCompleted() { return completed; }
	std::string GetDescription() { return description; }
	std::vector<std::shared_ptr<ICreature>> GetTurnOrder() { return currentTurnOrder; }

	void SetCurrentTurnOrder(std::vector<std::shared_ptr<ICreature>> turnOrder) {
		currentTurnOrder = turnOrder;
	}

	std::vector<std::shared_ptr<IEnemy>> GetEnemies() { return enemyList; }


	void SetCompleted();

};