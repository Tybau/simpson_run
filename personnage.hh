#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "tile.hh"
#include "position.hh"
#include "state.hh"

class Personnage
{
private:
	std::string nom;
	sf::Texture tex;
	Position pos;
	sf::Vector2f velocity;

	bool grounded;

	int score;
public:
	Personnage(const Position &pos, const std::string &texPath);
	void move(sf::Event &event);
	void update(State &state, std::vector<Tile *> &tiles);
	void draw(sf::RenderWindow &win);

	Position getPosition() const { return pos; };
	int getScore() const { return score; };
	void addScore(const int &s) { score += s; };
};
