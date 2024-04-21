#include "ExploreDungeonState.h"

void ExploreDungeonState::Explore() {

	SetValues();

	//story.EnterDungeonRoom();

	EvaluateAccess(); // check's if door is accessable
	EvaluateSpecial(); // check's for special events
	EnterRoom(); // outputs text based on room (access denied, description, cleared, etc...)
	// player menu here

}

void ExploreDungeonState::EvaluateAccess() {

	if (dungeonRoom_->GetIsLocked()) {

		if (CheckHasKey()) {

			//GenerateTurnOrder();
			ctx_->SetState(GameState::Battle);
		}
		else {
			ctx_->SetState(GameState::RevealMap);
		}
	}
	else if (!dungeonRoom_->GetCompleted()) {

		//GenerateTurnOrder();
		ctx_->SetState(GameState::Battle);
	}
}

void ExploreDungeonState::EvaluateSpecial() {

	if (dungeonRoom_->GetName() == "Forgotten Catacombs" && dungeonRoom_->GetTimesExplored() == 0) { // enemy event
		ctx_->SetState(GameState::Event);
		ctx_->SetEventState(EventState::Changeling);
		return;
	}
	else if (dungeonRoom_->GetName() == "Room of Moonlight" // trader location
		&& dungeonRoom_->GetTimesExplored() > 0) { 

		ctx_->SetEventState(EventState::Trader);
		ctx_->SetState(GameState::Event);
	}
	else if (dungeonRoom_->GetTimesExplored() > 0) { // no battle to be had
		ctx_->SetState(GameState::Loot);
	}
}
	

// lower level checking will result in specific text outputs based on the previously 
// checked conditions since the checks have been done
void ExploreDungeonState::EnterRoom() {

	if (dungeonRoom_->GetIsLocked()) {
		ui_.RoomLocked();
	}
	else if (dungeonRoom_->GetCompleted()) {
		ui_.NoEnemy();
	}
	else {
		ui_.DescribeDungeonRoom(dungeonRoom_->GetDescription());
	}
	return;
}

// Checks if the user;s inventory for the specific key pertaining to the current room attempting to be entered
bool ExploreDungeonState::CheckHasKey() {

	std::vector<std::shared_ptr<LootItem>> loot = player_->GetLoot(); // utilizing loot from player member varaible results in vector container variant error

	if (dungeonRoom_->GetName() == "Hozwardian Keep") {

		auto key = std::find_if(loot.begin(), loot.end(), [](const std::shared_ptr<LootItem>& requiredKey) {
			return requiredKey->GetName() == "Iron Key";
			});

		return key != loot.end();
	}
	else if (dungeonRoom_->GetName() == "Room of Offerings") {
		auto key = std::find_if(loot.begin(), loot.end(), [](const std::shared_ptr<LootItem>& requiredKey) {
			return requiredKey->GetName() == "Jewel Encrested Key";
			});

		return key != loot.end();
	}
	return false;

	ui_.RoomLocked();
}


void ExploreDungeonState::SetValues() {

	dungeonRoom_ = std::dynamic_pointer_cast<DungeonRoom>(ctx_->GetCurrentPlace());
	player_ = ctx_->GetPlayer();
}