#pragma once
#include <vector>
#include <string>
#include "DungeonRoom.h"
#include "IMap.h"

class DungeonMap : public IMap {
private:
    ActState act_;
    std::vector <std::shared_ptr<IPlace>> places_;
    std::shared_ptr<IPlace> currentPlace_;
    int roomsRemaining_;

public:
    DungeonMap(std::vector <std::shared_ptr<IPlace>> inDungeonRooms) : places_(inDungeonRooms), roomsRemaining_(inDungeonRooms.size()) {}

    ActState GetAct() override { return act_; }
    std::shared_ptr<IPlace> GetCurrentPlace() override { return currentPlace_; }
    std::vector<std::shared_ptr<IPlace>> GetPlaces() override { return places_; }
    std::vector<std::string> GetPlaceNames() override { return placeNames_; }
    int GetRoomsRemaining() { return roomsRemaining_; }

    void SetCurrentPlace(std::shared_ptr<IPlace> inCurrentRoom) override { currentPlace_ = inCurrentRoom; }
    void SetPlaceNames(std::vector<std::string> inPlaceNames) override { placeNames_ = inPlaceNames; }
    void SetRoomsRemaining() { roomsRemaining_ -= 1; }
};
