#include "Inventory.h"

void Inventory::OpenInventory(std::shared_ptr<PlayerCharacter> playerCharacter) {

	// player views menu and can select any item
	// items sometimes say "not sure what you want to do with that"
	// equiptables when equipt can add to your character / you can still see it in the inv as equipt and then you can unequipt
	// if health potion select equipt and it adds to players healpotion count unless they drink it then
	// trading menu is different than this
	// selected loot is if it was returnable, 

	std::shared_ptr<LootItem> selectedItem = ui.DisplayInventoryMenu(playerCharacter->GetLoot());
	ItemType itemType = selectedItem->GetItemType();

	switch (itemType) {
	case ItemType::Currency: {

		ui.CannotUseItem();
		break;
	}
	case ItemType::Equiptment: {

		ui.EquiptmentItemMenu(selectedItem, playerCharacter);
		break;
	}

	}
}
