#include "CreateNpcs.h"

std::vector<std::shared_ptr<INpc>> CreateNpcs::Generate() { // This all needs reworked

    std::vector<std::shared_ptr<INpc>> npcs;

    switch (ctx_->GetAct()) {
    case ActState::One: {

        std::vector<MerchType> abalaskTypes;
        abalaskTypes.push_back(MerchType::All);

        // npcs include Abalask
        std::vector<std::shared_ptr<LootItem>> stock = AbalaskWares();
        npcs.emplace_back(std::make_shared<NpcTrader>("Abalask", stock, abalaskTypes));

        return npcs;
    }
    case ActState::Town: {

        // Mergle the Mage
        std::vector<MerchType> mergleTypes;
        mergleTypes.push_back(MerchType::All);

        std::vector<std::shared_ptr<LootItem>> merStock = MergleWares();
        npcs.emplace_back(std::make_shared<INpc>("Mergle", merStock, mergleTypes));

        // Bueruth the Blacksmith
        std::vector<MerchType> bueruthTypes;
        bueruthTypes.push_back(MerchType::Weapon);

        std::vector<std::shared_ptr<LootItem>> bueStock = BueruthWares();
        npcs.emplace_back(std::make_shared<INpc>("Bueruth", bueStock, bueruthTypes));

        // Armsman the Craftsman
        std::vector<MerchType> armsTypes;
        armsTypes.push_back(MerchType::Amrour);

        std::vector<std::shared_ptr<LootItem>> armStock = ArmsmanWares();
        npcs.emplace_back(std::make_shared<INpc>("Mergle", armStock, armsTypes));

        // Ilaya the alchemist
        std::vector<MerchType> ilTypes;
        ilTypes.push_back(MerchType::Amrour);

        std::vector<std::shared_ptr<LootItem>> ilStock = IlayaWares();
        npcs.emplace_back(std::make_shared<INpc>("Ilaya", ilStock, ilTypes));

        return npcs;
    }
    case ActState::Three: {

        // npcs include Balask
        std::vector<MerchType> balaskTypes;
        balaskTypes.push_back(MerchType::All);

        std::vector<std::shared_ptr<LootItem>> stock = BalaskWares();
        npcs.emplace_back(std::make_shared<INpc>("Balask", stock, balaskTypes));
        
        return npcs;
    }
    }
}

std::vector<std::shared_ptr<LootItem>> CreateNpcs::AbalaskWares() {

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

std::vector<std::shared_ptr<LootItem>> CreateNpcs::MergleWares() {

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

std::vector<std::shared_ptr<LootItem>> CreateNpcs::BalaskWares() {

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

std::vector<std::shared_ptr<LootItem>> CreateNpcs::IlayaWares() {

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

std::vector<std::shared_ptr<LootItem>> CreateNpcs::ArmsmanWares() {

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

std::vector<std::shared_ptr<LootItem>> CreateNpcs::BueruthWares() {

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

