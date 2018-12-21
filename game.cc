#include "game.hh"

#include "wall.hh"

Game::Game()
	: player(Position(500, 200), "images/perso.png")
{

	tiles.push_back(new Wall(Position(2 * TILE_SIZE, 5 * TILE_SIZE)));
	tiles.push_back(new Wall(Position(3 * TILE_SIZE, 5 * TILE_SIZE)));
	tiles.push_back(new Wall(Position(4 * TILE_SIZE, 5 * TILE_SIZE)));
	tiles.push_back(new Wall(Position(5 * TILE_SIZE, 5 * TILE_SIZE)));

	tiles.push_back(new Wall(Position(7 * TILE_SIZE, 5 * TILE_SIZE)));
	tiles.push_back(new Wall(Position(8 * TILE_SIZE, 5 * TILE_SIZE)));
	tiles.push_back(new Wall(Position(9 * TILE_SIZE, 6 * TILE_SIZE)));
	tiles.push_back(new Wall(Position(10 * TILE_SIZE, 6 * TILE_SIZE)));
}

void Game::update(State &state)
{
	player.update(state, tiles);
}

void Game::draw(sf::RenderWindow &win)
{
	for(auto &tile : tiles)
	{
		tile->draw(win);
	}
	player.draw(win);
}
