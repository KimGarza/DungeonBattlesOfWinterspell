#pragma once
#include "IEnemy.h"
#include <vector>
#include <string>
#include <iostream>

class DungeonRoom
{
private:
	std::string name;
	bool completed;
	std::vector<std::shared_ptr<IEnemy>> enemyList;

public:
	DungeonRoom(std::string name, std::vector<std::shared_ptr<IEnemy>> enemieList);

	std::string GetName() { return name; }
	bool GetCompleted() { return completed; }
	std::vector<std::shared_ptr<IEnemy>> GetEnemies() { return enemyList; }
};