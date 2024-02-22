#include "DungeonRoom.h"

DungeonRoom::DungeonRoom(
	std::string name, 
	std::string description,
	int roomLevel,
	bool isLocked,
	std::vector<std::shared_ptr<Enemy>> enemyList,
	std::vector<std::shared_ptr<LootItem>> loot) : name_(name), description_(description), roomLevel_(roomLevel),
	isLocked_(isLocked), timesExplored_(0), enemyList_(enemyList), loot_(loot), completed_(false) {}

void DungeonRoom::SetCompleted() {
	completed_ = true;
}

void DungeonRoom::SetTimesExplored() {
	timesExplored_ += 1;
}
void DungeonRoom::SetIsLocked(bool isLocked) {
	isLocked = isLocked;
}