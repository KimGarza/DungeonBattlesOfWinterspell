#include "DungeonRoom.h"

DungeonRoom::DungeonRoom(
	std::string name, 
	std::vector<std::shared_ptr<IEnemy>> enemyList
) : name(name), enemyList(enemyList), completed(false), description("wow cool dungeon area, here are enemies") {}

void DungeonRoom::SetCompleted() {
	completed = true;
}

//void SetCurrentTurnOrder();
