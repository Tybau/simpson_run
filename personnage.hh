#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "tile.hh"
#include "position.hh"
#include "state.hh"

#include <iostream>

class Personnage
{
protected:
	std::string nom;
	sf::Texture tex;
	Position pos;
	sf::Vector2f velocity;

	bool grounded;
public:
	Personnage(const Position &pos, const std::string &texPath)
		: pos(pos)
	{
		if (!tex.loadFromFile(texPath))
		    std::cerr << "Erreur de chargement de la texture!" << std::endl;
		grounded = false;
	}

	virtual void update(const State &state, const std::vector<Tile *> &tiles) = 0;
	virtual void draw(sf::RenderWindow &win) = 0;

	Position getPosition() const { return pos; };
protected:
	virtual void applyCollisions(const std::vector<Tile *> &tiles, const Position oldPos) = 0;
};
