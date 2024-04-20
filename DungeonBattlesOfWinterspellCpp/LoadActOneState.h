#pragma once
#include "LoadActState.h"
#include "GameContext.h"
#include "CharacterCreation.h"
#include "CreateTrader.h"
#include "DungeonGenerator.h"
#include "DungeonMap.h"
#include "MusicPlayer.h"
#include "Story.h"
#include "Trader.h"
#include "Map.h"
#include "DungeonRoom.h"
#include <memory>

class LoadActOneState : public LoadActState
{
private:
	std::shared_ptr<GameContext> ctx_;
	Story story_;
	MusicPlayer music_;

public:
	LoadActOneState(std::shared_ptr<GameContext> inContext) : ctx_(inContext) {}

	void Load() override;
	void CreateMap() override;
	std::vector<std::shared_ptr<IPlace>> GeneratePlaces() override;
	void CreateCharacter();
};


