#include "Map.h"
#include "DungeonRoom.h"
#include <string>
#include <vector>

Map::Map(std::vector <std::shared_ptr<DungeonRoom>> dungeonRooms) : dungeonRooms(dungeonRooms), roomsRemaining(std::make_shared<int>(dungeonRooms.size())) {}

void Map::RevealMap() {

	std::vector<std::string> dungeonNames;
	for (const auto& dungeon : dungeonRooms) { // auto represents cpp inheritely knowing that the type is DungeonRoom

		dungeonNames.push_back(dungeon->GetName());
	}

	int indexStop = (dungeonRooms.size() - *roomsRemaining); // subtracting the remaining rooms gets us to the current # we are on to know where the last dungeon to write out is
	ui.DisplayMap(dungeonNames, indexStop);
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