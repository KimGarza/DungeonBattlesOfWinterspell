#include "Map.h"
#include "DungeonRoom.h"
#include <string>
#include <vector>

Map::Map(std::vector <std::shared_ptr<DungeonRoom>> dungeonRooms) : dungeonRooms(dungeonRooms), roomsRemaining(dungeonRooms.size()) {}

void Map::RevealMap() {

	std::vector<std::string> dungeonNames;
	for (const auto& dungeon : dungeonRooms) {

		dungeonNames.push_back(dungeon->GetName());
	}

	CalcRoomsRemaining();
	int indexStop = (dungeonRooms.size() - roomsRemaining) - 1;
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