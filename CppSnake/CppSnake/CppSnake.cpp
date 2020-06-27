// CppSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "Game.h"

#include <iostream>

int main()
{
	//Instantiates a game class and launches the game
	Game game;
	game.Snake(game);

	return 0;

	//TODO: Get multiple items on the field and make them respawn when all are removed
}