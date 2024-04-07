#pragma once
#include "LoadActState.h"
#include "GameContext.h"
#include "CharacterCreation.h"
#include "CreateNpcs.h"
#include "DungeonGenerator.h"
#include "MusicPlayer.h"
#include "Story.h"
#include "Map.h"
#include "DungeonRoom.h"
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
	void GenerateNPCs() override;
};


