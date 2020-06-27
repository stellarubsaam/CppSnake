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
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works... for now...");

	sf::Time time = {};
	sf::Clock clock = {};
	float lastTime = 0.0f;
	float currTime = 0.0f;

	int playerSpeed = 150;

	player.setSizePlayer(25);

	for (int i = 0; i < 1; i++)
	{
		item.push_back(Item());
	}

	while (window.isOpen())
	{
		time = clock.getElapsedTime();
		currTime = clock.getElapsedTime().asSeconds();
		
		deltaTime = currTime - lastTime;

		if (currTime - lastTime >= 1.0f / 60.0f)
		{
			
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				/*
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{

				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				{
				}
				*/

			}

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

			//time = clock.getElapsedTime();

			for (int i = 0; i < item.size(); i++)
			{
				if (item.at(i).getItem().getGlobalBounds().intersects(player.getPlayer().getGlobalBounds()))
				{
					item.erase(item.begin() + i);
					break;
				}
			}


			lastTime = currTime;
		}

		window.clear();
		for (int i = 0; i < item.size(); i++)
		{
			window.draw(item.at(i).getItem());
		}
		window.draw(player.getPlayer());
		window.display();
	}
}
