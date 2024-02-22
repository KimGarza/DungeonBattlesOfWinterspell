#include "Input.h"
#include "Input.h"
#include <iostream>
#include <memory>

std::string Input::PlayerChoice(std::vector<int> selectionRange) {

	std::string playerSelection; /**/ std::cin >> playerSelection;

	if (inputMgr.ValidatePlayerInput(playerSelection, selectionRange)) {
		return playerSelection;
	}

	return "";
}

std::string Input::PlayerChoice(std::size_t count) {

	std::string playerSelection; /**/ std::cin >> playerSelection;

	if (playerSelection == "x") { return "x"; }

	std::vector<int> selectionRange;

	for (int i = 0; i < count; i++) {
		selectionRange.emplace_back(i + 1);
	}

	if (inputMgr.ValidatePlayerInput(playerSelection, selectionRange)) {
		return playerSelection;
	}

	return "";
}

std::string Input::PlayerChoiceMap(std::size_t count) {

	std::string playerSelection; /**/ std::cin >> playerSelection;

	std::vector<int> selectionRange;

	for (int i = 0; i < count; i++) {
		selectionRange.emplace_back(i + 1);
	}

	if (inputMgr.ValidatePlayerInput(playerSelection, selectionRange)) {
		return playerSelection;
	}

	return "";
}

std::string Input::PlayerChoiceYN() {

	std::string playerSelection; /**/ std::cin >> playerSelection;

	return inputMgr.ValidateYN(playerSelection);
}

std::string Input::AttributePoints(int pointsRemaining) {

	std::string points; /**/ std::cin >> points;

	if (inputMgr.ValidatePoints(points, pointsRemaining)) {
		return points;
	}

	return "";
}