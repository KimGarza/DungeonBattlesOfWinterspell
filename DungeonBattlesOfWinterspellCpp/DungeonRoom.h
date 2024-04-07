#pragma once
#include "Enemy.h"
#include "IPlace.h"
#include "LootItem.h"
#include "UI.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

class DungeonRoom : public IPlace
{
private:
	std::string name_;
	std::string description_;
	ActState isInAct_;
	bool completed;
	int roomLevel;
	bool isLocked;
	int timesExplored_;
	std::vector<std::shared_ptr<Enemy>> enemyList;
	std::vector<std::shared_ptr<ICreature>> currentTurnOrder;
	std::vector<std::shared_ptr<LootItem>> loot;

public:
	DungeonRoom(
		std::string inName,
		std::string inDescription,
		int inRoomLevel,
		bool inIsLocked,
		std::vector<std::shared_ptr<Enemy>> inEnemyList,
		std::vector<std::shared_ptr<LootItem>> inLoot) : 
		name_(inName), description_(inDescription), roomLevel(inRoomLevel), isLocked(inIsLocked), 
		timesExplored_(0), enemyList(inEnemyList), loot(inLoot), completed(false) {}

	virtual ActState GetIsInAct() { return isInAct_; }
	std::string GetName() { return name_; }
	bool GetCompleted() { return completed; }
	bool GetRoomLevel() { return roomLevel; }
	bool GetIsLocked() { return isLocked; }
	int GetTimesExplored() { return timesExplored_; }
	std::string GetDescription() { return description_; }
	std::vector<std::shared_ptr<ICreature>> GetTurnOrder() { return currentTurnOrder; }
	std::vector<std::shared_ptr<Enemy>> GetEnemy() { return enemyList; }
	std::vector<std::shared_ptr<LootItem>> GetLoot() { return loot; }

	void SetName(std::string inName) override { name_ = inName; }
	void SetDescription(std::string inDescription) override { description_ = inDescription; }
	void SetIsInAct(ActState inIsInAct) override { isInAct_ = inIsInAct; }
	void SetTimesExplored() override { timesExplored_ += 1; }
	void SetCompleted();
	void SetIsLocked(bool isLocked);
	void SetTurnOrder(std::vector<std::shared_ptr<ICreature>> turnOrder) {
		currentTurnOrder = turnOrder;
	}
	void SetLoot();


	

	void SetCompleted() { completed = true;	}
	void SetIsLocked(bool isLocked) {
		isLocked = isLocked;
	}
};