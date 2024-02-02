#pragma once
#include "GameState.h"
#include "PlayerCharacter.h"
#include "Map.h"

class Game {
private:
	GameState currentState;
	std::shared_ptr<PlayerCharacter> playerCharacter;
	std::shared_ptr<Map> map;
	std::shared_ptr<DungeonRoom> currentRoom;
	std::vector<std::shared_ptr<DungeonRoom>> dungeonRooms;

public:

	Game();

	void CheckGameState();
	void ChangeGameState(GameState newState);
};
