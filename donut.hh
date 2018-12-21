#pragma once

#include <SFML/Audio.hpp>

#include "object.hh"

class Donut : public Object
{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Texture crocTex;
public:
	Donut(const Position &pos);
	virtual void interact(Personnage &p);
	virtual void draw(sf::RenderWindow &win);
};
