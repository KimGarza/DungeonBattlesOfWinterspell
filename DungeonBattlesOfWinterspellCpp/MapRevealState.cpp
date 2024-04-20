#include "MapRevealState.h"

void MapRevealState::RevealMap() {

	SetValues();
	LocationSelect();
	ctx_->SetState(GameState::Explore);
}


/// <summary>
/// Reveals all discovered locations by name and IF in dungeon, unexplored rooms are labeled "Undiscovered".
/// Includes a menu of available already visited or newly discovered locations the player can choose to travel to.
/// The selected place is now the current place in context.
/// </summary>
void MapRevealState::LocationSelect() {
	system("cls");

	int indexStop;

	if (region_ == RegionState::Winterspell) {

		indexStop = places_.size();
	}
	else {
		// subtracting remaining rooms from all rooms, gets to the current room by index to know where the last dungeon to output is
		indexStop = places_.size() - ctx_->GetDungeonMap()->GetRoomsRemaining();
	}

	// returns place player selection by name, identifies existing shared *IPlace and sets current place in context to there.
	std::string selectedPlace = mapUI_.LocationSelectMenu(ctx_, places_, indexStop); 

	auto travelTo = std::find_if(places_.begin(), places_.end(), [selectedPlace](const std::shared_ptr<IPlace>& place) { // identifies which room player selected
		return place->GetName() == selectedPlace;
		});
	
	SetCurrentLocation(selectedPlace);
}

// set's current place from context and the current map to the selected locaiton
void MapRevealState::SetCurrentLocation(std::string selectedPlace) {

	auto travelTo = std::find_if(places_.begin(), places_.end(), [selectedPlace](const std::shared_ptr<IPlace>& place) { // identifies which room player selected
		return place->GetName() == selectedPlace;
		});

	// set's current place from context and the current map to the selected locaiton
	if (travelTo != places_.end()) {

		region_ = ctx_->GetRegion();

		switch (region_) {
		case RegionState::Winterspell: {
			ctx_->GetTownMap()->SetCurrentPlace(*travelTo);
		}
		default: {
			ctx_->GetDungeonMap()->SetCurrentPlace(*travelTo);
		}
		}

		ctx_->SetCurrentPlace(*travelTo);
	}
}


void MapRevealState::SetValues() {

	region_ = ctx_->GetRegion();

	switch (region_) {
	case RegionState::Winterspell: {

		places_ = ctx_->GetTownMap()->GetPlaces();
	}
	defualt: {
		places_ = ctx_->GetDungeonMap()->GetPlaces();
	}
	}

	place_ = ctx_->GetCurrentPlace();
}