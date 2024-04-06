#include "..\..\..\Headers\GameStates\Act\DungeonGenerator.h"

/// <summary>
/// Acts as a factory producing dungeons without concretely creating seperate dungeon classes, and each time generates random enemies to spawn within.
/// Currently all happening at once at the start of the game rather than one by one throughout to reduce complexity in the flow.
/// </summary>
/// <returns></returns>
std::vector < std::shared_ptr<DungeonRoom>> DungeonGenerator::GenerateDungeons() {

    std::vector<std::shared_ptr<DungeonRoom>> dungeonRooms;

    int roomLevel = 1;

    for (const auto& dungeon : dungeonList) {

        std::vector<std::shared_ptr<Enemy>> enemyList = GenerateEnemy(roomLevel);
        std::vector<std::shared_ptr<LootItem>> loot = GenerateLoot();

        if (dungeon.first == "Hozwardian Keep" || dungeon.first == "Room of Offerings") { // lock these two rooms
            std::shared_ptr<DungeonRoom> newDungeonRoom = std::make_shared<DungeonRoom>(dungeon.first, dungeon.second, roomLevel, true, enemyList, loot);
            dungeonRooms.push_back(newDungeonRoom);
        }
        else {
            std::shared_ptr<DungeonRoom> newDungeonRoom = std::make_shared<DungeonRoom>(dungeon.first, dungeon.second, roomLevel, false, enemyList, loot);
            dungeonRooms.push_back(newDungeonRoom);
        }

        roomLevel++;
    }

    return dungeonRooms;
}


/// <summary>
/// Generates a list of all possible enemy types, random number of enemies accounted for returning in the list based upon the level of the room. Lower levels have less enemies. Randomizes which enemies are chosen from the list.
/// Would like to later come back and make troll scarier by references ES Arena
/// </summary>
/// <param name="roomLevel"></param>
/// <returns></returns>
std::vector<std::shared_ptr<Enemy>> DungeonGenerator::GenerateEnemy(int roomLevel) {

    std::vector<std::shared_ptr<Enemy>> enemies;
    enemies.push_back(std::make_shared<Enemy>("Firespitter",
        5, true, "Stealth", "Sneak through the shadows.", 2));

    enemies.push_back(std::make_shared<Enemy>("Dungeon Dweller",
        8, true, "Stealth", "Sneak through the shadows.", 4));

    enemies.push_back(std::make_shared<Enemy>("Goblin",
        5, true, "Stealth", "Sneak through the shadows.", 3));

    enemies.push_back(std::make_shared<Enemy>("HauntingSpirit",
        12, true, "Stealth", "Sneak through the shadows.", 7));

    enemies.push_back(std::make_shared<Enemy>("Troll",
        45, true, "Stealth", "Sneak through the shadows.", 19));

    enemies.push_back(std::make_shared<Enemy>("Skeleton",
        11, true, "Stealth", "Sneak through the shadows.", 5));

    enemies.push_back(std::make_shared<Enemy>("Undead Wolf",
        24, true, "Stealth", "Sneak through the shadows.", 12));

    //Changeling::Changeling() {
    //    name = "Changeling";
    //    health = 40;
    //    hasSwiftness = true;
    //    skillName = "Gutting Slash";
    //    skillDescription = "Slashes with needle like claws and a precise swipe to a foes area of most vunerabile.";
    //    skillDamage = 14;
    //    isDead = false;
    //}

    /*void Changeling::TakeDamage(int hitPoints) {
        health -= hitPoints;
        if (health <= 0) {
            isDead = true;
        }
    }

    int Changeling::AttackPlayer() {
        return skillDamage;
    }Changeling::Changeling() {
        name = "Changeling";
        health = 40;
        hasSwiftness = true;
        skillName = "Gutting Slash";
        skillDescription = "Slashes with needle like claws and a precise swipe to a foes area of most vunerabile.";
        skillDamage = 14;
        isDead = false;
    }

    void Changeling::TakeDamage(int hitPoints) {
        health -= hitPoints;
        if (health <= 0) {
            isDead = true;
        }
    }

    int Changeling::AttackPlayer() {
        return skillDamage;
    }*/
    // Gets random number between the min/max which are decided based upon what the room levels are. Represents how many enemies can spawn per room. (Maximum & minimum values inclusive).
    std::random_device rand; /**/ std::mt19937 gen(rand()); /**/ int min_value = 0; /**/ int max_value = 0;

    //if (roomLevel < 3) {
        //min_value = 2; max_value = 4;
        min_value = 1; max_value = 1;
    //} else if (roomLevel < 5) {
    //    //min_value = 3; max_value = 6;
    //    min_value = 1; max_value = 1;

    //} else {
    //    //min_value = 4; max_value = 7;
    //    min_value = 1; max_value = 1;

    //}

    std::uniform_int_distribution<int> distribution(min_value, max_value);

    int random_number = distribution(gen); // random_number is how many enemies can spawn per room


    std::vector<std::shared_ptr<Enemy>> enemiesInRoom; /**/ int randomIndex = 0;

    for (int i = 0; i < random_number; i++) {

        //if (roomLevel < 3) {
            int lowLevel = (enemies.size() + 3) / 4; // Adding 3 before dividing by 4 effectively rounds up
            randomIndex = std::rand() % lowLevel; // truncates 
            // The expression std::rand() % enemies.size() computes the remainder when the random number generated by std::rand() is divided by the number of elements in the enemies vector.
            // The remainder will always be in the range 0 to enemies.size() - 1. This is because the remainder of any division operation is always less than the divisor.

        //} else if (roomLevel < 5) {
        //    int medLevel = (enemies.size() + 3) / 2;
        //    randomIndex = std::rand() % medLevel;
        //} else {
        //    randomIndex = std::rand() % enemies.size();
        //}

        std::shared_ptr<Enemy> randomEnemy = enemies[randomIndex];

        enemiesInRoom.push_back(randomEnemy);
    }

    return enemiesInRoom;
}

std::vector<std::shared_ptr<LootItem>> DungeonGenerator::GenerateLoot() {

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
