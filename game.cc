#include "game.hh"

#include "wall.hh"
#include "donut.hh"
#include "spicy.hh"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

Game::Game()
	: player(Position(0, 0), "images/perso.png")
{
	setMap();

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
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(j == 0) continue;  // premiere ligne vide

			int p = 20;
			map[i][j] = 0;

			if(j > 0 && map[i][j - 1] == 1) p = -15; // pas 2 murs l'un sur l'autre
			if(i > 0 && map[i - 1][j] == 1) p += 35;
			if(i > 0 && j > 0 && map[i - 1][j - 1] == 1) p += 5;
			if(i > 0 && j < 12 && map[i - 1][j + 1] == 1) p += 5;

			if(i == 0 && j == 1) p = 100;

			if(std::rand() % 100 < p)
			{
				tiles.push_back(new Wall(Position(i * TILE_SIZE, j * TILE_SIZE)));
				map[i][j] = 1;
			}
		}
	}

	// Genere les bonus et fantomes
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int p = 5;

			if(!map[i][j])
			{
				if(j < 7 && map[i][j + 1] == 1) p += 15;
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

		// Gerer la chute de l'ecran
		if(player.getPosition().getY() > DESPLAY_HEIGHT)
			screen = 1; // Fin du jeu
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

// Pour afficher du texte
void displayText(sf::RenderWindow &win, std::string str, int x, int y, int size)
{
	sf::Font font;
	font.loadFromFile("fonts/simpson.ttf");

	sf::Text text(str, font);
	text.setCharacterSize(size);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color(255, 255, 0));
	text.setPosition(x, y);

	win.draw(text);
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

		// Score
		displayText(win, "Score : " + std::to_string(player.getScore()), 10, 560, 30);

		// timer
		int time = MAX_TIME - (int)timer.getElapsedTime().asSeconds();
		displayText(win, std::to_string(time) + "s", 700, 560, 30);
	}
	else if(screen == 1)
	{
		// Message
		displayText(win, "Appuyez sur espace pour rejouer !", 10, 10, 40);

		// Score
		displayText(win, "Score : " + std::to_string(player.getScore()), 10, 560, 30);
	}
}
