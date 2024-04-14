#pragma once
#include "IPlace.h"

class Place : public IPlace
{
private:
	std::string name_;
	std::string description_;
	ActState isInAct_;
	int timesExplored_;
	std::vector<std::shared_ptr<INpc>> npcs_;

public:
	Place(
		std::string inName,
		std::string inDescription,
		ActState inIsInAct,
		std::vector<std::shared_ptr<INpc>> inNpcs) :
		name_(inName),
		description_(inDescription),
		isInAct_(inIsInAct),
		timesExplored_(0),
		npcs_(inNpcs) {}

	std::string GetName() override { return name_; }
	std::string GetDescription() override { return description_; }
	ActState GetIsInAct() override { return isInAct_; }
	int GetTimesExplored() override { return timesExplored_; }
	std::vector<std::shared_ptr<INpc>> GetNpcs() override { return npcs_; }

	void SetTimesExplored() override { timesExplored_ += 1; }
	void SetNpcs(std::vector<std::shared_ptr<INpc>> inNpcs) override { npcs_ = inNpcs; }
};

