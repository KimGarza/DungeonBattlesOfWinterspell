#pragma once
#include "GameContext.h"
#include "ChangelingState.h"
#include "TraderInteractState.h"
#include "ChangelingState.h"
#include "TradeState.h"
#include <memory>

class GameEvent
{
private:
	std::shared_ptr<GameContext> ctx_;
	ChangelingState changelingState_;
	TraderInteractState traderInteractState_;
	TradeState tradeState_;

public:
	GameEvent(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx), 
		changelingState_(ChangelingState(inCtx)), traderInteractState_(TraderInteractState(inCtx)), tradeState_(TradeState(inCtx)) {}

	void CheckEventState();
};