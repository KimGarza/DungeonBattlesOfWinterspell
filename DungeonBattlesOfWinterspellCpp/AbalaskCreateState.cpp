#include "AbalaskCreateState.h"

void AbalaskCreateState::MeetAbalask() {

    GenerateAbalask();
    
    bool isPlayerTrading = abalaskUI_.AbalaskTradeInquiry();
    if (isPlayerTrading) {
        ctx_->SetState(GameState::AbalaskTrading);
    }

    story_.AbalaskTraderIntroduction();
}

void AbalaskCreateState::GenerateAbalask() {

    std::vector<std::shared_ptr<LootItem>> abalaskStock = GenerateWares();
    ctx_->SetAbalask(std::make_shared<Abalask>(abalaskStock));

}

std::vector<std::shared_ptr<LootItem>> AbalaskCreateState::GenerateWares() {

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