#include "wall.hh"

Wall::Wall(const Position &pos)
	: Tile(pos, "images/wall.jpg")
{
}

void Wall::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.setPosition(pos.getVector());
	win.draw(sprite);
}
