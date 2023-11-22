#include "Game.h"
#include "GameState.h"
#include "CharacterCreation.h"
#include "DungeonGenerator.h"
#include "PlayerCharacter.h"
#include "GameText.h"
#include "DungeonRoom.h"

#include <iostream>

Game::Game() {
	currentState = GameState::Begin; // at start
}

void Game::CheckGameState() {
	GameText gameText;
	// classes introduced and thrown away after use in switch statement
	CharacterCreation characterCreation;
	DungeonGenerator dungeonGenerator;

	while (currentState != GameState::None) {
		switch (currentState) {

		case GameState::None:
			break;
		case GameState::Begin: { // these xtra curly brackets for scoping purposes since things that are initialized within each case can't pass into the next case
			playerCharacter = characterCreation.ChooseClass(); // update function here 
			gameText.WriteText("Time for battle, off to the dugneons, here is your map:\n");
			std::vector<DungeonRoom> dungeonRooms = dungeonGenerator.GenerateDungeons();
			break;
		}
		case GameState::Map: {
			break;
		}
		case GameState::Room:
			break;
		case GameState::Battle:
			break;
		case GameState::Explore:
			break;
		default:
			currentState = GameState::None;
		}
	}
}

void Game::ChangeGameState(GameState newState) {
	currentState = newState;
	CheckGameState();
}

// remove all memory after building and returning
