#include "MapUpdateState.h"

void MapUpdateState::UpdateMap() {

	ctx_->GetCurrentRoom()->SetTimesExplored();

	if (ctx_->GetCurrentRoom()->GetTimesExplored() == 1) {

		ctx_->GetCurrentRoom()->SetCompleted();
		ctx_->GetMap()->SetRoomsRemaining();
	}

	ctx_->SetState(GameState::RevealMap);
}
