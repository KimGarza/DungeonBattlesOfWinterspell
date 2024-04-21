#include "ExploreTownState.h"
#include "Gamestate.h"
#include "TownEvent.h"

void ExploreTownState::Explore() {

	SetValues();

	EvaluateSpecial();

	ctx_->SetState(GameState::RevealMap);
}

void ExploreTownState::EvaluateSpecial() {
	// clear event state in case of non specific event still selected
	ctx_->SetEventState(EventState::None); 

	if (townPlace_->GetName() == "Sorcerers Guild") {

		ctx_->SetTownEvent(TownEvent::SorcerersGuild);
	}
	else if (townPlace_->GetName() == "King's Throne Room") {
		ctx_->SetTownEvent(TownEvent::KingsThroneRoom);
	}
	else if (townPlace_->GetName() == "Armoury") {
		ctx_->SetTownEvent(TownEvent::Armoury);
	}
	else if (townPlace_->GetName() == "Jeweler") {
		ctx_->SetTownEvent(TownEvent::Jeweler);
	}
	else if (townPlace_->GetName() == "Tavern") {
		ctx_->SetTownEvent(TownEvent::Tavern);
	}
	else if (townPlace_->GetName() == "Apothecary") {
		ctx_->SetTownEvent(TownEvent::Apothecary);
	}

	ctx_->SetState(GameState::Event);

}

void ExploreTownState::SetValues() {

	townPlace_ = std::dynamic_pointer_cast<Place>(ctx_->GetCurrentPlace());
	player_ = ctx_->GetPlayer();
}