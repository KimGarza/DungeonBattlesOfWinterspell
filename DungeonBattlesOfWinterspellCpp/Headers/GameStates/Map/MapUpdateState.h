#pragma once
#include "..\..\Game\GameContext.h"
#include "..\..\Helper\UI.h"
#include "..\..\Actors\DungeonRoom.h"
#include <memory>

class MapUpdateState
{
private:
	const std::shared_ptr<GameContext> ctx_;

public:
	MapUpdateState(std::shared_ptr<GameContext> inContext) : ctx_(inContext) {}
	
	void UpdateMap();
};

