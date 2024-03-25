#pragma once
#include "GameContext.h"
#include "CharacterCreation.h"
#include "DungeonGenerator.h"
#include "MusicPlayer.h"
#include "Story.h"
#include "Map.h"
#include "DungeonRoom.h"
#include <memory>

class BeginState
{
private:
	std::shared_ptr<GameContext> context_;
	Story story;
	MusicPlayer music_;

public:
	BeginState(std::shared_ptr<GameContext> inContext) : context_(inContext) {}

	void BeginSequence();
	void RenderSFMLGraphics();
	void CreateCharacter();
	void GenerateDungeons();
	void CreateMap();
	void PopulateDungeonMap();
};

