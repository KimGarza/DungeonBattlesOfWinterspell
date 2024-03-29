#include "AbalaskTradeState.h"

void AbalaskTradeState::Trade() {

    SetValues();
    Trading();
}


void AbalaskTradeState::SetValues() {

    player_ = ctx_->GetPlayer();
    abalask_ = ctx_->GetAbalask();
}

void AbalaskTradeState::Trading() {

    bool isPlayerTrading = abalaskUI_.AbalaskTradeInquiry();
    if (isPlayerTrading) {

        while (true) {

            std::string buySellCancel = abalaskUI_.AbalaskTradeSelectMenu(player_);
            if (buySellCancel == "s") {

                while (true) {

                    std::shared_ptr<LootItem> sellingItem = abalaskUI_.DisplaySellMenu(player_);

                    if (sellingItem) {


                        player_->RemoveFromInventory(sellingItem);
                        player_->SetGold(sellingItem->GetWorthInGold());

                        abalask_->AcceptTradeBuy(sellingItem);

                    }
                    else { // nullptr can be returned if player wishes to cancel
                        break;
                    }
                }
            }
            else if (buySellCancel == "b") {

                while (true) {

                    std::shared_ptr<LootItem> buyingItem = abalaskUI_.DisplayBuyMenu(player_, abalask_);

                    if (buyingItem) {

                        if (buyingItem->GetWorthInGold() <= player_->GetGold()) {

                            player_->AddToInventory(std::make_shared<LootItem>(
                                // find easier way to do this or make sure to delete buying item 
                                buyingItem->GetName(), buyingItem->GetItemType(), buyingItem->GetDescription(),
                                (buyingItem->GetWorthInGold() * .75), buyingItem->GetArmourRating(), buyingItem->GetEvasionRating(), buyingItem->GetAddedDex(),
                                buyingItem->GetAddedStr(), buyingItem->GetAddedInt(), buyingItem->GetSpellDamage(), buyingItem->GetPhysDamage(), buyingItem->GetSpellDamage()));
                            player_->AddToInventory(buyingItem);
                            player_->SetGold(buyingItem->GetWorthInGold() * -1);

                            abalask_->AcceptTradeSell(buyingItem);
                        }
                        else {
                            abalaskUI_.CannotAfford();
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
}