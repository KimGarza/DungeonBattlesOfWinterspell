#pragma once
#include <string>
#include <memory>
#include "PlayerCharacter.h"
#include "LootItem.h"
#include "GameText.h"
#include "Story.h"
#include "Input.h"
#include "Abalask.h"

class AbalaskUI {
private:

	GameText gameText;
	Story story;
	Input input;

public:
	bool AbalaskTradeInquiry();
	std::string AbalaskTradeSelectMenu(std::shared_ptr<PlayerCharacter> player);
	std::shared_ptr<LootItem> DisplaySellMenu(std::shared_ptr<PlayerCharacter> player);
	std::shared_ptr<LootItem> DisplayBuyMenu(std::shared_ptr<PlayerCharacter> player, std::shared_ptr<Abalask> abalask);

	void CannotAfford();
};