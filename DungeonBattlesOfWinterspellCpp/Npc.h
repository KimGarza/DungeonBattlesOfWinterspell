#pragma once
#include "INpc.h"
#include <string>

class Npc : public INpc
{
private:
	const std::string name_;
	bool hasPlayerMet_;

public:

	Npc(std::string inName) : name_(inName) {};

	std::string GetName() { return name_; }
	bool GetHasPlayerMet() { return hasPlayerMet_; }

	void SetHasPlayerMet() { hasPlayerMet_ = true; }
};