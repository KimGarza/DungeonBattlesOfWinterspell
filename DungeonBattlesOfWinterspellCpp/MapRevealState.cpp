#include "MapRevealState.h"

void MapRevealState::RevealMap() {

	SetValues();
	RoomSelect();
	context_->SetState(GameState::Explore);
}


/// <summary>
/// Reveals all discovered rooms by name and undiscovered are labeled "Undiscovered", includes a menu of available already visited or newly discovered locations the player can choose to travel to, 
/// The selected room is now the current room.
/// </summary>
void MapRevealState::RoomSelect() {
	system("cls");

	// subtracting remaining rooms from all rooms, gets to the current room by index to know where the last dungeon to output is
	int indexStop = (context_->GetDungeonRooms().size() - roomsRemaining_);
	std::string playerSelectedRoom = ui.DisplayMapMenu(roomNames_, indexStop);

	auto travelTo = std::find_if(rooms_.begin(), rooms_.end(), [playerSelectedRoom](const std::shared_ptr<DungeonRoom>& room) { // identifies which room player selected
		return room->GetName() == playerSelectedRoom;
		});

	if (travelTo != rooms_.end()) {
		context_->SetCurrentRoom(*travelTo);
	}
}


void MapRevealState::SetValues() {

	rooms_ = context_->GetDungeonRooms();
	roomsRemaining_ = context_->GetMap()->GetRoomsRemaining();
	roomNames_ = context_->GetMap()->GetRoomNames();
	currentRoom_ = context_->GetCurrentRoom();
}