#include "tile.hh"

#include <iostream>

#define PERSO_WIDTH 43
#define PERSO_HEIGHT 64

Tile::Tile(const Position &pos, const std::string &texPath)
	: pos(pos)
{
	if (!tex.loadFromFile(texPath))
	    std::cerr << "Erreur de chargement de la texture!" << std::endl;
}

bool Tile::collision(Position &p)
{
	float pX = p.getX();
	float pY = p.getY();

	float tX = pos.getX();
	float tY = pos.getY();

	return (pX + PERSO_WIDTH > tX && pX < tX + TILE_SIZE && pY + PERSO_HEIGHT > tY && pY < tY + TILE_SIZE);
}
