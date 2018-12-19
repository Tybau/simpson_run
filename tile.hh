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
	//virtual void colision(Personnage p);
	//virtual void draw(sf::RenderWindow &win) = 0;
	void draw(sf::RenderWindow &win);
};
