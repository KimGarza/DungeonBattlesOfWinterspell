#pragma once
#include <string>
#include <vector>
#include <iostream>

class InputManager
{
public:
	// takes in user's input to a requirement for a num, checks if parsable to an int returns bool
	bool ValidatePlayerInput(std::string userInput);
	bool ValidatePlayerInput(std::string userInput, std::vector<int> selectionRange);
	bool ValidatePoints(std::string pointsToAssign, int pointsRemaining);
};

