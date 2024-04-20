#pragma once
#include <memory>
#include "GameContext.h"
#include "IPlace.h"
#include "DungeonRoom.h"
#include "PlayerCharacter.h"
#include "ExploreUI.h"
#include "Story.h"
#include "MusicPlayer.h"

class ExploreDungeonState
{
private:
	std::shared_ptr<GameContext> ctx_;
	std::shared_ptr<IPlace> place_;
	std::shared_ptr<DungeonRoom> dungeonRoom_; // this will be null if in town
	std::shared_ptr<PlayerCharacter> player_;
	ExploreUI ui_;
	Story story;
	MusicPlayer music;

public:
	ExploreDungeonState(std::shared_ptr<GameContext> inContext) : ctx_(inContext) {}

	void Explore();
	void EvaluateAccess();
	void EvaluateSpecial();
	void EnterRoom();
	bool CheckHasKey();
	void SetValues();
};

