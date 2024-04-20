#pragma once
#include <memory>
#include "DungeonRoom.h"
#include "GameContext.h"
#include "MapUI.h"

class MapRevealState
{
private:
	const std::shared_ptr<GameContext> ctx_;
	RegionState region_;
	std::vector<std::shared_ptr<IPlace>> places_;
	std::shared_ptr<IPlace> place_;
	MapUI mapUI_;

public:
	MapRevealState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void RevealMap();
	void LocationSelect();
	void SetCurrentLocation(std::string selectedPlace);


	/* Setting all values from context. They cannot be setup in constructor since drilling
	into certain variables result in null exception due to Game.h declaring game states in constructor at entry point.
	Considering alternatives to reduce duplicate code */
	void SetValues();

};

