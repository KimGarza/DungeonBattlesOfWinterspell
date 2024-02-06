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

void Map::RevealMap() {

	int indexStop = (dungeonRooms.size() - *roomsRemaining); // by subtracting the remaining rooms from all rooms, gets us to the current room by index we are on to know where the last dungeon to write out is
	ui.DisplayMap(dungeonRoomNames, indexStop);
}

std::shared_ptr<DungeonRoom> Map::GetSetCurrentRoom() {
	for (int i = 0; i < dungeonRooms.size(); i++) {
		const auto& dungeon = dungeonRooms[i];

		if (!dungeon->GetCompleted()) {
			currentRoom = dungeon;
			return dungeon;
		}
	}
}

// sets current dungeon room and updates the completed one
void Map::UpdateMap() {
	currentRoom->SetCompleted();
	*roomsRemaining -= 1;
	GetSetCurrentRoom();
}