#pragma once
#include "UI.h";
#include "DungeonRoom.h"

class LootRoom
{
private:
	UI ui;
	std::shared_ptr<DungeonRoom> currentRoom;

public:
	LootRoom(std::shared_ptr<DungeonRoom> currentRoom);

	void Loot();
};

