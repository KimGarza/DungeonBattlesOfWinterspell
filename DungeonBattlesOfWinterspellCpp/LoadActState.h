#pragma once
#include <memory>
#include "GameContext.h"
#include "Story.h"

class LoadActState
{
public:
	virtual void Load() = 0;
	virtual void CreateMap() = 0;
	virtual std::vector<std::shared_ptr<IPlace>> GeneratePlaces() = 0;
};

