#pragma once
#include "GameText.h"
#include <string>
#include <conio.h>

class ExploreUI
{
private:
	GameText gameTxt_;
public:
	void RoomLocked();
	void NoEnemy();
	void DescribeDungeonRoom(std::string description);
};

