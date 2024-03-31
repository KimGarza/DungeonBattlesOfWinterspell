#pragma once
#include "GameContext.h"
#include "ActState.h"
#include "BeginState.h"
#include "MapUpdateState.h"
#include "MapRevealState.h"
#include "ExploreState.h"
#include "BattleState.h"
#include "ChangelingState.h"
#include "LootState.h"
#include "AbalaskCreateState.h"
#include "AbalaskTradeState.h"
#include "LoadActOneState.h"
#include "LoadActTwoState.h"
#include "LoadActThreeState.h"

class Game {

private:
	const std::shared_ptr<GameContext> ctx_;
	BeginState beginState_;
	MapUpdateState mapUpdateState_;
	MapRevealState mapRevealState_;
	ExploreState exploreState_;
	BattleState battleState_;
	ChangelingState changelingState_;
	LootState lootState_;
	AbalaskCreateState abalaskCreateState_;
	AbalaskTradeState abalaskTradeState_;
	LoadActOneState loadActOneState_;
	LoadActTwoState loadActTwoState_;
	LoadActThreeState loadActThreeState_;

public:
	// Starts game off with begin state
	Game(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx), beginState_(BeginState(inCtx)),
		mapUpdateState_(MapUpdateState(inCtx)), mapRevealState_(MapRevealState(inCtx)),
		exploreState_(ExploreState(inCtx)), battleState_(BattleState(inCtx)), 
		changelingState_(ChangelingState(inCtx)), lootState_(LootState(inCtx)),
		abalaskCreateState_(AbalaskCreateState(inCtx)), abalaskTradeState_(AbalaskTradeState(inCtx)),
		loadActOneState_(LoadActOneState(inCtx)), loadActTwoState_(LoadActTwoState(inCtx)), loadActThreeState_(LoadActThreeState(inCtx)) {}

	void StateCycle();
	void CheckGameState();
};
