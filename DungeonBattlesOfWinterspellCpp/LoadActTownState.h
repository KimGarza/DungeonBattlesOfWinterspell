#pragma once
#include "LoadActState.h"
#include "GameContext.h"
#include "CharacterCreation.h"
#include "CreateTrader.h"
#include "GenerateTown.h"
#include "MusicPlayer.h"
#include "Story.h"
#include "Map.h"
#include "DungeonRoom.h"
#include <memory>

class LoadActTownState : public LoadActState
{
private:
	std::shared_ptr<GameContext> ctx_;
	Story story_;
	MusicPlayer music_;

public:
	LoadActTownState(std::shared_ptr<GameContext> inContext) : ctx_(inContext) {}

	void Load() override;
	void CreateMap() override;
	void PopulateMap() override;
	//void GeneratePlaces() override;
	void GenerateTrader() override;
};


