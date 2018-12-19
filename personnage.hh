#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "position.hh"
#include "state.hh"

class Personnage
{
private:
	std::string nom;
	sf::Texture tex;
	Position pos;
	sf::Vector2f velocity;
public:
	Personnage(const Position &pos, const std::string &texPath);
	void move(sf::Event &event);
	void update(State &state);
	void draw(sf::RenderWindow &win);
};