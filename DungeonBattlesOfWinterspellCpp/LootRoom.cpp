#include "LootRoom.h"
#include "ItemTypes.h"
#include <conio.h>
#include <memory>

void LootRoom::Loot(std::shared_ptr<PlayerCharacter> playerCharacter, std::shared_ptr<DungeonRoom> currentRoom) {

	if (currentRoom->GetName() == "Tenebrific Depths" && currentRoom->GetTimesExplored() == 1) {
		ui.FoundKey(currentRoom->GetName());

		playerCharacter->AddToInventory(std::make_shared<LootItem>("Iron Key", ItemType::Key, "For unlocking doors of course.", 1));

	} else if (currentRoom->GetName() == "Abyssal Crypts" && currentRoom->GetTimesExplored() == 1) {
		ui.FoundKey(currentRoom->GetName());

		playerCharacter->AddToInventory(std::make_shared<LootItem>("Jewel Encrested Key", ItemType::Key, "For unlocking doors of course. A rather unique one at that.", 1));
	}
	else if (currentRoom->GetTimesExplored() == 0) {
		ui.LootBegin(currentRoom->GetLoot());

		for (const auto& item : currentRoom->GetLoot()) {
			
			if (item->GetName() != "Gold Coin") {
				playerCharacter->AddToInventory(item);
			}
		}
	}
}

