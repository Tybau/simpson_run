#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "tile.hh"

class Wall : public Tile
{
public:
	Wall(const Position &pos);
	virtual void draw(sf::RenderWindow &win);
};
