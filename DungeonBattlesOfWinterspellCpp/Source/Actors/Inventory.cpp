#include "..\..\Headers\Actors\Inventory.h"

#include <conio.h>

void Inventory::OpenInventory(std::shared_ptr<PlayerCharacter> playerCharacter) {

	system("cls");
	std::shared_ptr<LootItem> selectedItem = ui.DisplayInventoryMenu(playerCharacter->GetLoot());
		
	if (selectedItem) {
		ui.ItemMenu(selectedItem, playerCharacter); 
	}

	return;
}
