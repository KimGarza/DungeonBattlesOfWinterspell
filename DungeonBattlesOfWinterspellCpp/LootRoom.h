#pragma once
#include "UI.h";
#include "DungeonRoom.h"

class LootRoom
{
private:
	UI ui;
	std::shared_ptr<DungeonRoom> currentRoom;

public:
	void Loot(std::shared_ptr<PlayerCharacter> playerCharacter, std::shared_ptr<DungeonRoom> currentRoom);
};

