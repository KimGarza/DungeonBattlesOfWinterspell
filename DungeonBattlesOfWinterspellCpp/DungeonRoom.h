#pragma once
#include "IEnemy.h"
#include <vector>
#include <string>

class DungeonRoom
{
private:
	std::string name;
	bool completed;
	std::vector<IEnemy> enemyList;

public:
	DungeonRoom( std::string name, std::vector<IEnemy> enemyList );

	std::string GetName() { return name; }
};

