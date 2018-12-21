#include "spicy.hh"

#include <iostream>

Spicy::Spicy(const Position &pos):Object(pos, "images/spicy.png")
{
}

void Spicy::interact(Personnage &p)
{
	if(this->state)
	{
		p.addScore(-1);
		this->state = false;
	}
}

void Spicy::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	if(this->state)
		sprite.setTexture(tex);
	sprite.setPosition(pos.getVector());
	win.draw(sprite);
}
