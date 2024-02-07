#include "DungeonRoom.h"

DungeonRoom::DungeonRoom(
	std::string name, 
	std::string description,
	int roomLevel,
	std::vector<std::shared_ptr<IEnemy>> enemyList
) : name(name), description(description), roomLevel(roomLevel), enemyList(enemyList), completed(false) {}

void DungeonRoom::SetCompleted() {
	completed = true;
}