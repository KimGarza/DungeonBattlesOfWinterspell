#pragma once
#include "LootItem.h"
#include "INpc.h"
#include "Place.h"
#include "MerchType.h"
#include <vector>
#include <memory>

class NpcTrader : public INpc
{
private:
	const std::string name_;
	std::vector<std::shared_ptr<LootItem>> wares_;
	std::vector<MerchType> wareTypes_;
	Place place;
	//std::vector<std::vector<MerchType>> recipies_;
	bool hasPlayerMet_;

public:

	NpcTrader(
		std::string inName, 
		std::vector<std::shared_ptr<LootItem>> inWares,
		std::vector<MerchType> inWareTypes) :
		/*std::vector<std::vector<MerchType>> inRecipies)*/ 
		name_(inName), 
		wares_(inWares),
		wareTypes_(inWareTypes), 
		//recipies_(inRecipies),
		hasPlayerMet_(false) {};

	std::string GetName() { return name_; }
	std::vector<std::shared_ptr<LootItem>> GetWares() { return wares_; }
	std::vector<MerchType> GetWareTypes() { return wareTypes_; }
	//std::vector<std::vector<MerchType>> GetRecipies() { return recipies_; }
	bool GetHasPlayerMet() { return hasPlayerMet_; }

	void SetHasPlayerMet() { hasPlayerMet_ = true; }
};