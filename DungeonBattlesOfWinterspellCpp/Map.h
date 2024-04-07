#pragma once
#include <vector>
#include <string>
#include "GameText.h"
#include "DungeonRoom.h"
#include "UI.h"

class Map {
private:
    std::vector <std::shared_ptr<DungeonRoom>> rooms_;
    std::vector <std::string> roomNames_;
    int roomsRemaining_;
    std::shared_ptr<DungeonRoom> currentRoom_;

public:
    Map(std::vector <std::shared_ptr<DungeonRoom>> inDungeonRooms) : rooms_(inDungeonRooms), roomsRemaining_(inDungeonRooms.size()) {}

    std::vector<std::string> GetRoomNames() { return roomNames_; }
    int GetRoomsRemaining() { return roomsRemaining_; }
    std::shared_ptr<DungeonRoom> GetCurrentRoom() { return currentRoom_; }

    void SetRoomNames(std::vector<std::string> inRoomNames) { roomNames_ = inRoomNames; }
    void SetRoomsRemaining() { roomsRemaining_ -= 1; }
};

