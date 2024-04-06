#pragma once
#include "..\..\Game\GameContext.h"
#include "..\Changeling\ChangelingState.h"
#include "..\Trader\TraderState.h"
#include <memory>

class GameEvent
{
private:
	std::shared_ptr<GameContext> ctx_;
	ChangelingState changelingState_;
	TraderState traderState_;

public:
	GameEvent(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx), 
		changelingState_(ChangelingState(inCtx)), traderState_(TraderState(inCtx)) {}

	void CheckEventState();
};