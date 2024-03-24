#pragma once
#include "GameContext.h"
#include "DungeonRoom.h"
#include "UI.h"
#include <memory>

class MapUpdateState
{
private:
	const std::shared_ptr<GameContext> ctx_;

public:
	MapUpdateState(std::shared_ptr<GameContext> inContext) : ctx_(inContext) {}
	
	void UpdateMap();
};

