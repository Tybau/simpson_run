#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "tile.hh"
#include "personnage.hh"
#include "state.hh"

#define MAX_TIME 10

class Game
{
private:
	std::vector<Tile *> tiles;
	Personnage player;

	int screen;
	sf::Clock timer;
public:
	Game();
	virtual ~Game();
	void update(State &state);
	void draw(sf::RenderWindow &win);

	void setMap();
};
