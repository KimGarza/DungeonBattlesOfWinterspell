#pragma once
#include "GameContext.h"
#include "DungeonRoom.h"
#include "UI.h"
#include <memory>

class MapUpdateState
{
private:
	const std::shared_ptr<GameContext> context_;
	std::vector<std::shared_ptr<DungeonRoom>> rooms_;
	int roomsRemaining_;
	std::vector <std::string> roomNames_;
	std::shared_ptr<DungeonRoom> currentRoom_;

public:
	MapUpdateState(std::shared_ptr<GameContext> inContext) : context_(inContext) {}
	
	void UpdateMap();
	void Update();
	/* Setting all values from context. They cannot be setup in constructor since drilling
	into certain variables result in null exception due to Game.h declaring game states in constructor at entry point. */
	void SetValues();
};

