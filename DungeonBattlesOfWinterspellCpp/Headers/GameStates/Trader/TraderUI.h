#pragma once
#include <string>
#include <memory>
#include "..\..\Game\GameContext.h"
#include "..\..\Game\Story.h"
#include "..\..\Game\GameText.h"
#include "..\..\Helper\Input.h"
#include "..\..\Actors\PlayerCharacter.h"
#include "..\..\Actors\LootItem.h"
#include "..\..\Actors\Trader.h"

class TraderUI {
private:

	GameText gameText;
	Story story;
	Input input;

public:
	bool TradeInquiry();
	std::string TradeSelectMenu(std::shared_ptr<PlayerCharacter> player);
	std::shared_ptr<LootItem> DisplaySellMenu(std::shared_ptr<PlayerCharacter> player);
	std::shared_ptr<LootItem> DisplayBuyMenu(std::shared_ptr<PlayerCharacter> player, std::shared_ptr<Trader> trader_);

	void CannotAfford();
};