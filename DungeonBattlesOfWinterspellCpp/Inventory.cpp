#include "Inventory.h"
#include <conio.h>

void Inventory::OpenInventory(std::shared_ptr<PlayerCharacter> playerCharacter) {

	while (true) {

		system("cls");
		std::shared_ptr<LootItem> selectedItem = ui.DisplayInventoryMenu(playerCharacter->GetLoot());

		if (selectedItem != nullptr) {
			ItemType itemType = selectedItem->GetItemType();

			switch (itemType) {
			case ItemType::Currency: {

				ui.CannotUseItem(); /**/ _getch();

				break;
			}
			case ItemType::Equiptment: {

				ui.EquiptmentItemMenu(selectedItem, playerCharacter);
				break;
			}
			}
		}
		else {
			return;
		}
	}
	
}
