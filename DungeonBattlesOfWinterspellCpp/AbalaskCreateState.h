#pragma once
#include <memory>
#include "GameContext.h"
#include "AbalaskUI.h"
#include "Story.h"

class AbalaskCreateState
{
private:
	std::shared_ptr<GameContext> ctx_;
	AbalaskUI abalaskUI_;
	Story story_;

public:
	AbalaskCreateState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void MeetAbalask();
	void GenerateAbalask();
	std::vector<std::shared_ptr<LootItem>> GenerateWares();

};

