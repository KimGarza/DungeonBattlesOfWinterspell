#include "TownGenerator.h"

std::vector<std::shared_ptr<IPlace>> TownGenerator::GenerateTown() {

	std::vector<std::shared_ptr<IPlace>> townPlaces;

    for (const auto& place : placeList_) {

        std::vector<std::shared_ptr<INpc>> npcs;/* = GenerateNpcs(place);*/

        std::shared_ptr<Place> newPlace = std::make_shared<Place>(
            place.first,
            place.second,
            ActState::Town,
            npcs);

        townPlaces.push_back(newPlace);
    }

    return townPlaces;
}
