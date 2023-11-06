#pragma once
#include "GameState.h"
#include "PlayerCharacter.h"

class Game {
private:
	GameState currentState;
	//PlayerCharacter playerCharacter;

public:
	Game();

	void SetGameState(GameState newState);
	void CheckGameState();
};
