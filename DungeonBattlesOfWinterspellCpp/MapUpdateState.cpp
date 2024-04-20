#include "MapUpdateState.h"

void MapUpdateState::UpdateMap() {

	ctx_->GetCurrentPlace()->SetTimesExplored();

	switch (ctx_->GetRegion()) {
	case RegionState::Winterspell: {
		// nothing needed
	}
	default: { // if a dungeon map is active location, update works differently than town

		if (ctx_->GetCurrentPlace()->GetTimesExplored() == 1) {

			std::shared_ptr<DungeonRoom> room = std::dynamic_pointer_cast<DungeonRoom>(ctx_->GetDungeonMap()->GetCurrentPlace());

			room->SetCompleted();
			ctx_->GetDungeonMap()->SetRoomsRemaining();
		}
		if (ctx_->GetDungeonMap()->GetRoomsRemaining() == 0) {
			switch (ctx_->GetAct()) {

			case ActState::One: {
				ctx_->SetAct(ActState::Town); // instead set to cleanup act state and there set the next state
				break;
			}
			case ActState::Town: {
				ctx_->SetAct(ActState::Three);
				break;
			}
			case ActState::Three: {
				ctx_->SetState(GameState::EndGame);
				break;
			}
			}

			ctx_->SetState(GameState::LoadAct);
			return;
		}
	}
	}

	ctx_->SetState(GameState::RevealMap);
}
