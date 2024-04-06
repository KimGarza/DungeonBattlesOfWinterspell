#pragma once
#include <memory>
#include "..\..\Actors\Trader.h"
#include "..\..\Game\GameContext.h"
#include "..\Trader\TraderUI.h"
#include "..\..\Game\Story.h"

class CreateTrader
{
private:
	std::shared_ptr<GameContext> ctx_;
	TraderUI traderUI_;
	Story story_;

public:
	CreateTrader(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}
	std::shared_ptr<Trader> GenerateTrader();
	std::vector<std::shared_ptr<LootItem>> AbalaskWares();
	std::vector<std::shared_ptr<LootItem>> MergleWares();
	std::vector<std::shared_ptr<LootItem>> BalaskWares();
};
