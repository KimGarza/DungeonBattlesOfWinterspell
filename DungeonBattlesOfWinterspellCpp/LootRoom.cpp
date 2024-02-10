#include "LootRoom.h"
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

	if (_kbhit()) {
		char ch = _getch();
		if (ch == 'i' || ch == 'I') {
			
			OpenInventory(playerCharacter); // open inventory
		}
	}
	// generate random or constant loot
	//ui.RevealLoot();

}

void LootRoom::OpenInventory(std::shared_ptr<PlayerCharacter> playerCharacter) {

	// player views menu and can select any item
	// items sometimes sya "not sure what you want to do with that"
	// equiptables when equipt can add to your character / you can still see it in the inv as equipt and then you can unequipt
	// if health potion select equipt and it adds to players healpotion count unless they drink it then
	// trading menu is different than this
	// selected loot is if it was returnable, 

	std::shared_ptr<LootItem> SelectedItem = ui.DisplayInventoryMenu(playerCharacter->GetLoot());

}