#include "ExploreState.h"

// higher level determinations based on conditions, will only change the game state and then enters room
void ExploreState::Explore() {

	SetValues();

	story.EnterDungeonRoom();

	// player menu here
	
	// deals with locked doors and authorizing user by skeleton key
	if (room_->GetIsLocked()) {

		if (CheckHasKey()) {

			GenerateTurnOrder();
			ctx_->SetState(GameState::Battle);
		}
		else {
			ctx_->SetState(GameState::RevealMap);
		}
	}
	else if (!room_->GetCompleted()) {

		GenerateTurnOrder();
		ctx_->SetState(GameState::Battle);
	}

	// deals with events upon entering specific dungeons at specific intervals of repeated visits
	if (room_->GetName() == "Forgotten Catacombs" && room_->GetTimesExplored() == 0) {
		ctx_->SetState(GameState::Event);
		ctx_->SetEventState(EventState::Changeling);
		return;
	}
	else if (room_->GetName() == "Room of Moonlight" && room_->GetTimesExplored() > 0) {

		if (room_->GetTimesExplored() == 1) {

			ctx_->SetEventState(EventState::Trader);
			ctx_->SetState(GameState::Event);
		}
	}
	else if (room_->GetTimesExplored() > 0) {
		ctx_->SetState(GameState::Loot);
	}

	EnterRoom();
}

// lower level checking will result in specific text outputs based on the previously 
// checked conditions since the checks have been done
void ExploreState::EnterRoom() {

	if (room_->GetIsLocked()) {
		ui.RoomLocked();
	}
	else if (room_->GetCompleted()) {
		ui.NoEnemy();
	}
	else {
		ui.DescribeDungeonRoom(room_->GetDescription());
	}
	return;
}

// Checks if the user has the specific key pertaining to the current room attempting to be entered
bool ExploreState::CheckHasKey() {

	std::vector<std::shared_ptr<LootItem>> loot = player_->GetLoot(); // utilizing loot from player member varaible results in vector container variant error

	if (room_->GetName() == "Hozwardian Keep") {

		auto key = std::find_if(loot.begin(), loot.end(), [](const std::shared_ptr<LootItem>& requiredKey) {
			return requiredKey->GetName() == "Iron Key";
			});

		return key != loot.end();
	}
	else if (room_->GetName() == "Room of Offerings") {
		auto key = std::find_if(loot.begin(), loot.end(), [](const std::shared_ptr<LootItem>& requiredKey) {
			return requiredKey->GetName() == "Jewel Encrested Key";
			});

		return key != loot.end();
	}
	return false;

	ui.RoomLocked();
}

// creates vector of creatures including all enemies in room and player organized randomly 
// but swift creatures are at beginning of list
void ExploreState::GenerateTurnOrder() {

	std::vector<std::shared_ptr<Enemy>> enemiesInRoom = room_->GetEnemy();
	std::vector<std::shared_ptr<ICreature>> turnOrder;

	int swiftEnemy = 0;
	int randomIndex = 0;

	// enemy turn order
	for (std::shared_ptr<Enemy> enemy : enemiesInRoom) { // put swift enemies at front and non at the back
		if (enemy->GetHasSwiftness()) {
			turnOrder.emplace(turnOrder.begin(), enemy);
			swiftEnemy++;
		}
		else {
			turnOrder.emplace(turnOrder.end(), enemy);
		}
	}

	// shuffling in player where it make sense according to swiftness
	if (player_->GetHasSwiftness()) {
		if (swiftEnemy == 0) {
			turnOrder.insert(turnOrder.begin(), player_);
		}
		randomIndex = std::rand() % (swiftEnemy + 1);
		turnOrder.insert(turnOrder.begin() + randomIndex, player_);
	}
	else {

		if (turnOrder.size() == swiftEnemy) {
			turnOrder.emplace(turnOrder.end(), player_);
		}
		else {
			// Safe to calculate randomIndex because turnOrder.size() > swiftEnemy
			randomIndex = swiftEnemy + (std::rand() % (turnOrder.size() - swiftEnemy));
			turnOrder.insert(turnOrder.begin() + randomIndex, player_);
		}
	}

	ctx_->GetCurrentRoom()->SetTurnOrder(turnOrder);
}

void ExploreState::SetValues() {

	room_ = ctx_->GetCurrentRoom();
	player_ = ctx_->GetPlayer();
}
