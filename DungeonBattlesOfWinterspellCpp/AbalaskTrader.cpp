#include "AbalaskTrader.h"
#include "AbalaskUI.h"


std::shared_ptr<Abalask> AbalaskTrader::GenerateAbalask() {

    std::vector<std::shared_ptr<LootItem>> abalaskStock = GenerateWares();
	abalask = std::make_shared<Abalask>(abalaskStock);

    return abalask;
}

std::vector<std::shared_ptr<LootItem>> AbalaskTrader::GenerateWares() {


    std::vector<std::shared_ptr<LootItem>> waresInStock{
        std::make_shared<LootItem>("Circlet of Mirador", ItemType::Equiptment, "+10 to evasion, +3 to spell damage", 2, 0, 10, 0, 0, 1, 3, 0, 0),
        std::make_shared<LootItem>("Elegant Robe", ItemType::Equiptment, "+7 to spell damage.", 1, 0, 20, 0, 0, 1, 5, 0, 0), // gold | armour, evasion | addedDex, addedStr, addedInt, spellDamage, physDamage
        std::make_shared<LootItem>("Hyde Boots", ItemType::Equiptment, "+4 to evasion.", (14 * 1.15), 0, 4),
        std::make_shared<LootItem>("Special Leather Guantlets", ItemType::Equiptment, "+2 to evasion.", (14 * 1.15), 0, 2, 1, 0, 0, 0, 0, 0),


        std::make_shared<LootItem>("Helm of Protection", ItemType::Equiptment, "+10 to armour, +5 to life.", (14 * 1.15), 15, 0),
        std::make_shared<LootItem>("Chainmail Tunic", ItemType::Equiptment, "+12 to armour.", (14 * 1.15), 12, 0),
        std::make_shared<LootItem>("Steel Boots", ItemType::Equiptment, "+6 to armour, -1 to evasion.", (14 * 1.15), 6, -2),
        std::make_shared<LootItem>("Leather Guantlets", ItemType::Equiptment, "+5 to armour.", (14 * 1.15), 0, 5),

        std::make_shared<LootItem>("Health Potion", ItemType::HealthPotion, "Restores 22 HP.", (14 * 1.15)),
    };

    return waresInStock;
}

void AbalaskTrader::BeginTrading(std::shared_ptr<PlayerCharacter> player) {

    if (abalaskUI.AbalaskTradeInquiry()) { // bool of is player trading

        while (true) {

            std::string buySellCancel = abalaskUI.AbalaskTradeSelectMenu(player);
            if (buySellCancel == "s") {

                while (true) {

                    std::shared_ptr<LootItem> sellingItem = abalaskUI.DisplaySellMenu(player);

                    if (sellingItem) {

                        
                        player->RemoveFromInventory(sellingItem);
                        player->SetGold(sellingItem->GetWorthInGold());

                        abalask->AcceptTradeBuy(sellingItem);

                    }
                    else { // nullptr can be returned if player wishes to cancel
                        break;
                    }
                }
            }
            else if (buySellCancel == "b") {
                
                while (true) {

                    std::shared_ptr<LootItem> buyingItem = abalaskUI.DisplayBuyMenu(player, abalask);

                    if (buyingItem) {

                        if (buyingItem->GetWorthInGold() <= player->GetGold()) {

                            player->AddToInventory(std::make_shared<LootItem>( 
                                // find easier way to do this or make sure to delete buying item 
                                buyingItem->GetName(), buyingItem->GetItemType(), buyingItem->GetDescription(),
                                (buyingItem->GetWorthInGold() * .75), buyingItem->GetArmourRating(), buyingItem->GetEvasionRating(), buyingItem->GetAddedDex(),
                                buyingItem->GetAddedStr(), buyingItem->GetAddedInt(), buyingItem->GetSpellDamage(), buyingItem->GetPhysDamage(), buyingItem->GetSpellDamage()));
                            player->AddToInventory(buyingItem);
                            player->SetGold(buyingItem->GetWorthInGold() * -1);

                            abalask->AcceptTradeSell(buyingItem);
                        }
                        else {
                            abalaskUI.CannotAfford();
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

