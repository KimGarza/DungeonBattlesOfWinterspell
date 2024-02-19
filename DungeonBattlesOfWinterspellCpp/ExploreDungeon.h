#pragma once
#include "DungeonRoom.h"
#include "PlayerCharacter.h"
#include "UI.h"
#include "AbalaskUI.h"

class ExploreDungeon
{
private:
	std::shared_ptr<DungeonRoom> currentRoom;
	std::shared_ptr<PlayerCharacter> playerCharacter;
	UI ui;
	AbalaskUI abalaskUI;

public:
	ExploreDungeon(std::shared_ptr<DungeonRoom> currentRoom, std::shared_ptr<PlayerCharacter> playerCharacter);
	void EnterDungeonRoom();
	std::vector<std::shared_ptr<ICreature>> GenerateTurnOrder();

	void ReExploreRoom();

	void LootDungeon();
	bool CheckForKey();
	void PlayerMenu();
	bool ChangelingEvent();
	void RoomOfMoonlightEvent();
};

