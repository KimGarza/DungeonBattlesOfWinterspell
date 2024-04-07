#pragma once
#include <vector>
#include <sstream>
#include <map>
#include "GenerateTown.h"
#include "LootItem.h"

class GenerateTown
{
private:
    std::vector<std::pair<std::string, std::string>> townPlaces = {
         { "Mages Guild", "Description"},
         { "King's Throne Room", "Description"},
         { "Armoury", "Description"},
         { "Jeweler", "Description"},
         { "Black Bear Tavern", "Description"},
         { "Crystal Moon Tavern", "Description"},
         { "Apothecary", "Description"},
    };

public:
    //std::vector < std::shared_ptr<Place>> GeneratePlaces();
    //std::vector<std::shared_ptr<Enemy>> GenerateNpcs(int roomLevel);
};