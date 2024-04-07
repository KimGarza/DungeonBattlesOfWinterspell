#pragma once
#include "GameContext.h"
#include "PlayerCharacter.h"
#include "NpcTrader.h"
#include "TraderUI.h"
#include "Story.h"

class TraderInteractState
{
private:
	std::shared_ptr<GameContext> ctx_;
	TraderUI traderUI_;
	std::shared_ptr<PlayerCharacter> player_;
	std::shared_ptr<NpcTrader> trader_;
	Story story_;

public:
	TraderInteractState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void TraderInteract();
	/*void SetValues();
	void Trade();*/
	void MeetTrader();
};

