#include "MapUpdateState.h"

void MapUpdateState::UpdateMap() {

	if (ctx_->GetCurrentRoom()->GetTimesExplored() == 1) {

		ctx_->GetCurrentRoom()->SetCompleted();
		ctx_->GetCurrentRoom()->SetTimesExplored();
		ctx_->GetMap()->SetRoomsRemaining();
	}

	ctx_->SetState(GameState::RevealMap);
}
