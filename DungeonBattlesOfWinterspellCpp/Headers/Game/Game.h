#pragma once
#include "GameContext.h"
#include "..\GameStates\Act\ActState.h"
#include "..\GameStates\Act\LoadActOneState.h"
#include "..\GameStates\Act\LoadActTownState.h"
#include "..\GameStates\Act\LoadActThreeState.h"
#include "..\GameStates\Event\GameEvent.h"
#include "..\GameStates\Begin\BeginState.h"
#include "..\GameStates\Battle\BattleState.h"
#include "..\GameStates\Map\MapUpdateState.h"
#include "..\GameStates\Map\MapRevealState.h"
#include "..\GameStates\Explore\ExploreState.h"
#include "..\GameStates\Loot\LootState.h"

class Game {

private:
	const std::shared_ptr<GameContext> ctx_;
	GameEvent gameEvent_;
	BeginState beginState_;
	MapUpdateState mapUpdateState_;
	MapRevealState mapRevealState_;
	ExploreState exploreState_;
	BattleState battleState_;
	LootState lootState_;
	LoadActOneState loadActOneState_;
	//LoadActTownState loadActTownState_;
	LoadActThreeState loadActThreeState_;


public:
	// Starts game off with begin state
	Game(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx), gameEvent_(GameEvent(inCtx)), beginState_(BeginState(inCtx)),
		mapUpdateState_(MapUpdateState(inCtx)), mapRevealState_(MapRevealState(inCtx)),
		exploreState_(ExploreState(inCtx)), battleState_(BattleState(inCtx)), 
		lootState_(LootState(inCtx)),
		loadActOneState_(LoadActOneState(inCtx)), /*loadActTownState_(LoadActTownState(inCtx)),*/ loadActThreeState_(LoadActThreeState(inCtx)) {}

	void StateCycle();
	void CheckGameState();
};
