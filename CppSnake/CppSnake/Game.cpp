#include "pch.h"
#include "Game.h"
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

void Game::Snake(Game game)
{
	//gameplay window
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works... for now...");

#pragma region To_calculate_deltaTime_because_SFML_doesnt_have_it_build-in

	sf::Time time = {};
	sf::Clock clock = {};
	float lastTime = 0.0f;
	float currTime = 0.0f;

#pragma endregion

	//speed of the player
	int playerSpeed = 150;

	//sets the size of the player in pixels
	player.setSizePlayer(25);

	//set's the amount of items on the field
	for (int i = 0; i < 1; i++)
	{
		item.push_back(Item());
	}

	//Update function - global
	while (window.isOpen())
	{
		//delta time calculation
		time = clock.getElapsedTime();
		currTime = clock.getElapsedTime().asSeconds();
		deltaTime = currTime - lastTime;

		//delta time implementation, forces the game to run at 60fps
		if (currTime - lastTime >= 1.0f / 60.0f)
		{
			//Update function - Is only executed on mouse/keyboard input
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}

			//player movement
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				player.MovePlayer(-playerSpeed * deltaTime, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				player.MovePlayer(playerSpeed * deltaTime, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				player.MovePlayer(0, -playerSpeed * deltaTime);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				player.MovePlayer(0, playerSpeed * deltaTime);
			}

			//checks if any of the items have touched the player and removes them
			for (int i = 0; i < item.size(); i++)
			{
				if (item.at(i).getItem().getGlobalBounds().intersects(player.getPlayer().getGlobalBounds()))
				{
					item.erase(item.begin() + i);
					break;
				}
			}
			//updates deltaTime
			lastTime = currTime;
		}

		//updates the draw
		window.clear();
		for (int i = 0; i < item.size(); i++)
		{
			window.draw(item.at(i).getItem());
		}
		window.draw(player.getPlayer());
		window.display();
	}
}
