#include "GameText.h"
#include <iostream>
#include <thread>
#include <conio.h>

void GameText::WriteLineInput(std::string text) {
	for (char character : text) {
		std::cout << character;
		std::cout.flush(); // Flush the output to ensure immediate display
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); // chrono lib for time duration
	}
	std::cout << '\n';

	_getch();
	system("cls");

	/*std::cout << text << std::endl;
	_getch();
	system("cls");*/
}

void GameText::WriteLine(std::string text) {
	for (char character : text) {
		std::cout << character;
		std::cout.flush(); // Flush the output to ensure immediate display
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); // chrono lib for time duration
	}
	std::cout << '\n';

	//std::cout << text << std::endl;
}


void GameText::WriteText(std::string text) {
	for (char character : text) {
		std::cout << character;
		std::cout.flush(); // Flush the output to ensure immediate display
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); // chrono lib for time duration
	}

	//std::cout << text;
}

void GameText::WriteWithoutTyping(std::string text) {
	std::cout << text << std::endl;

}