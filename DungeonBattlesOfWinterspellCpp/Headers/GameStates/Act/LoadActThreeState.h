#pragma once
#include "..\..\Helper\MusicPlayer.h"
#include "..\..\Game\Story.h"
#include "..\..\Game\GameContext.h"
#include "LoadActState.h"
#include "CharacterCreation.h"
#include "CreateTrader.h"
#include "DungeonGenerator.h"
#include "..\..\Actors\Map.h"
#include "..\..\Actors\DungeonRoom.h"
#include <memory>

class LoadActThreeState : public LoadActState
{
private:
	std::shared_ptr<GameContext> ctx_;
	Story story_;
	MusicPlayer music_;

public:
	LoadActThreeState(std::shared_ptr<GameContext> inContext) : ctx_(inContext) {}

	void Load() override;
	void CreateMap() override;
	void PopulateMap() override;
	void GeneratePlaces() override;
	void GenerateTrader() override;
};


