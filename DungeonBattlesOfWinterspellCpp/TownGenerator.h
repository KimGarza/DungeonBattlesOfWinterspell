#pragma once
#include <vector>
#include <sstream>
#include <map>
#include "TownGenerator.h"
#include "Place.h"
#include "LootItem.h"

class TownGenerator
{
private:
    std::vector<std::pair<std::string, std::string>> placeList_ = {
         { "Mages Guild", "Description"},
         { "King's Throne Room", "Description"},
         { "Armoury", "Description"},
         { "Jeweler", "Description"},
         { "Black Bear Tavern", "Description"},
         { "Crystal Moon Tavern", "Description"},
         { "Apothecary", "Description"},
    };

public:
    std::vector<std::shared_ptr<IPlace>> GenerateTown();
    //std::vector<std::shared_ptr<Enemy>> GenerateNpcs(int roomLevel);
};