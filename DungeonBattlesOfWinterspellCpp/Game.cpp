#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "Game.h"
#include "GameState.h"
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


// Set's default state to Begin at start of game.
Game::Game() {
	currentState_ = GameState::Begin;
}


/// <summary>
/// Cycles on a game loop to execute current state tasks until end of game where it runs only once more.
/// </summary>
void Game::StateMachineCycler() {

	while (true) {

		if (currentState_ == GameState::EndGame) {

			CheckGameState();
			return;
		}

		CheckGameState();
	}
}

void Game::ChangeGameState(GameState newState) {
	currentState_ = newState;
	CheckGameState();
}


/// <summary>
/// Game State Machine - the switching of game states to perform the current state's actions, then returns to the cycler to repeat until game ends.
/// </summary>
void Game::CheckGameState() {
	switch (currentState_) {

	case GameState::Begin: { 
		// each state is a class from IState?
		// returns current state and sets that value upon return here.

		Begin();

		currentState_ = GameState::Map;
		return;
	}
	case GameState::Map: {
		currentRoom = map->RevealMapMenu();

		currentState_ = GameState::Explore;
		return;
	}
	case GameState::Explore: {
		Explore();

		currentState_ = GameState::Explore;
		return;
	}
	case GameState::Battle: {
		Battling();

		currentState_ = GameState::Loot;
		return;
	}
	case GameState::BattleChangeling: {
		Battle battle; /**/ battle.ChangelingFight(playerCharacter);
		return;
	}
	case GameState::AbalaskTrader: {
		Trading();
		return;
	}
	case GameState::Loot: {
		Loot();
		return;
	}
	case GameState::UpdateMap: {
		UpdateMap();
		return;
	}
	case GameState::EndGame: {
		std::cout << "You've beat the game!!!";
		exit(0);
		return;
	}
	}
}

void Game::Begin() {

	music.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav");

	story.OpeningStory();

	playerCharacter = characterCreation.CreateCharacter();
	dungeonRooms = dungeonGenerator.GenerateDungeons();
	map = std::make_shared<Map>(dungeonRooms);
	map->PopulateDungeonMap();

	story.MapIntro();

	//sf::RenderWindow window(sf::VideoMode(1200, 1000), "My Game", sf::Style::Default);
	//window.setFramerateLimit(60); // Limit the framerate to 60 FPS

	//sf::Texture texture;
	//if (!texture.loadFromFile("../images/brickwall.png")) {
	//	// Handle error here
	//	// For example, you can print an error message or throw an exception
	//}

	//sf::Sprite sprite;
	//sprite.setTexture(texture);

	//// Inside the game loop
	//window.clear();
	//window.draw(sprite);
	//window.display();

}

void Game::Explore() {
	ExploreDungeon exploreDungeon(currentRoom, playerCharacter);

	story.EnterDungeonRoom();

	exploreDungeon.PlayerMenu();

	if (currentRoom->GetName() == "Forgotten Catacombs" && currentRoom->GetTimesExplored() == 0) {

		music.PlayMusic(L"8bit-chikadou.wav");
		if (exploreDungeon.ChangelingEvent()) {

			currentState_ = GameState::BattleChangeling;
		}
	}

	else if (currentRoom->GetName() == "Room of Moonlight" && currentRoom->GetTimesExplored() > 0) {

		currentState_ = GameState::AbalaskTrader;
	}
	// consider else or will it store on the stack to assume return to this method
	exploreDungeon.EnterDungeonRoom();

	if (!currentRoom->GetCompleted() && !currentRoom->GetIsLocked()) {
		std::vector<std::shared_ptr<ICreature>> turnOrder = exploreDungeon.GenerateTurnOrder();

		currentState_ = GameState::Battle;
	}
	else if (currentRoom->GetIsLocked()) {

		if (exploreDungeon.CheckForKey()) {

			std::vector<std::shared_ptr<ICreature>> turnOrder = exploreDungeon.GenerateTurnOrder();

			currentState_ = GameState::Battle;
		}
		else {
			currentState_ = GameState::Map;
		}
	}
	else {

		currentState_ = GameState::Loot;
	}
}

void Game::Battling() {
	music.PlayMusic(L"108 - Mouryou Senki Madara (VRC6) - Ma-Da-Ra.wav");

	Battle battle(currentRoom->GetTurnOrder());

	battle.RevealTurnOrder(currentRoom->GetTurnOrder(), currentRoom->GetName());
	battle.CommenceBattle(playerCharacter);
}

void Game::Trading() {
	if (currentRoom->GetTimesExplored() == 1) {

		story.AbalaskTraderIntroduction();
	}

	AbalaskTrader abalaskTrader;
	abalask = abalaskTrader.GenerateAbalask();

	abalaskTrader.BeginTrading(playerCharacter);
}

void Game::Loot() {

	music.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav");

	LootRoom lootRoom;

	lootRoom.Loot(playerCharacter, currentRoom);

	ChangeGameState(GameState::UpdateMap);
}

void Game::UpdateMap() {
	map->UpdateMap();

	if (*map->GetRoomsRemaining() == 0) {
		ChangeGameState(GameState::EndGame);
	}

	ChangeGameState(GameState::Map);
}
