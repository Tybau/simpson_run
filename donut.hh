#pragma once

#include "object.hh"

class Donut : public Object
{
private:
	bool state;
	sf::Texture crocTex;
public:
	Donut(const Position &pos);
	virtual void interact(Personnage &p);
	virtual void draw(sf::RenderWindow &win);
};
