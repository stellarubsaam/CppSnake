#pragma once
#include <SFML/Graphics.hpp>

class Item
{
public:
	Item();
	~Item();

	sf::CircleShape getItem();

private:
	sf::CircleShape shape;
};

