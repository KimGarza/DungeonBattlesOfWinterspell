#pragma once
#include <memory>
#include "GameContext.h"
#include "Story.h"

class LoadActState
{
public:
	virtual void Load() = 0;
	virtual void CreateMap() = 0;
	virtual void PopulateMap() = 0;
	virtual void GeneratePlaces() = 0;
};

