#pragma once
#include "InputManager.h"

class Input
{
private:
	InputManager inputMgr;

public:
	std::string PlayerChoice(std::vector<int> selectionRange);
	std::string PlayerChoice(std::size_t count);
	std::string PlayerChoiceMap(std::size_t count);
	std::string PlayerChoiceYN();
	std::string AttributePoints(int pointsRemaining);
};