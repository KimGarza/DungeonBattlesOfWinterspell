#include "DungeonRoom.h"

DungeonRoom::DungeonRoom(
	std::string name, 
	std::string description,
	int roomLevel,
	bool isLocked,
	std::vector<std::shared_ptr<Enemy>> enemyList,
	std::vector<std::shared_ptr<LootItem>> loot) : name(name), description(description), roomLevel(roomLevel), isLocked(isLocked), timesExplored(0), enemyList(enemyList), loot(loot), completed(false) {}

void DungeonRoom::SetCompleted() {
	completed = true;
}

void DungeonRoom::SetTimesExplored() {
	timesExplored += 1;
}
void DungeonRoom::SetIsLocked(bool isLocked) {
	isLocked = isLocked;
}