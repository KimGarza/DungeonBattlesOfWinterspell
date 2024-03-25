#pragma once
#include "GameContext.h"
#include "BeginState.h"
#include "MapUpdateState.h"
#include "MapRevealState.h"
#include "ExploreState.h"
#include "BattleState.h"
#include "ChangelingState.h"

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

	const std::shared_ptr<GameContext> ctx_;
	BeginState beginState_;
	MapUpdateState mapUpdateState_;
	MapRevealState mapRevealState_;
	ExploreState exploreState_;
	BattleState battleState_;
	ChangelingState changelingState_;

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
	// Starts game off with begin state
	Game(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx), beginState_(BeginState(inCtx)),
		mapUpdateState_(MapUpdateState(inCtx)), mapRevealState_(MapRevealState(inCtx)),
		exploreState_(ExploreState(inCtx)), battleState_(BattleState(inCtx)), changelingState_(ChangelingState(inCtx)) {}

	void StateCycle();
	void CheckGameState();

	void ChangeConsoleDesign();
	void Begin();
	void UpdateMap();
	void Explore();
	void Loot();
	void Trading();
	void Battling();
};
