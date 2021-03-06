#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

#include "tile.hh"
#include "player.hh"
#include "ghost.hh"
#include "state.hh"

#define DISPLAY_WIDTH 832
#define DESPLAY_HEIGHT 600
#define MAX_TIME 25

class Game
{
private:
	std::vector<Tile *> tiles;
	Player player;
	std::list<Ghost> ghosts;

	int screen;
	sf::Clock timer;
public:
	Game();
	virtual ~Game();
	void update(State &state);
	void draw(sf::RenderWindow &win);

	void setMap();
};
