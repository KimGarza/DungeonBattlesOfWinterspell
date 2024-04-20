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
	int timesExplored_;
	std::vector<std::shared_ptr<INpc>> npcs_;
	bool completed_;
	int roomLvl_;
	bool isLocked_;
	std::vector<std::shared_ptr<Enemy>> enemies_;
	std::vector<std::shared_ptr<ICreature>> currentTurnOrder_;
	std::vector<std::shared_ptr<LootItem>> loot_;

public:
	DungeonRoom(
		std::string inName,
		std::string inDescription,
		int inRoomLevel,
		ActState inIsInAct,
		bool inIsLocked,
		std::vector<std::shared_ptr<INpc>> inNpcs,
		std::vector<std::shared_ptr<Enemy>> inEnemyList,
		std::vector<std::shared_ptr<LootItem>> inLoot) :
		name_(inName),
		description_(inDescription),
		roomLvl_(inRoomLevel),
		isLocked_(inIsLocked),
		completed_(false),
		isInAct_(inIsInAct),
		timesExplored_(0),
		npcs_(inNpcs),
		enemies_(inEnemyList),
		loot_(inLoot) {}

	std::string GetName() override { return name_; }
	std::string GetDescription() override { return description_; }
	ActState GetIsInAct() override { return isInAct_; }
	int GetTimesExplored() override { return timesExplored_; }
	std::vector<std::shared_ptr<INpc>> GetNpcs() override { return npcs_; }
	bool GetCompleted() { return completed_; }
	bool GetRoomLevel() { return roomLvl_; }
	bool GetIsLocked() { return isLocked_; }
	std::vector<std::shared_ptr<ICreature>> GetTurnOrder() { return currentTurnOrder_; }
	std::vector<std::shared_ptr<Enemy>> GetEnemy() { return enemies_; }
	std::vector<std::shared_ptr<LootItem>> GetLoot() { return loot_; }

	void SetTimesExplored() override { timesExplored_ += 1; }
	void SetNpcs(std::vector<std::shared_ptr<INpc>> inNpcs) override { npcs_ = inNpcs; }
	void SetTurnOrder(std::vector<std::shared_ptr<ICreature>> turnOrder) { currentTurnOrder_ = turnOrder; }
	void SetCompleted() { completed_ = true; }
	void SetIsLocked(bool inIsLocked) { isLocked_ = inIsLocked;}
};