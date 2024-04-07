#pragma once
#include "ActState.h"
#include <string>

class IPlace
{
private:
	std::string name_;
	std::string description_;
	ActState isInAct_;
	int timesExplored_;

public:
	virtual ~IPlace() {}  // Virtual destructor for proper cleanup

	virtual std::string GetName() = 0;
	virtual std::string GetDescription() = 0;
	virtual ActState GetIsInAct() = 0;
	virtual int GetTimesExplored() = 0;

	virtual void SetName(std::string inName) = 0;
	virtual void SetDescription(std::string inDescription) = 0;
	virtual void SetIsInAct(ActState inIsInAct) = 0;
	virtual void SetTimesExplored() = 0;
};

