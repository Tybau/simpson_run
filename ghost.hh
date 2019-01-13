#pragma once

#include "personnage.hh"

class Ghost: public Personnage
{
private:
	int score;
	char dir;
public:
	Ghost(const Position &pos, const char dir)
		: Personnage(pos, "images/ghost.png"), score(0), dir(dir) {};
	virtual void update(const State &state, const std::vector<Tile *> &tiles);
	virtual void draw(sf::RenderWindow &win);
private:
	virtual void applyCollisions(const std::vector<Tile *> &tiles, const Position oldPos);
};
