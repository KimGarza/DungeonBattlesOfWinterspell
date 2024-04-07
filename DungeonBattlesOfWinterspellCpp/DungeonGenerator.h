#pragma once
#include <vector>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "DungeonRoom.h"
#include "LootItem.h"
#include "LootGenerator.h"
#include "DungeonRoom.h"
#include <random>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Enemy.h"
#include "ItemTypes.h"
#include "EnemyGenerator.h"
#include "Enemy.h"

class DungeonGenerator
{
    // Source: Other than a couple names, all names and descriptions were generated by ChatGPT
private:
    std::vector<std::pair<std::string, std::string>> actOneDungeons_ = {
        { "Stilagmite Ruins", "Shadows dance playfully among the jagged stalagmites of this ancient room.\nThe air hums with a mysterious tune, as if the stone teeth themselves are whispering the secrets of the old."},
        { "Tenebrific Depths", "A veil of darkness clings to every corner, broken only by the faint, eerie glow\nof phosphorescent fungi. Each step echoes into the unseen depths, a reminder that you are not alone in this suffocating gloom."},
        { "Foul Tomb", "The air is thick with the scent of forgotten ages and the ground squelches underfoot.\nMurals of past glories fade on the walls, now mere spectators to the creeping decay and the whispers of the restless dead."},
        { "Hozwardian Keep", "Echoes of ancient battles resonate through the cold, stone walls.\nThe air is heavy with the weight of lost secrets and the ghosts of old, standing guard over their long-forgotten treasures."},
        { "Room of Moonlight", "Bathed in an ethereal glow, this chamber holds a tranquil, yet haunting beauty.\nMoonbeams cast through hidden crevices, playing with shadows and illuminating ancient runes etched into the walls."},
        { "Abyssal Crypts", "An oppressive darkness consumes the air, as if the shadows themselves are alive.\nThe cold stone underfoot seems to pulse with a heartbeat, resonating with the silent screams of souls long consumed by the abyss."},
        { "Enigmas Embrance", "Every surface is adorned with cryptic symbols and intricate puzzles, whispering riddles from ages past.\nThe air is thick with the scent of old parchment and the promise of undiscovered knowledge, hanging tantalizingly just out of reach."},
        { "Forgotten Catacombs", "The air is stale, the silence deafening, as if even the dust has given up whispering.\nSkeletal remains of unfortunate adventurers clutch their last possessions, a grim reminder of the catacomb's insatiable hunger."},
        {"Cursed Abyssal Sanctum", "A chilling wind howls through the room, carrying with it the faint murmurs of ancient curses.\nThe very stones seem to moan in despair, ensnaring all who enter in a labyrinth of sorrow and shadow."},
        { "Room of Offerings", " An eerie calm pervades this space, the walls adorned with niches filled with offerings from bygone eras.\nEach relic tells a story, a silent prayer frozen in time, while an unseen force watches, judging the worthiness of all who enter."},
    };

    std::vector<std::pair<std::string, std::string>> actThreeDungeons_ = {
         { "Stilagmite Ruins", "Shadows dance playfully among the jagged stalagmites of this ancient room.\nThe air hums with a mysterious tune, as if the stone teeth themselves are whispering the secrets of the old."},
         { "Tenebrific Depths", "A veil of darkness clings to every corner, broken only by the faint, eerie glow\nof phosphorescent fungi. Each step echoes into the unseen depths, a reminder that you are not alone in this suffocating gloom."},
         { "Foul Tomb", "The air is thick with the scent of forgotten ages and the ground squelches underfoot.\nMurals of past glories fade on the walls, now mere spectators to the creeping decay and the whispers of the restless dead."},
         { "Hozwardian Keep", "Echoes of ancient battles resonate through the cold, stone walls.\nThe air is heavy with the weight of lost secrets and the ghosts of old, standing guard over their long-forgotten treasures."},
         { "Room of Moonlight", "Bathed in an ethereal glow, this chamber holds a tranquil, yet haunting beauty.\nMoonbeams cast through hidden crevices, playing with shadows and illuminating ancient runes etched into the walls."},
         { "Abyssal Crypts", "An oppressive darkness consumes the air, as if the shadows themselves are alive.\nThe cold stone underfoot seems to pulse with a heartbeat, resonating with the silent screams of souls long consumed by the abyss."},
         { "Enigmas Embrance", "Every surface is adorned with cryptic symbols and intricate puzzles, whispering riddles from ages past.\nThe air is thick with the scent of old parchment and the promise of undiscovered knowledge, hanging tantalizingly just out of reach."},
         { "Forgotten Catacombs", "The air is stale, the silence deafening, as if even the dust has given up whispering.\nSkeletal remains of unfortunate adventurers clutch their last possessions, a grim reminder of the catacomb's insatiable hunger."},
         {"Cursed Abyssal Sanctum", "A chilling wind howls through the room, carrying with it the faint murmurs of ancient curses.\nThe very stones seem to moan in despair, ensnaring all who enter in a labyrinth of sorrow and shadow."},
         { "Room of Offerings", " An eerie calm pervades this space, the walls adorned with niches filled with offerings from bygone eras.\nEach relic tells a story, a silent prayer frozen in time, while an unseen force watches, judging the worthiness of all who enter."},
    };

public:
    std::vector < std::shared_ptr<DungeonRoom>> GenerateActOneDungeons();
    std::vector < std::shared_ptr<DungeonRoom>> GenerateActThreeDungeons();
};