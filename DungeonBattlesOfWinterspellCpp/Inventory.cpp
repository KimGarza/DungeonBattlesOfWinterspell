#include "Inventory.h"
#include <conio.h>

void Inventory::OpenInventory(std::shared_ptr<PlayerCharacter> playerCharacter) {

	while (true) {

		system("cls");
		std::shared_ptr<LootItem> selectedItem = ui.DisplayInventoryMenu(playerCharacter->GetLoot());
		ui.ItemMenu(selectedItem, playerCharacter);
	}
}
