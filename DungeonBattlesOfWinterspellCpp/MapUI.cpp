#include "MapUI.h"

/// <summary>
/// Presents menu where displays all IPlaces in current region in order. 
/// For Dungeons, rooms that are discovered are named, others are labeled "Undiscovered".
/// </summary>
std::string MapUI::DisplayLocationsMenu(std::shared_ptr<GameContext> ctx, std::vector<std::shared_ptr<IPlace>> places, int indexStop) {

    while (true) {

        if (ctx->GetRegion() == RegionState::Winterspell) {
            gameTxt_.WriteLine("Map of Winterspell");
        } else if (ctx->GetRegion() == RegionState::DungeonOne) {
            gameTxt_.WriteLine("Dungon Caverns");
        } else {
            gameTxt_.WriteLine("Dungon Outskirts");
        }

        std::cout << " ____________________________________\n\n";

        std::vector<std::pair<int, std::string>> selectablePlaces;

        for (int i = 0; i < places.size(); i++) {

            if (i % 4 == 0) {
                gameTxt_.WriteText("\n");
            }
            if (i > indexStop) { // for dungeons, this will be for undiscovered places

                // formatting purposes
                if (i < places.size() - 1) {
                    gameTxt_.WriteText("Undiscovered...    -->  ");
                }
                else {
                    gameTxt_.WriteText("Undiscovered");
                }
            }
            else { // within bounds of discovery, load the current iteration of places to selectablePlaces list for selection by index

                if (i < places.size() - 1) {
                    gameTxt_.WriteText(places[i]->GetName() + "   -->  ");

                    selectablePlaces.emplace_back((i + 1), places[i]->GetName());
                }
                else {
                    gameTxt_.WriteText(places[i]->GetName());

                    selectablePlaces.emplace_back((i + 1), places[i]->GetName());
                }
            }
        }
        if (indexStop == places.size()) {

            gameTxt_.WriteLine(std::to_string(indexStop + 1) + ") Town of Winterspell");

            selectablePlaces.emplace_back((places.size() + 1), "Town");
        }

        std::cout << "\n\n";

        std::string selectedPlace = PlaceSelect(selectablePlaces);
        if (selectedPlace != "") {
            return selectedPlace;
        }
        else {
            system("cls");
            gameTxt_.WriteLine("Those regions are uncharted.");
        }
    }

    _getch();
    system("cls");
}

/// <summary>
/// Presents optional places to travel. Player selects the number which is the location identifier from availablePlaces vector pair (index, name).
/// Checks player's selection is available and returns the selected place by name.
/// </summary>
std::string MapUI::PlaceSelect(std::vector<std::pair<int, std::string>> availablePlaces) {

    while (true) {

        for (const auto& place : availablePlaces) {
            gameTxt_.WriteLine("\n" + std::to_string(place.first) + ")  " + place.second); // index) place name - for selection
        }

        std::string playerChoice = input_.PlayerChoiceMap(availablePlaces.size());

        if (playerChoice != "") {
            int placeIndex = std::stoi(playerChoice);

            // std::find_if with a lambda to find the matching room
            auto selectedRoomIt = std::find_if(availablePlaces.begin(), availablePlaces.end(), [placeIndex](const std::pair<int, std::string>& room) {
                return room.first == placeIndex;
                });

            if (selectedRoomIt != availablePlaces.end()) {
                std::pair<int, std::string> place = *selectedRoomIt;

                return place.second;
            }
        }
    }

    return "";
}