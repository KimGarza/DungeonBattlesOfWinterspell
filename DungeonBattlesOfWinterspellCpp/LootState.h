#pragma once
#include <memory>
#include "GameContext.h"
#include "UI.h"
#include "MusicPlayer.h"

class LootState
{
private:
	std::shared_ptr<GameContext> ctx_;
	std::shared_ptr<DungeonRoom> room_;
	UI ui_;
	MusicPlayer music_;

public:
	LootState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void Loot();
};
