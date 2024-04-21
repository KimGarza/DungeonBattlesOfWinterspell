#pragma once
#include "PlayerCharacter.h"
#include "DungeonRoom.h"
#include "GameContext.h"

class TurnOrder
{
private:
	std::shared_ptr<GameContext> ctx_;
	std::shared_ptr<DungeonRoom> room_;
	std::shared_ptr<PlayerCharacter> player_;
public:
	TurnOrder(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx), 
		player_(inCtx->GetPlayer()),
		room_(std::dynamic_pointer_cast<DungeonRoom>(inCtx->GetCurrentPlace())) {}
			

	void Generate();
};

