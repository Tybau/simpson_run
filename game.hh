#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "tile.hh"
#include "personnage.hh"
#include "state.hh"

class Game
{
private:
	std::vector<Tile *> tiles;
	Personnage player;
public:
	Game();
	virtual ~Game();
	void update(State &state);
	void draw(sf::RenderWindow &win);
};
