#pragma once
#include "PlayerCharacter.h"
#include "GameState.h"
#include "ActState.h"
#include "Map.h"
#include "DungeonRoom.h"
#include "Abalask.h"

class GameContext
{
private:
	GameState gameState_;
	ActState act_;
	std::shared_ptr<PlayerCharacter> player_;
	std::shared_ptr<Map> map_;
	std::shared_ptr<DungeonRoom> room_;
	std::vector<std::shared_ptr<DungeonRoom>> dungeonRooms_;
	std::shared_ptr<Abalask> abalask_;

public:
	GameContext() : gameState_(GameState::Begin) {}

	GameState GetState() { return gameState_; }
	ActState GetAct() { return act_; }
	std::shared_ptr<PlayerCharacter> GetPlayer() { return player_; }
	std::shared_ptr<Map> GetMap() { return map_; }
	std::shared_ptr<DungeonRoom> GetCurrentRoom() { return room_; }
	std::vector<std::shared_ptr<DungeonRoom>> GetDungeonRooms() { return dungeonRooms_; }
	std::shared_ptr<Abalask> GetAbalask() { return abalask_; }

	void SetState(GameState inGameState) { gameState_ = inGameState; }
	void SetAct(ActState inActState) { act_ = inActState; }
	void SetPlayer(std::shared_ptr<PlayerCharacter> inPlayer_) { player_ = inPlayer_; }
	void SetMap(std::shared_ptr<Map> inMap) { map_ = inMap; }
	void SetCurrentRoom(std::shared_ptr<DungeonRoom> inRoom) { room_ = inRoom; }
	void SetDungeonRooms(std::vector<std::shared_ptr<DungeonRoom>> inDungeonRooms) { dungeonRooms_ = inDungeonRooms; }
	void SetAbalask(std::shared_ptr<Abalask> inAbalask) { abalask_ = inAbalask; }
};

