#include "LootRoom.h"
#include "ItemTypes.h"
#include <conio.h>

void LootRoom::Loot(std::shared_ptr<PlayerCharacter> playerCharacter, std::shared_ptr<DungeonRoom> currentRoom) {
	currentRoom->SetTimesExplored();

	if (currentRoom->GetName() == "Tenebrific Depths" && currentRoom->GetTimesExplored() > 1) {
		ui.FoundKey(currentRoom->GetName());
	} else if (currentRoom->GetName() == "Abyssal Crypts" && currentRoom->GetTimesExplored() > 1) {
		ui.FoundKey(currentRoom->GetName());
	}
	else if (currentRoom->GetTimesExplored() == 1) {
		ui.LootBegin(currentRoom->GetLoot());
		playerCharacter->AddToInventory(currentRoom->GetLoot());
	}

	_getch();
}

