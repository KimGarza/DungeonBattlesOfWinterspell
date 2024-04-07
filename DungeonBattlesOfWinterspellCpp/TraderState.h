#pragma once
#include "GameContext.h"
#include "PlayerCharacter.h"
#include "TraderUI.h"
#include "Story.h"

class TraderState
{
private:
	std::shared_ptr<GameContext> ctx_;
	TraderUI traderUI_;
	std::shared_ptr<PlayerCharacter> player_;
	std::shared_ptr<Trader> trader_;
	Story story_;

public:
	TraderState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void TraderInteract();
	void SetValues();
	void Trade();
	void MeetTrader();

};

