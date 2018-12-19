#include "personnage.hh"

#include <iostream>

#define MAX_SPEED 8
#define INERTIE 2
#define REAL_SPEED (MAX_SPEED * INERTIE)

Personnage::Personnage(const Position &pos, const std::string &texPath)
	: pos(pos)
{
	if (!tex.loadFromFile(texPath))
	    std::cerr << "Erreur de chargement de la texture!" << std::endl;
}

void Personnage::update(State &state)
{
	// Augmenter la vitesse en fonction du clavier
	if (state.KEY_Z)
		velocity.y -= 2;
	if (state.KEY_S)
        velocity.y += 2;
	if (state.KEY_Q)
        velocity.x -= 2;
	if (state.KEY_D)
        velocity.x += 2;

	// Caper la vitesse
	if(velocity.x > REAL_SPEED) velocity.x = REAL_SPEED;
	if(velocity.x < -REAL_SPEED) velocity.x = -REAL_SPEED;
	if(velocity.y > REAL_SPEED) velocity.y = REAL_SPEED;
	if(velocity.y < -REAL_SPEED) velocity.y = -REAL_SPEED;

	// Ralentir le personnage (frottements)
	if(velocity.x > 0) velocity.x--;
	if(velocity.x < 0) velocity.x++;
	if(velocity.y > 0) velocity.y--;
	if(velocity.y < 0) velocity.y++;

	// Appliquer le mouvement
	pos.setX(pos.getX() + velocity.x / INERTIE);
	pos.setY(pos.getY() + velocity.y / INERTIE);
}

void Personnage::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
	sprite.setScale(sf::Vector2f(64.0 / 279.0, 64.0 / 279.0));
	win.draw(sprite);
}