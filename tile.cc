#include "tile.hh"

#include <iostream>

Tile::Tile(Position &pos, const std::string &texPath)
	: pos(pos)
{
	if (!tex.loadFromFile(texPath))
	{
	    std::cerr << "Erreur chargement" << std::endl;
	}
}

void Tile::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
	win.draw(sprite);
}
