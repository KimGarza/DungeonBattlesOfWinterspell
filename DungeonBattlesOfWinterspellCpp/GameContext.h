#pragma once
#include "PlayerCharacter.h"
#include "Map.h"
#include "DungeonRoom.h"
#include "Abalask.h"

class GameContext
{
private:
	std::shared_ptr<PlayerCharacter> player_;
	std::shared_ptr<Map> map_;
	std::shared_ptr<DungeonRoom> room_;
	std::vector<std::shared_ptr<DungeonRoom>> dungeonRooms_;
	std::shared_ptr<Abalask> abalask_;

public:
	std::shared_ptr<PlayerCharacter> GetPlayer() { return player_; }
	std::shared_ptr<Map> GetMap() { return map_; }
	std::shared_ptr<DungeonRoom> GetCurrentRoom() { return room_; }
	std::vector<std::shared_ptr<DungeonRoom>> GetDungeonRooms() { return dungeonRooms_; }
	std::shared_ptr<Abalask> GetAbalask() { return abalask_; }

	void SetPlayer(std::shared_ptr<PlayerCharacter> inPlayer_) { player_ = inPlayer_; }
	void SetMap(std::shared_ptr<Map> inMap) { map_ = inMap; }
	void SetCurrentRoom(std::shared_ptr<DungeonRoom> inRoom) { room_ = inRoom; }
	void SetDungeonRooms(std::vector<std::shared_ptr<DungeonRoom>> inDungeonRooms) { dungeonRooms_ = inDungeonRooms; }
	void SetAbalask(std::shared_ptr<Abalask> inAbalask) { abalask_ = inAbalask; }
};

