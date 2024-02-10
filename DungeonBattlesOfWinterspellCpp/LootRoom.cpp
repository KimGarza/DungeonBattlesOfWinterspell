#include "LootRoom.h"

LootRoom::LootRoom(std::shared_ptr<DungeonRoom> currentRoom) : currentRoom(currentRoom) {}

void LootRoom::Loot() {
	currentRoom->SetTimesExplored();

	if (currentRoom->GetName() == "Tenebrific Depths" && currentRoom->GetTimesExplored() > 1) {
		ui.FoundKey(currentRoom->GetName());
	} else if (currentRoom->GetName() == "Abyssal Crypts" && currentRoom->GetTimesExplored() > 1) {
		ui.FoundKey(currentRoom->GetName());
	}
	else if (currentRoom->GetTimesExplored() == 1) {
		ui.LootBegin(currentRoom->GetLoot());
	}

	// generate random or constant loot
	//ui.RevealLoot();

}