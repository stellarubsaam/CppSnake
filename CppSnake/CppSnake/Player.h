#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();

	void setSizePlayer(float aSize);
	sf::CircleShape getPlayer();
	void MovePlayer(float x, float y);

private:
	sf::CircleShape shape;
};

