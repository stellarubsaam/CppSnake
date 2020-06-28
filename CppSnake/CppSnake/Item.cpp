#include "pch.h"
#include "Item.h"

Item::Item(float aRandomNumber, float anotherRandomNumber)
{
	shape.setRadius(15.);
	shape.setFillColor(sf::Color::Red);

	shape.setPosition(aRandomNumber, anotherRandomNumber);
}

Item::~Item()
{
}

sf::CircleShape Item::getItem()
{
	return shape;
}
