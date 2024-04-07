#include "DungeonGenerator.h"

/// <summary>
/// Acts as a factory producing dungeons without concretely creating seperate dungeon classes, and each time generates random enemies to spawn within.
/// Currently all happening at once at the start of the game rather than one by one throughout to reduce complexity in the flow.
/// </summary>
/// <returns></returns>
std::vector < std::shared_ptr<DungeonRoom>> DungeonGenerator::GenerateActOneDungeons() {

    std::vector<std::shared_ptr<DungeonRoom>> dungeonRooms;

    int roomLevel = 1;

    for (const auto& dungeon : actOneDungeons_) {

        EnemyGenerator enemyGen;
        std::vector<std::shared_ptr<Enemy>> enemyList = enemyGen.GenerateActOneEnemies(roomLevel);;

        LootGenerator lootGen;
        std::vector<std::shared_ptr<LootItem>> loot = lootGen.GenerateLoot();

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

std::vector < std::shared_ptr<DungeonRoom>> DungeonGenerator::GenerateActThreeDungeons() {

    std::vector<std::shared_ptr<DungeonRoom>> dungeonRooms;

    int roomLevel = 1;

    for (const auto& dungeon : actOneDungeons_) {

        EnemyGenerator enemyGen;
        std::vector<std::shared_ptr<Enemy>> enemyList = enemyGen.GenerateActOneEnemies(roomLevel);;

        LootGenerator lootGen;
        std::vector<std::shared_ptr<LootItem>> loot = lootGen.GenerateLoot();

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