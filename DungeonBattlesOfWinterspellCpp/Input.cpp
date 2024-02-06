#include "Input.h"
#include "ICharacter.h"
#include <iostream>
#include <memory>

std::string Input::PlayerChoice(std::vector<int> selectionRange) {

	std::string playerSelection; /**/ std::cin >> playerSelection;
	
	if (inputMgr.ValidatePlayerInput(playerSelection, selectionRange)) {
		return playerSelection;
	}

	return "";
}

std::string Input::AttributePoints(int pointsRemaining) {
	
	std::string points; /**/ std::cin >> points;

	if (inputMgr.ValidatePoints(points, pointsRemaining)) {
		return points;
	}

	return "";
}