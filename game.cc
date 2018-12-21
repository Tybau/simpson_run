#include "game.hh"

Game::Game()
	: player(Position(500, 200), "images/perso.jpg")
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = i; j < 10; j++)
		{
			tiles.push_back(Tile(Position(i * TILE_SIZE, j * TILE_SIZE), "images/wall.jpg"));
		}
	}
}

void Game::update(State &state)
{
	player.update(state, tiles);
}

void Game::draw(sf::RenderWindow &win)
{
	for(auto &tile : tiles)
	{
		tile.draw(win);
	}
	player.draw(win);
}
