#include "personnage.hh"

#include <iostream>

Personnage::Personnage(const Position &pos, const std::string &texPath)
	: pos(pos)
{
	if (!tex.loadFromFile(texPath))
	    std::cerr << "Erreur de chargement de la texture!" << std::endl;
}

void Personnage::update(State &state)
{
	if (state.KEY_Z)
		velocity.y -= 2;
	if (state.KEY_S)
        velocity.y += 2;
	if (state.KEY_Q)
        velocity.x -= 2;
	if (state.KEY_D)
        velocity.x += 2;

	if(velocity.x > 10) velocity.x = 10;
	if(velocity.x < -10) velocity.x = -10;
	if(velocity.y > 10) velocity.y = 10;
	if(velocity.y < -10) velocity.y = -10;

	if(velocity.x > 0) velocity.x--;
	if(velocity.x < 0) velocity.x++;
	if(velocity.y > 0) velocity.y--;
	if(velocity.y < 0) velocity.y++;

	pos.setX(pos.getX() + velocity.x * 0.2);
	pos.setY(pos.getY() + velocity.y * 0.2);

	std::cout << velocity.x << " , " << velocity.y << std::endl;
}

void Personnage::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
	sprite.setScale(sf::Vector2f(64.0 / 279.0, 64.0 / 279.0));
	win.draw(sprite);
}
