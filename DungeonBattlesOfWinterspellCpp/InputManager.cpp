#include "InputManager.h"

// takes in user's input to a requirement for a num, checks if parsable to an int, returns the int
int InputManager::ParseIntCheck(std::string userInput) {
	bool parsable = false;
	int num;

	while (!parsable) {
		try {
			num = std::stoi(userInput);
			return num;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Input is out of the valid integer range." << std::endl;
		}
	}
}