#include "InputManager.h"
#include <cctype>
#include <iostream>
#include <string>

// Checks user's input can convert to int in response to prompt
bool InputManager::ValidatePlayerInput(std::string playerInput) {

	bool parsable = false;
	int num;

	while (!parsable) {
		try {
			num = std::stoi(playerInput);
			return true;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
			return false;
		}
	}
}

// Checks user's input can convert to int in response to prompt and is within range provided
bool InputManager::ValidatePlayerInput(std::string playerInput, std::vector<int> selectionRange) {

	try {
		int num;
		num = std::stoi(playerInput); // catches

		auto it = std::find(selectionRange.begin(), selectionRange.end(), num); // num wasn't found in range provided
		if (it != selectionRange.end()) {
			return true;
		}
		return false;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Invalid input" << std::endl;
		return false;
	}
}

bool InputManager::ValidatePoints(std::string pointsToAssign, int pointsRemaining) {

	try {
		int pointsDesired = std::stoi(pointsToAssign); // catches

		int pointsSpentSoFar = 3 - pointsRemaining;

		if (pointsDesired < 0 && (pointsDesired * -1 > pointsSpentSoFar)) { // preventing subtraction of more points than has been allocated so far
			std::cout << "You dirty little cheating rat, sqorble off you!\n";
			return false;
		}
		else if (pointsDesired <= pointsRemaining) {
			return true;
		}
		else {
			return false;
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Invalid input" << std::endl;
		return false;
	}
}

std::string InputManager::ValidateYN(std::string playerInput) {

	try {
		for (char& c : playerInput) {
			c = std::toupper(c);
		}

		if (playerInput == "Y" || playerInput == "YES" ) {
			return "y";
		}
		else if (playerInput == "N" || playerInput == "NO") {
			return "n";
		}
		return "";
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Invalid input" << std::endl;
		return "";
	}
}