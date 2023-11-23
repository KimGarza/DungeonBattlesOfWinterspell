#include "DungeonRoom.h"

DungeonRoom::DungeonRoom(
	std::string name, 
	std::vector<std::shared_ptr<IEnemy>> enemyList
) : name(name), enemyList(enemyList), completed(false) {}