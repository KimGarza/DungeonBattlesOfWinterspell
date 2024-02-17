// DungeonBattlesOfWinterspellCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Game.h"
#undef min
#undef max
#define NOMINMAX
#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>


int main()
{
    Game game;
    game.CheckGameState();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
