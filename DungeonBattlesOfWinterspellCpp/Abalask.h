#pragma once
#include <vector>
#include <memory>
#include "LootItem.h"

class Abalask
{
private:
	std::vector<std::shared_ptr<LootItem>> wares_;

public:
	Abalask(std::vector<std::shared_ptr<LootItem>> wares);

	std::vector<std::shared_ptr<LootItem>> GetWares() { return wares_; }

	void AcceptTradeSell(std::shared_ptr<LootItem> item);
	void AcceptTradeBuy(std::shared_ptr<LootItem> newItem);
};

