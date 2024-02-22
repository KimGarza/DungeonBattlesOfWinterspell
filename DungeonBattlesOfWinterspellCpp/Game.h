#pragma once
#include "GameState.h"
#include "Story.h"
#include "PlayerCharacter.h"
#include "CharacterCreation.h"
#include "Abalask.h"
#include "DungeonGenerator.h"
#include "ExploreDungeon.h"
#include "Map.h"
#include "MusicPlayer.h";

class Game {
private:
	GameState currentState;
	std::shared_ptr<PlayerCharacter> playerCharacter;
	std::shared_ptr<Map> map;
	Story story;
	std::shared_ptr<DungeonRoom> currentRoom;
	std::vector<std::shared_ptr<DungeonRoom>> dungeonRooms;
	CharacterCreation characterCreation;
	DungeonGenerator dungeonGenerator;
	MusicPlayer music;
	std::shared_ptr<Abalask> abalask;

public:

	Game();

	void CheckGameState();
	void ChangeConsoleDesign();
	void ChangeGameState(GameState newState);

	void Begin();
	void UpdateMap();
	void Explore();
	void Loot();
	void Trading();
	void Battling();
};
