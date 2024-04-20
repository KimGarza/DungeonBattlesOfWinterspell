#pragma once
#include "PlayerCharacter.h"
#include "GameState.h"
#include "Trader.h"
#include "EventState.h"
#include "DungeonMap.h"
#include "RegionState.h"
#include "TownMap.h"
#include "ActState.h"
#include "Map.h"
#include "DungeonRoom.h"

class GameContext
{
private:
	GameState gameState_;
	EventState eventState_;
	ActState act_;
	RegionState region_;
	std::shared_ptr<PlayerCharacter> player_;
	std::shared_ptr<IPlace> place_;
	std::shared_ptr<TownMap> townMap_;
	std::shared_ptr<DungeonMap> dungeonMap_;

public:
	GameContext() : gameState_(GameState::Begin) {}

	GameState GetState() { return gameState_; }
	EventState GetEventState() { return eventState_; }
	ActState GetAct() { return act_; }
	RegionState GetRegion() { return region_; }
	std::shared_ptr<PlayerCharacter> GetPlayer() { return player_; }
	std::shared_ptr<IPlace> GetCurrentPlace() { return place_; }
	std::shared_ptr<DungeonMap> GetDungeonMap() { return dungeonMap_; }
	std::shared_ptr<TownMap> GetTownMap() { return townMap_; }


	void SetState(GameState inGameState) { gameState_ = inGameState; }
	void SetEventState(EventState inEventState) { eventState_ = inEventState; }
	void SetAct(ActState inActState) { act_ = inActState; }
	void SetRegion(RegionState inRegionState) { region_ = inRegionState; }
	void SetPlayer(std::shared_ptr<PlayerCharacter> inPlayer_) { player_ = inPlayer_; }
	void SetCurrentPlace(std::shared_ptr<IPlace> inPlace) { place_ = inPlace; }
	void SetTownMap(std::shared_ptr<TownMap> inTownMap) { townMap_ = inTownMap; }
	void SetDungeonMap(std::shared_ptr<DungeonMap> inDungeonMap) { dungeonMap_ = inDungeonMap; }
};

