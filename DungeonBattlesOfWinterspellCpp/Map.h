#pragma once
#include <vector>
#include <string>
#include "GameText.h"
#include "DungeonRoom.h"
#include "UI.h"

class Map {
private:
    std::vector <std::shared_ptr<DungeonRoom>> dungeonRooms;
    std::vector <std::string> dungeonRoomNames;
    std::shared_ptr<int> roomsRemaining;
    std::shared_ptr<DungeonRoom> currentRoom;
    UI ui;

public:
    Map(std::vector <std::shared_ptr<DungeonRoom>>);

    void PopulateDungeonMap();

    std::shared_ptr<int> GetRoomsRemaining() const {
        return roomsRemaining;
    }

    void RevealMap();
    std::shared_ptr<DungeonRoom> GetSetCurrentRoom();
    void UpdateMap();
};

