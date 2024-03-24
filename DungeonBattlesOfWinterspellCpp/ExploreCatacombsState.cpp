#include "ExploreCatacombsState.h"

void ExploreCatacombsState::Explore() {

	music.PlayMusic(L"8bit-chikadou.wav");

	ui.DescribeDungeonRoom(ctx_->GetCurrentRoom()->GetDescription());

	if (EncounterChangeling()) {

		ctx_->SetState(GameState::BattleChangeling);
		return;
	}
	
	ctx_->SetState(GameState::Battle);
}

bool ExploreCatacombsState::EncounterChangeling() {

	std::string playerChoice = story.Changeling();
	if (playerChoice == "y") {

		return true;
	}
	
	return false;
}