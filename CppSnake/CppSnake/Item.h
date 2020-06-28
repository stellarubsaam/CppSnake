#pragma once
#include <SFML/Graphics.hpp>

class Item
{
public:
	Item(float aRandomNumber, float anotherRandomNumber);
	~Item();

	sf::CircleShape getItem();

private:
	sf::CircleShape shape;
};

