#include "Map.h"
#include "DungeonRoom.h"
#include <string>
#include <vector>

Map::Map(std::vector <std::shared_ptr<DungeonRoom>> dungeonRooms) : dungeonRooms(dungeonRooms), roomsRemaining(dungeonRooms.size()) {}

void Map::RevealMap() {

	std::vector<std::string> dungeonNames;
	for (const auto& dungeon : dungeonRooms) { // auto represents cpp inheritely knowing that the type is DungeonRoom

		dungeonNames.push_back(dungeon->GetName());
	}

	CalcRoomsRemaining(); // since I only passed in dungeon rooms once so here is to hoping shared pointer is a success and setup the right way with keeping track
	int indexStop = (dungeonRooms.size() - roomsRemaining) - 1; // subtracting the remaining rooms gets us to the current # we are on to know where the last dungeon to write out is
	ui.DisplayMap(dungeonNames, indexStop);
}

void Map::CalcRoomsRemaining() {
	for (int i = 0; i < dungeonRooms.size() - 1; i++) {
		const auto& dungeon = dungeonRooms[i];

		if (dungeon->GetCompleted() == false) {
			roomsRemaining = dungeonRooms.size() - (i + 1);
			break;
		}
	}
}

std::shared_ptr<DungeonRoom> Map::GetCurrentRoom() {
	for (int i = 0; i < dungeonRooms.size() - 1; i++) {
		const auto& dungeon = dungeonRooms[i];

		if (!dungeon->GetCompleted()) {
			currentRoom = dungeon;
			return currentRoom;
		}
	}
}