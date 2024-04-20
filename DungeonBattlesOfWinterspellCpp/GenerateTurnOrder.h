#pragma once
#include "DungeonRoom.h"
#include "GameContext.h"
#include <memory>

class GenerateTurnOrder
{
private:
	std::shared_ptr<GameContext> ctx_;
	std::shared_ptr<DungeonRoom> room_;
	std::shared_ptr<PlayerCharacter> player_;

public:
	GenerateTurnOrder(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void Generate();
	void EvaluateOrder();
	void SetValues();
};

