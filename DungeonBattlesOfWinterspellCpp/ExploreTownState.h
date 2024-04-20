#pragma once
#include "Story.h"
#include "GameContext.h"
#include "ExploreUI.h"
#include "MusicPlayer.h"
#include "IPlace.h"
#include <memory>


class ExploreTownState
{
private:
	std::shared_ptr<GameContext> ctx_;
	ExploreUI ui_;
	Story story_;
	MusicPlayer music_;

public:
	ExploreTownState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void Explore();
	void EvaluateSpecial();
	void EnterPlace();
	void SetValues();
};