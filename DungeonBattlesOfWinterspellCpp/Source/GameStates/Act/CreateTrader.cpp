#include "..\..\..\Headers\GameStates\Act\CreateTrader.h"

// Creates a specific trader based on act / location. Introduces specific trader based on act.
//void CreateTrader::TraderCreate() {
//
//    GenerateTrader();
//
//    //TraderIntroduction();
//
//    /*bool isPlayerTrading = traderUI_.AbalaskTradeInquiry();
//    if (isPlayerTrading) {
//        ctx_->SetEventState(EventState::Trade);
//        ctx_->SetState(GameState::Event);
//    }*/
//}

//void CreateTrader::TraderIntroduction() {
//
//    switch (ctx_->GetAct()) {
//    case ActState::One: {
//
//        story_.AbalaskTraderIntroduction();
//        break;
//    }
//    case ActState::Town: {
//
//        story_.AbalaskTraderIntroduction();
//
//        break;
//    }
//    case ActState::Three: {
//
//        story_.AbalaskTraderIntroduction();
//        break;
//    }
//    }
//}


// Creates trader using factory method based on act. Instead of seperate state inherited from trader generation, this is much more streamlined.
std::shared_ptr<Trader> CreateTrader::GenerateTrader() {

    switch (ctx_->GetAct()) {
    case ActState::One: {

        std::vector<std::shared_ptr<LootItem>> stock = AbalaskWares();
        return std::make_shared<Trader>("Abalask", stock);
    }
    case ActState::Town: {

        std::vector<std::shared_ptr<LootItem>> stock = MergleWares();
        return std::make_shared<Trader>("Mergle", stock);
    }
    case ActState::Three: {

        std::vector<std::shared_ptr<LootItem>> stock = BalaskWares();
        return std::make_shared<Trader>("Balask", stock);
    }
    }
}

std::vector<std::shared_ptr<LootItem>> CreateTrader::AbalaskWares() {

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

std::vector<std::shared_ptr<LootItem>> CreateTrader::MergleWares() {

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

std::vector<std::shared_ptr<LootItem>> CreateTrader::BalaskWares() {

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

