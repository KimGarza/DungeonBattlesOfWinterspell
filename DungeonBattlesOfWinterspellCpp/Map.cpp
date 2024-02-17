#include <string>
#include <vector>
#include "Map.h"
#include "DungeonRoom.h"


Map::Map(std::vector <std::shared_ptr<DungeonRoom>> dungeonRooms) : dungeonRooms(dungeonRooms), roomsRemaining(std::make_shared<int>(dungeonRooms.size())) {}

void Map::PopulateDungeonMap() {

	for (const auto& dungeon : dungeonRooms) {

		dungeonRoomNames.push_back(dungeon->GetName());
	}
}

/// <summary>
/// Reveals the current rooms discovered by name and undiscovered, includes a menu of available discovered locations the player can choose to go to, 
/// or fast travel to the previously excivated ones. The selected room is now the current room.
/// </summary>
std::shared_ptr<DungeonRoom> Map::RevealMapMenu() {

	system("cls");
	int indexStop = (dungeonRooms.size() - *roomsRemaining); // by subtracting the remaining rooms from all rooms, gets us to the current room by index we are on to know where the last dungeon to write out is
	std::string playerSelectedRoom = ui.DisplayMapMenu(dungeonRoomNames, indexStop);

	auto travelTo = std::find_if(dungeonRooms.begin(), dungeonRooms.end(), [playerSelectedRoom](const std::shared_ptr<DungeonRoom>& room) {
		return room->GetName() == playerSelectedRoom;
	});

	

	if (travelTo != dungeonRooms.end()) {
		currentRoom = *travelTo;
		return *travelTo;
	}
}

std::shared_ptr<DungeonRoom> Map::GetCurrentRoom() {

	return currentRoom;
}


// sets current dungeon room and updates the completed one
void Map::UpdateMap() {

	if (currentRoom->GetTimesExplored() == 1) {

		currentRoom->SetCompleted();
		*roomsRemaining -= 1;
	}
}