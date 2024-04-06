#pragma once
#include <memory>
#include "..\..\Game\GameContext.h"
#include "..\..\Game\Story.h"


class LoadActState
{
public:
	virtual void Load() = 0;
	virtual void CreateMap() = 0;
	virtual void PopulateMap() = 0;
	virtual void GeneratePlaces() = 0;
	virtual void GenerateTrader() = 0;
};

