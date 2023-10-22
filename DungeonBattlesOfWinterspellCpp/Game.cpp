#include "Game.h"
#include "GameState.h"
#include "PlayerCharacter.h"
#include "CharacterCreation.h"

#include <iostream>

Game::Game() :
	currentState(GameState::Begin),
	playerCharacter()
{

}
// Setter methods implementation
void Game::SetGameState(GameState newState) {
	this->currentState = newState;
}

void Game::CheckGameState() {
	CharacterCreation characterCreation; // remove all memory after building and returning

	switch (currentState) {
	case GameState::None:
		break;
	case GameState::Begin:
		// call and execute gametext.begin to start off the story
		// call and execute character building, ask user who are they?
		// character building TO BE REMOVED SOME
		std::cout << "Hello, world!" << std::endl;
		std::cout << "Build yo character" << std::endl;
		playerCharacter = characterCreation.ChooseClass();
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

//int number;
//std::cin >> number;
//std::string name;
//std::cin >> name;
//std::string sentence;
//std::getline(std::cin, sentence);