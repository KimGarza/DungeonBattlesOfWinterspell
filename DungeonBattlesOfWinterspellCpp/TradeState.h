#pragma once
#include <memory>
#include "GameContext.h"
#include "TraderUI.h"
#include "Trader.h"

class TradeState
{
private:
	std::shared_ptr<GameContext> ctx_;
	std::shared_ptr < PlayerCharacter> player_;
	std::shared_ptr<Trader> trader_;
	std::vector<std::shared_ptr<LootItem>> wares_;
	TraderUI traderUI_;

public:
	TradeState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void Trade();
	void SetValues();
	void Trading();
	void AcceptTradeSell(std::shared_ptr<LootItem> item);
	void AcceptTradeBuy(std::shared_ptr<LootItem> newItem);
};

