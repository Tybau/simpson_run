#pragma once

#include "object.hh"

class Spicy : public Object
{
public:
	Spicy(const Position &pos);
	virtual void interact(Personnage &p);
	virtual void draw(sf::RenderWindow &win);
};
