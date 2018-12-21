#pragma once

#include "tile.hh"
#include "personnage.hh"

class Object : public Tile
{
protected:
	bool state;
public:
	Object(const Position &pos, const std::string &texPath):Tile(pos, texPath), state(true){};
	virtual void interact(Personnage &p) = 0;
	virtual void draw(sf::RenderWindow &win) = 0;
};
