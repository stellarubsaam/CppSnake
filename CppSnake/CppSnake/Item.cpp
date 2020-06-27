#include "pch.h"
#include "Item.h"

Item::Item()
{
	shape.setRadius(15.);
	shape.setFillColor(sf::Color::Red);

	shape.setPosition(300, 300);
}

Item::~Item()
{
}

sf::CircleShape Item::getItem()
{
	return shape;
}
