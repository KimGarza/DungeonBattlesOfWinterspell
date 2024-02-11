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
#include "ExploreDungeon.h"


Game::Game() {
	currentState = GameState::Begin;
}

void Game::ChangeConsoleDesign() {
	//HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

	//// Set screen buffer size
	//COORD coordScreenBuffer = { 120, 9001 };
	//SetConsoleScreenBufferSize(hConsoleOutput, coordScreenBuffer);

	//// Set window size
	//SMALL_RECT windowSize = { 0, 0, 119, 29 }; // Window size coordinates (right and bottom are inclusive)
	//SetConsoleWindowInfo(hConsoleOutput, TRUE, &windowSize);

	//// Set font size and style
	//CONSOLE_FONT_INFOEX cfi;
	//cfi.cbSize = sizeof(cfi);
	//cfi.nFont = 0;
	//cfi.dwFontSize.X = 0; // Width of each character in the font
	//cfi.dwFontSize.Y = 20; // Height
	//cfi.FontFamily = FF_DONTCARE;
	//cfi.FontWeight = FW_NORMAL;
	//wcscpy_s(cfi.FaceName, L"MS Gothic");
	//SetCurrentConsoleFontEx(hConsoleOutput, FALSE, &cfi);

	//// Set console text and background colors
	//// Assuming the color settings you want are RGB(242, 242, 242) for text and RGB(12, 12, 12) for background
	//// These RGB values must be converted to the appropriate console color attributes
	//// This is a simplification and may not give you the exact RGB values due to console limitations
	//WORD wAttributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | // Light gray text
	//	BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; // Dark green background
	//SetConsoleTextAttribute(hConsoleOutput, wAttributes);

	//// Rest of your application code
	//std::cout << "Console settings have been applied." << std::endl;
}

void Game::CheckGameState() {

	switch (currentState) {

	case GameState::Begin: { 
		ChangeConsoleDesign();
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

		if (currentRoom->GetName() == "Forgotten Catacombs" && exploreDungeon.ChangelingEvent()) {
			ChangeGameState(GameState::BattleChangeling);
		}
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

			//exploreDungeon.ChangeInstnace();

			ChangeGameState(GameState::Loot);
		}

		break;
	}
	case GameState::Battle: {

		Battle battle(currentRoom->GetTurnOrder());

		battle.RevealTurnOrder(currentRoom->GetTurnOrder(), currentRoom->GetName());

		battle.CommenceBattle(playerCharacter);

		ChangeGameState(GameState::Loot);

		break;
	}
	case GameState::BattleChangeling: {
		Battle battle;
		battle.ChangelingFight(playerCharacter)

	}
	case GameState::Loot: {

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
