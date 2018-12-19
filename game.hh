#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "tile.hh"

class Game
{
private:
	std::vector<Tile> tiles;
public:
	Game();
	void update();
	void draw(sf::RenderWindow &win);
};
