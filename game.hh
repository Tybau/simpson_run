#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "tile.hh"
#include "player.hh"
#include "ghost.hh"
#include "state.hh"

#define MAX_TIME 15

class Game
{
private:
	std::vector<Tile *> tiles;
	Player player;
	std::vector<Ghost> ghosts;

	int screen;
	sf::Clock timer;
public:
	Game();
	virtual ~Game();
	void update(State &state);
	void draw(sf::RenderWindow &win);

	void setMap();
};
