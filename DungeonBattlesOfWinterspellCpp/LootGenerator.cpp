#include "LootGenerator.h"

std::vector<std::shared_ptr<LootItem>> LootGenerator::GenerateLoot() {

    std::vector<std::shared_ptr<LootItem>> lootInRoom;

    std::vector<std::shared_ptr<LootItem>> lootStock{
        std::make_shared<LootItem>("Gold Coin", ItemType::Currency, "A very valueable piece of currency; Can be used for purchasing in the markets.", 1),
        std::make_shared<LootItem>("Ruby Gem", ItemType::Valueable, "A dazzling rich red jewel; Tradeable for cold coin", 35),
        std::make_shared<LootItem>("Starlight Gem", ItemType::Valueable, "A valueable piece of currency; can be used to purchase things in the markets.", 26),
        std::make_shared<LootItem>("Palantíri", ItemType::Valueable, "An orb of pondering, it can see things that may not be meant for our eyes. Looks to belong to a wise mage or wizard.", 35),
        std::make_shared<LootItem>("Moonstone", ItemType::Valueable, "A valueable piece of currency; can be used to purchase things in the markets.", 13),
        std::make_shared<LootItem>("Luminescent Mushie", ItemType::Valueable, "A valueable piece of currency; can be used to purchase things in the markets.", 11),
        std::make_shared<LootItem>("Ancient Scroll", ItemType::AncientScroll, "Hidden secrets are etched upon a tattered sturdy cloth.", 2),
        std::make_shared<LootItem>("Jewel Encrested Chalice", ItemType::Valueable, "A beautifully ornately crafted chalice, encrested in colorful polished jewels, looks of dwarven-make.", 25),
        std::make_shared<LootItem>("Health Potion", ItemType::HealthPotion, "Restores 20 HP.", 14),
        std::make_shared<LootItem>("Boots of Swiftness", ItemType::Equiptment, "Gives wearer swiftness.", 5),
        std::make_shared<LootItem>("Helm of Protection", ItemType::Equiptment, "+10 to armour.", 8, 15, 0),
        std::make_shared<LootItem>("Steel Chestplate", ItemType::Equiptment, "+20 to armour.", 7, 20, 0),
        std::make_shared<LootItem>("Leather Guantlets", ItemType::Equiptment, "+5 to armour.", 6, 10, 0)
    };

    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(1, 4); // Define the range
    // Generate and print a random number between 1 and 10
    int randomNumber = distr(gen);


    for (int i = 0; i < randomNumber; i++) {

        std::uniform_int_distribution<> distr(0, lootStock.size() - 1);
        int randomLootPull = distr(gen);

        lootInRoom.push_back(lootStock[randomLootPull]);
    }
    return lootInRoom;

}