#pragma once
#include "IPlace.h"
#include "GameText.h"
#include "GameContext.h"
#include "Input.h"
#include <memory>
#include <conio.h>
#include <iostream>

class MapUI
{
private:
	GameText gameTxt_;
	Input input_;

public:
	std::string DisplayLocationsMenu(std::shared_ptr<GameContext> ctx, std::vector<std::shared_ptr<IPlace>> places, int indexStop);
	std::string PlaceSelect(std::vector<std::pair<int, std::string>> availablePlaces);

	std::string DisplayRegionsMenu(std::shared_ptr<GameContext> ctx, int indexStop);
	std::string RegionSelect();
};
