#include "MapUpdateState.h"

void MapUpdateState::UpdateMap() {

	ctx_->GetCurrentRoom()->SetTimesExplored();

	if (ctx_->GetCurrentRoom()->GetTimesExplored() == 1) {

		ctx_->GetCurrentRoom()->SetCompleted();
		ctx_->GetMap()->SetRoomsRemaining();
	}

	if (ctx_->GetMap()->GetRoomsRemaining() == 0) {

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

	ctx_->SetState(GameState::RevealMap);
}
