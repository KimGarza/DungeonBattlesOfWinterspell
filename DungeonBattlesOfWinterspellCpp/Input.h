#pragma once
#include "InputManager.h"

class Input
{
private:
	InputManager inputMgr;

public:
	std::string PlayerChoice(std::vector<int> selectionRange);
	std::string AttributePoints(int pointsRemaining);
};

