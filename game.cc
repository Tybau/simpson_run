#include "game.hh"

#include "wall.hh"
#include "donut.hh"
#include "spicy.hh"

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
	tiles.push_back(new Wall(Position(11 * TILE_SIZE, 6 * TILE_SIZE)));

	tiles.push_back(new Donut(Position(11 * TILE_SIZE, 5 * TILE_SIZE)));
	tiles.push_back(new Donut(Position(2 * TILE_SIZE, 4 * TILE_SIZE)));

	tiles.push_back(new Spicy(Position(9 * TILE_SIZE, 5 * TILE_SIZE)));
}

Game::~Game()
{
	for(auto &tile : tiles)
		delete tile;
}

void Game::update(State &state)
{
	player.update(state, tiles);
}

void Game::draw(sf::RenderWindow &win)
{
	// Affichage des tuiles
	for(auto &tile : tiles)
	{
		tile->draw(win);
	}

	// Affichage du joueur
	player.draw(win);

	// Affichage du texte
	sf::Font font;
	font.loadFromFile("fonts/simpson.ttf");

	sf::Text text("Score : " + std::to_string(player.getScore()), font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color(255, 255, 0));
	text.setPosition(10, 560);

	win.draw(text);
}
