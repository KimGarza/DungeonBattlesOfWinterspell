#pragma once
#include "GameText.h"
#include "DungeonRoom.h"
#include "UI.h"
#include <vector>

class Map {
private:
    std::vector <std::shared_ptr<DungeonRoom>> dungeonRooms;
    int roomsRemaining;
    std::shared_ptr<DungeonRoom> currentRoom;
    UI ui;

public:
    Map(std::vector <std::shared_ptr<DungeonRoom>>);
    std::shared_ptr<DungeonRoom> GetCurrentRoom() { return currentRoom; }

    int GetRoomsRemaining() const {
        return roomsRemaining;
    }


    void RevealMap();
    std::shared_ptr<DungeonRoom> SetCurrentRoom();
    void UpdateMap();
};

