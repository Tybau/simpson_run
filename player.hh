#pragma once

#include "personnage.hh"

class Player: public Personnage
{
private:
	int score;
public:
	Player(const Position &pos, const std::string &texPath)
		: Personnage(pos, texPath), score(0) {};
	virtual void update(const State &state, const std::vector<Tile *> &tiles);
	virtual void draw(sf::RenderWindow &win);

	int getScore() const { return score; };
	void addScore(const int &s) { score += s; };
	void resetScore() { score = 0; };
private:
	virtual void applyCollisions(const std::vector<Tile *> &tiles, const Position oldPos);
};
