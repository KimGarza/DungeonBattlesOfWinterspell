#pragma once
#include "GameContext.h"
#include "ActState.h"
#include "GameEvent.h"
#include "BeginState.h"
#include "MapUpdateState.h"
#include "MapRevealState.h"
#include "ExploreDungeonState.h"
#include "ExploreTownState.h"
#include "BattleState.h"
#include "LootState.h"
#include "LoadActOneState.h"
#include "LoadActTownState.h"
#include "LoadActThreeState.h"

class Game {

private:
	const std::shared_ptr<GameContext> ctx_;
	GameEvent gameEvent_;
	BeginState beginState_;
	MapUpdateState mapUpdateState_;
	MapRevealState mapRevealState_;
	ExploreDungeonState exploreDungeonState_;
	ExploreTownState exploreTownState_;
	BattleState battleState_;
	LootState lootState_;
	LoadActOneState loadActOneState_;
	LoadActTownState loadActTownState_;
	LoadActThreeState loadActThreeState_;


public:
	// Starts game off with begin state
	Game(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx), gameEvent_(GameEvent(inCtx)), beginState_(BeginState(inCtx)),
		mapUpdateState_(MapUpdateState(inCtx)), mapRevealState_(MapRevealState(inCtx)),
		exploreDungeonState_(ExploreDungeonState(inCtx)), exploreTownState_(ExploreTownState(inCtx)),
		battleState_(BattleState(inCtx)), lootState_(LootState(inCtx)),
		loadActOneState_(LoadActOneState(inCtx)), loadActTownState_(LoadActTownState(inCtx)), loadActThreeState_(LoadActThreeState(inCtx)) {}

	void StateCycle();
	void CheckGameState();
};
