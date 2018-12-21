#include "position.hh"

Position::Position()
{
	x = 0;
	y = 0;
}

Position::Position(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Position::set(float x, float y)
{
	this->x = x;
	this->y = y;
}

Position &Position::operator+=(const sf::Vector2f &v)
{
	this->x = this->x + v.x;
	this->y = this->y + v.y;
	return *this;
}

sf::Vector2f Position::getVector()
{
	return sf::Vector2f(x, y);
}


sf::Vector2f operator/(const sf::Vector2f &v, const float d)
{
	sf::Vector2f res;
	res.x = v.x / d;
	res.y = v.y / d;
	return res;
}
