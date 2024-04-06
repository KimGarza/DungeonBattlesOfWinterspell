#pragma once
#include <memory>
#include "..\..\Game\GameContext.h"
#include "..\..\Actors\DungeonRoom.h"

class MapRevealState
{
private:
	const std::shared_ptr<GameContext> context_;
	std::vector<std::shared_ptr<DungeonRoom>> rooms_;
	int roomsRemaining_;
	std::vector <std::string> roomNames_;
	std::shared_ptr<DungeonRoom> currentRoom_;
	UI ui;

public:
	MapRevealState(std::shared_ptr<GameContext> inContext) : context_(inContext) {}

	void RevealMap();
	void RoomSelect();
	/* Setting all values from context. They cannot be setup in constructor since drilling
	into certain variables result in null exception due to Game.h declaring game states in constructor at entry point.
	Considering alternatives to reduce duplicate code */
	void SetValues();

};

