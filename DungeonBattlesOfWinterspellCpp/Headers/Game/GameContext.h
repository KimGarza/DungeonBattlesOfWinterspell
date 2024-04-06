#pragma once
#include "..\Actors\PlayerCharacter.h"
#include "GameState.h"
#include "..\Actors\Trader.h"
#include "..\GameStates\Event\EventState.h"
#include "..\GameStates\Act\ActState.h"
#include "..\Actors\Map.h"
#include "..\Actors\DungeonRoom.h"
#include <memory>
#include <vector>

class GameContext
{
private:
	GameState gameState_;
	EventState eventState_;
	ActState act_;
	std::shared_ptr<PlayerCharacter> player_;
	std::shared_ptr<Map> map_;
	std::shared_ptr<DungeonRoom> room_;
	std::vector<std::shared_ptr<DungeonRoom>> dungeonRooms_;
	std::shared_ptr<Trader> trader_;

public:
	GameContext() : gameState_(GameState::Begin) {}

	GameState GetState() { return gameState_; }
	EventState GetEventState() { return eventState_; }
	ActState GetAct() { return act_; }
	std::shared_ptr<PlayerCharacter> GetPlayer() { return player_; }
	std::shared_ptr<Map> GetMap() { return map_; }
	std::shared_ptr<DungeonRoom> GetCurrentRoom() { return room_; }
	std::vector<std::shared_ptr<DungeonRoom>> GetDungeonRooms() { return dungeonRooms_; }
	std::shared_ptr<Trader> GetTrader() { return trader_; }

	void SetState(GameState inGameState) { gameState_ = inGameState; }
	void SetEventState(EventState inEventState) { eventState_ = inEventState; }
	void SetAct(ActState inActState) { act_ = inActState; }
	void SetPlayer(std::shared_ptr<PlayerCharacter> inPlayer_) { player_ = inPlayer_; }
	void SetMap(std::shared_ptr<Map> inMap) { map_ = inMap; }
	void SetCurrentRoom(std::shared_ptr<DungeonRoom> inRoom) { room_ = inRoom; }
	void SetDungeonRooms(std::vector<std::shared_ptr<DungeonRoom>> inDungeonRooms) { dungeonRooms_ = inDungeonRooms; }
	void SetTrader(std::shared_ptr<Trader> inTrader) { trader_ = inTrader; }
};

