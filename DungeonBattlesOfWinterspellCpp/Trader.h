#pragma once
#include <vector>
#include <memory>
#include "LootItem.h"

class Trader
{
private:
	std::string name_;
	std::vector<std::shared_ptr<LootItem>> wares_;
	bool hasPlayerMet_;

public:
	Trader(std::string inName, std::vector<std::shared_ptr<LootItem>> inWares) : name_(inName), wares_(inWares), hasPlayerMet_(false) {};

	std::string GetName() { return name_; }
	std::vector<std::shared_ptr<LootItem>> GetWares() { return wares_; }
	bool GetHasPlayerMet() { return hasPlayerMet_; }

	void SetName(std::string inName) { name_ = inName; }
	void SetHasPlayerMet() { hasPlayerMet_ = true; }
	void SetWares(std::vector<std::shared_ptr<LootItem>> inWares) { wares_ = inWares; }

};

