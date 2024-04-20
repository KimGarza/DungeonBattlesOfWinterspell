#pragma once
#include "IMap.h"
#include "Place.h"
#include <vector>
#include <string>

class TownMap : public IMap {
private:
    ActState act_;
    std::vector <std::shared_ptr<IPlace>> places_;
    std::vector<std::string> placeNames_;
    std::shared_ptr<IPlace> currentPlace_;
    int roomsRemaining_;

public:
    TownMap(std::vector <std::shared_ptr<IPlace>> inPlaces) : places_(inPlaces) {}

    ActState GetAct() override { return act_; }
    std::shared_ptr<IPlace> GetCurrentPlace() override { return currentPlace_; }
    std::vector<std::shared_ptr<IPlace>> GetPlaces() override { return places_; }
    std::vector<std::string> GetPlaceNames() override { return placeNames_; }

    void SetCurrentPlace(std::shared_ptr<IPlace> inCurrentRoom) override { currentPlace_ = inCurrentRoom; }
    void SetPlaceNames(std::vector<std::string> inPlaceNames) override { placeNames_ = inPlaceNames; }

};