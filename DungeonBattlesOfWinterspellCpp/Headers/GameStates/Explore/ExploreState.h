#pragma once
#include <memory>
#include "..\..\Game\GameContext.h"
#include "..\..\Actors\DungeonRoom.h"
#include "..\..\Actors\PlayerCharacter.h"
#include "..\..\Helper\UI.h"
#include "..\..\Game\Story.h"
#include "..\..\Helper\MusicPlayer.h"

class ExploreState
{
private:
	std::shared_ptr<GameContext> ctx_;
	std::shared_ptr<DungeonRoom> room_;
	std::shared_ptr<PlayerCharacter> player_;
	UI ui;
	Story story;
	MusicPlayer music;

public:
	ExploreState(std::shared_ptr<GameContext> inContext) : ctx_(inContext) {}

	void Explore();
	void EnterRoom();
	bool CheckHasKey();
	void GenerateTurnOrder();
	void SetValues();
};

