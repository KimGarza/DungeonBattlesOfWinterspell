#include "GameText.h"
#include <iostream>
#include <thread>
#include <chrono>

void GameText::WriteLine(std::string text) {
	for (char character : text) {
		std::cout << character;
		std::cout.flush(); // Flush the output to ensure immediate display
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); // chrono lib for time duration
	}
	std::cout << '\n';
}

void GameText::WriteText(std::string text) {
	for (char character : text) {
		std::cout << character;
		std::cout.flush(); // Flush the output to ensure immediate display
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); // chrono lib for time duration
	}
}