#include "Abalask.h"
#include <memory>


Abalask::Abalask(std::vector<std::shared_ptr<LootItem>> wares) : wares(wares) {}

void Abalask::AcceptTradeSell(std::shared_ptr<LootItem> item) {

	auto checkInvItem = std::find_if(wares.begin(), wares.end(), [item](const std::shared_ptr<LootItem>& invItem) {
		return invItem == item;
		});

	if (checkInvItem != wares.end()) {
		wares.erase(checkInvItem);
	}
}

void Abalask::AcceptTradeBuy(std::shared_ptr<LootItem> newItem) {

	// delete new item after since shared pointer

	wares.emplace_back(std::make_shared<LootItem>(
		newItem->GetName(), newItem->GetItemType(), newItem->GetDescription(),
		(newItem->GetWorthInGold() * 1.50), newItem->GetArmourRating(), newItem->GetEvasionRating(), newItem->GetAddedDex(),
		newItem->GetAddedStr(), newItem->GetAddedInt(), newItem->GetSpellDamage(), newItem->GetPhysDamage()));
}