#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "Game.h"
#include "GameState.h"
#include "Battle.h"
#include "LootRoom.h"
#include "CharacterCreation.h"
#include "DungeonGenerator.h"
#include "PlayerCharacter.h"
#include "GameText.h"
#include "windows.h"
#include "DungeonRoom.h"
#include "DungeonGenerator.h"
#include "Map.h"
#include "AbalaskTrader.h"
#include "ExploreDungeon.h"



Game::Game() {
	currentState = GameState::Begin;
}

void Game::CheckGameState() {

	switch (currentState) {

	case GameState::Begin: { 

		sf::RenderWindow window(sf::VideoMode(1200, 1000), "My Game", sf::Style::Default);
		window.setFramerateLimit(60); // Limit the framerate to 60 FPS

		sf::Texture texture;
		if (!texture.loadFromFile("../images/brickwall.png")) {
			// Handle error here
			// For example, you can print an error message or throw an exception
		}

		sf::Sprite sprite;
		sprite.setTexture(texture);

		// Inside the game loop
		window.clear();
		window.draw(sprite);
		window.display();


		music.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav");


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


		currentRoom = map->RevealMapMenu();

		ChangeGameState(GameState::Explore);

		break;
	}
	case GameState::Explore: {


		ExploreDungeon exploreDungeon(currentRoom, playerCharacter);

		story.EnterDungeonRoom();

		exploreDungeon.PlayerMenu();

		if (currentRoom->GetName() == "Forgotten Catacombs" && currentRoom->GetTimesExplored() == 0) {
			
			music.PlayMusic(L"8bit-chikadou.wav");
			if (exploreDungeon.ChangelingEvent()) {
				ChangeGameState(GameState::BattleChangeling);
			}

		}



		else if (currentRoom->GetName() == "Room of Moonlight" && currentRoom->GetTimesExplored() > 0) {
			ChangeGameState(GameState::AbalaskTrader);
		}
		// consider else or will it store on the stack to assume return to this method
		exploreDungeon.EnterDungeonRoom();

		if (!currentRoom->GetCompleted() && !currentRoom->GetIsLocked()) {
			std::vector<std::shared_ptr<ICreature>> turnOrder = exploreDungeon.GenerateTurnOrder();

			ChangeGameState(GameState::Battle);
		}
		else if (currentRoom->GetIsLocked()) {

			if (exploreDungeon.CheckForKey()) {

				std::vector<std::shared_ptr<ICreature>> turnOrder = exploreDungeon.GenerateTurnOrder();
				ChangeGameState(GameState::Battle);
			}
			else {
				ChangeGameState(GameState::Map);
			}
		}
		else {

			ChangeGameState(GameState::Loot);
		}

		break;
	}
	case GameState::Battle: {

		music.PlayMusic(L"108 - Mouryou Senki Madara (VRC6) - Ma-Da-Ra.wav");

		Battle battle(currentRoom->GetTurnOrder());

		battle.RevealTurnOrder(currentRoom->GetTurnOrder(), currentRoom->GetName());

		battle.CommenceBattle(playerCharacter);

		ChangeGameState(GameState::Loot);

		break;
	}
	case GameState::BattleChangeling: {
		Battle battle;
		battle.ChangelingFight(playerCharacter);

	}
	case GameState::AbalaskTrader: {

		if (currentRoom->GetTimesExplored() == 1) {

			story.AbalaskTraderIntroduction();
		}

		AbalaskTrader abalaskTrader;
		abalask = abalaskTrader.GenerateAbalask();

		abalaskTrader.BeginTrading(playerCharacter);

	}
	case GameState::Loot: {

		music.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav");

		LootRoom lootRoom;

		lootRoom.Loot(playerCharacter, currentRoom);

		ChangeGameState(GameState::UpdateMap);
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
