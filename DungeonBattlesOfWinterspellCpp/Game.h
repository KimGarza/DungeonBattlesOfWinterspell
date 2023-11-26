#pragma once
#include "GameState.h"
#include "PlayerCharacter.h"
#include "Map.h"

class Game {
private:
	GameState currentState;
	std::shared_ptr<PlayerCharacter> playerCharacter;
	Map* map;
	std::shared_ptr<DungeonRoom> currentRoom;

public:
	Game();

	void CheckGameState();
	void ChangeGameState(GameState newState);
};
