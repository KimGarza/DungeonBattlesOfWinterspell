// DungeonBattlesOfWinterspellCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Headers\Game\Game.h"
#undef min
#undef max
#define NOMINMAX
#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>


int main()
{
    std::shared_ptr<GameContext> ctx = std::make_shared<GameContext>();
    Game game(ctx);
    game.StateCycle();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
