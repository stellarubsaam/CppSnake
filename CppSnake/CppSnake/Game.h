#pragma once

#include "pch.h"

#include <SFML/System.hpp>
#include <sfml/Graphics.hpp>
#include <sfml/Audio.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Item.h"
#include "Game.h"
#include "vector"

class Game
{
public:
	Game();
	~Game();

	void Snake(Game game);

private:
	float deltaTime;
	Player player;
	//array of items
	std::vector<Item> item;
};

