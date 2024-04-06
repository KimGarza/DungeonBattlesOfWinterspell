#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <conio.h>

class GameText
{

public:
	void WriteLineInput(std::string text);
	void WriteLine(std::string text);
	void WriteText(std::string text);
	void WriteWithoutTyping(std::string text);
};

