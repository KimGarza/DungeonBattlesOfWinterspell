#pragma once
#include <memory>
#include "Trader.h"
#include "GameContext.h"
#include "TraderUI.h"
#include "Story.h"

class CreateTrader
{
private:
	std::shared_ptr<GameContext> ctx_;
	TraderUI traderUI_;
	Story story_;

public:
	//virtual void TraderCreate();
	//void TraderIntroduction();
	std::shared_ptr<Trader> GenerateTrader();
	std::vector<std::shared_ptr<LootItem>> AbalaskWares();
	std::vector<std::shared_ptr<LootItem>> MergleWares();
	std::vector<std::shared_ptr<LootItem>> BalaskWares();
};
