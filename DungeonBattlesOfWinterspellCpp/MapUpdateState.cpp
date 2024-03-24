#include "MapUpdateState.h"

void MapUpdateState::UpdateMap() {
	SetValues();
	Update();
}

// sets current 
void MapUpdateState::Update() {

	if (currentRoom_->GetTimesExplored() == 1) {

		currentRoom_->SetCompleted();
		roomsRemaining_ -= 1;
	}
}

void MapUpdateState::SetValues() {

	rooms_ = context_->GetDungeonRooms();
	roomsRemaining_ = context_->GetMap()->GetRoomsRemaining();
	roomNames_ = context_->GetMap()->GetRoomNames();
	currentRoom_ = context_->GetCurrentRoom();
}