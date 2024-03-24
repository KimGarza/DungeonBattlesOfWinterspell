#pragma once
#include <memory>
#include "GameContext.h"
#include "MusicPlayer.h"
#include "Story.h"

class ExploreCatacombsState
{
private:
	std::shared_ptr<GameContext> ctx_;
	MusicPlayer music;
	UI ui;
	Story story;

public:
	ExploreCatacombsState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void Explore();
	bool EncounterChangeling();
};

