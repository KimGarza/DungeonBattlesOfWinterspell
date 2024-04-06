#pragma once
#include <memory>
#include "..\..\Game\GameContext.h"
#include "..\..\Helper\UI.h"
#include "..\..\Game\Story.h"
#include "..\..\Helper\MusicPlayer.h"


class ChangelingState
{
private:
	std::shared_ptr<GameContext> ctx_;
	std::shared_ptr<Enemy> changeling_;
	UI ui;
	Story story;
	MusicPlayer music_;

public:
	ChangelingState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void ChangelingEncounter();
	void BattleChangeling(); // coinsidering combining with traditonal battle
	bool PlayerEngages();
	void PlayerTurn(); 
	void EnemyTurn();
};

