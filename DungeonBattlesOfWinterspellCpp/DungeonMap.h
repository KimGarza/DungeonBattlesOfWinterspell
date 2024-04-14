#pragma once
#include <vector>
#include <string>
#include "GameText.h"
#include "DungeonRoom.h"
#include "UI.h"
#include "IMap.h"

class DungeonMap : public IMap {
private:
    std::string name_;
    std::vector <std::shared_ptr<IPlace>> places_;
    std::shared_ptr<IPlace> currentRoom_;
    std::vector <std::string> roomNames_;
    int roomsRemaining_;

public:
    DungeonMap(std::vector <std::shared_ptr<IPlace>> inDungeonRooms, std::string inName) : places_(inDungeonRooms), name_(inName), roomsRemaining_(inDungeonRooms.size()) {}

    std::string GetName() override { return name_; };
    std::shared_ptr<IPlace> GetCurrentPlace() { return currentRoom_; }
    std::vector<std::string> GetRoomNames() { return roomNames_; }
    std::vector<std::shared_ptr<IPlace>> GetPlaces() override { return places_; }
    int GetRoomsRemaining() { return roomsRemaining_; }

    void SetRoomNames(std::vector<std::string> inRoomNames) { roomNames_ = inRoomNames; }
    void SetCurrentPlace(std::shared_ptr<IPlace> inCurrentRoom) { currentRoom_ = inCurrentRoom; }
    void SetRoomsRemaining() { roomsRemaining_ -= 1; }
};