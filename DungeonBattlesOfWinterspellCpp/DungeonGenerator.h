#pragma once
#include "DungeonRoom.h"
#include "vector"
#include <sstream>

class DungeonGenerator
{
private:
    std::vector<std::string> dungeonList = {
        "StilagmiteRuins",
        "TenebrificDepths",
        ////"HiddenRoomOfTheRestingDead",
        //"FoulTomb",
        //"HozwardianKeep",
        //"RoomOfMoonlight",
        //"AbyssalCrypts",
        //"EnigmasEmbrance",
        ////"ShadowedLabyrinth",
        //"ForgottenCatacombs",
        //"CursedAbyssalSanctum",
        //"RoomOfOfferings"
    };

public:
    std::vector < std::shared_ptr<DungeonRoom>> GenerateDungeons();
    std::vector<std::shared_ptr<IEnemy>> GenerateEnemies(int roomLevel);
};