#pragma once
#include <memory>
#include "GameContext.h"
#include "UI.h"
#include "MusicPlayer.h"
#include "GenerateTurnOrder.h"
#include "BattleUI.h"

class BattleState
{
private:
	std::shared_ptr<GameContext> ctx_;
	std::shared_ptr<DungeonRoom> room_;
	std::vector<std::shared_ptr<ICreature>> turnOrder_;
	std::shared_ptr<PlayerCharacter> player_;
	std::shared_ptr<Enemy> enemy_;
	// enemy to remove from the list to generate new updated list with alive enemies only during player's turn
	std::shared_ptr<ICreature> slaughteredEnemy_; 
	BattleUI ui_;
	MusicPlayer music_;

public:
	BattleState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx), ui_(BattleUI(inCtx)) {}

	void Battle();
	void SetValues();
	void CommenceBattle();
	void PlayerTurn();
	void EnemyTurn();
};

