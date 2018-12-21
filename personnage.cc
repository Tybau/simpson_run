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

void Personnage::update(State &state, std::vector<Tile *> &tiles)
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
	Position oldPos = Position(pos.getX(), pos.getY());
	pos += velocity / INERTIE;

	// Gérer les collisions
	for(auto& tile : tiles)
	{
		if(tile->collision(pos))
		{
			pos.set(oldPos.getX(), oldPos.getY());
			velocity.x = 0;
			velocity.y = 0;
		}
	}
}

void Personnage::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
	win.draw(sprite);
}
