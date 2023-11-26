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

    int GetRoomsRemaining() const {
        return roomsRemaining;
    }


    void RevealMap();
    void CalcRoomsRemaining();
    std::shared_ptr<DungeonRoom> GetCurrentRoom();
};

