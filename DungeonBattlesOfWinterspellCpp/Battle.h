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
	std::vector<std::shared_ptr<ICreature>> turnOrder;

public:
	Battle(std::vector<std::shared_ptr<ICreature>> turnOrder);
	Battle();

	void RevealTurnOrder(std::vector<std::shared_ptr<ICreature>> turnOrder, std::string dungeonRoomName);
	void CommenceBattle(std::shared_ptr<PlayerCharacter> playerCharacter);
	void ChangelingFight(std::shared_ptr<PlayerCharacter> playerCharacter);
};

