#pragma once

#include "personnage.hh"
#include "player.hh"

class Ghost: public Personnage
{
private:
	int score;
	char dir;

	bool active;
public:
	Ghost(const Position &pos, const char dir)
		: Personnage(pos, "images/ghost.png"), score(0), dir(dir), active(true) {};
	virtual void update(const State &state, const std::vector<Tile *> &tiles);
	virtual void draw(sf::RenderWindow &win);

	void collide(Player &player);
private:
	virtual void applyCollisions(const std::vector<Tile *> &tiles, const Position oldPos);
};
