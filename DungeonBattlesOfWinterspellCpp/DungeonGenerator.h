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
        "HiddenRoomOfTheRestingDead",
        "FoulTomb",
        "HozwardianKeep",
        "RoomOfMoonlight",
        "AbyssalCrypts",
        "EnigmasEmbrance",
        "ShadowedLabyrinth",
        "ForgottenCatacombs",
        "CursedAbyssalSanctum",
        "RoomOfOfferings",
        "Undiscovered",
        "Unknown"
    };

public:
    std::vector<DungeonRoom> GenerateDungeons();
};