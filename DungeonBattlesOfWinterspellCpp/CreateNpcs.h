#pragma once
#include <memory>
#include "Trader.h"
#include "GameContext.h"
#include "TraderUI.h"
#include "MerchType.h"
#include "Story.h"

class CreateNpcs
{
private:
	std::shared_ptr<GameContext> ctx_;

public:
	CreateNpcs(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	std::vector<std::shared_ptr<INpc>> Generate();

	std::vector<std::shared_ptr<LootItem>> AbalaskWares();
	std::vector<std::shared_ptr<LootItem>> MergleWares();
	std::vector<std::shared_ptr<LootItem>> BalaskWares();
	std::vector<std::shared_ptr<LootItem>> IlayaWares();
	std::vector<std::shared_ptr<LootItem>> ArmsmanWares();
	std::vector<std::shared_ptr<LootItem>> BueruthWares();
};
