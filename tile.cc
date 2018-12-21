#include "tile.hh"

#include <iostream>

Tile::Tile(const Position &pos, const std::string &texPath)
	: pos(pos)
{
	if (!tex.loadFromFile(texPath))
	    std::cerr << "Erreur de chargement de la texture!" << std::endl;
}

void Tile::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.setPosition(pos.getVector());
	win.draw(sprite);
}

bool Tile::collision(Position &p)
{
	float pX = p.getX();
	float pY = p.getY();

	float tX = pos.getX();
	float tY = pos.getX();

	return (pX + TILE_SIZE > tX && pX < tX + TILE_SIZE && pY + TILE_SIZE > tY && pY < tY + TILE_SIZE);
}
