#pragma once
#include <vector>
#include <string>
#include "GameText.h"

class UI
{
private:
	GameText gameText;

public:
	void DisplayMap(std::vector<std::string> dungeonRooms, int indexStop);
	void DescribeDungeonRoom(std::string description);
	void DisplayTurnOrder(std::vector<std::string> creatureNames, std::string dungeonRoomName);

};

