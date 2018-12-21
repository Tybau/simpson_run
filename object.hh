#pragma once

#include "tile.hh"
#include "personnage.hh"

class Object : public Tile
{
public:
	Object(const Position &pos, const std::string &texPath):Tile(pos, texPath){};
	virtual void interact(Personnage &p) = 0;
	virtual void draw(sf::RenderWindow &win) = 0;
};
