#pragma once
#include "ActState.h"
#include "INpc.h"
#include "IPlace.h"
#include <string>
#include <vector>
#include <memory>

class Place : public IPlace
{
private:
	std::string name_;
	std::string description_;
	ActState isInAct_;
	int timesExplored_;

public:
	Place(std::string inName,
		std::string inDescription,
		ActState inAct,
		std::vector<std::shared_ptr<INpc>> inNpcs) :
		name_(inName), description_(inDescription), isInAct_(inAct), timesExplored_(0) {}


	std::string GetName() override { return name_; }
	std::string GetDescription() override { return description_; }
	ActState GetIsInAct() override { return isInAct_; }
	int GetTimesExplored() override { return timesExplored_; }

	void SetName(std::string inName) override { name_ = inName; }
	void SetDescription(std::string inDescription) override { description_ = inDescription; }
	void SetIsInAct(ActState inIsInAct) override { isInAct_ = inIsInAct; }
	void SetTimesExplored() override { timesExplored_ += 1; }
};
