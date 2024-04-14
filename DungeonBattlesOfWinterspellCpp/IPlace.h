#pragma once
#include "ActState.h"
#include "INpc.h"
#include <string>
#include <memory>
#include <vector>

class IPlace
{
protected: // not accessable in .cpp of subclasses?
	std::string name_;
	std::string description_;
	ActState isInAct_;
	int timesExplored_;
	std::vector<std::shared_ptr<INpc>> npcs_;

public:
	virtual ~IPlace() {}  // Virtual destructor for proper cleanup

	virtual std::string GetName() = 0;
	virtual std::string GetDescription() = 0;
	virtual ActState GetIsInAct() = 0;
	virtual int GetTimesExplored() = 0;
	virtual std::vector<std::shared_ptr<INpc>> GetNpcs() = 0;

	virtual void SetTimesExplored() = 0;
	virtual void SetNpcs(std::vector<std::shared_ptr<INpc>> inNpcs) = 0;
};
