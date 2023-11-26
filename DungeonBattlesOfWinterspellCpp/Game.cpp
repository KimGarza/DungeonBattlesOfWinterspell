#include "Game.h"
#include "GameState.h"
#include "Battle.h"
#include "CharacterCreation.h"
#include "DungeonGenerator.h"
#include "PlayerCharacter.h"
#include "GameText.h"
#include "DungeonRoom.h"
#include "DungeonGenerator.h"
#include <iostream>
#include "Map.h"
#include "ExploreDungeon.h"

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
			playerCharacter = characterCreation.ChooseClass(); // character creation
			
			std::vector <std::shared_ptr<DungeonRoom>> dungeonRooms = dungeonGenerator.GenerateDungeons(); // generate dungeons
			map = new Map(dungeonRooms);
			gameText.WriteLine("Time for battle, off to the dugneons, here is your map\n");
			ChangeGameState(GameState::Map);
			break;
		}
		case GameState::Map: {
			map->RevealMap();
			ChangeGameState(GameState::Explore);
			break;
		}
		case GameState::Explore: {

			std::shared_ptr<DungeonRoom> dungeonRoom = map->GetCurrentRoom();
			currentRoom = dungeonRoom;
			ExploreDungeon exploreDungeon(dungeonRoom, playerCharacter);
			exploreDungeon.EnterDungeonRoom();
			std::vector<std::shared_ptr<ICreature>> turnOrder = exploreDungeon.GenerateTurnOrder();
			dungeonRoom->SetCurrentTurnOrder(turnOrder);

			ChangeGameState(GameState::Battle);
			break;
		}
		case GameState::Battle: {
			Battle battle(map->GetCurrentRoom()->GetTurnOrder());

			battle.RevealTurnOrder(map->GetCurrentRoom()->GetTurnOrder(), currentRoom->GetName());
			battle.CommenceBattle();
			
			break;
		}
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


//for (const auto& dungeon : dungeonRooms) {
//	std::cout << "dungeon name: " << dungeon->GetName() << std::endl;
//	std::cout << "dungeon complete: " << dungeon->GetCompleted() << std::endl;
//	if (size_t length = dungeon->GetEnemies().size() > 0) {
//		std::cout << "it is populated" << std::endl;
//		for (const auto& enemy : dungeon->GetEnemies()) {
//			std::cout << "enemy: " << enemy->GetName() << std::endl;
//		}
//	}
//
//}