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


/// <summary>
/// Game loop that continuously checks each game state until end of game. This is what keeps the game persisting.
/// First ran in main.cpp, constructor decides Begin is initial state
/// </summary>
void Game::StateCycle() {

	while (ctx_->GetState() != GameState::EndGame) {

		CheckGameState();
	} 

	CheckGameState(); // requires one more check game state for the end game but will close afterwards
	return;
}

/// <summary>
/// State machine: switches between states to execute relevant state. Each state will set the currentState_ to the next relevant state.
/// </summary>
void Game::CheckGameState() {
	switch (ctx_->GetState()) {

	case GameState::Begin: {

		beginState_.BeginSequence();
		return;
	}
	case GameState::RevealMap: {

		mapRevealState_.RevealMap();
		return;
	}
	case GameState::Explore: {

		exploreState_.Explore();
		return;
	}
	case GameState::ForgottenCatacombs: {

		exploreCatacombsState_.Explore();
		return;
	}
	case GameState::Battle: {
		Battling();
		ctx_->SetState(GameState::Loot);


		break;
	}
	case GameState::BattleChangeling: {
		Battle battle;
		battle.ChangelingFight(playerCharacter);

		break;
	}
	case GameState::AbalaskTrader: {
		Trading();

		break;
	}
	case GameState::Loot: {
		Loot();

		break;
	}
	case GameState::UpdateMap: {
		UpdateMap();

		break;
	}
	case GameState::EndGame: {
		std::cout << "Congrats on finishing the game!";
		exit(0);

		break;
	}
	default:
		ctx_->SetState(GameState::None);
		
		break;
	}
}

void Game::Explore() {
	ExploreDungeon exploreDungeon(ctx_->GetCurrentRoom(), ctx_->GetPlayer());

	story.EnterDungeonRoom();

	exploreDungeon.PlayerMenu();

	if (ctx_->GetCurrentRoom()->GetName() == "Forgotten Catacombs" && ctx_->GetCurrentRoom()->GetTimesExplored() == 0) {

		music.PlayMusic(L"8bit-chikadou.wav");
		if (exploreDungeon.ChangelingEvent()) {
			ctx_->SetState(GameState::BattleChangeling);
		}
	}

	else if (ctx_->GetCurrentRoom()->GetName() == "Room of Moonlight" && ctx_->GetCurrentRoom()->GetTimesExplored() > 0) {
		ctx_->SetState(GameState::AbalaskTrader);
	}
	// consider else or will it store on the stack to assume return to this method
	exploreDungeon.EnterDungeonRoom();

	if (!ctx_->GetCurrentRoom()->GetCompleted() && !ctx_->GetCurrentRoom()->GetIsLocked()) {
		std::vector<std::shared_ptr<ICreature>> turnOrder = exploreDungeon.GenerateTurnOrder();

		ctx_->SetState(GameState::Battle);
	}
	else if (ctx_->GetCurrentRoom()->GetIsLocked()) {

		if (exploreDungeon.CheckForKey()) {

			std::vector<std::shared_ptr<ICreature>> turnOrder = exploreDungeon.GenerateTurnOrder();
			ctx_->SetState(GameState::Battle);
		}
		else {
			ctx_->SetState(GameState::RevealMap);
		}
	}
	else {

		ctx_->SetState(GameState::Loot);
	}
}

void Game::Battling() {
	music.PlayMusic(L"108 - Mouryou Senki Madara (VRC6) - Ma-Da-Ra.wav");

	Battle battle(ctx_->GetCurrentRoom()->GetTurnOrder());

	battle.RevealTurnOrder(ctx_->GetCurrentRoom()->GetTurnOrder(), ctx_->GetCurrentRoom()->GetName());

	battle.CommenceBattle(ctx_->GetPlayer());
}

void Game::Trading() {
	if (ctx_->GetCurrentRoom()->GetTimesExplored() == 1) {

		story.AbalaskTraderIntroduction();
	}

	AbalaskTrader abalaskTrader;
	abalask = abalaskTrader.GenerateAbalask();

	abalaskTrader.BeginTrading(ctx_->GetPlayer());
}

void Game::Loot() {

	music.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav");

	LootRoom lootRoom;

	lootRoom.Loot(ctx_->GetPlayer(), ctx_->GetCurrentRoom());

	ctx_->SetState(GameState::UpdateMap);
}

void Game::UpdateMap() {
	mapUpdateState_.UpdateMap();
	if (ctx_->GetMap()->GetRoomsRemaining() == 0) {
		ctx_->SetState(GameState::EndGame);
	}
	ctx_->SetState(GameState::RevealMap);
}
