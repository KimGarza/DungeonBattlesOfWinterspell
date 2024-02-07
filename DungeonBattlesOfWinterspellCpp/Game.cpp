#include <iostream>
#include "Game.h"
#include "GameState.h"
#include "Battle.h"
#include "CharacterCreation.h"
#include "DungeonGenerator.h"
#include "PlayerCharacter.h"
#include "GameText.h"
#include "DungeonRoom.h"
#include "DungeonGenerator.h"
#include "Map.h"
#include "ExploreDungeon.h"

Game::Game() {
	currentState = GameState::Begin;
}

void Game::CheckGameState() {

	switch (currentState) {

	case GameState::Begin: { 

		story.OpeningStory();

		playerCharacter = characterCreation.CreateCharacter();
		dungeonRooms = dungeonGenerator.GenerateDungeons();

		map = std::make_shared<Map>(dungeonRooms);
		map->PopulateDungeonMap();

		story.MapIntro();

		ChangeGameState(GameState::Map);

		break;
	}
	case GameState::Map: {

		map->RevealMap();

		ChangeGameState(GameState::Explore);

		break;
	}
	case GameState::Explore: {

		currentRoom = map->GetSetCurrentRoom(); // awkward acts as getter and setter

		ExploreDungeon exploreDungeon(currentRoom, playerCharacter);

		story.EnterDungeonRoom();

		exploreDungeon.EnterDungeonRoom();

		std::vector<std::shared_ptr<ICreature>> turnOrder = exploreDungeon.GenerateTurnOrder();

		currentRoom->SetCurrentTurnOrder(turnOrder);

		ChangeGameState(GameState::Battle);
		break;
	}
	case GameState::Battle: {
		Battle battle(map->GetSetCurrentRoom()->GetTurnOrder()); // odd mix here of using game or map to get the current room

		battle.RevealTurnOrder(map->GetSetCurrentRoom()->GetTurnOrder(), currentRoom->GetName());
		

		battle.CommenceBattle(playerCharacter);

		ChangeGameState(GameState::UpdateMap);
		break;
	}
	case GameState::UpdateMap: {

		map->UpdateMap();

		if (*map->GetRoomsRemaining() == 0) {
			ChangeGameState(GameState::EndGame);
		}

		ChangeGameState(GameState::Map);

		break;
	}
	case GameState::EndGame: {
		std::cout << "Congrats on finishing the game!";
		exit(0);
	}
	default:
		currentState = GameState::None;
	}
}

void Game::ChangeGameState(GameState newState) {
	currentState = newState;
	CheckGameState();
}

// remove all memory after building and returning
