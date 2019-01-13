#include "game.hh"

#include "wall.hh"
#include "donut.hh"
#include "spicy.hh"

Game::Game()
	: player(Position(500, 200), "images/perso.png")
{
	setMap();

	ghosts.push_back(Ghost(Position(1 * TILE_SIZE, 1 * TILE_SIZE), 0));
	ghosts.push_back(Ghost(Position(3 * TILE_SIZE, 3 * TILE_SIZE), 1));
	ghosts.push_back(Ghost(Position(5 * TILE_SIZE, 4 * TILE_SIZE), 2));
	ghosts.push_back(Ghost(Position(8 * TILE_SIZE, 8 * TILE_SIZE), 3));

	screen = 0;
}

Game::~Game()
{
	for(auto &tile : tiles)
		delete tile;
}

void Game::setMap()
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

void Game::update(State &state)
{
	if(screen == 0)
	{
		int time = MAX_TIME - (int)timer.getElapsedTime().asSeconds();
		if(time <= 0)
			screen = 1;
		player.update(state, tiles);
		for(auto &g : ghosts)
			g.update(state, tiles);
	}
	if(screen == 1)
	{
		if(state.KEY_SPACE)
		{
			// Reset le jeu
			screen = 0;
			player.resetScore();
			timer.restart();

			// Reset la Map
			for(auto &tile : tiles)
				delete tile;
			tiles.clear();
			setMap();
		}
	}
}

void Game::draw(sf::RenderWindow &win)
{
	if(screen == 0)
	{
		// Affichage des tuiles
		for(auto &tile : tiles)
		{
			tile->draw(win);
		}

		// Affichage du joueur
		player.draw(win);

		// Affichage des fantomes
		for(auto &g : ghosts)
			g.draw(win);

		// Affichage du texte
		sf::Font font;
		font.loadFromFile("fonts/simpson.ttf");

		// Score
		sf::Text text("Score : " + std::to_string(player.getScore()), font);
		text.setCharacterSize(30);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color(255, 255, 0));
		text.setPosition(10, 560);

		// timer
		int time = MAX_TIME - (int)timer.getElapsedTime().asSeconds();
		sf::Text text2(std::to_string(time) + "s", font);
		text2.setCharacterSize(30);
		text2.setStyle(sf::Text::Bold);
		text2.setFillColor(sf::Color(255, 255, 0));
		text2.setPosition(700, 560);

		win.draw(text);
		win.draw(text2);
	}
	else if(screen == 1)
	{
		sf::Font font;
		font.loadFromFile("fonts/simpson.ttf");

		// Message
		sf::Text text("Appuyez sur espace pour rejouer !", font);
		text.setCharacterSize(40);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color(255, 255, 0));
		text.setPosition(10, 10);

		// Score
		sf::Text text2("Score : " + std::to_string(player.getScore()), font);
		text2.setCharacterSize(30);
		text2.setStyle(sf::Text::Bold);
		text2.setFillColor(sf::Color(255, 255, 0));
		text2.setPosition(10, 560);

		win.draw(text);
		win.draw(text2);
	}
}
