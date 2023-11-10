#pragma once
#include <string>
#include <iostream>

class InputManager
{
public:
	// takes in user's input to a requirement for a num, checks if parsable to an int, returns the int
	int ParseIntCheck(std::string userInput);
};

