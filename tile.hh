#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "position.hh"

#define TILE_SIZE 64

class Tile
{
protected:
	Position pos;
	sf::Texture tex;
public:
	Tile(const Position &pos, const std::string &texPath);
	virtual ~Tile(){};
	bool collision(Position &p);
	virtual void draw(sf::RenderWindow &win) = 0;

	Position getPosition() const { return pos; };
};
