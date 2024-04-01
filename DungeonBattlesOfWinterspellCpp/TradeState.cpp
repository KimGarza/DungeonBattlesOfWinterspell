#include "TradeState.h"

void TradeState::Trade() {

    SetValues();
    Trading();
}

void TradeState::SetValues() {

    player_ = ctx_->GetPlayer();
    trader_ = ctx_->GetTrader();
    wares_ = ctx_->GetTrader()->GetWares();
}

void TradeState::Trading() {

    while (true) {

        std::string buySellCancel = traderUI_.TradeSelectMenu(player_);
        if (buySellCancel == "s") {

            while (true) {

                std::shared_ptr<LootItem> sellingItem = traderUI_.DisplaySellMenu(player_);

                if (sellingItem) {


                    player_->RemoveFromInventory(sellingItem);
                    player_->SetGold(sellingItem->GetWorthInGold());

                    AcceptTradeBuy(sellingItem);

                }
                else { // nullptr can be returned if player wishes to cancel
                    break;
                }
            }
        }
        else if (buySellCancel == "b") {

            while (true) {

                std::shared_ptr<LootItem> buyingItem = traderUI_.DisplayBuyMenu(player_, trader_);

                if (buyingItem) {

                    if (buyingItem->GetWorthInGold() <= player_->GetGold()) {

                        player_->AddToInventory(std::make_shared<LootItem>(
                            // find easier way to do this or make sure to delete buying item 
                            buyingItem->GetName(), buyingItem->GetItemType(), buyingItem->GetDescription(),
                            (buyingItem->GetWorthInGold() * .75), buyingItem->GetArmourRating(), buyingItem->GetEvasionRating(), buyingItem->GetAddedDex(),
                            buyingItem->GetAddedStr(), buyingItem->GetAddedInt(), buyingItem->GetSpellDamage(), buyingItem->GetPhysDamage(), buyingItem->GetSpellDamage()));
                        player_->AddToInventory(buyingItem);
                        player_->SetGold(buyingItem->GetWorthInGold() * -1);

                        AcceptTradeSell(buyingItem);
                    }
                    else {
                        traderUI_.CannotAfford();
                        system("cls");
                    }


                }
                else { // nullptr can be returned if player wishes to cancel
                    break;
                }
            }
        }
        else {
            return;
        }
    }
}

void TradeState::AcceptTradeSell(std::shared_ptr<LootItem> item) {

	auto checkInvItem = std::find_if(wares_.begin(), wares_.end(), [item](const std::shared_ptr<LootItem>& invItem) {
		return invItem == item;
		});

	if (checkInvItem != wares_.end()) {
		wares_.erase(checkInvItem);
	}
}

void TradeState::AcceptTradeBuy(std::shared_ptr<LootItem> newItem) {

	// delete new item after since shared pointer
	wares_.emplace_back(std::make_shared<LootItem>(
		newItem->GetName(), newItem->GetItemType(), newItem->GetDescription(),
		(newItem->GetWorthInGold() * 1.50), newItem->GetArmourRating(), newItem->GetEvasionRating(), newItem->GetAddedDex(),
		newItem->GetAddedStr(), newItem->GetAddedInt(), newItem->GetSpellDamage(), newItem->GetPhysDamage(), 30));
}