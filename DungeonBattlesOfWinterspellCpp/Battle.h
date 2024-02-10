#pragma once
#include "ICreature.h"
#include "DungeonRoom.h"
#include "UI.h"
#include <vector>
#include <iostream>

class Battle
{
private:
	UI ui;
	std::shared_ptr<DungeonRoom> currentRoom;

public:
	Battle(std::shared_ptr<DungeonRoom> currentRoom);

	void RevealTurnOrder();
	void CommenceBattle(std::shared_ptr<PlayerCharacter> playerCharacter);
};

