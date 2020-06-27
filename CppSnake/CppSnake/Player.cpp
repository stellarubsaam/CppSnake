#include "pch.h"
#include "Player.h"
#include <iostream>

Player::Player()
{
}

Player::~Player()
{
}

void Player::setSizePlayer(float aSize)
{

	shape.setRadius(aSize);
	shape.setFillColor(sf::Color::Green);
}

sf::CircleShape Player::getPlayer()
{
	return shape;
}

void Player::MovePlayer(float x, float y)
{
	shape.move(x,y);
}
