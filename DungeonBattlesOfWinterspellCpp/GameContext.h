#pragma once
#include "PlayerCharacter.h"
#include "INpc.h"
#include "NpcTrader.h"
#include "Npc.h"
#include "IPlace.h"
#include "GameState.h"
#include "INpc.h"
#include "EventState.h"
#include "ActState.h"
#include "DungeonDungeonMap.h"
#include "DungeonRoom.h"

class GameContext
{
private:
	GameState gameState_;
	EventState eventState_;
	ActState act_;
	std::shared_ptr<PlayerCharacter> player_;
	std::shared_ptr<DungeonMap> map_;
	std::shared_ptr<DungeonRoom> room_;
	std::shared_ptr<IPlace> location_;
	std::vector<std::shared_ptr<DungeonRoom>> dungeonRooms_;
	std::vector<std::shared_ptr<IPlace>> places_;
	std::vector<std::shared_ptr<INpc>> npcs_;

public:
	GameContext() : gameState_(GameState::Begin) {}

	GameState GetState() { return gameState_; }
	EventState GetEventState() { return eventState_; }
	ActState GetAct() { return act_; }
	std::shared_ptr<PlayerCharacter> GetPlayer() { return player_; }
	std::shared_ptr<DungeonDungeonMap> GetDungeonMap() { return map_; }
	std::shared_ptr<DungeonRoom> GetCurrentRoom() { return room_; }
	std::shared_ptr<IPlace> GetCurrentLocation() { return location_; }
	std::vector<std::shared_ptr<DungeonRoom>> GetDungeonRooms() { return dungeonRooms_; }
	std::vector<std::shared_ptr<INpc>> GetActOneNpcs() { return npcs_; }
	std::vector<std::shared_ptr<INpc>> GetActTownNpcs() { return npcs_; }
	std::vector<std::shared_ptr<INpc>> GetActThreeNpcs() { return npcs_; }

	void SetState(GameState inGameState) { gameState_ = inGameState; }
	void SetEventState(EventState inEventState) { eventState_ = inEventState; }
	void SetAct(ActState inActState) { act_ = inActState; }
	void SetPlayer(std::shared_ptr<PlayerCharacter> inPlayer_) { player_ = inPlayer_; }
	void SetDungeonMap(std::shared_ptr<DungeonMap> inDungeonMap) { map_ = inDungeonMap; }
	void SetCurrentRoom(std::shared_ptr<DungeonRoom> inRoom) { room_ = inRoom; }
	void SetCurrentLocation(std::shared_ptr<IPlace> inLoc) { location_ = inLoc; }
	void SetDungeonRooms(std::vector<std::shared_ptr<DungeonRoom>> inDungeonRooms) { dungeonRooms_ = inDungeonRooms; }
	void SetActOneNpcs(std::vector<std::shared_ptr<INpc>> inNpcs) { npcs_ = inNpcs; }
	void SetActTownNpcs(std::vector<std::shared_ptr<INpc>> inNpcs) { npcs_ = inNpcs; }
	void SetActThreeNpcs(std::vector<std::shared_ptr<INpc>> inNpcs) { npcs_ = inNpcs; }
};

