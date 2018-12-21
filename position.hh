#pragma once

#include <SFML/Graphics.hpp>

class Position
{
private:
	float x;
	float y;
public:
	Position();
	Position(float x, float y);
	Position &operator+=(const sf::Vector2f &v);
	void set(float x, float y);

	int getX() const { return x; };
	void setX(float x) { this->x = x; };
	int getY() const { return y; };
	void setY(float y) { this->y = y; };

	sf::Vector2f getVector();
};

// Pour l'inertie
sf::Vector2f operator/(const sf::Vector2f &v, const float d);
