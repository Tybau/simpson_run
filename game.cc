#include "game.hh"

#include "wall.hh"
#include "donut.hh"
#include "spicy.hh"

#include <cstdlib>
#include <iostream>
#include <ctime>

Game::Game()
	: player(Position(0, 0), "images/perso.png")
{
	setMap();

	/*ghosts.push_back(Ghost(Position(1 * TILE_SIZE, 1 * TILE_SIZE), 0));
	ghosts.push_back(Ghost(Position(3 * TILE_SIZE, 3 * TILE_SIZE), 1));
	ghosts.push_back(Ghost(Position(5 * TILE_SIZE, 4 * TILE_SIZE), 2));
	ghosts.push_back(Ghost(Position(8 * TILE_SIZE, 8 * TILE_SIZE), 3));*/

	screen = 0;
}

Game::~Game()
{
	for(auto &tile : tiles)
		delete tile;
}

void Game::setMap()
{
	int map[13][8];

	std::srand(std::time(nullptr));

	// Genere les murs
	for (int i = -1; i < 13; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(j == 0) continue;  // premiere ligne vide

			int p = 20;
			map[i][j] = 0;

			if(j > 0 && map[i][j - 1] == 1) p -= 15;
			if(i > 0 && map[i - 1][j] == 1) p += 30;
			if(i > 0 && j > 0 && map[i - 1][j - 1] == 1) p += 15;
			if(i > 0 && j < 13 && map[i - 1][j + 1] == 1) p += 15;

			if(std::rand() % 100 < p)
			{
				tiles.push_back(new Wall(Position(i * TILE_SIZE, j * TILE_SIZE)));
				map[i][j] = 1;
			}
		}
	}

	// Genere les bonus
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int p = 5;

			if(!map[i][j])
			{
				if(i < 13 && map[i][j + 1] == 1) p += 15;
				if(std::rand() % 100 < p)
					tiles.push_back(new Donut(Position(i * TILE_SIZE, j * TILE_SIZE)));
				else if(std::rand() % 100 < p / 2)
					tiles.push_back(new Spicy(Position(i * TILE_SIZE, j * TILE_SIZE)));
				else if(std::rand() % 100 < p)
					ghosts.push_back(Ghost(Position(i * TILE_SIZE, j * TILE_SIZE), (i+j)%4));
			}
		}
	}
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
		{
			g.update(state, tiles);
			g.collide(player);
		}
	}
	if(screen == 1)
	{
		if(state.KEY_SPACE)
		{
			// Reset le jeu
			screen = 0;
			player.resetScore();
			player.setPosition(Position(0, 0));
			timer.restart();

			// Reset la Map
			for(auto &tile : tiles)
				delete tile;
			tiles.clear();
			ghosts.clear();
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
