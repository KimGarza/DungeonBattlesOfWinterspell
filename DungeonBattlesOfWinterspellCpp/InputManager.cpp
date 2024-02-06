#include "InputManager.h"

// Checks user's input can convert to int in response to prompt
bool InputManager::ValidatePlayerInput(std::string userInput) {

	bool parsable = false;
	int num;

	while (!parsable) {
		try {
			num = std::stoi(userInput);
			return true;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
			return false;
		}
	}
}

// Checks user's input can convert to int in response to prompt and is within range provided
bool InputManager::ValidatePlayerInput(std::string userInput, std::vector<int> selectionRange) {

	try {
		int num;
		num = std::stoi(userInput); // catches

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
		int num;
		num = std::stoi(pointsToAssign); // catches

		int pointsSpentSoFar = 10 - pointsRemaining;

		if (num < 0 && (num < pointsSpentSoFar)) { // preventing subtraction of more points than has been allocated so far
			std::cout << "You dirty little cheating rat, sqorble off you!";
			return false;
		}
		else if (num <= pointsRemaining) {
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