#include "Game.h"
#include "GameState.h"
#include "CharacterCreation.h"

#include <iostream>

Game::Game() {
	currentState = GameState::Begin; // at start
}

// Setter methods implementation
void Game::SetGameState(GameState newState) {
	currentState = newState;
}

void Game::CheckGameState() {

	// classes introduced and thrown away after use in switch statement
	CharacterCreation characterCreation;

	switch (currentState) {

		case GameState::None:
			break;
		case GameState::Begin:
			// call and execute gametext.begin to start off the story
			// call and execute character building, ask user who are they?
			// character building TO BE REMOVED SOME
			characterCreation.ChooseClass();
			break;
		case GameState::Map:
			break;
		case GameState::DungeonRoom:
			break;
		case GameState::Battle:
			break;
		case GameState::Explore:
			break;
		default:
			currentState = GameState::None;
	}
}
// // remove all memory after building and returning
