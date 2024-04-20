#pragma once
#include <memory>
#include "GameContext.h"
#include "ExploreUI.h"
#include "BattleUI.h"
#include "story.h"
#include "MusicPlayer.h"

class ChangelingState
{
private:
	std::shared_ptr<GameContext> ctx_;
	std::shared_ptr<Enemy> changeling_;
	ExploreUI ui_;
	BattleUI battleUI_;
	Story story;
	MusicPlayer music_;

public:
	ChangelingState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx), battleUI_(BattleUI(inCtx)) {}

	void ChangelingEncounter();
	void BattleChangeling(); // coinsidering combining with traditonal battle
	bool PlayerEngages();
	void PlayerTurn(); 
	void EnemyTurn();
};

